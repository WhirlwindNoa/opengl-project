#include <iostream>
#include <vector>
#include <math.h>

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include "shader.h"
#include "utilities.h"
#include "graphics.h"

class Settings {
	public:
		int resolution[2] = { 600, 600 };
};

class Player {
	private:
		float speed;
		float size;

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
			size = 0.1f;

			std::cout << "[LOG] Player object has been initialized!" << std::endl;
		}
};

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

int main() {
	Settings settings;
	Player player;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	GLFWwindow* window = glfwCreateWindow(settings.resolution[0], settings.resolution[1], "OpenGL", NULL, NULL);
	if (!window)
	{
		std::cout << "[ERROR] Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, settings.resolution[0], settings.resolution[1]);
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
		g_RenderSquare(player.getSize(), player.getPosition(), color);
		g_RenderRect({ 0.0f, 0.0f, 0.1f, 0.2f }, { 0.1f, 0.1f, 0.1f });

		std::cout << "\r" 
				  << "xyz: "
			      << player.getPosition().at(0) 
				  << " / " 
			      << player.getPosition().at(1) 
			      << std::flush;

		std::cout << "";
		
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAOcube);
	glDeleteBuffers(1, &VBOcube);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}