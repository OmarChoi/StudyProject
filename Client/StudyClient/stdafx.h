#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <vector>

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