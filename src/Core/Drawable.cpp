#include "Core/Drawable.hpp"

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

void Drawable::InitProgram() {
    s_Program = std::make_unique<Program>("../assets/shaders/Base.vert",
                                          "../assets/shaders/Base.frag");
}

void Drawable::InitVertexArray() {
    s_VertexArray = std::make_unique<VertexArray>();

    // NOLINTBEGIN
    // These are vertex data for the rectangle but clang-tidy has magic
    // number warnings

    // Vertex
    s_VertexArray->AddVertexBuffer(std::make_unique<VertexBuffer>(
        std::vector<float>{
            -1.0F, 1.0F,  //
            -1.0F, -1.0F, //
            1.0F, -1.0F,  //
            1.0F, 1.0F,   //
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
    // TODO: Maybe change UniformBuffer constructor to use pointer
    s_UniformBuffer =
        std::make_unique<UniformBuffer<Matrices>>(*s_Program, "Matrices", 0);
}
} // namespace Core
