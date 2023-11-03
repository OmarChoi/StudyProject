#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	m_size = 400;
	m_pos.x = 0.0f; m_pos.y = 0.0f;
	m_color.x = 1.0f;
	m_type = CT_WARRIOR;
}

GameObject::GameObject(XMFLOAT2 pos, float size)
{
	m_pos = pos;
	m_size = size;
	m_type = CT_WARRIOR;
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

void SquareObject::UpdateTransform()
{
	if (m_pos.x != m_camera->m_pos.x)
		cout << m_pos.x << ", " << m_pos.y << endl;
	m_camera->UpdateCamera(m_pos.x, m_pos.y);
}

SquareObject::SquareObject()
{
	m_size = 40;
	m_type = CT_NONE;
	m_pos.x = 0.0f; 0.0f;
	m_color.x = 1.0f;
	m_camera = new Camera();
}

ObjectData GameObject::GetObjectData()
{
	ObjectData objData;
	objData.m_pos = m_pos;
	objData.m_color = m_color;
	objData.m_size = m_size;
	objData.m_type = m_type;
	return objData;
}

void GetGLPosition(float x, float y, float* newX, float* newY)
{
}
