//
//  App.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "App.h"
#include <stdexcept>
#include "Controller.h"

using namespace Mahjonger;

App::App()
{
	glfwInit();
	
	window = glfwCreateWindow(800, 600, "Mahjonger", NULL, NULL);
	if(!window)
		throw std::runtime_error("Couldn't create a Window");
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
}

App::~App()
{
	glfwTerminate();
}

void App::run()
{
	while(!quitting && !glfwWindowShouldClose(window))
	{
		// Clear
		glClearColor(0, 0, 1, 1);
		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
		
		// Note: This will crash if controllers is empty!
		if(!controllers.empty())
		{
			// Check mode flags and tick/draw ranges
			std::deque<Controller*>::iterator tickStartIt;
			std::deque<Controller*>::iterator drawStartIt;
			for(std::deque<Controller*>::reverse_iterator it = controllers.rbegin(); it != controllers.rend(); ++it)
			{
				Controller::Mode mode = (*it)->mode();
				
				// If the mode contains either Passthrough flag,
				if(!(mode & Controller::PassthroughTick))
					tickStartIt = --(it.base());
				if(!(mode & Controller::PassthroughDraw))
					drawStartIt = --(it.base());
			}
			
			// Tick
			for(std::deque<Controller*>::iterator it = tickStartIt; it != controllers.end(); ++it)
				(*it)->tick();
			
			// Draw
			for(std::deque<Controller*>::iterator it = drawStartIt; it != controllers.end(); ++it)
				(*it)->draw();
		}
		
		// Finish
		glfwSwapBuffers(window);
		
		// Update
		glfwPollEvents();
	}
}

void App::quit()
{
	quitting = true;
}

void App::pushController(Controller *controller)
{
	std::deque<Controller*>::iterator it = std::find(controllers.begin(), controllers.end(), controller);
	if(it == controllers.end())
	{
		controller->app = this;
		controllers.push_back(controller);
	}
}

void App::popController(Controller *controller)
{
	std::deque<Controller*>::iterator it = std::find(controllers.begin(), controllers.end(), controller);
	if(it != controllers.end())
		controllers.erase(it);
}
