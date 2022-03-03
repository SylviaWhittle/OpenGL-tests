#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &ID);
}

// Link VBO to VAO using a layout
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
    VBO.Bind();
    // Tell OpenGL how to read the VBO
	// First pass the index of the vertex attribute that we want to use
	// A vertex attribute is a way to communicate with a Vertex Shader from outside.
	// First input - Position of the vertex attribute - 0
	// Second input - how many values per vertex - 3
	// Third input - Data types
	// Fourth input - only relevant if integers
	// Fifth input - stride of the vertices - the amount of data in each vertex
	// Sixth input - offset - pointer to where vertices begin in the array
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, stride, offset);
    // Enable using the vertex attribute
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Bind() {
    glBindVertexArray(ID);
}
void VAO::Unbind() {
    glBindVertexArray(0);
}
void VAO::Delete() {
    glDeleteVertexArrays(1, &ID);
}
