#pragma once
#include "GameObjectManager.h"

class Shader;
class GameFrameWork
{
public:
	GameFrameWork();
	~GameFrameWork();

public:
	void KeyInput(unsigned char key, KEY_STATE state);
	void MouseInput(int button, int state, int x, int y);
	void RenderScene();

	void BuildObject();
private:

private:
	Shader* m_shader = NULL;
	GameObjectManager* m_objectMgr = NULL;
};

