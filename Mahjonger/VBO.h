//
//  whatsUpFuckers.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-03.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__whatsUpFuckers__
#define __Mahjonger__whatsUpFuckers__

#define GLEW_STATIC 1
#include <stdlib.h>
#include <stdio.h>
#include <glfw3.h>

GLuint makeBuffer(GLenum target, const void *buffer_data, GLsizei buffer_size);
GLuint make_shader(GLenum type, const char *filename);
void show_info_log(GLuint object, void(*glGet__iv)(GLuint,GLenum,GLint*),void(*glGet__InfoLog)(GLuint,GLsizei,GLsizei*,GLchar*));
GLuint make_program(GLuint vertex_shader, GLuint fragment_shader);

#endif /* defined(__Mahjonger__whatsUpFuckers__) */
