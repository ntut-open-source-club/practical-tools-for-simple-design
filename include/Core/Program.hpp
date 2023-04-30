#ifndef CORE_PROGRAM_HPP
#define CORE_PROGRAM_HPP

#include <string>

#include <GL/glew.h>

namespace Core {
class Program {
public:
    Program(const std::string &vertexShaderFilepath,
            const std::string &fragmentShaderFilepath);
    Program(const Program &) = delete;

    ~Program();

    Program &operator=(const Program &) = delete;

    void Bind() const;
    void Unbind() const;

    void Validate() const;

private:
    void CheckStatus() const;

private:
    GLuint m_ProgramId;
};
} // namespace Core
#endif
