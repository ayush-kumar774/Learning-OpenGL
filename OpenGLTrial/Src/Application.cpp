#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Vertexbuffer.h"
#include "Shader.h"

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glewInit();
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
    }
    //std::cout << glGetString(GL_VERSION) << std::endl;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        createTriangle(); // This function is defined in VertexBuffer.h

        // Generic way of rendering a triangle
        /*glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f,  0.5f);
        glVertex2f(0.5f,  -0.5f);
        glEnd();*/

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
         

        =
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
