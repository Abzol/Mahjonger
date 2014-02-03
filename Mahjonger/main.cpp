//
//  main.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "tile.h"
#include "libpngHook.h"
#include "VBO.h"

//basically copypasted glfw example, only adding a clClear call and vsync

int main(int argc, const char* argv[])
{
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Mahjonger", NULL, NULL);
    
    if (!window){
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glfwSwapInterval(1);
    
    glClearColor(0, 0, 0, 1);
    
    Tile tile(2);
    
    glScalef(0.5,0.5,0.5);
    glRotatef(70, 1, 0, 0);
    
    int time=0;
    
    
    
    
    
    
    
    
    
    
    int width, height;
    int* ww = &width;
    int* hw = &height;
    
    GLuint vbuffer= makeBuffer(GL_ARRAY_BUFFER, vertices, sizeof(vertices));
    GLuint ibuffer= makeBuffer(GL_ARRAY_BUFFER, indices, sizeof(indices));
    GLuint texture= png_texture_load("/Users/Wolfie/Desktop/tile2.png", ww, hw);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);

    
    
    
    
    
    
    
    
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        tile.render();
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Poll for and process events */
        glfwPollEvents();
        
        ++time;
    }
    
    glfwTerminate();
    return 0;
}
