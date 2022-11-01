#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <math.h>

#include "config.h"

std::vector<bool> processInput(GLFWwindow* window)
{
	std::vector<bool> keys(255, false);

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

	keys.at(4) = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) ? true : false;
	keys.at(5) = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) ? true : false;

	return keys;
}

class Player {
private:
	int speed;
	int size;
	float angle;

	std::vector < float > pos{ 0, 0, 0 };


public:
	// get player attributes
	std::vector<float> getPosition() {
		return pos;
	}

	float getSpeed() {
		return speed;
	}
	float getSize() {
		return size;
	}

	float getAngle() {
		return angle;
	}

	// set player attributes
	void setPosition(float x, float y, float z) {
		pos.at(0) = x;
		pos.at(1) = y;
		pos.at(2) = z;
	}

	void setSpeed(int s) {
		speed = s;
	}
	void setSize(int s) {
		size = s;
	}

	// game functions
	void movement(std::vector<bool> keys) {
		float sin_a = sin(angle);
		float cos_a = cos(angle);

		if (keys.at(0)) { // W
			pos.at(0) += (speed * cos_a);
			pos.at(1) += (speed * sin_a);
		}
		if (keys.at(1)) { // A
			pos.at(0) += (speed * sin_a);
			pos.at(1) += (-speed * cos_a);
		}
		if (keys.at(2)) { // S
			pos.at(0) += (-speed * cos_a);
			pos.at(1) += (-speed * sin_a);
		}
		if (keys.at(3)) { // D
			pos.at(0) += (-speed * sin_a);
			pos.at(1) += (speed * cos_a);
		}

		if (keys.at(4)) { // ARROW LEFT
			angle += 0.05;
		}
		if (keys.at(5)) { // ARROW RIGHT
			angle -= 0.05;
		}

		if (angle > 360) {
			angle - 360;
		}
	}

	// constructor
	Player() {
		speed = 5;
		size = 20;
		angle = 0;

		std::cout << "[LOG] Player object has been initialized!" << std::endl;
	}
};

#endif