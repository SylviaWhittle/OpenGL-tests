#include "VBO.h"

// Constructor for the VBO 
VBO::VBO(GLfloat* vertices, GLsizeiptr size) {
    glGenBuffers(1, &ID); 
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    // Store the vertices - type of buffer, total size of the buffer in bytes,
	// and the data itself.
	// Choose between STREAM, STATIC, DYNAMIC
	// STREAM - Vertices modified once and used a few times
	// STATIC - Vertices modified once and used many, many times.
	// DYNAMIC - Vertices modified many times and used many, many times.
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
    glDeleteBuffers(1, &ID);
}