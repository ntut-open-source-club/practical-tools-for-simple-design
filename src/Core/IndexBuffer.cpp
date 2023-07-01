#include "Core/IndexBuffer.hpp"

namespace Core {
IndexBuffer::IndexBuffer(const std::vector<unsigned int> &indices)
    : m_Count(indices.size()) {
    glGenBuffers(1, &m_BufferId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 static_cast<GLsizeiptr>(indices.size() * sizeof(GLuint)),
                 indices.data(), GL_STATIC_DRAW);
}

IndexBuffer::IndexBuffer(IndexBuffer &&other) {
    m_BufferId = other.m_BufferId;
    other.m_BufferId = 0;

    m_Count = std::move(other.m_Count);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_BufferId);
}

IndexBuffer &IndexBuffer::operator=(IndexBuffer &&other) {
    m_BufferId = other.m_BufferId;
    other.m_BufferId = 0;

    m_Count = std::move(other.m_Count);

    return *this;
}

void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
}

void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
} // namespace Core
