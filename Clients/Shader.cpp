#include "stdafx.h"
#include "Shader.h"
#include "GameObject.h"
#include <fstream>

#include "Dependencies\glew.h"

Shader::Shader()
{
	// SetShader();
	// CreateVertexBuffer();
}

Shader::~Shader()
{
	for (auto& p : m_objects)
	{
		if (p != nullptr)
			delete p;
	}
}

void Shader::Draw(ObjectData data, const Camera* camera)
{

	glUseProgram(m_shaderIndex);

	glUniform1f(glGetUniformLocation(m_shaderIndex, "u_Size"), data.m_size);
	glUniform4f(glGetUniformLocation(m_shaderIndex, "u_Color"),
		data.m_color.x, data.m_color.y, data.m_color.z, data.m_color.a);
	glUniform2f(glGetUniformLocation(m_shaderIndex, "u_Transform"), data.m_pos.x / g_WindowSizeX, data.m_pos.y / g_WindowSizeX);

	int attribPosition = glGetAttribLocation(m_shaderIndex, "a_Position");
	glEnableVertexAttribArray(attribPosition);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(attribPosition);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Shader::Render(double ElapsedTime, const Camera* camera)
{
	for (auto& p : m_objects) {
		p->UpdateTransform(ElapsedTime);
		ObjectData data = p->GetObjectData();
		Draw(data, camera);
	}
}

void Shader::SetShader()
{
	m_shaderIndex = CompileShaders("./Shaders/SolidRect.vs", "./Shaders/SolidRect.fs");
}

bool Shader::ReadFile(char* filename, std::string* target)
{
	// 한국공학대학교 게임공학과 게임 소프트웨어 공학 수업 코드

	std::ifstream file(filename);
	if (file.fail())
	{
		std::cout << filename << " file loading failed.. \n";
		file.close();
		return false;
	}
	std::string line;
	while (getline(file, line)) {
		target->append(line.c_str());
		target->append("\n");
	}
	return true;
}

void Shader::CreateVertexBuffer()
{
	float rect[]
		=
	{
		-1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f,
		-1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f,
		1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f,

		-1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f,
		1.f / g_WindowSizeX, 1.f / g_WindowSizeY, 0.f,
		1.f / g_WindowSizeX, -1.f / g_WindowSizeY, 0.f,
	};

	glGenBuffers(1, &m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rect), rect, GL_STATIC_DRAW);
}

GLuint Shader::CompileShaders(char* filenameVS, char* filenameFS)
{
	// 한국공학대학교 게임공학과 게임 소프트웨어 공학 수업 코드

	GLuint ShaderProgram = glCreateProgram(); //빈 쉐이더 프로그램 생성

	if (ShaderProgram == 0) { //쉐이더 프로그램이 만들어졌는지 확인
		fprintf(stderr, "Error creating shader program\n");
	}

	std::string vs, fs;

	//shader.vs 가 vs 안으로 로딩됨
	if (!ReadFile(filenameVS, &vs)) {
		printf("Error compiling vertex shader\n");
		return -1;
	};

	//shader.fs 가 fs 안으로 로딩됨
	if (!ReadFile(filenameFS, &fs)) {
		printf("Error compiling fragment shader\n");
		return -1;
	};

	// ShaderProgram 에 vs.c_str() 버텍스 쉐이더를 컴파일한 결과를 attach함
	AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);

	// ShaderProgram 에 fs.c_str() 프레그먼트 쉐이더를 컴파일한 결과를 attach함
	AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	//Attach 완료된 shaderProgram 을 링킹함
	glLinkProgram(ShaderProgram);

	//링크가 성공했는지 확인
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);

	if (Success == 0) {
		// shader program 로그를 받아옴
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		std::cout << filenameVS << ", " << filenameFS << " Error linking shader program\n" << ErrorLog;
		return -1;
	}

	glValidateProgram(ShaderProgram);
	glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
	if (!Success) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		std::cout << filenameVS << ", " << filenameFS << " Error validating shader program\n" << ErrorLog;
		return -1;
	}

	glUseProgram(ShaderProgram);
	std::cout << filenameVS << ", " << filenameFS << " Shader compiling is done.";

	return ShaderProgram;
}

void Shader::AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
	// 한국공학대학교 게임공학과 게임 소프트웨어 공학 수업 코드

	//쉐이더 오브젝트 생성
	GLuint ShaderObj = glCreateShader(ShaderType);

	if (ShaderObj == 0) {
		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
	}

	const GLchar* p[1];
	p[0] = pShaderText;
	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);
	//쉐이더 코드를 쉐이더 오브젝트에 할당
	glShaderSource(ShaderObj, 1, p, Lengths);

	//할당된 쉐이더 코드를 컴파일
	glCompileShader(ShaderObj);

	GLint success;
	// ShaderObj 가 성공적으로 컴파일 되었는지 확인
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];

		//OpenGL 의 shader log 데이터를 가져옴
		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
		printf("%s \n", pShaderText);
	}

	// ShaderProgram 에 attach!!
	glAttachShader(ShaderProgram, ShaderObj);
}
