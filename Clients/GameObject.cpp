#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	m_size = 400;
	m_pos.x = 0.0f; m_pos.y = 0.0f;
	m_color.x = 1.0f;
	m_type = CT_NONE;
}

GameObject::GameObject(XMFLOAT2 pos, float size)
{
	m_pos = pos;
	m_size = size;
	m_type = CT_NONE;
}

GameObject::~GameObject()
{
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