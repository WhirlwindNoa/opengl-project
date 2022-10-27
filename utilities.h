#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cmath>
#include <vector>
#include <fstream>

#include "config.h"

std::vector<bool> processInput(GLFWwindow* window)
{
	std::vector<bool> keys(4, false);

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// wireframe
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	keys.at(0) = (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) ? true : false;
	keys.at(1) = (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) ? true : false;
	keys.at(2) = (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) ? true : false;
	keys.at(3) = (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) ? true : false;

	return keys;
}

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

float u_fix(float n) {
	return floor(n * 100.0f) / 100.0f;
}

float u_norm(int px) {
	return ((float) px / RES[0]);
}
#endif