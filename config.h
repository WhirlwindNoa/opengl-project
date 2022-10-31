#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#define _USE_MATH_DEFINES

#include <glad/glad.h>
#include <math.h>

GLuint VAOcube, VBOcube, EBOcube;
GLuint VAOline, VBOline;

// game globals
const int RES[2] = { 800, 700 };

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

int TILE = 100;

#endif