cmake_minimum_required(VERSION 3.16)
project(PracticalToolsForSimpleDesign)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Dependencies.cmake)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SRC_FILES
    ${SRC_DIR}/Core/Context.cpp
    ${SRC_DIR}/Core/DebugMessageCallback.cpp
    ${SRC_DIR}/Core/VertexArray.cpp
    ${SRC_DIR}/Core/VertexBuffer.cpp
    ${SRC_DIR}/Core/IndexBuffer.cpp
    ${SRC_DIR}/Core/Shader.cpp
    ${SRC_DIR}/Core/Program.cpp

    ${SRC_DIR}/Util/LoadTextFile.cpp
    ${SRC_DIR}/Util/Logger.cpp
    ${SRC_DIR}/Util/Time.cpp
    ${SRC_DIR}/Util/Input.cpp
    ${SRC_DIR}/Util/SFX.cpp
    ${SRC_DIR}/Util/BGM.cpp

    ${SRC_DIR}/App.cpp
    ${SRC_DIR}/Triangle.cpp
)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
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

    ${INCLUDE_DIR}/Util/LoadTextFile.hpp
    ${INCLUDE_DIR}/Util/Logger.hpp
    ${INCLUDE_DIR}/Util/Time.hpp
    ${INCLUDE_DIR}/Util/Input.hpp
    ${INCLUDE_DIR}/Util/Keycode.hpp
    ${INCLUDE_DIR}/Util/SFX.hpp
    ${INCLUDE_DIR}/Util/BGM.hpp

    ${INCLUDE_DIR}/App.hpp
    ${INCLUDE_DIR}/Triangle.hpp
    ${INCLUDE_DIR}/config.hpp
)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(TEST_FILES
    ${TEST_DIR}/SimpleTest.cpp
    ${TEST_DIR}/NotSimpleTest.cpp
    ${TEST_DIR}/Audio.cpp
)

add_executable(Sample
    ${SRC_FILES}
    ${SRC_DIR}/main.cpp
)
target_link_libraries(Sample
    ${DEPENDENCY_LINK_LIBRARIES}
)
target_include_directories(Sample SYSTEM PRIVATE
    ${DEPENDENCY_INCLUDE_DIRS}
)
target_include_directories(Sample PRIVATE
    ${INCLUDE_DIR}
)
target_precompile_headers(Sample PRIVATE
    include/pch.hpp
)
if (MSVC)
    target_compile_options(Sample PRIVATE
        /W4
    )
else()
    target_compile_options(Sample PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

enable_testing()

add_executable(Tests
    ${TEST_FILES}
    ${SRC_FILES}
)
target_link_libraries(Tests
    GTest::gtest_main
    ${DEPENDENCY_LINK_LIBRARIES}
)
target_include_directories(Tests SYSTEM PRIVATE
    ${DEPENDENCY_INCLUDE_DIRS}
)
target_include_directories(Tests PRIVATE
    ${INCLUDE_DIR}
)
target_include_directories(Tests SYSTEM PRIVATE
    lib/googletest/googletest/include
    lib/googletest/googlemock/include
)
if (MSVC)
    target_compile_options(Tests PRIVATE
        /W4
    )
else()
    target_compile_options(Tests PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

include(GoogleTest)
gtest_discover_tests(Tests)
