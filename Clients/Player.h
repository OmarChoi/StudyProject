#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	Camera* m_Camera;
	KeyInput m_direction;
public:
	Player();
	~Player();
	virtual void UpdateTransform(double ElapsedTime);
	virtual Camera* getCamera() { return m_Camera; }

	void AddKeyInput(DIRECTION dir) { m_direction.m_keyInput[dir] = true; }
	void RemoveKeyInput(DIRECTION dir) { m_direction.m_keyInput[dir] = false; };
};

