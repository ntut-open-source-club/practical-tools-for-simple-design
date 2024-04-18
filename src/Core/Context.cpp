#include "Core/Context.hpp"

#include <memory>

#include "Core/DebugMessageCallback.hpp"

#include "Util/Input.hpp"
#include "Util/Logger.hpp"
#include "Util/Time.hpp"

#include "config.hpp"

using Util::ms_t;

namespace Core {
Context::Context() {
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

    if (Mix_Init(MIX_INIT_MP3) < 0) {
        LOG_ERROR("Failed to initialize SDL_mixer");
        LOG_ERROR(SDL_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        LOG_ERROR("Failed to initialize SDL_mixer");
        LOG_ERROR(SDL_GetError());
    }

    m_Window =
        SDL_CreateWindow(TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH,
                         WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (m_Window == nullptr) {
        LOG_ERROR("Failed to create window");
        LOG_ERROR(SDL_GetError());
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    m_GlContext = SDL_GL_CreateContext(m_Window);

    if (m_GlContext == nullptr) {
        LOG_ERROR("Failed to initialize GL context");
        LOG_ERROR(SDL_GetError());
    }

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        GLuint err = glGetError();
        LOG_ERROR(reinterpret_cast<const char *>(glewGetErrorString(err)));
    }

#ifndef __APPLE__
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(Core::OpenGLDebugMessageCallback, nullptr);
#endif

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    LOG_INFO("OpenGL Info");
    LOG_INFO("  Vendor: {}", glGetString(GL_VENDOR));
    LOG_INFO("  Renderer: {}", glGetString(GL_RENDERER));
    LOG_INFO("  Version: {}", glGetString(GL_VERSION));
    LOG_INFO("  GLSL Version: {}", glGetString(GL_SHADING_LANGUAGE_VERSION));

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GlContext);
    ImGui_ImplOpenGL3_Init();
}
std::shared_ptr<Context> Context::s_Instance(nullptr);

Context::~Context() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyWindow(m_Window);
    SDL_GL_DeleteContext(m_GlContext);
    SDL_VideoQuit();
    Mix_HaltGroup(-1);
    Mix_CloseAudio();

    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void Context::Setup() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void Context::Update() {
    Util::Input::Update();
    SDL_GL_SwapWindow(m_Window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    constexpr ms_t frameTime = FPS_CAP != 0 ? 1000.0F / FPS_CAP : 0;
    ms_t afterUpdate = Util::Time::GetElapsedTimeMs();
    ms_t updateTime = afterUpdate - m_BeforeUpdateTime;
    if (updateTime < frameTime) {
        SDL_Delay(static_cast<Uint32>(frameTime - updateTime));
    }
    m_BeforeUpdateTime = Util::Time::GetElapsedTimeMs();

    // Here's a figure explaining how Delta time & Delay work:
    //
    // --|--UT--|--Delay--|--UT--|--
    //   |---Delta time---|  ^ Last delta time used here
    //   ^                ^
    //   (s_Last)         (s_Now) Time::Update here
    //
    // # Updating/rendering time is denoted as "UT"
    Util::Time::Update();

#ifdef DEBUG_DELTA_TIME
    auto deltaTime = Util::Time::GetDeltaTimeMs();
    LOG_DEBUG("Delta(Update+Delay): {:.1f}({:.1f}+{:.1f}) ms, FPS: {:.1f}",
              deltaTime, updateTime,
              updateTime < frameTime ? frameTime - updateTime : 0,
              1000.0f / deltaTime);
#endif // DEBUG_DELTA_TIME
}

std::shared_ptr<Context> Context::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance = std::make_shared<Context>();
    }
    return s_Instance;
}

void Context::SetWindowIcon(const std::string &path) {
    SDL_Surface *image = IMG_Load(path.c_str());
    SDL_SetWindowIcon(m_Window, image);
}
} // namespace Core
