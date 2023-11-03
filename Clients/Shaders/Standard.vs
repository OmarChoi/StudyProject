#version 330

layout(location = 0) in vec3 a_DefaultPos;
layout(location = 1) in vec2 a_TexCoord;

uniform vec2 u_ObjectPos;
uniform float u_Time;
uniform float u_Size;

uniform mat4 u_Projection;

out vec2 v_Texcoord;

void main()
{   
	vec4 newPosition;
	newPosition.xyz = a_DefaultPos.xyz * u_Size;
	newPosition.w = 1.0f;
	newPosition.xy += u_ObjectPos.xy;
	gl_Position = u_Projection * newPosition;
    v_Texcoord = a_TexCoord + vec2(0.5);
}