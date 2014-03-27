//
//  TestController.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "TestController.h"
#include "TestVertex.h"

static const TestVertex vertices[] = {
	{-0.5, -0.5,	0, 0, 0, 1},
	{ 0.5, -0.5,	1, 0, 0, 1},
	{-0.5,  0.5,	0, 1, 0, 1},
	{ 0.5,  0.5,	0, 0, 1, 1},
};

static const GLubyte indices[] = {0, 1, 2, 3};

using namespace Mahjonger;

TestController::TestController(App *app):
	Controller(app)
{
	vsh = new VertexShader("vertex.vertex");
	fsh = new FragmentShader("fragment.fragment");
	program = new ShaderProgram(vsh, fsh);
	
	squareIBuffer = new ArrayBuffer(indices, sizeof(indices)/sizeof(indices[0]));
	squareVBuffer = new ElementArrayBuffer(vertices, sizeof(vertices)/sizeof(vertices[0]));
	
	thing = new TestDrawable(program, squareIBuffer, squareVBuffer);
}

TestController::~TestController()
{
	
}

void TestController::tick()
{
	
}

void TestController::draw()
{
	thing->draw();
}
