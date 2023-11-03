#pragma once
#include "Shader.h"
class StandardShader : public Shader
{
public:
	StandardShader();
	~StandardShader();

public:
	vector<GLuint> m_textures;

protected:
	virtual GLuint CreateTexture(char* filePath, GLuint samplingMethod);
	virtual void CreateVertexBuffer();

protected:
	virtual void SetShader();
	virtual void SetTexture();
	virtual void Draw(ObjectData data);
};

