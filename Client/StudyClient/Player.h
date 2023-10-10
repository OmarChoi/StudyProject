#pragma once
#include "MovingObject.h"

class Player : public MovingObject
{
private:
	CHARACTER_TYPE m_characterType;

public:
	Player();
	~Player();

public:
	virtual void Attack();
	virtual void Move();
	virtual void UseSkill();
	virtual void Render();

};

