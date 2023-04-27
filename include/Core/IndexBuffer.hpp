#ifndef CORE_INDEX_BUFFER_HPP
#define CORE_INDEX_BUFFER_HPP

#include <vector>

#include <GL/glew.h>

namespace Core {
class IndexBuffer {
public:
    IndexBuffer(const std::vector<float> &indices);
    IndexBuffer(const IndexBuffer &) = delete;

    ~IndexBuffer();

    IndexBuffer &operator=(const IndexBuffer &) = delete;

    unsigned int GetCount() const { return m_Count; }

    void Bind() const;
    void Unbind() const;

private:
    GLuint m_BufferId;

    unsigned int m_Count;
};
} // namespace Core

#endif
