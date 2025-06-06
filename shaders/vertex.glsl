#version 410 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;// Vertex color input

out vec3 ourColor;// Output color to the fragment shader

void main()
{
    // Pass the vertex position to the fragment shader
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor;// Pass the vertex color to the fragment shader
    // shade of red
}