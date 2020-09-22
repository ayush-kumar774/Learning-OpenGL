#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
void createTriangle() {
    float positions[6] = {
        -0.5f, -0.5f ,
         0.0f,  0.5f ,
         0.5f, -0.5f
    }; 
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    std::string vertexShader =
        "#version 330 core\n"
        "\n"
        "layout (location = 0 ) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        " gl_Position = position; \n"
        "}\n";
    std::string fragmentShader =
        "#version 330 core\n"
        "\n"
        "layout (location = 0 ) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        " color = vec4(1.0, 0.0, 0.0, 1.0); \n"
        "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

   /* std::cout << vertexShader << std::endl;
    std::cout << fragmentShader << std::endl;*/
    
    //glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteProgram(shader);
}
