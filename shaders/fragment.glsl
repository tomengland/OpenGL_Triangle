#version 410 core
out vec4 FragColor;
uniform vec4 vertexColor;// Uniform variable to receive color from vertex shader
void main()
{
    // Set the fragment color to yellow
    FragColor = vertexColor;
}