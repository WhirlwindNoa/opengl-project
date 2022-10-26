#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>

float u_fix(float n) {
	return floor(n * 100.0f) / 100.0f;
}

#endif