#include "stdafx.h"
#include "Shader.h"
#include "Player.h"
#include "GameObject.h"
#include "InGameScene.h"
#include "StandardShader.h"

InGameScene::InGameScene()
{
	m_shader = new StandardShader();
	m_chatMode = false;
	m_myCharacter = nullptr;
}

InGameScene::~InGameScene()
{
}

void InGameScene::KeyInput(unsigned char key, KEY_STATE state)
{
	switch (state)
	{
	case KS_DOWN:
	{
		switch (key)
		{
			// ¹æÇâÅ°
		case GLUT_KEY_UP:
			m_myCharacter->AddKeyInput(DIR_UP);
			break;
		case GLUT_KEY_DOWN:
			m_myCharacter->AddKeyInput(DIR_DOWN);
			break;
		case GLUT_KEY_LEFT:
			m_myCharacter->AddKeyInput(DIR_LEFT);
			break;
		case GLUT_KEY_RIGHT:
			m_myCharacter->AddKeyInput(DIR_RIGHT);
			break;

			// attack
		case 'a' | 'A':
		{
			int randX = 2.f * (((float)rand() / (float)RAND_MAX) - 0.5f) * g_WindowSizeX;
			int randY = 2.f * (((float)rand() / (float)RAND_MAX) - 0.5f) * g_WindowSizeY;
			AddObjects<Player>(randX, randY);
		}
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
			m_myCharacter->RemoveKeyInput(DIR_UP);
			break;
		case GLUT_KEY_DOWN:
			m_myCharacter->RemoveKeyInput(DIR_DOWN);
			break;
		case GLUT_KEY_LEFT:
			m_myCharacter->RemoveKeyInput(DIR_LEFT);
			break;
		case GLUT_KEY_RIGHT:
			m_myCharacter->RemoveKeyInput(DIR_RIGHT);
			break;
		}
	}
	break;
	}
}

void InGameScene::MouseInput(int button, int state, int x, int y)
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

void InGameScene::RenderScene(double ElapsedTime)
{
	m_shader->Render(ElapsedTime, m_myCharacter->getCamera());
}

void InGameScene::BuildObject()
{
	GameObject* object = new GameObject();
	object->SetSize(400'000'0);
	m_shader->AddObjects(object);

	Player* player = new Player();
	m_myCharacter = player;
	m_shader->AddObjects(player);

}
