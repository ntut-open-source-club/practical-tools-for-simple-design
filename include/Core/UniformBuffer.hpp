#ifndef CORE_UNIFORM_BUFFER_HPP
#define CORE_UNIFORM_BUFFER_HPP

#include <memory>
#include <string>

#include <GL/glew.h>

#include "Core/Program.hpp"

namespace Core {
template <typename T>
class UniformBuffer {
public:
    UniformBuffer(const Program &program, const std::string &name, int binding);
    UniformBuffer(const UniformBuffer &) = delete;

    ~UniformBuffer();

    UniformBuffer &operator=(const UniformBuffer &) = delete;

    void SetData(int offset, const T &data);

private:
    GLuint m_BufferId;
};
} // namespace Core

#include "UniformBuffer.inl"

#endif
