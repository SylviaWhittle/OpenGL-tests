#version 330 core
// Take input aPos using layout location 0
// Layouts help read the vertex data
// We are saying that on the 0th layout htere is a vec3 datatype for positions 
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

// Need to pass the colour to the fragment shader, so we
// output it
out vec3 color;

// Uniforms are like global variables that can be accessed outside the shader 
// without the use of a VAO
// uniform float scale;

// uniform mat4 model;
// uniform mat4 view;
// uniform mat4 proj;

uniform mat4 camMatrix;

void main()
{
   // Arbitrary 1 for 4th dimension
   // gl_Position is a keyword in OpenGL and knows to use it as the position for the vertex
   //gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
   
   // 3D matrix position
   gl_Position = camMatrix * vec4(aPos, 1.0);

   color = aColor;
}
