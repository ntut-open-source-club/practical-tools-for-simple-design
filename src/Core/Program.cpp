#include "Core/Program.hpp"

#include "Core/Shader.hpp"

#include "Util/Logger.hpp"

namespace Core {
Program::Program(const std::string &vertexShaderFilepath,
                 const std::string &fragmentShaderFilepath) {
    m_ProgramId = glCreateProgram();

    Shader vertex(vertexShaderFilepath, Shader::Type::VERTEX);
    Shader fragment(fragmentShaderFilepath, Shader::Type::FRAGMENT);

    glAttachShader(m_ProgramId, vertex.GetShaderId());
    glAttachShader(m_ProgramId, fragment.GetShaderId());

    glLinkProgram(m_ProgramId);

    CheckStatus();

    glDetachShader(m_ProgramId, vertex.GetShaderId());
    glDetachShader(m_ProgramId, fragment.GetShaderId());
}

Program::Program(Program &&other) {
    m_ProgramId = other.m_ProgramId;
    other.m_ProgramId = 0;
}

Program::~Program() {
    glDeleteProgram(m_ProgramId);
}

Program &Program::operator=(Program &&other) {
    m_ProgramId = other.m_ProgramId;
    other.m_ProgramId = 0;

    return *this;
}

void Program::Bind() const {
    glUseProgram(m_ProgramId);
}

void Program::Unbind() const {
    glUseProgram(0);
}

void Program::Validate() const {
    GLint status = GL_FALSE;

    glValidateProgram(m_ProgramId);
    glGetProgramiv(m_ProgramId, GL_VALIDATE_STATUS, &status);
    if (status != GL_TRUE) {
        int infoLogLength;
        glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> message(infoLogLength + 1);
        glGetProgramInfoLog(m_ProgramId, infoLogLength, nullptr,
                            message.data());

        LOG_ERROR("Validation Failed:");
        LOG_ERROR("{}", message.data());
    }
}

void Program::CheckStatus() const {
    GLint status = GL_FALSE;

    glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &status);
    if (status != GL_TRUE) {
        int infoLogLength;
        glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &infoLogLength);

        std::vector<char> message(infoLogLength + 1);
        glGetProgramInfoLog(m_ProgramId, infoLogLength, nullptr,
                            message.data());

        LOG_ERROR("Failed to Link Program:");
        LOG_ERROR("{}", message.data());
    }
}
} // namespace Core
