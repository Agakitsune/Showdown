#version 400 core

in vec4 color;
in vec2 coord;

uniform sampler2D Texture;

out vec4 FragColor;

void main()
{
    FragColor = texture(Texture, coord);
}