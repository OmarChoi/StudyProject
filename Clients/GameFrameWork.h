#pragma once
#include "GameObjectManager.h"

class Scene;
class GameFrameWork
{
public:
	GameFrameWork();
	~GameFrameWork();

	chrono::high_resolution_clock::time_point m_lastTime;
public:
	void KeyInput(unsigned char key, KEY_STATE state);
	void MouseInput(int button, int state, int x, int y);
	void RenderScene();
	void BuildObject();

private:
	array<Scene*, 3> m_scene;
	SCENE_TYPE m_sceneType;

public:
	void SetSceneType(SCENE_TYPE st) { m_sceneType = st; }
	SCENE_TYPE GetSceneType() { return m_sceneType; }
};