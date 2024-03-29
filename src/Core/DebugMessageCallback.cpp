#include "Core/DebugMessageCallback.hpp"

#include "Util/Logger.hpp"

namespace Core {
void GLAPIENTRY OpenGLDebugMessageCallback(GLenum source, GLenum type,
                                           GLuint id, // NOLINT
                                           GLenum severity, GLsizei length,
                                           const GLchar *message,
                                           const void *data) {
    std::string sourceString;
    std::string typeString;
    std::string severityString;

    // clang-format off
    switch (source) {
    case GL_DEBUG_SOURCE_API:               sourceString = "API";               break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:     sourceString = "WINDOW SYSTEM";     break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:   sourceString = "SHADER COMPILER";   break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:       sourceString = "THIRD PARTY";       break;
    case GL_DEBUG_SOURCE_APPLICATION:       sourceString = "APPLICATION";       break;
    default:                                sourceString = "UNKNOWN";           break;
    }

    switch (type) {
    case GL_DEBUG_TYPE_ERROR:               typeString = "ERROR";               break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: typeString = "DEPRECATED BEHAVIOR"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  typeString = "UNDEFINED BEHAVIOR";  break;
    case GL_DEBUG_TYPE_PORTABILITY:         typeString = "PORTABILITY";         break;
    case GL_DEBUG_TYPE_PERFORMANCE:         typeString = "PERFORMANCE";         break;
    case GL_DEBUG_TYPE_OTHER:               typeString = "OTHER";               break;
    case GL_DEBUG_TYPE_MARKER:              typeString = "MARKER";              break;
    default:                                typeString = "UNKNOWN";             break;
    }

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:            severityString = "HIGH";            break;
    case GL_DEBUG_SEVERITY_MEDIUM:          severityString = "MEDIUM";          break;
    case GL_DEBUG_SEVERITY_LOW:             severityString = "LOW";             break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:    severityString = "NOTIFICATION";    break;
    default:                                severityString = "UNKNOWN";         break;
    }
    // clang-format on

    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:
        LOG_ERROR("OpenGL Severity: {}", severityString);
        LOG_ERROR(" ID: {}", id);
        LOG_ERROR(" Source: {}", sourceString);
        LOG_ERROR(" Type: {}", typeString);
        LOG_ERROR(" Message: {}", message);
        break;

    case GL_DEBUG_SEVERITY_MEDIUM:
        LOG_WARN("OpenGL Severity: {}", severityString);
        LOG_WARN(" ID: {}", id);
        LOG_WARN(" Source: {}", sourceString);
        LOG_WARN(" Type: {}", typeString);
        LOG_WARN(" Message: {}", message);
        break;

    case GL_DEBUG_SEVERITY_LOW:
        LOG_INFO("OpenGL Severity {}", severityString);
        LOG_INFO(" ID: {}", id);
        LOG_INFO(" Source: {}", sourceString);
        LOG_INFO(" Type: {}", typeString);
        LOG_INFO(" Message: {}", message);
        break;

    case GL_DEBUG_SEVERITY_NOTIFICATION:
        // LOG_DEBUG("OpenGL Severity {}", severityString);
        // LOG_DEBUG(" ID: {}", id);
        // LOG_DEBUG(" Source: {}", sourceString);
        // LOG_DEBUG(" Type: {}", typeString);
        // LOG_DEBUG(" Message: {}", message);
        break;

    default:
        LOG_DEBUG("OpenGL Severity Unknown");
        LOG_DEBUG(" ID: {}", id);
        LOG_DEBUG(" Source: {}", sourceString);
        LOG_DEBUG(" Type: {}", typeString);
        LOG_DEBUG(" Message: {}", message);
        break;
    }

    // unused variable, this is for silencing warnings
    (void)length;
    (void)data;
}
} // namespace Core
