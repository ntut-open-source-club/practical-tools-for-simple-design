#ifndef CORE_DRAWABLE_HPP
#define CORE_DRAWABLE_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Core/Program.hpp"
#include "Core/UniformBuffer.hpp"
#include "Core/VertexArray.hpp"

namespace Core {
struct Matrices {
    glm::mat2 m_Model;
    glm::mat2 m_Projection;
};

class Drawable {
public:
    Drawable(glm::mat3 transform);

    void Draw();

private:
    void InitProgram();
    void InitVertexArray();
    void InitUniformBuffer();

    static std::unique_ptr<Program> s_Program;
    static std::unique_ptr<VertexArray> s_VertexArray;
    static std::unique_ptr<UniformBuffer<Matrices>> s_UniformBuffer;

    glm::mat3 m_Transform;
};
} // namespace Core

#endif
