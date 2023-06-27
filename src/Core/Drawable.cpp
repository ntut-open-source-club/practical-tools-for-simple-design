#include "Core/Drawable.hpp"

#include "config.hpp"

namespace Core {
Drawable::Drawable(glm::mat3 transform)
    : m_Transform(transform) {
    if (s_Program == nullptr) {
        InitProgram();
    }

    if (s_VertexArray == nullptr) {
        InitVertexArray();
    }

    if (s_UniformBuffer == nullptr) {
        InitUniformBuffer();
    }
}

void Drawable::Draw() {
    s_Program->Bind();
    s_Program->Validate();

    s_VertexArray->Bind();
    s_VertexArray->DrawTriangles();
}

void Drawable::InitProgram() {
    s_Program = std::make_unique<Program>("../assets/shaders/Base.vert",
                                          "../assets/shaders/Base.frag");
}

void Drawable::InitVertexArray() {
    s_VertexArray = std::make_unique<VertexArray>();

    // hard coded value
    constexpr float scale = 100.0F;

    // NOLINTBEGIN
    // These are vertex data for the rectangle but clang-tidy has magic
    // number warnings

    // Vertex
    s_VertexArray->AddVertexBuffer(std::make_unique<VertexBuffer>(
        std::vector<float>{
            -1.0F * scale, 1.0F * scale,  //
            -1.0F * scale, -1.0F * scale, //
            1.0F * scale, -1.0F * scale,  //
            1.0F * scale, 1.0F * scale,   //
        },
        2));

    // UV
    s_VertexArray->AddVertexBuffer(std::make_unique<VertexBuffer>(
        std::vector<float>{
            0.0F, 1.0F, //
            0.0F, 0.0F, //
            1.0F, 0.0F, //
            1.0F, 1.0F, //
        },
        2));

    // Index
    s_VertexArray->SetIndexBuffer(
        std::make_unique<IndexBuffer>(std::vector<unsigned int>{
            0, 1, 2, //
            0, 2, 3, //
        }));
    // NOLINTEND
}

void Drawable::InitUniformBuffer() {
    s_UniformBuffer =
        std::make_unique<UniformBuffer<Matrices>>(*s_Program, "Matrices", 0);

    constexpr Matrices data = {
        {
            1.0F, 0.0F, //
            0.0F, 1.0F, //
        },
        {
            1.0F / WINDOW_WIDTH, 0.0F,  //
            0.0F, 1.0F / WINDOW_HEIGHT, //
        },
    };

    s_UniformBuffer->SetData(0, data);
}

std::unique_ptr<Program> Drawable::s_Program = nullptr;
std::unique_ptr<VertexArray> Drawable::s_VertexArray = nullptr;
std::unique_ptr<UniformBuffer<Matrices>> Drawable::s_UniformBuffer = nullptr;
} // namespace Core
