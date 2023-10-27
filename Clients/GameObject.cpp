#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	m_size = 40;
	m_pos.x = 0; m_pos.y = 0;
	m_color.x = 1.0f;
}

GameObject::GameObject(XMFLOAT2 pos, float size)
{
	m_pos = pos;
	m_size = size;
}

GameObject::~GameObject()
{
}

XMFLOAT2 GameObject::GetPos()
{
	return m_pos;
}

float GameObject::GetSize()
{
	return m_size;
}

void SquareObject::BuildObject()
{
	float rect[]
		=
	{
		-1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f,
		-1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f, 
		1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f,

		-1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f, 
		1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f, 
		1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f,
	};

	glGenBuffers(1, &m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rect), rect, GL_STATIC_DRAW);
}

void SquareObject::UpdateTransform()
{
}

SquareObject::SquareObject()
{
	m_size = 40;
	m_pos.x = 0; m_pos.y = 0;
	m_color.x = 1.0f;
}

void GetGLPosition(float x, float y, float* newX, float* newY)
{
}

void SquareObject::Render(GLuint ShaderIndex)
{

	glUseProgram(ShaderIndex);

	glUniform1f(glGetUniformLocation(ShaderIndex, "u_Size"), m_size);
	glUniform4f(glGetUniformLocation(ShaderIndex, "u_Color"),
		m_color.x, m_color.y, m_color.z, m_color.a);
	glUniform2f(glGetUniformLocation(ShaderIndex, "u_Transform"), m_pos.x / g_WindowSizeX, m_pos.y / g_WindowSizeX);

	int attribPosition = glGetAttribLocation(ShaderIndex, "a_Position");
	glEnableVertexAttribArray(attribPosition);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(attribPosition);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}