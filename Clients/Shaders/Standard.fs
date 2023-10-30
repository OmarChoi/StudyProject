#version 330

layout(location=0) out vec4 FragColor;

in vec2 v_Texcoord;

uniform float u_Time;
uniform sampler2D u_TexSampler;

void main()
{	
	float x =v_Texcoord.x / 11.0;
	float y =v_Texcoord.y / 6.0;
	vec2 newTexPos = vec2(x, y);
	FragColor = texture(u_TexSampler, newTexPos);
}
