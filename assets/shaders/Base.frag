#version 410 core

layout(location = 0) in vec2 uv;

layout(location = 0) out vec4 fragColor;

uniform sampler2D surface;

void main() {
    vec4 texColor = texture(surface, uv);

    if (texColor.a < 0.01)
        discard;

    fragColor = texColor;
}
