#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
	float windowSize[2]{ g_WindowSizeX * 0.5f, g_WindowSizeY * 0.5f };
	m_ortho = glm::ortho(-windowSize[0], windowSize[0], -windowSize[1], windowSize[1], 0.0001f, 10000.f);
	m_view = glm::lookAt(m_pos, m_look, m_up);
	m_ProjView = m_ortho * m_view;
}

void Camera::UpdateCamera(float x, float y)
{
	m_pos = glm::vec3(x, y, 1000.f);
	m_look = glm::vec3(x, y, 0.f);
	m_up = glm::vec3(0.f, 1.f, 0.f);
	m_view = glm::lookAt(m_pos, m_look, m_up);
	m_ProjView = m_ortho * m_view;
}