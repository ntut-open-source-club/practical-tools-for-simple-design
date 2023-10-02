#version 410 core

layout(location = 0) in vec2 uv;

layout(location = 0) out vec4 fragColor;

uniform sampler2D surface;

void main() {
    fragColor = texture(surface, uv);
}
