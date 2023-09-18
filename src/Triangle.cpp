#include "Triangle.hpp"

#include "Core/IndexBuffer.hpp"
#include "Core/VertexBuffer.hpp"

#include "Util/Time.hpp"

Triangle::Triangle() {
    std::vector<float> vertex({
        -300.0F, -300.0F, // NOLINT
        300.0F, -300.0F,  // NOLINT
        0, 300.0F,        // NOLINT
    });
    std::vector<float> color({
        1.0F, 0.0F, 0.0F, //
        0.0F, 1.0F, 0.0F, //
        0.0F, 0.0F, 1.0F, //
    });
    std::vector<unsigned int> index({
        0, 1, 2 //
    });

    m_VertexArray->AddVertexBuffer(
        std::make_unique<Core::VertexBuffer>(vertex, 2));

    m_VertexArray->AddVertexBuffer(
        std::make_unique<Core::VertexBuffer>(color, 3));

    m_VertexArray->SetIndexBuffer(std::make_unique<Core::IndexBuffer>(index));
}

void Triangle::Update() {
    m_Program.Bind();
    m_Program.Validate();

    static float counter = 0.0F;
    counter += static_cast<float>(50.0F * Util::Time::GetDeltaTime()); // NOLINT
    const float angle = glm::radians(counter);

    const float width = 1280.0F / 2.0F;
    const float height = 720.0F / 2.0F;

    Matrices data = {
        {
            glm::cos(angle), -glm::sin(angle), //
            glm::sin(angle), glm::cos(angle)   //
        },
        {
            1.0F / width, 0.0F, //
            0.0F, 1.0F / height //
        },
    };

    m_Matrices->SetData(0, data);

    m_VertexArray->Bind();
    m_VertexArray->DrawTriangles();
}
