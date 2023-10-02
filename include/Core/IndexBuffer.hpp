#ifndef CORE_INDEX_BUFFER_HPP
#define CORE_INDEX_BUFFER_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Core {
/**
 * @brief Wrapper for OpenGL Index Buffer Object (a.k.a
 * `GL_ELEMENT_ARRAY_BUFFER`)
 */
class IndexBuffer {
public:
    explicit IndexBuffer(const std::vector<unsigned int> &indices);
    IndexBuffer(const IndexBuffer &) = delete;
    IndexBuffer(IndexBuffer &&other);

    ~IndexBuffer();

    IndexBuffer &operator=(const IndexBuffer &) = delete;
    IndexBuffer &operator=(IndexBuffer &&other);

    size_t GetCount() const { return m_Count; }

    void Bind() const;
    void Unbind() const;

private:
    GLuint m_BufferId;

    size_t m_Count;
};
} // namespace Core

#endif
