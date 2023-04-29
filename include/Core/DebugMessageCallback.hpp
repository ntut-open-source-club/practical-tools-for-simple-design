#ifndef CORE_DEBUG_MESSAGE_CALLBACK_HPP
#define CORE_DEBUG_MESSAGE_CALLBACK_HPP

#include <GL/glew.h>

namespace Core {
/**
 * @brief Callback function for OpenGL handling
 *
 * This function is called by OpenGL and if users want to use it they should do
 * so via `glDebugMessageInsert()` and not call it directly
 *
 * @see https://www.khronos.org/opengl/wiki/Debug_Output
 */
void OpenGLDebugMessageCallback(GLenum source, GLenum type, GLuint id, // NOLINT
                                GLenum severity, GLsizei length,
                                const GLchar *message, const void *data);
} // namespace Core

#endif
