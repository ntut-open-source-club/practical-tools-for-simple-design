#ifndef CORE_VERTEX_ARRAY_HPP
#define CORE_VERTEX_ARRAY_HPP

#include <GL/glew.h>

#include "Core/IndexBuffer.hpp"
#include "Core/VertexBuffer.hpp"

namespace Core {
class VertexArray {
public:
    VertexArray(std::initializer_list<VertexBuffer> vertexBuffers,
                IndexBuffer &&indexBuffer);
    VertexArray(const VertexArray &) = delete;

    ~VertexArray();

    VertexArray &operator=(const VertexArray &) = delete;

    void Bind() const;
    void Unbind() const;

    void DrawTriangles() const;

private:
    GLuint m_ArrayId;

    IndexBuffer &m_IndexBuffer;
};
} // namespace Core
#endif
