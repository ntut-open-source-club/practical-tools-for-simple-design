#include "Core/Context.hpp"

#include <SDL_events.h>
#include <SDL_video.h>
#include <iostream>

#include <GL/glew.h>

#include <SDL_image.h>
#include <SDL_ttf.h>

#include <SDL_opengl.h>

#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/PTSDScancode.hpp"
#include "Util/Time.hpp"

#include "config.hpp"

namespace Core {
void Context::Init() {
    Util::Logger::Init();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        LOG_ERROR("Failed to initialize SDL");
        LOG_ERROR(SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0) {
        LOG_ERROR("Failed to initialize SDL_image");
        LOG_ERROR(SDL_GetError());
    }

    if (TTF_Init() < 0) {
        LOG_ERROR("Failed to initialize SDL_ttf");
        LOG_ERROR(SDL_GetError());
    }

    s_Window =
        SDL_CreateWindow(TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH,
                         WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (s_Window == nullptr) {
        LOG_ERROR("Failed to create window");
        LOG_ERROR(SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    s_GlContext = SDL_GL_CreateContext(s_Window);

    if (s_GlContext == nullptr) {
        LOG_ERROR("Failed to initialize GL context");
        LOG_ERROR(SDL_GetError());
    }

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        GLuint err = glGetError();
        LOG_ERROR(reinterpret_cast<const char *>(glewGetErrorString(err)));
    }

    LOG_INFO("OpenGL Info");
    LOG_INFO("  Vendor: {}", glGetString(GL_VENDOR));
    LOG_INFO("  Renderer: {}", glGetString(GL_RENDERER));
    LOG_INFO("  Version: {}", glGetString(GL_VERSION));
    LOG_INFO("  GLSL Version: {}", glGetString(GL_SHADING_LANGUAGE_VERSION));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void Context::Quit() {
    SDL_DestroyWindow(s_Window);
    SDL_GL_DeleteContext(s_GlContext);
    SDL_VideoQuit();

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Context::Update() {
    Util::Time::Update();
    SDL_GL_SwapWindow(s_Window);
}

 SDL_Window* Context::s_Window = nullptr;
 SDL_GLContext Context::s_GlContext = nullptr;
 bool Context::s_Exit = false;

} // namespace Core
