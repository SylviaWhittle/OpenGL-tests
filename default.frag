#version 330 core
out vec4 FragColor;

// Input the colour from the vertex shader
in vec3 color;

void main()
{
   // Give it a colour in RGBA format
   FragColor = vec4(color, 1.0f);
}