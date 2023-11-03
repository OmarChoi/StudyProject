#version 330 core

in vec2 v_Texcoord;
out vec4 FragColor;

uniform sampler2D u_TexSampler;

void main()
{
    vec4 texColor = texture(u_TexSampler, v_Texcoord);
    FragColor = texColor;
}