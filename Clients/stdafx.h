#pragma once
#include <iostream>
#include <vector>

#include "targetver.h"
#include "Dependencies/glew.h"
#include "Dependencies/freeglut.h"

using namespace std;

constexpr int g_WindowSizeX = 1280;
constexpr int g_WindowSizeY = 720;

#define MAX_OBJECT_COUNT 1000

struct XMFLOAT2 {
	float x, y;
	
};

struct XMFLOAT3 {
	float x, y, z;
};

struct XMFLOAT4 {
	float x, y, z, a;
};

enum NPC_TYPE : char
{
	NT_NONE,
};

enum CHARACTER_TYPE : char
{
	CT_NONE,
	CT_WARRIOR,
	CT_ARCHER,
	CT_MAGE,
};

enum KEY_STATE : char
{
	KS_DOWN,
	KS_UP
};

