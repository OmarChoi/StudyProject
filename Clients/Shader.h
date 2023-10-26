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

	template <typename T>
	void BuildObject() {
		T* objects = new T();
		objects->BuildObject();
		m_objects.emplace_back(objects);
	}

private:
	void SetShader();
	GLuint CompileShaders(char* filenameVS, char* filenameFS);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);
	bool ReadFile(char* filename, std::string* target);
};

