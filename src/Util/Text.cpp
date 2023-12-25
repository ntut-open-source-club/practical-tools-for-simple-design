// FIXME: this file should be refactor, API change reference from Image.cpp

#include "Core/Texture.hpp"

#include "Util/Text.hpp"
#include "Util/TransformUtils.hpp"

#include "config.hpp"

namespace Util {
Text::Text(const std::string &font, int size, const std::string &text) {
    if (s_Program == nullptr) {
        InitProgram();
    }
    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }
    if (s_UniformBuffer == nullptr) {
        InitUniformBuffer();
    }

    m_Font = {TTF_OpenFont(font.c_str(), size), TTF_CloseFont};

    if (m_Font == nullptr) {
        LOG_ERROR("Failed to load font: '{}'", text);
        LOG_ERROR("{}", TTF_GetError());
    }

    m_Surface = {TTF_RenderUTF8_Blended_Wrapped(m_Font.get(), text.c_str(),
                                                SDL_Color{255, 0, 255, 0}, 0),
                 SDL_FreeSurface};

    if (m_Surface == nullptr) {
        LOG_ERROR("Failed to create text");
        LOG_ERROR("{}", TTF_GetError());
    }

    m_Texture = std::make_unique<Core::Texture>(
        m_Surface->format->BytesPerPixel,
        m_Surface->pitch / m_Surface->format->BytesPerPixel, m_Surface->h,
        m_Surface->pixels);
}

void Text::Draw(const Util::Transform &transform, const float zIndex) {
    // FIXME: temporary fix
    auto data = Util::ConvertToUniformBufferData(transform, zIndex);
    s_UniformBuffer->SetData(0, data);

    m_Texture->Bind(UNIFORM_SURFACE_LOCATION);
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Text::InitProgram() {
    // TODO: Create `BaseProgram` from `Program` and pass it into `Drawable`
    s_Program = std::make_unique<Core::Program>("../assets/shaders/Base.vert",
                                                "../assets/shaders/Base.frag");
    s_Program->Bind();

    GLint location = glGetUniformLocation(s_Program->GetId(), "surface");
    glUniform1i(location, UNIFORM_SURFACE_LOCATION);
}

void Text::InitVertexArray() {
    s_VertexArray = std::make_unique<Core::VertexArray>();

    // hard coded value
    constexpr float scale = 100.0F;

    // NOLINTBEGIN
    // These are vertex data for the rectangle but clang-tidy has magic
    // number warnings

    // Vertex
    s_VertexArray->AddVertexBuffer(std::make_unique<Core::VertexBuffer>(
        std::vector<float>{
            -1.0F * scale, 1.0F * scale,  //
            -1.0F * scale, -1.0F * scale, //
            1.0F * scale, -1.0F * scale,  //
            1.0F * scale, 1.0F * scale,   //
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

void Text::InitUniformBuffer(const Util::Transform &transform,
                             const float zIndex) {
    s_UniformBuffer = std::make_unique<Core::UniformBuffer<Core::Matrices>>(
        *s_Program, "Matrices", 0);

    auto data = Util::ConvertToUniformBufferData(transform, zIndex);
    s_UniformBuffer->SetData(0, data);
}

std::unique_ptr<Core::Program> Text::s_Program = nullptr;
std::unique_ptr<Core::VertexArray> Text::s_VertexArray = nullptr;
std::unique_ptr<Core::UniformBuffer<Core::Matrices>> Text::s_UniformBuffer =
    nullptr;

} // namespace Util
