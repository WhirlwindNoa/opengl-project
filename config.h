#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#define _USE_MATH_DEFINES

#include <glad/glad.h>
#include <math.h>

GLuint VAOcube, VBOcube, EBOcube;

const int RES[2] = { 600, 600 };

const int RAYS = 60, MAX_DEPTH = 800, TILE = 100;
const float FOV = M_PI / 3, DELTA_ANGLE = FOV / RAYS;

#endif