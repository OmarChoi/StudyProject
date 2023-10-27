#pragma once

class GameObject
{
public:
	GameObject();
	GameObject(XMFLOAT2 pos, float size);
	~GameObject();

	XMFLOAT2 GetPos();
	float GetSize();

	virtual void BuildObject() {};
	virtual void UpdateTransform() {};
	virtual void Render(GLuint ShaderIndex) {};

	void SetSize(float size) { m_size = size; }
	void SetPosition(XMFLOAT2 pos) { m_pos = pos; }
	void AddPosition(XMFLOAT2 pos) { m_pos = m_pos + pos; }
	void AddPosition(float x, float y) {
		m_pos.x = m_pos.x + x;
		m_pos.y = m_pos.y + y;
	}

protected:
	XMFLOAT2 m_pos;
	XMFLOAT4 m_color;
	XMFLOAT2 m_posTransform;
	float m_size;
	GLuint m_vertexBufferObject;
	GLuint m_TransformBufferObject;
};

class SquareObject : public GameObject
{
public:
	SquareObject();
	virtual void BuildObject();
	virtual void UpdateTransform();
	virtual void Render(GLuint ShaderIndex);
};
