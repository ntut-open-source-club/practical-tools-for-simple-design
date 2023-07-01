#include "Core/Shader.hpp"

#include "Util/LoadTextFile.hpp"
#include "Util/Logger.hpp"

namespace Core {
Shader::Shader(const std::string &filepath, Type shaderType) {
    m_ShaderId = glCreateShader(static_cast<GLenum>(shaderType));

    Compile(Util::LoadTextFile(filepath));
    CheckStatus(filepath);
}

Shader::Shader(Shader &&other) {
    m_ShaderId = other.m_ShaderId;
    other.m_ShaderId = 0;
}

Shader::~Shader() {
    glDeleteShader(m_ShaderId);
}

Shader &Shader::operator=(Shader &&other) {
    m_ShaderId = other.m_ShaderId;
    other.m_ShaderId = 0;

    return *this;
}

void Shader::Compile(const std::string &src) const {
    const char *srcPtr = src.c_str();

    glShaderSource(m_ShaderId, 1, &srcPtr, nullptr);
    glCompileShader(m_ShaderId);
}

void Shader::CheckStatus(const std::string &filepath) const {
    GLint status = GL_FALSE;

    glGetShaderiv(m_ShaderId, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE) {
        int infoLogLength;
        glGetShaderiv(m_ShaderId, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> message(infoLogLength + 1);
        glGetShaderInfoLog(m_ShaderId, infoLogLength, nullptr, message.data());

        LOG_ERROR("Failed to Compile Shader: '{}'");
        LOG_ERROR("{}", filepath, message.data());
    }
}
} // namespace Core
