#ifndef CORE_SHADER_HPP
#define CORE_SHADER_HPP

#include <string>

#include <GL/glew.h>

namespace Core {
class Shader {
public:
    enum class Type {
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER,
    };

    Shader(const std::string &filepath, Type shaderType);
    Shader(const Shader &) = delete;

    ~Shader();

    Shader &operator=(const Shader &) = delete;

    GLuint GetShaderId() const { return m_ShaderId; }

private:
    void Compile(const std::string &src) const;
    void CheckStatus(const std::string &filepath) const;

private:
    GLuint m_ShaderId;
};
} // namespace Core

#endif
