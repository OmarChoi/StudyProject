#version 330

in vec3 a_Position;
uniform vec2 u_Transform;
uniform float u_Size;

void main()
{
	vec4 newPosition;
	newPosition.xy = a_Position.xy * u_Size;
	newPosition.xy += u_Transform;
	newPosition.z = 0;
	newPosition.w= 1;
	gl_Position = newPosition;
}
