#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <string>

#include "targetver.h"
#include "Dependencies/glew.h"
#include "Dependencies/freeglut.h"

using namespace std;

constexpr int g_WindowSizeX = 1280;
constexpr int g_WindowSizeY = 720;

#define MAX_OBJECT_COUNT 1000

struct XMFLOAT2 {
public:
	float x, y;
public:
	XMFLOAT2() : x(0), y(0) {}
	XMFLOAT2(float px, float py) : x(px), y(py) {}
	void operator =(XMFLOAT2 rhs) {
		x = rhs.x;
		y = rhs.y;
	}
	bool operator ==(XMFLOAT2 rhs) {
		return (x == rhs.x) && (y == rhs.y);
	}
	bool operator !=(XMFLOAT2 rhs) {
		return (x != rhs.x) || (y != rhs.y);
	}
	XMFLOAT2 operator +(XMFLOAT2 rhs) {
		XMFLOAT2 temp{ x, y };
		temp.x += rhs.x;
		temp.y += rhs.y;
		return temp;
	}
	XMFLOAT2 operator -(XMFLOAT2 rhs) {
		XMFLOAT2 temp{ x, y };
		temp.x -= rhs.x; temp.y -= rhs.y;
		return temp;
	}
};

struct XMFLOAT3 {
public:
	float x, y, z;
public:
	XMFLOAT3() : x(0), y(0), z(0) {}
	XMFLOAT3(float px, float py, float pz) : x(px), y(py), z(pz) {}
	void operator =(XMFLOAT3 rhs) {
		x = rhs.x; y = rhs.y; z = rhs.z;
	}
	bool operator ==(XMFLOAT3 rhs) {
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
	}
	bool operator !=(XMFLOAT3 rhs) {
		return (x != rhs.x) || (y != rhs.y) || (z != rhs.z);
	}
	XMFLOAT3 operator +(XMFLOAT3 rhs) {
		XMFLOAT3 temp{ x, y, z };
		temp.x += rhs.x; temp.y += rhs.y; temp.z += rhs.z;
		return temp;
	}
	XMFLOAT3 operator -(XMFLOAT3 rhs) {
		XMFLOAT3 temp{ x, y, z };
		temp.x -= rhs.x; temp.y -= rhs.y; temp.z -= rhs.z;
		return temp;
	}
};

struct XMFLOAT4 {
public:
	float x, y, z, a;
public:
	XMFLOAT4() : x(0), y(0), z(0), a(0) {}
	XMFLOAT4(float px, float py, float pz, float pa) : x(px), y(py), z(pz), a(pa) {}
	void operator =(XMFLOAT4 rhs) {
		x = rhs.x; y = rhs.y; z = rhs.z; a = rhs.a;
	}
	bool operator ==(XMFLOAT4 rhs) {
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (a == rhs.a);
	}
	bool operator !=(XMFLOAT4 rhs) {
		return (x != rhs.x) || (y != rhs.y) || (z != rhs.z) || (a != rhs.a);
	}
	XMFLOAT4 operator +(XMFLOAT4 rhs) {
		XMFLOAT4 temp{ x, y, z, a };
		temp.x += rhs.x; temp.y += rhs.y; temp.z += rhs.z; temp.a += rhs.a; 
		return temp;
	}
	XMFLOAT4 operator -(XMFLOAT4 rhs) {
		XMFLOAT4 temp{ x, y, z, a };
		temp.x -= rhs.x; temp.y -= rhs.y; temp.z -= rhs.z; temp.a -= rhs.a;
		return temp;
	}
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

enum SCENE_TYPE 
{
	ST_LOGIN,
	ST_LOBBY,
	ST_INGAME
};

enum DIRETION
{
	DIR_LEFT,
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN
};
