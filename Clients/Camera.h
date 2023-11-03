#pragma once

class Camera {
public:
	glm::vec3 m_pos{ 0.0f, 0.0f, 1000.0f };
	glm::vec3 m_look{ 0.0f, 0.0f, 0.0f };
	glm::vec3 m_up{ 0.0f, 1.0f, 0.0f };
	glm::mat4 m_view;
	glm::mat4 m_ortho;
	glm::mat4 m_ProjView;
public:
	Camera();
	void UpdateCamera(float x, float y);
};
