//
//  TestDrawable.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-27.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "TestDrawable.h"

using namespace Mahjonger;

TestDrawable::TestDrawable(ShaderProgram *program, ArrayBuffer *ibuffer, ElementArrayBuffer *vbuffer):
	Drawable(program, ibuffer, vbuffer)
{
	
}

TestDrawable::~TestDrawable()
{
	
}

void TestDrawable::draw()
{
	program->use();
	
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(1, 1, 1);
		glColor3f(1, 0, 0);
		
		glVertex3f(-1, 1, 1);
		glColor3f(0, 1, 0);
		
		glVertex3f(1, -1, 1);
		glColor3f(0, 0, 1);
	}
	glEnd();
	
	/*GLuint positionIndex = program->attribLocation("position");
	glEnableVertexAttribArray(positionIndex);
    glVertexAttribPointer(positionIndex, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, (void*)0);
	
	//ibuffer->bind();
	vbuffer->bind();
	glDrawElements(GL_TRIANGLE_STRIP, 1, GL_UNSIGNED_BYTE, indices);
	
	glDisableVertexAttribArray(positionIndex);*/
}
