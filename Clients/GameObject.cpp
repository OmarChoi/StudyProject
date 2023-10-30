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

void SquareObject::UpdateTransform()
{
}

SquareObject::SquareObject()
{
	m_size = 400;
	m_pos.x = 0; m_pos.y = 0;
	m_color.x = 1.0f;
}

ObjectData SquareObject::GetObjectData()
{
	ObjectData objData;
	objData.m_pos = m_pos;
	objData.m_color = m_color;
	objData.m_size = m_size;
	objData.m_type = CT_NONE;
	return objData;
}

void GetGLPosition(float x, float y, float* newX, float* newY)
{
}
