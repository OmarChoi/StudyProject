#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto& obj : m_objects)
	{
		if (obj != nullptr)
			delete obj;
	}
}