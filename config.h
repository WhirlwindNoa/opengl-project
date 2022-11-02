#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#define _USE_MATH_DEFINES

#include <glad/glad.h>
#include <math.h>

GLuint VAOcube, VBOcube, EBOcube;
GLuint VAOline, VBOline;

struct Rect {
    float x, y, width, height;
};

struct Vector2f
{
    float x, y;
};

struct Vector2i
{
    int x, y;
};

struct Vector3f
{
    float x, y, z;
};

struct Vector3i
{
    int x, y, z;
};

// game globals
const int RES[2] = { 800, 600 };

const int TILE = 100;
const int NUM_RAYS = 30;
const int MAX_DEPTH = 800;

float FOV = M_PI / 3;

float DELTA_ANGLE = (float)FOV / NUM_RAYS;
float DIST = (float)NUM_RAYS / (2 * tan(FOV / 2));
float PROJ_COEFF = (float)4 * DIST * TILE;
float SCALE = (float)RES[0] / NUM_RAYS;

float u_isqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));

	return y;
}

float u_fix(float n, int prec = 2) {
	float coeff = pow(10, prec);

	return floor(n * coeff) / coeff;
}

#endif