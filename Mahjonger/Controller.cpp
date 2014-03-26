//
//  Controller.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "Controller.h"
#include "App.h"

using namespace Mahjonger;

Controller::Controller(App *app):
	app(app)
{
	
}

Controller::~Controller()
{
	// Deleting a controller should pop it from the stack
	// Without this, you'd have to remember to pop every deleted controller
	// yourself, or you'd have an unnecessary access violation crash
	if(app)
		app->popController(this);
}
