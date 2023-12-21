#ifndef CORE_UNIFORM_BUFFER_HPP
#define CORE_UNIFORM_BUFFER_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Core/Program.hpp"

namespace Core {
/**
 * @brief Wrapper for OpenGL Uniform Buffer Object (a.k.a `GL_UNIFORM_BUFFER`)
 *
 * This class uses templates because data is passed in as `void *` in the
 * original C function, using templates would provide more robust type checking
 * and no need for manually entering the type size.
 *
 * @see https://www.khronos.org/opengl/wiki/Uniform_Buffer_Object
 */
template <typename T>
class UniformBuffer {
public:
    UniformBuffer(const Program &program, const std::string &name, int binding);
    UniformBuffer(const UniformBuffer &) = delete;
    UniformBuffer(UniformBuffer &&other);

    ~UniformBuffer();

    UniformBuffer &operator=(const UniformBuffer &) = delete;
    UniformBuffer &operator=(UniformBuffer &&other);

    void SetData(int offset, const T &data);

private:
    GLuint m_Binding;
    GLuint m_BufferId;
};
} // namespace Core

#include "UniformBuffer.inl"

#endif
