#pragma once
#include "GameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

private:
	vector<GameObject*> m_objects;

};

