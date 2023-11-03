#pragma once
class Shader;

class Scene
{
public:
	virtual void KeyInput(unsigned char key, KEY_STATE state);
	virtual void MouseInput(int button, int state, int x, int y);
	virtual void RenderScene(double ElapsedTime);
	virtual void BuildObject();

	template <typename OBJ>
	void AddObjects(int x, int y) {
		m_shader->AddObjects<OBJ>(x, y);
	}
protected:
	Shader* m_shader = NULL;
};

