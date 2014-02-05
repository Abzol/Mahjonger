//
//  tile.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__tile__
#define __Mahjonger__tile__

#include <glfw3.h>

struct gprog{
    GLuint vbuffer, ibuffer, texture, vshader, fshader, program;
    struct {
        GLint fadefactor, textures[2], position;
    }uniforms;
    GLfloat fadefactor;
};

class Tile {
public:
    Tile(int type);
    void render(gprog pkg);
    void flip();
    
private:
    int _type;
    bool _visible;
};

static const GLfloat vertices[] =
    {1,1,0, 1,0,0,
    0,1,0, 0,0,0,
    0,0,1, 1,0,1,
    1,1,1, 0,1,1};

static const GLubyte indices[] = {0,1,2,3,4,1,5,6,4,7,2,6,0,1};

#endif /* defined(__Mahjonger__tile__) */
