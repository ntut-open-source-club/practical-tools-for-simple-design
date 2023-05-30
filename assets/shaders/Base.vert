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
    vec4 _model;
    vec4 _projection;
};

void main() {
    mat2 model = mat2(_model);
    mat2 projection = mat2(_projection);

    vec2 pos = vertPosition * model * projection;

    gl_Position = vec4(pos.x, pos.y, 0, 1);

    uv = vertUv;
}
