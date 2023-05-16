#version 410 core

layout(location = 0) in vec2 vertexPos;
layout(location = 1) in vec3 color;

layout(location = 0) out vec3 vertexColor;

// C++ and GLSL maps `mat2` because fuck you
layout(std140) uniform Matrices {
    vec4 _model;
    vec4 _projection;
};

void main() {
    mat2 model = mat2(_model);
    mat2 projection = mat2(_projection);

    vec2 pos = vertexPos * model * projection;

    gl_Position = vec4(pos.x, pos.y, 0, 1);
    vertexColor = color;
}
