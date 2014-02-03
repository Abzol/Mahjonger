//
//  main.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "windowManager.h"
#include "tile.h"
#include "libpngHook.h"

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
    
    int height, width;
    int* hw = &height;
    int* ww = &width;
    
    GLuint* east = new GLuint (png_texture_load("/Users/Wolfie/Desktop/tile.png", ww, hw));
    GLuint* east_s = new GLuint (png_texture_load("/Users/Wolfie/Desktop/tile.png", ww, hw));
    
    
    //glEnable(GL_TEXTURE_2D);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glfwSwapInterval(1);
    
    glClearColor(0, 0, 0, 1);
    
    //glClientActiveTexture(*east);
    //glBindTexture(GL_TEXTURE_2D, *east);
    
    Tile tile(2, east);
    
    glScalef(0.5,0.5,0.5);
    glRotatef(70, 1, 0, 0);
    
    int time=0;
    
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glPushMatrix();
        //glBindTexture(GL_TEXTURE_2D, *east);
        glRotatef(time,0,0,1);
        glTranslatef(-0.5,-0.5,0);
            tile.render();
        glPopMatrix();
        
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
