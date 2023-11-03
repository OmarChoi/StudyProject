#include "stdafx.h"
#include "assert.h"
#include "LoadPng.h"
#include "Camera.h"
#include "StandardShader.h"

StandardShader::StandardShader()
{
	SetShader();
	SetTexture();
	CreateVertexBuffer();
}

StandardShader::~StandardShader()
{
}

void StandardShader::SetShader()
{
	m_shaderIndex = CompileShaders("./Shaders/Standard.vs", "./Shaders/Standard.fs");
}

void StandardShader::SetTexture()
{
	int texture = CreateTexture("./Image/TX_Grass.png", GL_NEAREST);
	m_textures.emplace_back(texture);
	
	texture = CreateTexture("./Image/TX_Player.png", GL_NEAREST);
	m_textures.emplace_back(texture);
}

GLuint StandardShader::CreateTexture(char* filePath, GLuint samplingMethod)
{
	std::vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, filePath);
	if (error != 0)
	{
		std::cout << "PNG image loading failed: " << std::endl;
		assert(0);
	}
	GLuint temp;
	glGenTextures(1, &temp);
	glBindTexture(GL_TEXTURE_2D, temp);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, samplingMethod);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, samplingMethod);
	return temp;
}

void StandardShader::CreateVertexBuffer()
{
	int totalFloatCountPosUV = 6 * (3 + 2);
	float* verticesPosUV = new float[totalFloatCountPosUV];

	int index = 0;

	// V0
	//Pos
	verticesPosUV[index++] = -1.f / g_WindowSizeX;
	verticesPosUV[index++] = -1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 0.0f;
	verticesPosUV[index++] = 1.0f;

	// V1
	//Pos
	verticesPosUV[index++] = -1.f / g_WindowSizeX;
	verticesPosUV[index++] = 1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 0.0f;
	verticesPosUV[index++] = 0.0f;

	// V2
	//Pos
	verticesPosUV[index++] = 1.f / g_WindowSizeX;
	verticesPosUV[index++] = 1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 1.0f;
	verticesPosUV[index++] = 0.0f;

	// V3
	//Pos
	verticesPosUV[index++] = -1.f / g_WindowSizeX;
	verticesPosUV[index++] = -1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 0.0f;
	verticesPosUV[index++] = 1.0f;

	// V4
	//Pos
	verticesPosUV[index++] = 1.f / g_WindowSizeX;
	verticesPosUV[index++] = 1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 1.0f;
	verticesPosUV[index++] = 0.0f;

	// V5
	//Pos
	verticesPosUV[index++] = 1.f / g_WindowSizeX;
	verticesPosUV[index++] = -1.f / g_WindowSizeY;
	verticesPosUV[index++] = 0.0f;
	//UV
	verticesPosUV[index++] = 1.0f;
	verticesPosUV[index++] = 1.0f;

	glGenBuffers(1, &m_vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, totalFloatCountPosUV * sizeof(float), verticesPosUV, GL_STATIC_DRAW);
	delete[] verticesPosUV;
}

void StandardShader::Draw(ObjectData data, const Camera* camera)
{
	glUseProgram(m_shaderIndex);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	int projectionLoc = glGetUniformLocation(m_shaderIndex, "u_Projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, &camera->m_ProjView[0][0]);

	int defaultPos = glGetAttribLocation(m_shaderIndex, "a_DefaultPos");
	int texCoord = glGetAttribLocation(m_shaderIndex, "a_TexCoord");
	glEnableVertexAttribArray(defaultPos);
	glEnableVertexAttribArray(texCoord);


	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	glVertexAttribPointer(defaultPos, 3, GL_FLOAT,
		GL_FALSE, sizeof(float) * 5, 0);
	glVertexAttribPointer(texCoord, 2, GL_FLOAT,
		GL_FALSE, sizeof(float) * 5, (GLvoid*)(sizeof(float) * 3));

	int objectPos = glGetUniformLocation(m_shaderIndex, "u_ObjectPos");
	int time = glGetUniformLocation(m_shaderIndex, "u_Time");
	int size = glGetUniformLocation(m_shaderIndex, "u_Size");
	glUniform2f(objectPos, data.m_pos.x, data.m_pos.y);
	glUniform1f(time, 0.0f);
	glUniform1f(size, data.m_size);

	GLuint samplerULoc = glGetUniformLocation(m_shaderIndex, "u_TexSampler");
	glUniform1i(samplerULoc, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_textures[data.m_type]);

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(defaultPos);
	glDisableVertexAttribArray(texCoord);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glDisable(GL_BLEND);
}

