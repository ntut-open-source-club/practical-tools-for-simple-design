#version 410 core

layout(location = 0) in vec2 vertPosition;
layout(location = 1) in vec2 vertUv;

layout(location = 0) out vec2 uv;

/**
 * C++ and GLSL maps `mat2` differently because weird padding issues
 * https://www.khronos.org/opengl/wiki/Layout_Qualifier_(GLSL)#Interface_components
 *
 * Sample code: `mat2 m = {a, b, c, d};`
 *
 * C++:
 * | a | b | c | d |
 *
 * GLSL:
 * | a | b |   |   |
 * | c | d |   |   |
 */
layout(std140) uniform Matrices {
    mat4 model;
    mat4 projection;
};

void main() {
    vec4 pos = projection * model * vec4(vertPosition, 0, 1);

    gl_Position = vec4(pos.x, pos.y, 0, 1);

    uv = vertUv;
}
