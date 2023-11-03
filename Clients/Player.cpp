#include "stdafx.h"
#include "Camera.h"
#include "Player.h"

Player::Player()
{
	m_size = 40000;
	m_speed = 10.0f;
	m_type = CT_WARRIOR;
	m_pos.x = 0.0f; 0.0f;
	m_color.x = 1.0f;
	m_Camera = new Camera();
}

Player::~Player()
{
	if (m_Camera)
		delete m_Camera;
}

void Player::UpdateTransform(double ElapsedTime)
{
	double moveDist = m_speed * ElapsedTime;
	array<float, 4> deltaX{ -moveDist, 0, moveDist, 0 };
	array<float, 4> deltaY{ 0, moveDist, 0, -moveDist };
	for (int i = 0; i < 4; ++i) {
		if (m_direction.m_keyInput[i] == true) {
			m_pos.x += deltaX[i];
			m_pos.y += deltaY[i];
		}
	}

	if(m_Camera)
		m_Camera->UpdateCamera(m_pos.x, m_pos.y);
}
