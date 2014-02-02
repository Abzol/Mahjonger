//
//  windowManager.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__windowManager__
#define __Mahjonger__windowManager__

#include <glfw3.h>

class WindowManager {
public:
    static WindowManager& get();
    GLFWwindow* getWindow();
private:
    WindowManager();
    WindowManager(const WindowManager&);
    WindowManager operator= (const WindowManager&);
    GLFWwindow* window;
};

#endif /* defined(__Mahjonger__windowManager__) */
