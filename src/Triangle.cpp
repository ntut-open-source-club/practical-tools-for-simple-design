#include "Triangle.hpp"

#include "Core/IndexBuffer.hpp"
#include "Core/VertexArray.hpp"
#include "Core/VertexBuffer.hpp"

Triangle::Triangle()
    : m_Program("../assets/shaders/Triangle.vert",
                "../assets/shaders/Triangle.frag") {
    Core::VertexArray vao( //
        {
            Core::VertexBuffer(
                {
                    -0.5F, -0.5F, // NOLINT
                    0.5F, -0.5F,  // NOLINT
                    0.0F, 0.5F,   // NOLINT
                },
                2),
            Core::VertexBuffer(
                {
                    1.0F, 0.0F, 0.0F, //
                    0.0F, 1.0F, 0.0F, //
                    0.0F, 0.0F, 1.0F, //
                },
                3),
        },
        Core::IndexBuffer({0, 1, 2}));
}

void Triangle::Update() {
    m_Program.Bind();
    m_Program.Validate();
}
