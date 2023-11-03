#pragma once
#include "Scene.h"

class Player;
class InGameScene : public Scene
{
private:
	bool m_chatMode;
	Player* m_myCharacter;
public:
	InGameScene();
	~InGameScene();
public:
	void KeyInput(unsigned char key, KEY_STATE state);
	void MouseInput(int button, int state, int x, int y);
	void RenderScene(double ElapsedTime);
	void BuildObject();
};

