#include "Util/Image.hpp"

#include "Util/Logger.hpp"
#include "pch.hpp"

#include "Core/Texture.hpp"
#include "Core/TextureUtils.hpp"

#include "Util/MissingTexture.hpp"
#include "Util/TransformUtils.hpp"

#include "config.hpp"
#include <glm/fwd.hpp>

std::shared_ptr<SDL_Surface> LoadSurface(const std::string &filepath) {
    auto surface = std::shared_ptr<SDL_Surface>(IMG_Load(filepath.c_str()),
                                                SDL_FreeSurface);

    if (surface == nullptr) {
        surface = {GetMissingTextureSDLSurface(), SDL_FreeSurface};
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    return surface;
}

namespace Util {
Image::Image(const std::string &filepath)
    : m_Path(filepath) {
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }

    m_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);

    m_Surface = s_Store.Get(filepath);

    m_Texture = std::make_unique<Core::Texture>(
        Core::SdlFormatToGlFormat(m_Surface->format->format), m_Surface->w,
        m_Surface->h, m_Surface->pixels);
    m_Size = {m_Surface->w, m_Surface->h};
}

void Image::SetImage(const std::string &filepath) {
    m_Surface = s_Store.Get(filepath);

    m_Texture->UpdateData(Core::SdlFormatToGlFormat(m_Surface->format->format),
                          m_Surface->w, m_Surface->h, m_Surface->pixels);
    m_Size = {m_Surface->w, m_Surface->h};
}

void Image::Draw(const Core::Matrices &data) {
    m_UniformBuffer->SetData(0, data);

    m_Texture->Bind(UNIFORM_SURFACE_LOCATION);
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Image::InitProgram() {
    // TODO: Create `BaseProgram` from `Program` and pass it into `Drawable`
    s_Program =
        std::make_unique<Core::Program>(PTSD_DIR "/assets/shaders/Base.vert",
                                        PTSD_DIR "/assets/shaders/Base.frag");
    s_Program->Bind();

    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}

void Image::InitVertexArray() {
    s_VertexArray = std::make_unique<Core::VertexArray>();

    // NOLINTBEGIN
    // These are vertex data for the rectangle but clang-tidy has magic
    // number warnings

    // Vertex
    s_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(
        std::vector<float>{
            -0.5F, 0.5F,  //
            -0.5F, -0.5F, //
            0.5F, -0.5F,  //
            0.5F, 0.5F,   //
        },
        2));

    // UV
    s_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(
        std::vector<float>{
            0.0F, 0.0F, //
            0.0F, 1.0F, //
            1.0F, 1.0F, //
            1.0F, 0.0F, //
        },
        2));

    // Index
    s_VertexArray->SetIndexBuffer(
        std::make_unique<Core::IndexBuffer>(std::vector<unsigned int>{
            0, 1, 2, //
            0, 2, 3, //
        }));
    // NOLINTEND
}

void Image::UpdateTextureData(const SDL_Surface &surface) {
    m_Texture->UpdateData(Core::SdlFormatToGlFormat(surface.format->format),
                          surface.w, surface.h, surface.pixels);
    m_Size = {surface.w, surface.h};
}

void Image::SetAlpha(const Uint8 alpha) {
    auto OriginalBlendMode = SDL_BlendMode::SDL_BLENDMODE_BLEND;
    SDL_SetSurfaceAlphaMod(m_Surface.get(), alpha);
    SDL_GetSurfaceBlendMode(m_Surface.get(), &OriginalBlendMode);
    SDL_SetSurfaceBlendMode(m_Surface.get(), SDL_BLENDMODE_BLEND);

    auto targetSurface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
            SDL_CreateRGBSurfaceWithFormat(0, m_Surface->w, m_Surface->h,
                                           m_Surface->format->BitsPerPixel,
                                           m_Surface->format->format),
            SDL_FreeSurface,
        };
    SDL_BlitSurface(m_Surface.get(), NULL, targetSurface.get(), NULL);
    m_Texture->UpdateData(
        Core::SdlFormatToGlFormat(targetSurface->format->format),
        targetSurface->w, targetSurface->h, targetSurface->pixels);
    SDL_SetSurfaceAlphaMod(m_Surface.get(), 255);
    SDL_SetSurfaceBlendMode(m_Surface.get(), OriginalBlendMode);
}

std::unique_ptr<Core::Program> Image::s_Program = nullptr;
std::unique_ptr<Core::VertexArray> Image::s_VertexArray = nullptr;

Util::AssetStore<std::shared_ptr<SDL_Surface>> Image::s_Store(LoadSurface);
} // namespace Util
