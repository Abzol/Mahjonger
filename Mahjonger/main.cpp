//
//  main.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "windowManager.h"

//basically copypasted glfw example, only adding a clClear call and vsync

int main(int argc, const char* argv[])
{
    auto window = WindowManager::get().getWindow();
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glfwSwapInterval(1);
    
    glClearColor(0, 0, 0, 1);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
