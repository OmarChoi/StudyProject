#include "stdafx.h"
#include "InGameScene.h"
#include "Shader.h"
#include "StandardShader.h"
#include "GameObject.h"
#include "Player.h"

constexpr float speed = 0.2;
array<float, 4> deltaX{ -speed, 0, speed, 0 };
array<float, 4> deltaY{ 0, speed, 0, -speed };

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
			m_myCharacter->AddPosition(deltaX[DIR_UP], deltaY[DIR_UP]);
			break;
		case GLUT_KEY_DOWN:
			m_myCharacter->AddPosition(deltaX[DIR_DOWN], deltaY[DIR_DOWN]);
			break;
		case GLUT_KEY_LEFT:
			m_myCharacter->AddPosition(deltaX[DIR_LEFT], deltaY[DIR_LEFT]);
			break;
		case GLUT_KEY_RIGHT:
			m_myCharacter->AddPosition(deltaX[DIR_RIGHT], deltaY[DIR_RIGHT]);
			break;

			// attack
		case 'a' | 'A':
		{
			int randX = 2.f * (((float)rand() / (float)RAND_MAX) - 0.5f) * g_WindowSizeX;
			int randY = 2.f * (((float)rand() / (float)RAND_MAX) - 0.5f) * g_WindowSizeY;
			AddObjects<SquareObject>(randX, randY);
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

void InGameScene::RenderScene()
{
	m_shader->Render();
}

void InGameScene::BuildObject()
{
	GameObject* object2 = new GameObject();
	object2->SetSize(400000);
	m_shader->AddObjects(object2);

	SquareObject* objects = new SquareObject();
	m_myCharacter = static_cast<GameObject*>(objects);
	m_shader->AddObjects(objects);

}
