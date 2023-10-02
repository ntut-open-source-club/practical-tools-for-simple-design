#include "Core/VertexArray.hpp"

namespace Core {
VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_ArrayId);
}

VertexArray::VertexArray(VertexArray &&other) {
    m_ArrayId = other.m_ArrayId;
    other.m_ArrayId = 0;

    m_VertexBuffers = std::move(other.m_VertexBuffers);
    m_IndexBuffer = std::move(other.m_IndexBuffer);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_ArrayId);
}

VertexArray &VertexArray::operator=(VertexArray &&other) {
    m_ArrayId = other.m_ArrayId;
    other.m_ArrayId = 0;

    m_VertexBuffers = std::move(other.m_VertexBuffers);
    m_IndexBuffer = std::move(other.m_IndexBuffer);

    return *this;
}

void VertexArray::Bind() const {
    glBindVertexArray(m_ArrayId);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer) {
    glBindVertexArray(m_ArrayId);

    glEnableVertexAttribArray(m_VertexBuffers.size());
    vertexBuffer->Bind();

    glVertexAttribPointer(m_VertexBuffers.size(),
                          static_cast<GLint>(vertexBuffer->GetComponentCount()),
                          vertexBuffer->GetType(), GL_FALSE, 0, nullptr);

    m_VertexBuffers.push_back(std::move(vertexBuffer));
}

void VertexArray::SetIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer) {
    m_IndexBuffer = std::move(indexBuffer);
}

void VertexArray::DrawTriangles() const {
    glDrawElements(GL_TRIANGLES, static_cast<GLint>(m_IndexBuffer->GetCount()),
                   GL_UNSIGNED_INT, nullptr);
}
} // namespace Core
