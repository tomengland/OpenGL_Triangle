#version 410 core
layout(location = 0) in vec3 aPos;

void main()
{
    // Pass the vertex position to the fragment shader
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}