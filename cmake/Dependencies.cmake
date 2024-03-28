find_package(OpenGL REQUIRED)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCH_CONTENT_QUIET FALSE)

FetchContent_Declare(
    glew

    URL         https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
    URL_HASH    MD5=970535b75b1b69ebd018a0fa05af63d1
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glew
)

FetchContent_Declare(
    sdl2

    URL         https://github.com/libsdl-org/SDL/releases/download/release-2.26.5/SDL2-2.26.5.zip
    URL_HASH    MD5=0664f3980570c4641128866e6c9f2e29
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sdl2
)

FetchContent_Declare(
    sdl2_image

    URL         https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-2.6.3.zip
    URL_HASH    MD5=ecedb5078bbd31e7d1552e2b1443d2f6
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sdl2_image
)

FetchContent_Declare(
    sdl2_ttf

    URL         https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-2.20.2.zip
    URL_HASH    MD5=7258258fdb2a4adb0072d337f94305f9
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sdl2_ttf
)

FetchContent_Declare( # At this time 1.11.0 has some issues formatting `const unsigned char *`
    spdlog

    URL         https://github.com/gabime/spdlog/archive/refs/tags/v1.10.0.zip
    URL_HASH    MD5=031565384b28f29e44c6e7fb247ad48a
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog
)

FetchContent_Declare(
    glm

    URL         https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip
    URL_HASH    MD5=69895110052f0d711c9c54fbf385f6f5
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glm
)

FetchContent_Declare(
    googletest

    URL         https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
    URL_HASH    MD5=a1279c6fb5bf7d4a5e0d0b2a4adb39ac
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/googletest
)

FetchContent_Declare(
    imgui

    URL         https://github.com/ocornut/imgui/archive/refs/tags/v1.90.4-docking.zip
    URL_HASH    MD5=384084df566474aec3729df4ea30b937
    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui
)

set(BUILD_SHARED_LIBS FALSE)

set(SDL2IMAGE_INSTALL OFF)
set(SDL2IMAGE_VENDORED ON)

set(SDL2TTF_INSTALL OFF)
set(SDL2TTF_VENDORED ON)

set(SDL2MIXER_INSTALL OFF)
set(SDL2MIXER_VENDORED ON)
set(SDL2MIXER_FLAC OFF)
set(SDL2MIXER_MIDI OFF)
set(SDL2MIXER_MOD OFF)
set(SDL2MIXER_OPUS OFF)
set(SDL2MIXER_OGG OFF)
set(SDL2MIXER_VORBIS OFF)
set(SDL2MIXER_VOC OFF)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(sdl2 sdl2_image sdl2_ttf spdlog glm googletest)

add_compile_definitions(GLEW_NO_GLU)

FetchContent_GetProperties(glew)
if (NOT ${glew_POPULATED})
    FetchContent_Populate(glew)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glew/build/cmake)
endif()

FetchContent_GetProperties(imgui)
if (NOT ${imgui_POPULATED})
    FetchContent_Populate(imgui)
    set(IMGUI_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/backends/imgui_impl_sdl2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/backends/imgui_impl_opengl3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/imgui.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/imgui_demo.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/imgui_draw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/imgui_tables.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/imgui_widgets.cpp
    )

    set(IMGUI_INCLUDE_DIR
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/imgui/backends/
        ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sdl2/include/
    )

    add_library(ImGui STATIC
        ${IMGUI_SOURCE}
    )
    target_include_directories(ImGui PUBLIC
        ${IMGUI_INCLUDE_DIR}
    )
endif()

set(DEPENDENCY_LINK_LIBRARIES
    ${OPENGL_LIBRARY}
    glew_s

    SDL2::SDL2-static
    SDL2_image::SDL2_image-static
    SDL2_ttf::SDL2_ttf-static

    spdlog::spdlog

    ImGui
)
set(DEPENDENCY_LINK_LIBRARIES ${DEPENDENCY_LINK_LIBRARIES} PARENT_SCOPE)

set(DEPENDENCY_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/sdl2/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glew/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glm/
)
set(DEPENDENCY_INCLUDE_DIRS ${DEPENDENCY_INCLUDE_DIRS} PARENT_SCOPE)
