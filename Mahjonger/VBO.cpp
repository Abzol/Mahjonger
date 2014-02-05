//
//  whatsUpFuckers.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-03.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//


#include "VBO.h"
#include <fstream>

GLuint makeBuffer(GLenum target, const void *buffer_data, GLsizei buffer_size) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(target, buffer);
    glBufferData(target, buffer_size, buffer_data, GL_STATIC_DRAW);
    return buffer;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
GLuint make_shader(GLenum type, const char *filename){
    GLint length;
    //GLchar *source = file_contents(filename, &length);
    
    
    
    std::ifstream file (filename,std::ios::in);
	if (file.good() ==false)
	{
		return 0;
	}
    
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	GLchar* source = new GLchar[size];
	file.seekg(0,std::ios::beg);
	file.read(source,size);
	file.close();
    
    GLuint shader;
    GLint shader_ok;
    
    if (!source)
        return 0;
    
    shader = glCreateShader(type);
    glShaderSource(shader, 1, (const GLchar**)&source, &length);
    free(source);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_ok);
    if (!shader_ok) {
        fprintf(stderr, "Failed to compile %s:\n", filename);
        show_info_log(shader, glGetShaderiv, glGetShaderInfoLog);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void show_info_log(GLuint object, PFNGLGETSHADERIVPROC glGet__iv,PFNGLGETSHADERINFOLOGPROC glGet__InfoLog)
{
    GLint log_length;
    char* log;
    
    glGet__iv(object, GL_INFO_LOG_LENGTH, &log_length);
    log = reinterpret_cast<char*>(malloc(log_length));
    glGet__InfoLog(object, log_length, NULL, log);
    fprintf(stderr, "%s", log);
    free(log);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
GLuint make_program(GLuint vertex_shader, GLuint fragment_shader){
    GLint program_ok;
    
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    
    glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
    if (!program_ok) {
        fprintf(stderr, "Failed to link shader program:\n");
        show_info_log(program, glGetProgramiv, glGetProgramInfoLog);
        glDeleteProgram(program);
        return 0;
    }
    return program;
}
