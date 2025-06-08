#include <fstream>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
// This is a simple OpenGL program that initializes a window and sets up a triangle.
// OpenGL 4.1, Core Profile
// Thomas England
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

int main()
{

    // glfw setup
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    float vertices[] = {
        // triangle with colors
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// bottom left
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,// bottom right
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };


    // glfw window creation
    GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Bro!", nullptr,
                                          nullptr);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    Shader ourShader("shaders/vertex.glsl", "shaders/fragment.glsl");
    // set up vertex data (and buffer(s)) and configure vertex attributes
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
        reinterpret_cast<void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // Note that this is allowed. The call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so after we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO after so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray, so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    while (!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);
        //render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // activate the shader program
        ourShader.use();


        // render the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // check events and swap buffers.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

