#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <math.h>

#include "config.h"
#include "trigmath.h"

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

	Vector3f pos = { 0, 0, 0 };


public:
	// get player attributes
	Vector3f getPosition() {
		return pos;
	}

	Vector3i getGridPosition() {
		return { (int)pos.x / TILE, (int)pos.y / TILE, (int)pos.z / TILE};
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
	void setPosition(Vector3f apos) {
		pos = apos;
	}

	void setSpeed(int s) {
		speed = s;
	}
	void setSize(int s) {
		size = s;
	}

	// game functions
	void movement(std::vector<bool> keys) {
		double sin_a;
		double cos_a;

		cossin_cordic(angle, 5, cos_a, sin_a);

		if (keys.at(0)) { // W
			pos.x += (speed * cos_a);
			pos.y += (speed * sin_a);
		}
		if (keys.at(1)) { // A
			pos.x += (-speed * sin_a);
			pos.y += (speed * cos_a);
		}
		if (keys.at(2)) { // S
			pos.x += (-speed * cos_a);
			pos.y += (-speed * sin_a);
		}
		if (keys.at(3)) { // D
			pos.x += (speed * sin_a);
			pos.y += (-speed * cos_a);
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