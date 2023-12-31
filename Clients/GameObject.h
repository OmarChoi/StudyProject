#pragma once
class Camera;
class GameObject
{
public:
	GameObject();
	GameObject(XMFLOAT2 pos, float size);
	~GameObject();

	XMFLOAT2 GetPos() { return m_pos; }
	float GetSize() { return m_size; };
	virtual Camera* getCamera() { return nullptr; }

	virtual ObjectData GetObjectData();
	virtual void UpdateTransform(double ElapsedTime) {};

	void SetSize(float size) { m_size = size; }
	void SetPosition(XMFLOAT2 pos) { m_pos = pos; }
	void AddPosition(XMFLOAT2 pos) { m_pos = m_pos + pos; }
	void AddPosition(float x, float y) {
		m_pos.x = m_pos.x + x;
		m_pos.y = m_pos.y + y;
	}

protected:
	CHARACTER_TYPE m_type;
	XMFLOAT2 m_pos;
	XMFLOAT4 m_color;
	XMFLOAT2 m_posTransform;
	float m_size;
	GLuint m_vertexBufferObject;
	GLuint m_TransformBufferObject;

protected:
	float m_speed;
};
