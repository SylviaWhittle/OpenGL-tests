#include"shaderClass.h"

// Read text file and output a string with everything in the file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor for the shader program
// Constructs it from two shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    std::cout << "btest0";

	// Read files: vertexFile and fragmentFile, store the results in strings
	std::string vertexCode = get_file_contents(vertexFile);
    std::cout << vertexCode;
	std::string fragmentCode = get_file_contents(fragmentFile);
    std::cout << "btest2";

    // Convert to char* format
    const char* vertexSource = vertexCode.c_str();
    std::cout << "btest3";
	const char* fragmentSource = fragmentCode.c_str();
    std::cout << "btest4";

    

    // Create Vertex Shader object reference
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach Vertex Shader to the object
    // and link to the source code (1 means one string for whole shader)
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    // Compile to machine code
    glCompileShader(vertexShader);
    // Check for errors
    compileErrors(vertexShader, "VERTEX");  
    

    // Create Fragment Shader object reference
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // Attach Fragment Shader to the object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    // Compile to machine code
    glCompileShader(fragmentShader);
    // Check for errors
    compileErrors(fragmentShader, "FRAGMENT");

    

    // Create Shader Program object reference
    ID = glCreateProgram();
    // Attach Vertex Shader and Fragment Shader to Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    // Link shaders into the Shader Program
    glLinkProgram(ID);
    // Check for errors
    compileErrors(ID, "PROGRAM");


    // Clean up objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    

}

// Activate Shader Program
void Shader::Activate() {
    glUseProgram(ID);
}

// Delete Shader Program
void Shader::Delete() {
    glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type) {
    GLint hasCompiled;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_COMPILATION_ERROR for: " << type << "\n" << std::endl;
        }
    }
    else {
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_LINKING_ERROR for: " << type << "\n" << std::endl;
        }
    }
}