#version 410 core
out vec4 FragColor;
in vec3 ourColor;

void main()
{
    // Set the fragment color to yellow
    FragColor = vec4(ourColor, 1.0); // Use the color passed from the vertex shader
}