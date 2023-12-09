#version 400 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec4 clr;
layout (location = 2) in vec2 tex;

uniform mat4 model;
uniform mat4 projection;
uniform float Z;

out vec4 color;
out vec2 coord;

void main()
{
    gl_Position = (projection * model) * vec4(aPos.x, aPos.y, Z, 1.0);
    color = clr;
    coord = tex;
}