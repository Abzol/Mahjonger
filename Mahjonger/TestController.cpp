//
//  TestController.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "TestController.h"

using namespace Mahjonger;

TestController::TestController(App *app):
	Controller(app)
{
	
}

TestController::~TestController()
{
	
}

void TestController::tick()
{
	std::cout << "Tick...";
}

void TestController::draw()
{
	std::cout << " Draw!" << std::endl;
}
