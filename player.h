#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>

#include "utilities.h"

class Player {
private:
	float speed;
	float size;
	int angle;

	std::vector < float > pos{ 0.0f, 0.0f, 0.0f };


public:
	// get player attributes
	std::vector<float> getPosition() {
		return { u_fix(pos.at(0)), u_fix(pos.at(1)), u_fix(pos.at(2)) };
	}

	float getSpeed() {
		return speed;
	}
	float getSize() {
		return size;
	}

	int getAngle() {
		return angle;
	}

	// set player attributes
	void setPosition(float x, float y, float z) {
		pos.at(0) = x;
		pos.at(1) = y;
		pos.at(2) = z;
	}

	void setSpeed(float s) {
		speed = s;
	}
	void setSize(float s) {
		size = s;
	}

	// game functions
	void movement(std::vector<bool> keys) {
		if (keys.at(0)) {
			pos.at(1) += speed;
		}
		if (keys.at(1)) {
			pos.at(0) -= speed;
		}
		if (keys.at(2)) {
			pos.at(1) -= speed;
		}
		if (keys.at(3)) {
			pos.at(0) += speed;
		}
	}

	// constructor
	Player() {
		speed = 0.01f;
		size = 0.02f;
		angle = 0;

		std::cout << "[LOG] Player object has been initialized!" << std::endl;
	}
};

#endif