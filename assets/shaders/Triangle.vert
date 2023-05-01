#version 410 core

layout(location = 0) in vec2 vertexPos;
layout(location = 1) in vec3 color;

layout(location = 0) out vec3 vertexColor;

void main() {
    gl_Position = vec4(vertexPos.x, vertexPos.y, 0, 1);
    vertexColor = color;
}