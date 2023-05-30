#version 410 core

layout(location = 0) in vec2 uv;

layout(location = 0) out vec4 fragColor;

void main() {
    fragColor = vec4(uv.x, uv.y, 0.0, 1.0);
}
