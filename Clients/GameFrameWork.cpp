#include "stdafx.h"
#include "GameFrameWork.h"
#include "GameObject.h"
#include "Shader.h"
#include <string>

void renderBitmapString(float x, float y, void* font, const std::string& text) {
	glRasterPos2f(x, y);
	for (char c : text) {
		glutBitmapCharacter(font, c);
	}
}

GameFrameWork::GameFrameWork()
{
	m_shader = new Shader();
	m_objectMgr = new GameObjectManager();
	BuildObject();
}

GameFrameWork::~GameFrameWork()
{
	if (m_shader)
		delete m_shader;
	if (m_objectMgr)
		delete m_objectMgr;

}

void GameFrameWork::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	m_shader->Render();
	renderBitmapString(0, 10, GLUT_BITMAP_TIMES_ROMAN_24, "Hello, OpenGL!");
}

void GameFrameWork::BuildObject()
{
	m_shader->BuildObject<SquareObject>();
}

void GameFrameWork::KeyInput(unsigned char key, KEY_STATE state)
{
	// Scene 생성 후 Scene에 따른 KeyInput 함수 호출하게 설정
	switch (state)
	{
	case KS_DOWN:
	{
		switch (key)
		{
			// 방향키
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_RIGHT:
			break;

			// attack
		case 'a' | 'A':
			break;

			// Escape
		case 27:
			break;
		}
	}
	break;
	case KS_UP:
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_RIGHT:
			break;
		}
	}
	break;
	}
}

void GameFrameWork::MouseInput(int button, int state, int x, int y)
{
	switch (state)
	{
	case GLUT_DOWN:
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON: break;
		case GLUT_MIDDLE_BUTTON: break;
		case GLUT_RIGHT_BUTTON: break;
		}
	}
	break;
	case GLUT_UP:
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON: break;
		case GLUT_MIDDLE_BUTTON: break;
		case GLUT_RIGHT_BUTTON: break;
		}
	}
	break;
	}
}
