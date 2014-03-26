//
//  App.h
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__App__
#define __Mahjonger__App__

#include <iostream>
#include <glfw3.h>
#include <deque>

namespace Mahjonger
{
	class Controller;
	class App
	{
	public:
		App();
		virtual ~App();
		
		void run();
		void quit();
		
		void pushController(Controller *controller);
		void popController(Controller *controller = 0);
		
	protected:
		std::deque<Controller*> controllers;
		
		GLFWwindow *window;
		bool quitting;
	};
}

#endif /* defined(__Mahjonger__App__) */
