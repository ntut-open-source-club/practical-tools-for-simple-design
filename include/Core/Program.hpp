#ifndef CORE_PROGRAM_HPP
#define CORE_PROGRAM_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Core {
/**
 * In OpenGL, programs are objects composed of multiple shaders files compiled
 * and linked together. A typical program would require at least a vertex shader
 * and a fragment shader. However, users could add more optional middle layers
 * such as geometry shaders or tesselation shaders.
 */
class Program {
public:
    Program(const std::string &vertexShaderFilepath,
            const std::string &fragmentShaderFilepath);
    Program(const Program &) = delete;
    Program(Program &&other);

    ~Program();

    Program &operator=(const Program &) = delete;
    Program &operator=(Program &&other);

    GLuint GetId() const { return m_ProgramId; }

    void Bind() const;
    void Unbind() const;

    void Validate() const;

private:
    void CheckStatus() const;

    GLuint m_ProgramId;
};
} // namespace Core
#endif
