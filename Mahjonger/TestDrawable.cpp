//
//  TestDrawable.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-27.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "TestDrawable.h"
#include "TestVertex.h"

using namespace Mahjonger;

TestDrawable::TestDrawable(ShaderProgram *program, ArrayBuffer *ibuffer, ElementArrayBuffer *vbuffer):
	Drawable(program, ibuffer, vbuffer)
{
	int tmp;
	glGetProgramiv(program->glHandle(), GL_ATTACHED_SHADERS, &tmp);
	std::cout << "Attached Shaders: " << tmp << std::endl;
	glGetProgramiv(program->glHandle(), GL_ACTIVE_ATTRIBUTES, &tmp);
	std::cout << "Active Attributes: " << tmp << std::endl;
	glGetProgramiv(program->glHandle(), GL_ACTIVE_UNIFORMS, &tmp);
	std::cout << "Active Uniforms: " << tmp << std::endl;
}

TestDrawable::~TestDrawable()
{
	
}

void TestDrawable::draw()
{
	program->use();
	//ibuffer->bind();
	//vbuffer->bind();
	
	struct {
		GLint position, color;
	} attribIndices = {
		program->attribIndex("position"),
		program->attribIndex("color")
	};
	
	glEnableVertexAttribArray(attribIndices.position);
	glEnableVertexAttribArray(attribIndices.color);
	
	//glVertexAttribPointer(attribIndices.position, 2, GL_FLOAT, GL_FALSE, sizeof(TestVertex), (const GLvoid*)offsetof(TestVertex, position));
	//glVertexAttribPointer(attribIndices.color, 3, GL_FLOAT, GL_FALSE, sizeof(TestVertex), (const GLvoid*)offsetof(TestVertex, color));
	
	//glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_BYTE, (const GLvoid*)0);
	
	glBegin(GL_TRIANGLE_STRIP);
	{
		glVertexAttrib2f(attribIndices.position, -1, -1);
		glVertexAttrib4f(attribIndices.color, 0, 0, 0, 1);
		
		glVertexAttrib2f(attribIndices.position, 1, -1);
		glVertexAttrib4f(attribIndices.color, 1, 0, 0, 1);
		
		glVertexAttrib2f(attribIndices.position, -1, 1);
		glVertexAttrib4f(attribIndices.color, 0, 1, 0, 1);
		
		glVertexAttrib2f(attribIndices.position, 1, 1);
		glVertexAttrib4f(attribIndices.color, 0, 0, 1, 1);
	}
	glEnd();
	
	glDisableVertexAttribArray(attribIndices.position);
	glDisableVertexAttribArray(attribIndices.color);
}
