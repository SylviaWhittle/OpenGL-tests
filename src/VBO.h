#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include <glad/glad.h>
class VBO {
    public:
        GLuint ID;
        // Size of vertices is in the GLsizeiptr since 
        // that is what OpenGL uses for sizes in bytes
        VBO(GLfloat* vertices, GLsizeiptr size); 

        void Bind();
        void Unbind();
        void Delete();
};
#endif
