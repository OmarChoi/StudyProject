#pragma once
class GameObject;

class Shader
{
	vector<GameObject*> m_objects;
	GLuint m_shaderIndex;
public:
	Shader();
	~Shader();

	void Render();

	template <typename OBJ>
	void BuildObject() {
		OBJ* objects = new OBJ();
		objects->BuildObject();
		m_objects.emplace_back(objects);
	}

	template <typename OBJ>
	void AddObjects(int x, int y, int size) {
		OBJ* objects = new OBJ();
		objects->BuildObject();
		m_objects.emplace_back(objects);
	}

	void AddObjects(GameObject* obj) {
		m_objects.emplace_back(obj);
	}

private:
	void SetShader();
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	bool ReadFile(char* filename, std::string* target);
};

