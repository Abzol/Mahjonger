//
//  windowManager.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "windowManager.h"

WindowManager& WindowManager::get(){
    static WindowManager winman;
    return winman;
}

GLFWwindow* WindowManager::getWindow(){
    return window;
}



WindowManager::WindowManager(){
    GLFWwindow* winptr;
    winptr = glfwCreateWindow(800, 600, "Mahjonger", NULL, NULL);
    if (!winptr)
    {
        glfwTerminate();
    }
    window = winptr;
}