#include "Core/VertexArray.hpp"

namespace Core {
VertexArray::VertexArray(std::initializer_list<VertexBuffer> vertexBuffers,
                         IndexBuffer &&indexBuffer)
    : m_IndexBuffer(indexBuffer) {
    glGenVertexArrays(1, &m_ArrayId);
    glBindVertexArray(m_ArrayId);

    int counter = 0;
    for (const auto &buffer : vertexBuffers) {
        glEnableVertexAttribArray(counter);
        buffer.Bind();

        glVertexAttribPointer(counter,
                              static_cast<GLint>(buffer.GetComponentCount()),
                              buffer.GetType(), GL_FALSE, 0, nullptr);

        ++counter;
    }
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_ArrayId);
}

void VertexArray::Bind() const {
    glBindVertexArray(m_ArrayId);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::DrawTriangles() const {
    glDrawElements(GL_TRIANGLES, static_cast<GLint>(m_IndexBuffer.GetCount()),
                   GL_UNSIGNED_INT, nullptr);
}
} // namespace Core
