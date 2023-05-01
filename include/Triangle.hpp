#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <memory>

#include "Core/Program.hpp"
#include "Core/VertexArray.hpp"

class Triangle {
public:
    Triangle();

    void Update();

private:
    Core::Program m_Program;
    std::unique_ptr<Core::VertexArray> m_VertexArray;
};

#endif
