#version 330

in vec3 a_DefaultPos;
in vec2 a_TexCoord;

uniform vec2 u_ObjectPos;
uniform float u_Time;
uniform float u_Size;


out vec2 v_Texcoord;

void main()
{
	vec4 newPosition;
	newPosition.xy = a_DefaultPos.xy * u_Size;
	newPosition.xy += u_ObjectPos;
	newPosition.z = 0.0f; newPosition.w = 1.0f;

	gl_Position = newPosition;
	v_Texcoord = a_TexCoord;
}
