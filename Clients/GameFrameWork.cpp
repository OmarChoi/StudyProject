#include "stdafx.h"
#include "GameFrameWork.h"
#include "GameObject.h"
#include "Shader.h"
#include "InGameScene.h"
#include "LobbyScene.h"
#include "LoginScene.h"

void renderBitmapString(float x, float y, void* font, const std::string& text) {
	glRasterPos2f(x, y);
	for (char c : text)
		glutBitmapCharacter(font, c);
}

GameFrameWork::GameFrameWork()
{
	m_scene[ST_LOGIN] = new LoginScene();
	m_scene[ST_LOBBY] = new LobbyScene();
	m_scene[ST_INGAME] = new InGameScene();

	m_sceneType = ST_INGAME;
	m_lastTime = chrono::high_resolution_clock::now();
	BuildObject();
}

GameFrameWork::~GameFrameWork()
{
}

void GameFrameWork::RenderScene()
{
	auto currentTime = chrono::high_resolution_clock::now();
	double ElapsedTime = chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_lastTime).count();
	m_lastTime = currentTime;
	cout << (double)ElapsedTime << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_scene[m_sceneType]->RenderScene(ElapsedTime);
	renderBitmapString(0, 10, GLUT_BITMAP_TIMES_ROMAN_24, "Hello, OpenGL!");
}

void GameFrameWork::BuildObject()
{
	for (auto& p : m_scene)
		p->BuildObject();
}

void GameFrameWork::KeyInput(unsigned char key, KEY_STATE state)
{
	m_scene[m_sceneType]->KeyInput(key, state);
}

void GameFrameWork::MouseInput(int button, int state, int x, int y)
{
	m_scene[m_sceneType]->MouseInput(button, state, x, y);
}
