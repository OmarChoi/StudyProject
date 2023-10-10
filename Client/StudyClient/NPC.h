#pragma once
#include "MovingObject.h"

class NPC : public MovingObject
{
private:
	NPC_TYPE m_npcType;
	// float m_agroRange; 서버에 들어갈 변수
public:
	NPC();
	~NPC();

public:
	virtual void Attack();
	virtual void Move();
	virtual void UseSkill();
	virtual void Render();

};

