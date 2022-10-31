#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <time.h>

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "shader.h"
#include "graphics.h"
#include "player.h"
#include "config.h"

int main() {
	srand((unsigned)time(NULL));
	Player player;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	GLFWwindow* window = glfwCreateWindow(RES[0], RES[1], "OpenGL", NULL, NULL);
	if (!window)
	{
		std::cout << "[ERROR] Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, RES[0], RES[1]);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "[ERROR] Failed to initialize GLAD" << std::endl;
		return -1;
	}

	Shader shader("./shader.vs", "./shader.fs");

	while (!glfwWindowShouldClose(window)) 
	{
		shader.use();

		// renderer
		std::vector<bool> keys = processInput(window);
		
		std::vector<float> color{ 0.0f, 0.0f, 1.0f };

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		player.movement(keys);
		
		Rect playerRect(player.getPosition().at(0), player.getPosition().at(1), player.getSize(), player.getSize());
		g_RenderRect(playerRect, color);

		renderMap();
		
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAOcube);
	glDeleteBuffers(1, &VBOcube);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}