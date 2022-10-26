#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h> 

#include <vector>

GLuint VAOcube, VBOcube, EBOcube;

void g_RenderSquare(float size, std::vector<float> coor, std::vector<float> clr) {
	float pos[3];
	float color[3];

	for (int i = 0; i < 3; i++) {
		pos[i] = coor.at(i);
		color[i] = clr.at(i);
	};

	GLuint indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	GLfloat vertices[] = {
		pos[0] + size, pos[1] + size, pos[2],/* top right    */color[0], color[1], color[2],
		pos[0] + size, pos[1] - size, pos[2],/* bottom right */color[0], color[1], color[2],
		pos[0] - size, pos[1] - size, pos[2],/* bottom left  */color[0], color[1], color[2],
		pos[0] - size, pos[1] + size, pos[2],/* top left     */color[0], color[1], color[2]
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

// render a rectangle
// coor = {center x, center y, width, height}
void g_RenderRect(std::vector<float> coor, std::vector<float> clr) {
	GLuint indices[] = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	GLfloat vertices[] = {
		coor.at(0) - coor.at(2), coor.at(1) + coor.at(3), 0,/* top right    */clr.at(0), clr.at(1), clr.at(2),
		coor.at(0) - coor.at(2), coor.at(1) - coor.at(3), 0,/* bottom right */clr.at(0), clr.at(1), clr.at(2),
		coor.at(0) + coor.at(2), coor.at(1) - coor.at(3), 0,/* bottom left  */clr.at(0), clr.at(1), clr.at(2),
		coor.at(0) + coor.at(2), coor.at(1) + coor.at(3), 0,/* top left     */clr.at(0), clr.at(1), clr.at(2)
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

#endif