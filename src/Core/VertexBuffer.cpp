#include "Core/VertexBuffer.hpp"

namespace Core {
VertexBuffer::VertexBuffer(const std::vector<float> &vertices,
                           unsigned int componentCount)
    : m_ComponentCount(componentCount) {
    glGenBuffers(1, &m_BufferId);
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
    glBufferData(GL_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(vertices.size() * sizeof(GLfloat)),
                 vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::VertexBuffer(VertexBuffer &&other) {
    m_BufferId = other.m_BufferId;
    other.m_BufferId = 0;

    m_ComponentCount = std::move(other.m_ComponentCount);
    m_Type = std::move(other.m_Type);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_BufferId);
}

VertexBuffer &VertexBuffer::operator=(VertexBuffer &&other) {
    m_BufferId = other.m_BufferId;
    other.m_BufferId = 0;

    m_ComponentCount = std::move(other.m_ComponentCount);
    m_Type = std::move(other.m_Type);

    return *this;
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
}

void VertexBuffer::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
} // namespace Core
