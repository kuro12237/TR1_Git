#pragma once

#include "Vector2.h"
#define MAP_WIDTH 63
#define MAP_HEIGHT 63
//奇数のみ
//63*63が限界値

struct int_Position
{
	int x, y;
};

struct MapTip
{
	int m[MAP_WIDTH][MAP_HEIGHT];
	int BlockSize;
	unsigned int Resource;
};

enum  Block
{
	Wall,
	Load
};


struct DoubleVector2
{
	double x, y;

};

enum  Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
enum MODE
{
	DIG,
	FRACTAL

};
