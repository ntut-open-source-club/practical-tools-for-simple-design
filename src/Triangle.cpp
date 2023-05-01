#include "Triangle.hpp"

#include <memory>
#include <vector>

#include "Core/IndexBuffer.hpp"
#include "Core/VertexArray.hpp"
#include "Core/VertexBuffer.hpp"

Triangle::Triangle()
    : m_Program("../assets/shaders/Triangle.vert",
                "../assets/shaders/Triangle.frag"),
      m_VertexArray(std::make_unique<Core::VertexArray>()) {
    std::vector<float> vertex({
        -0.5F, -0.5F, // NOLINT
        0.5F, -0.5F,  // NOLINT
        0.0F, 0.5F,   // NOLINT
    });
    std::vector<float> color({
        1.0F, 0.0F, 0.0F, //
        0.0F, 1.0F, 0.0F, //
        0.0F, 0.0F, 1.0F, //
    });
    std::vector<unsigned int> index({
        0, 1, 2 //
    });

    m_VertexArray->AddVertexBuffer(
        std::make_unique<Core::VertexBuffer>(vertex, 2));

    m_VertexArray->AddVertexBuffer(
        std::make_unique<Core::VertexBuffer>(color, 3));

    m_VertexArray->SetIndexBuffer(std::make_unique<Core::IndexBuffer>(index));
}

void Triangle::Update() {
    m_Program.Bind();
    m_Program.Validate();

    m_VertexArray->DrawTriangles();
}
