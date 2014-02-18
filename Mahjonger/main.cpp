//
//  main.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include <iostream>
// Including glew redefines OpenGL functions in a weird way I can't handle
// It somehow manages to break passing OpenGL functions to templates, f.ex.
//#include <glew.h>
#include <glfw3.h>
#include "Shader.h"
#include "ShaderProgram.h"
#include "VBO.h"
#include "tile.h"
#include "libpngHook.h"

int main(int argc, const char* argv[])
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "Mahjonger", NULL, NULL);
    
    if (!window){
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
	// See note above about GLEW
    /*if( glewInit() != GLEW_OK ) {
        fputs("Could not initialize extensions.\n", stderr);
        return 1;
    }*/
    
    glfwSwapInterval(1);
    
    glClearColor(0, 0, 0, 1);
    
    Tile tile(2);
    
    glScalef(0.5,0.5,0.5);
    glRotatef(70, 1, 0, 0);
    
    int time=0;
    
    gprog tilepkg;
    
    
    
    
    int width, height;
    int* ww = &width;
    int* hw = &height;
    
    tilepkg.vbuffer= makeBuffer(GL_ARRAY_BUFFER, vertices, sizeof(vertices));
    tilepkg.ibuffer= makeBuffer(GL_ELEMENT_ARRAY_BUFFER, indices, sizeof(indices));
    tilepkg.texture= png_texture_load("tile2.png", ww, hw);
	tilepkg.vshader = new VertexShader("vertex.vertex");
	tilepkg.fshader = new FragmentShader("fragment.fragment");
    //tilepkg.vshader= make_shader(GL_VERTEX_SHADER, "vertex.vertex");
    //tilepkg.fshader= make_shader(GL_FRAGMENT_SHADER, "fragment.fragment");

    if(!tilepkg.vshader || !tilepkg.fshader)
	{
		std::cerr << "Couldn't load shaders" << std::endl;
		std::cerr << "VSH Compile: " << tilepkg.vshader->compileResult << std::endl;
		std::cerr << "FSH Compile: " << tilepkg.fshader->compileResult << std::endl;
        return 2;
	}
    
    //tilepkg.program= make_program(tilepkg.vshader, tilepkg.fshader);
	tilepkg.program = new ShaderProgram(tilepkg.vshader, tilepkg.fshader);
    if(!tilepkg.program)
	{
		std::cerr << "Couldn't make a program." << std::endl;
		std::cerr << "Linking: " << tilepkg.program->linkResult << std::endl;
		std::cerr << "Validation: " << tilepkg.program->validateResult << std::endl;
		return 3;
	}
    
    /*tilepkg.uniforms.fadefactor = glGetUniformLocation(tilepkg.program, "fade_factor");
    tilepkg.uniforms.textures[0] = glGetUniformLocation(tilepkg.program, "textures[0]");
    tilepkg.uniforms.textures[1] = glGetUniformLocation(tilepkg.program, "textures[1]");*/
    
    tilepkg.uniforms.position = glGetAttribLocation(tilepkg.program->glHandle(), "position");
    
    
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_EDGE);
    
    
    
    
    
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glEnable(GL_CULL_FACE);
    glCullFace(GL_FRONT);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        tile.render(tilepkg);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
		glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Poll for and process events */
        glfwPollEvents();
        
        ++time;
    }
    
    glfwTerminate();
    return 0;
}
