#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <GLFW/linmath.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

// Matrix library
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// Camera
#include "Camera.h"

const unsigned int width = 800;
const unsigned int height = 800;

// FLAT TRIANGLES
// // Vertices coordinates
// GLfloat vertices[] =
// { //               COORDINATES                  /     COLORS           //
// 	-1.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower left corner
// 	 0.5f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f, // Lower right corner
// 	 0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f,     1.0f, 0.6f,  0.32f, // Upper corner
// 	-0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner left
// 	 0.25f, 0.5f * float(sqrt(3)) * 1 / 6, 0.0f,     0.9f, 0.45f, 0.17f, // Inner right
// 	 0.0f, -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,     0.8f, 0.3f,  0.02f  // Inner down
// };

// // Indices for vertices order
// GLuint indices[] =
// {
// 	0, 3, 5, // Lower left triangle
// 	3, 2, 4, // Lower right triangle
// 	5, 4, 1 // Upper triangle
// };

// // Vertices coordinates
// GLfloat vertices[] =
// { //     COORDINATES     /        COLORS      /   TexCoord  //
// 	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
// 	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
// 	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
// 	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
// 	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
// };

// // Indices for vertices order
// GLuint indices[] =
// {
// 	0, 1, 2,
// 	0, 2, 3,
// 	0, 1, 4,
// 	1, 2, 4,
// 	2, 3, 4,
// 	3, 0, 4
// };

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.24f,	
	-0.5f, 0.0f, -0.5f,     0.83f, 0.80f, 0.44f,	
	 0.5f, 0.0f, -0.5f,     0.23f, 0.70f, 0.94f,	
	 0.5f, 0.0f,  0.5f,     0.23f, 0.70f, 0.55f,	
	 0.0f, 0.8f,  0.0f,     0.92f, 0.16f, 0.76f,	
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};



int main()
{
	// INITIALIZATION * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(width, height, "mywindow", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);


	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generate Shader Object using vertex shader from default.vert, 
	// and fragment shader from default.frag.
	Shader shaderProgram("C:\\Users\\sylvi\\Desktop\\opengl-cpp-template-master\\opengl-cpp-template-master\\default.vert", "C:\\Users\\sylvi\\Desktop\\opengl-cpp-template-master\\opengl-cpp-template-master\\default.frag");

	// Make and bind Vertex Array Object
	VAO VAO1;
	// Binding - making a certain object the current object. When something modifies 
	// an object, it modifies the current object. 
	// The GL_ARRAY_BUFFER is the kind of buffer we need for the vertex buffer.
	VAO1.Bind();

	// Make Vertex Buffer Object and link to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Make Elements Buffer Object and link to indices
	EBO EBO1(indices, sizeof(indices));

	// Link VBO to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	// Unbind unused buffers
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Enable depth based rendering (order triangle rendering based on position)
	glEnable(GL_DEPTH_TEST);

	// Create a camera object - width, height, position
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clear the back buffer and assign colour
		// Also clear the depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Tell OpenGL what shader to use
		shaderProgram.Activate();


		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		// // Create a model of type mat4
		// glm::mat4 model = glm::mat4(1.0f);
		// glm::mat4 view = glm::mat4(1.0f);
		// glm::mat4 proj = glm::mat4(1.0f);

		// // Rotate the model
		// model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

		// // Move the whole world (same as if the camera moved)
		// view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		// // Define near and far clipping distances
		// proj = glm::perspective(glm::radians(45.0f), (float)(width / height), 0.1f, 100.0f);

		// // Get the uniform from the vertex shader
		// int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		// // Input the location then 1, then GL_FALSE since we don't want 
		// // OpenGL to transpose them, and then 'value_ptr' which gives the pointer of the 
		// // model matrix instead of the data inside it.
		// glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		// int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		// glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		// glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		// // This edits a uniform value, only run it 
		// // AFTER ACTIVATING THE SHADER PROGRAM. 1f since one float is the input
		// glUniform1f(uniID, 0.5f);
		// Bind the VAO 
		VAO1.Bind();

		// Tell OpenGL to draw our vertices
		// Arg1 - the type of primitive
		// Arg2 - the index of the vertices - 0
		// Arg3 - the amount of vertices - 3
		// glDrawArrays(GL_TRIANGLES, 0, 3);
		// glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		// 3D rendering - Tell OpenGL to draw the vertices
		glDrawElements(GL_TRIANGLE_STRIP, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

		// Swap the buffers to ensure that the image is updated! 
		// VERY IMPORTANT - EFFECIVELY PUSHING CHANGES
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all objects we have created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// Delete window 
	glfwDestroyWindow(window);
	// Terminate GLFW 
	glfwTerminate();
	return 0;
}

