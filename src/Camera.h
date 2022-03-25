#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "shaderClass.h"

class Camera {
    public:
        glm::vec3 Position;
        glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 cameraMatrix = glm::mat4(1.0f);

        bool firstClick = true;

        int width;
        int height;
        
        float speed = 0.02f;
        float sensitivity = 100.0f;

        Camera(int width, int height, glm::vec3 position);

        // Update camera matrix to vertex shader
        void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

        // Sends camera matrix to a shader
        void Matrix(Shader& shader, const char* uniform);
        // User inputs
        void Inputs(GLFWwindow* window);
};

#endif