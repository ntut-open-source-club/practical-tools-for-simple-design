#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <memory>

#include <glm/glm.hpp>

#include "Core/Program.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"

struct Matrices {
    glm::mat2 m_Model;
    glm::mat2 m_Projection;
};

class Triangle {
public:
    Triangle();

    ~Triangle() = default;

    void Update();

private:
    Core::Program m_Program;
    std::unique_ptr<Core::VertexArray> m_VertexArray;

    std::unique_ptr<Core::UniformBuffer<Matrices>> m_Matrices;
};

#endif
