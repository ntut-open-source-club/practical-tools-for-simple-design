cmake_minimum_required(VERSION 3.16)
project(PracticalToolsForSimpleDesign)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Dependencies.cmake)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SRC_FILES
    ${SRC_DIR}/main.cpp
)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(INCLUDE_FILES
)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(TEST_FILES
    ${TEST_DIR}/SimpleTest.cpp
    ${TEST_DIR}/NotSimpleTest.cpp
)

add_executable(Sample
    ${SRC_FILES}
)
target_include_directories(Sample SYSTEM PRIVATE
    ${DEPENDENCY_INCLUDE_DIRS}
)
target_include_directories(Sample PRIVATE
    ${CMAKE_SOURCE_DIR}/include
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
)
target_link_libraries(Tests
    GTest::gtest_main
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
