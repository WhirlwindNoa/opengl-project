#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h> 

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <cmath>

#include "trigmath.h";
#include "config.h"
#include "maps.h"

Maps map;

// render a rectangle
// coor = {center x, center y, width, height}
void g_RenderRect(Rect rect, std::vector<float> clr) {
	GLuint indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	GLfloat vertices[] = {
		(float) rect.x / RES[0] - (float) rect.width / RES[0], (float) rect.y / RES[1] + (float) rect.height / RES[1], 0,/* top right    */clr.at(0), clr.at(1), clr.at(2),
		(float) rect.x / RES[0] - (float) rect.width / RES[0], (float) rect.y / RES[1] - (float) rect.height / RES[1], 0,/* bottom right */clr.at(0), clr.at(1), clr.at(2),
		(float) rect.x / RES[0] + (float) rect.width / RES[0], (float) rect.y / RES[1] - (float) rect.height / RES[1], 0,/* bottom left  */clr.at(0), clr.at(1), clr.at(2),
		(float) rect.x / RES[0] + (float) rect.width / RES[0], (float) rect.y / RES[1] + (float) rect.height / RES[1], 0,/* top left     */clr.at(0), clr.at(1), clr.at(2),
	};

	glGenVertexArrays(1, &VAOcube);
	glGenBuffers(1, &VBOcube);
	glGenBuffers(1, &EBOcube);

	glBindVertexArray(VAOcube);
	glBindBuffer(GL_ARRAY_BUFFER, VBOcube);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOcube);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glDeleteVertexArrays(1, &VAOcube);
	glDeleteBuffers(1, &VBOcube);
	glDeleteBuffers(1, &EBOcube);
}

void g_RenderLine(int startx, int starty, int endx, int endy, std::vector<float> color) {
	GLfloat vertices[] = {
		(float) startx / RES[0], (float) starty / RES[1], 0, color.at(0), color.at(1), color.at(2),
		(float) endx   / RES[0], (float) endy   / RES[1], 0, color.at(0), color.at(1), color.at(2)
	};

	glGenVertexArrays(1, &VAOline);
	glGenBuffers(1, &VBOline);

	glBindVertexArray(VAOline);
	glBindBuffer(GL_ARRAY_BUFFER, VBOline);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDrawArrays(GL_LINES, 0, 2);

	glDeleteVertexArrays(1, &VAOline);
	glDeleteBuffers(1, &VBOline);
}

//Vector2f rayInTile(Vector2f rayEnd)
//{
//	std::vector<std::vector<int>>::iterator it;
//	it = std::find(map.world.begin(), map.world.end(), { rayEnd.x, rayEnd.y })
//}


void renderMap() {
	for (int i = 0; i < map.world.size(); i++) {
		int x = map.world.at(i).at(0);
		int y = map.world.at(i).at(1);

		std::vector<float> color = { 
									(float)map.world.at(i).at(2) / 255,
									(float)map.world.at(i).at(3) / 255,
									(float)map.world.at(i).at(4) / 255
								   };

		Rect rect = { x, y, TILE / 2, TILE / 2 };
		g_RenderRect(rect, color);
	}
}

void rayCasting(int xo, int yo, float angle) {
	float cur_angle = angle - FOV / 2;

	for (int ray = 0; ray < NUM_RAYS; ray++) {
		double sin_a = sin(cur_angle);
		double cos_a = cos(cur_angle);

		float x = (float)xo + RES[0] * cos_a;
		float y = (float)yo + RES[0] * sin_a;

		g_RenderLine(xo, yo, x, y, { 0.5f, 0.5f, 0.5f });

		cur_angle += DELTA_ANGLE;
	}
}

#endif