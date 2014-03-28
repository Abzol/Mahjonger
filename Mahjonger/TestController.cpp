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
	vsh = VertexShader("vertex.vertex");
	fsh = FragmentShader("fragment.fragment");
	program = ShaderProgram(vsh, fsh);
	
	squareVBuffer = ArrayBuffer(vertices, sizeof(vertices)/sizeof(vertices[0]));
	squareIBuffer = ElementArrayBuffer(indices, sizeof(indices)/sizeof(indices[0]));
	
	thing = new TestDrawable(program, squareVBuffer, squareIBuffer);
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
