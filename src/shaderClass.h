// Here we declare our shader class and other functions associated with it
#ifndef SHADER_CLASS_H // This "if" makes sure we do not define them twice
#define SHADER_CLASS_H
//#include <C:\Users\sylvi\Desktop\opengl-cpp-template-master\opengl-cpp-template-master\include\glad\glad.h>
#include <glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);
class Shader {
    
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();
    private:
        void compileErrors(unsigned int shader, const char* type);
};

#endif



