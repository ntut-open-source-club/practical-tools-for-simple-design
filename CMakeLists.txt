cmake_minimum_required(VERSION 3.16)
project(PracticalToolsForSimpleDesign)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    set(TARGET_COMPILE_OPTIONS
        /W4
    )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build)
else()
    set(TARGET_COMPILE_OPTIONS
        -Wall -Wextra -pedantic
    )
endif()

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # see https://github.com/ntut-open-source-club/practical-tools-for-simple-design/issues/22
    set(CMAKE_RC_FLAGS="-C 1252")
endif()

option(PTSD_ENABLE_PCH "Turn on PCH to increase compilation speed" OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_FILES
    ${SRC_DIR}/Core/Context.cpp
    ${SRC_DIR}/Core/DebugMessageCallback.cpp
    ${SRC_DIR}/Core/VertexArray.cpp
    ${SRC_DIR}/Core/VertexBuffer.cpp
    ${SRC_DIR}/Core/IndexBuffer.cpp
    ${SRC_DIR}/Core/Shader.cpp
    ${SRC_DIR}/Core/Program.cpp
    ${SRC_DIR}/Core/Texture.cpp
    ${SRC_DIR}/Core/TextureUtils.cpp

    ${SRC_DIR}/Util/LoadTextFile.cpp
    ${SRC_DIR}/Util/Logger.cpp
    ${SRC_DIR}/Util/Time.cpp
    ${SRC_DIR}/Util/Input.cpp
    # ${SRC_DIR}/Util/SFX.cpp
    # ${SRC_DIR}/Util/BGM.cpp
    ${SRC_DIR}/Util/Image.cpp
    ${SRC_DIR}/Util/Text.cpp
    ${SRC_DIR}/Util/TransformUtils.cpp
    ${SRC_DIR}/Util/GameObject.cpp
    ${SRC_DIR}/Util/Renderer.cpp
    ${SRC_DIR}/Util/Color.cpp
    ${SRC_DIR}/Util/Animation.cpp
    ${SRC_DIR}/Util/MissingTexture.cpp

    ${SRC_DIR}/Util/Root.cpp
    ${SRC_DIR}/Util/SpriteSheet.cpp
)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(INCLUDE_FILES
    ${INCLUDE_DIR}/Core/Context.hpp
    ${INCLUDE_DIR}/Core/DebugMessageCallback.hpp
    ${INCLUDE_DIR}/Core/VertexArray.hpp
    ${INCLUDE_DIR}/Core/VertexBuffer.hpp
    ${INCLUDE_DIR}/Core/UniformBuffer.hpp
    ${INCLUDE_DIR}/Core/UniformBuffer.inl
    ${INCLUDE_DIR}/Core/IndexBuffer.hpp
    ${INCLUDE_DIR}/Core/Shader.hpp
    ${INCLUDE_DIR}/Core/Program.hpp
    ${INCLUDE_DIR}/Core/Texture.hpp
    ${INCLUDE_DIR}/Core/TextureUtils.hpp
    ${INCLUDE_DIR}/Core/Drawable.hpp

    ${INCLUDE_DIR}/Util/LoadTextFile.hpp
    ${INCLUDE_DIR}/Util/Logger.hpp
    ${INCLUDE_DIR}/Util/Time.hpp
    ${INCLUDE_DIR}/Util/Input.hpp
    ${INCLUDE_DIR}/Util/Keycode.hpp
    # ${INCLUDE_DIR}/Util/SFX.hpp
    # ${INCLUDE_DIR}/Util/BGM.hpp
    ${INCLUDE_DIR}/Util/Image.hpp
    ${INCLUDE_DIR}/Util/Text.hpp
    ${INCLUDE_DIR}/Util/Transform.hpp
    ${INCLUDE_DIR}/Util/TransformUtils.hpp
    ${INCLUDE_DIR}/Util/GameObject.hpp
    ${INCLUDE_DIR}/Util/Renderer.hpp
    ${INCLUDE_DIR}/Util/Color.hpp
    ${INCLUDE_DIR}/Util/TransparentImage.hpp
    ${INCLUDE_DIR}/Util/Base64.hpp
    ${INCLUDE_DIR}/Util/Animation.hpp

    ${INCLUDE_DIR}/Util/AssetStore.hpp
    ${INCLUDE_DIR}/Util/AssetStore.inl
    ${INCLUDE_DIR}/Util/Root.hpp
    ${INCLUDE_DIR}/Util/MissingTexture.hpp
    ${INCLUDE_DIR}/Util/SpriteSheet.hpp
    
    ${INCLUDE_DIR}/config.hpp
)

add_library(${PROJECT_NAME}
    ${SRC_FILES}
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        PTSD_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
    )
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        PTSD_DIR=".."
    )
else ()
    message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
    ${DEPENDENCY_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main # IDK what happens if we don't link SDL2main
    ${DEPENDENCY_LINK_LIBRARIES}
)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
    ${DEPENDENCY_INCLUDE_DIRS}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDE_DIR}
)
if(${PTSD_ENABLE_PCH})
    target_precompile_headers(${PROJECT_NAME} PRIVATE
        include/pch.hpp
    )
endif()
target_compile_options(${PROJECT_NAME} PRIVATE
    ${TARGET_COMPILE_OPTIONS}
)