#pragma once
#include "GameObject.h"

class MovingObject
{
private:
	float m_hp;
	float m_damage;
	float m_speed;
	float m_range;

public:
	MovingObject();
	~MovingObject();

	virtual void Attack() {};
	virtual void Move() {};
	virtual void UseSkill() {};
};

