cmake_minimum_required(VERSION 3.16)
project(PracticalToolsForSimpleDesign)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Sample
    src/main.cpp
)
target_include_directories(Sample PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
target_compile_options(Sample PRIVATE
    -Wall -pedantic
)
