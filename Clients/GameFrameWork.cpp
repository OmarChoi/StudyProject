#include "stdafx.h"
#include "GameFrameWork.h"
#include "GameObject.h"
#include "Shader.h"

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
}

void GameFrameWork::BuildObject()
{
	m_shader->BuildObject<SquareObject>();
}

void GameFrameWork::KeyInput(unsigned char key, KEY_STATE state)
{
	switch (state)
	{
	case KS_DOWN:
	{
		switch (key)
		{
			// πÊ«‚≈∞
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
