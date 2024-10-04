// FIXME: this file should be refactor, API change reference from Image.cpp

#include "Core/Texture.hpp"
#include "Core/TextureUtils.hpp"

#include "Util/Logger.hpp"
#include "Util/MissingTexture.hpp"
#include "Util/Text.hpp"
#include "Util/TransformUtils.hpp"

namespace Util {
Text::Text(const std::string &font, int fontSize, const std::string &text,
           const Util::Color &color, bool useAA)
    : m_Text(text),
      m_Color(color) {
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }

    m_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);

    auto surface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>();
    m_Font = {TTF_OpenFont(font.c_str(), fontSize), TTF_CloseFont};

    if (m_Font == nullptr) {
        LOG_ERROR("Failed to load font: '{}'", font.c_str());
        LOG_ERROR("{}", TTF_GetError());
        surface = {GetMissingFontTextureSDLSurface(), SDL_FreeSurface};
    } else {
        surface =
            std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
                TTF_RenderUTF8_Blended_Wrapped(m_Font.get(), m_Text.c_str(),
                                               m_Color.ToSdlColor(), 0),
                SDL_FreeSurface,
            };
    }

    m_Texture = std::make_unique<Core::Texture>(
        Core::SdlFormatToGlFormat(surface->format->format),
        surface->pitch / surface->format->BytesPerPixel, surface->h,
        surface->pixels, useAA);
    m_Size = {surface->pitch / surface->format->BytesPerPixel, surface->h};
}

void Text::UseAntiAliasing(bool useAA) {
    m_Texture->UseAntiAliasing(useAA);
}

void Text::Draw(const Core::Matrices &data) {
    m_UniformBuffer->SetData(0, data);

    m_Texture->Bind(UNIFORM_SURFACE_LOCATION);
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Text::InitProgram() {
    // TODO: Create `BaseProgram` from `Program` and pass it into `Drawable`
    s_Program =
        std::make_unique<Core::Program>(PTSD_ASSETS_DIR "/shaders/Base.vert",
                                        PTSD_ASSETS_DIR "/shaders/Base.frag");
    s_Program->Bind();

    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}

void Text::InitVertexArray() {
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

void Text::ApplyTexture() {
    auto surface =
        std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>();
    if (m_Font == nullptr) {
        surface = {GetMissingFontTextureSDLSurface(), SDL_FreeSurface};
    } else {
        surface =
            std::unique_ptr<SDL_Surface, std::function<void(SDL_Surface *)>>{
                TTF_RenderUTF8_Blended_Wrapped(m_Font.get(), m_Text.c_str(),
                                               m_Color.ToSdlColor(), 0),
                SDL_FreeSurface,
            };
    }
    if (surface == nullptr) {
        LOG_ERROR("Failed to create text: {}", TTF_GetError());
    }

    m_Texture->UpdateData(Core::SdlFormatToGlFormat(surface->format->format),
                          surface->pitch / surface->format->BytesPerPixel,
                          surface->h, surface->pixels);
    m_Size = {surface->pitch / surface->format->BytesPerPixel, surface->h};
}

std::unique_ptr<Core::Program> Text::s_Program = nullptr;
std::unique_ptr<Core::VertexArray> Text::s_VertexArray = nullptr;

} // namespace Util
