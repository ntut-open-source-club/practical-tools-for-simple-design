#version 410 core

layout(location = 0) in vec2 vertPosition;
layout(location = 1) in vec2 vertUv;

layout(location = 0) out vec2 uv;

layout(std140) uniform Matrices {
    mat4 model;
    mat4 viewProjection;
};

void main() {
    // Reference from
    // https://github.com/NOOBDY/Indigo/blob/f31c7ef82c610d8e91214892a7a1e3f860ba4aaa/assets/shaders/base_pass.vert#L21-L22
    gl_Position = viewProjection * model * vec4(vertPosition, 0, 1);

    uv = vertUv;
}
