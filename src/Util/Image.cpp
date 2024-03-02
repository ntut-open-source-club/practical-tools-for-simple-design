#include "Util/Image.hpp"

#include "SDL_error.h"
#include "SDL_surface.h"
#include "Util/Logger.hpp"
#include "pch.hpp"

#include "Core/Texture.hpp"
#include "Core/TextureUtils.hpp"

#include "Util/MissingTexture.hpp"
#include "Util/TransformUtils.hpp"

#include "config.hpp"
#include <memory>

namespace Util {
Image::Image(const std::string &filepath)
    : m_Path(filepath) {
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }
    if (s_UniformBuffer == nullptr) {
        InitUniformBuffer();
    }

    m_Surface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
            IMG_Load(filepath.c_str()),
            SDL_FreeSurface,
        };

    if (m_Surface == nullptr) {
        m_Surface = {GetMissingTextureSDLSurface(), SDL_FreeSurface};
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    m_Texture = std::make_unique<Core::Texture>(
        Core::SdlFormatToGlFormat(m_Surface->format->format), m_Surface->w,
        m_Surface->h, m_Surface->pixels);
    m_Size = {m_Surface->w, m_Surface->h};
}

void Image::SetImage(const std::string &filepath) {
    m_Surface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
            IMG_Load(filepath.c_str()),
            SDL_FreeSurface,
        };
    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to load image: '{}'", filepath);
        LOG_ERROR("{}", IMG_GetError());
    }

    m_Texture->UpdateData(Core::SdlFormatToGlFormat(m_Surface->format->format),
                          m_Surface->w, m_Surface->h, m_Surface->pixels);
    m_Size = {m_Surface->w, m_Surface->h};
}

void Image::Draw(const Util::Transform &transform, const float zIndex) {
    auto data = Util::ConvertToUniformBufferData(transform, m_Size, zIndex);
    s_UniformBuffer->SetData(0, data);

    m_Texture->Bind(UNIFORM_SURFACE_LOCATION);
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Image::InitProgram() {
    // TODO: Create `BaseProgram` from `Program` and pass it into `Drawable`
    s_Program = std::make_unique<Core::Program>("../assets/shaders/Base.vert",
                                                "../assets/shaders/Base.frag");
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

void Image::InitUniformBuffer() {
    s_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);
}

void Image::SetDrawRect(const SDL_Rect displayRect) {
    // can't just simplely use SDL_SetClipRect, because we use opengl to render
    // and I'm not sure this way if cost a lot performance?
    if (displayRect.h + displayRect.y > m_Surface->h ||
        displayRect.w + displayRect.x > m_Surface->w) {
        LOG_DEBUG("SetDrawRect OverRange");
        return;
    }

    auto targetSurface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
            SDL_CreateRGBSurfaceWithFormat(0, displayRect.w, displayRect.h, 32,
                                           m_Surface->format->format),
            SDL_FreeSurface,
        };

    int isCopyWork = SDL_BlitSurface(m_Surface.get(), &displayRect,
                                     targetSurface.get(), NULL);
    if (isCopyWork != 0) {
        LOG_ERROR("{}", SDL_GetError());
        return;
    }

    m_Texture->UpdateData(
        Core::SdlFormatToGlFormat(targetSurface->format->format),
        targetSurface->w, targetSurface->h, targetSurface->pixels);
    m_Size = {targetSurface->w, targetSurface->h};
}

std::unique_ptr<Core::Program> Image::s_Program = nullptr;
std::unique_ptr<Core::VertexArray> Image::s_VertexArray = nullptr;
std::unique_ptr<Core::UniformBuffer<Core::Matrices>> Image::s_UniformBuffer =
    nullptr;
} // namespace Util
