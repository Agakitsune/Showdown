#version 400 core

in vec3 color;
in vec2 coord;

uniform sampler2D Texture;

out vec4 FragColor;

void main()
{
    FragColor = mix(vec4(color, 1.0), texture(Texture, coord), 0.5);
}