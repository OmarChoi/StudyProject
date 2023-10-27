#pragma once

class GameObject
{
public:
	GameObject() {};
	GameObject(XMFLOAT2 pos, float size);
	~GameObject();

	XMFLOAT2 GetPos();
	float GetSize();

	virtual void BuildObject() {};
	virtual void Render(GLuint ShaderIndex) {};

	void SetSize(float size) { m_size = size; }
	void SetPosition(float size) { m_size = size; }

protected:
	XMFLOAT2 m_pos;
	XMFLOAT4 m_color;
	float m_size;
	GLuint m_vertexBufferObject;
};

class SquareObject : public GameObject
{
public:
	SquareObject();
	virtual void BuildObject();
	virtual void Render(GLuint ShaderIndex);
};
