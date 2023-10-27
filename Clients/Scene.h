#pragma once
class Shader;

class Scene
{
public:
	virtual void KeyInput(unsigned char key, KEY_STATE state);
	virtual void MouseInput(int button, int state, int x, int y);
	virtual void RenderScene();
	virtual void BuildObject();

protected:
	Shader* m_shader = NULL;
};

