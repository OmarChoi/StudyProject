#pragma once
class GameObject;
class Camera;
class Shader
{
protected:
	vector<GameObject*> m_objects;

	GLuint m_shaderIndex;
	GLuint m_vertexBufferObject;
	GLuint m_TransformBufferObject;

public:
	Shader();
	virtual ~Shader();

	void Render(double ElapsedTime, const Camera* camera = nullptr);
	virtual void Draw(ObjectData data, const Camera* camera);

	template <typename OBJ>
	void BuildObject() {
		OBJ* objects = new OBJ();
		objects->BuildObject();
		m_objects.emplace_back(objects);
	}

	template <typename OBJ>
	void AddObjects(int x, int y) {
		OBJ* objects = new OBJ();
		objects->SetPosition(XMFLOAT2(x, y));
		m_objects.emplace_back(objects);
	}

	void AddObjects(GameObject* obj) {
		m_objects.emplace_back(obj);
	}

protected:
	virtual void SetShader();
	virtual void CreateVertexBuffer();

protected:
	bool ReadFile(char* filename, std::string* target);
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
};

