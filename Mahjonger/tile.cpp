//
//  tile.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "tile.h"
#include "libpngHook.h"

Tile::Tile(int type, GLuint* texture){
    _visible=1;
    _type=type;
    _texture=texture;
}

void Tile::flip(){
    _visible=!_visible;
}

void Tile::render(){
    GLfloat vertices[] =
        {1,1,0, 1,0,0,
        0,1,0, 0,0,0,
        0,0,1, 1,0,1,
        1,1,1, 0,1,1};
    GLubyte indices[] = {0,1,2,3,4,1,5,6,4,7,2,6,0,1};
    GLfloat texcoords[] = {0.75,0.75, 0.75,0.25, 0.25,0.75, 0.25,0.25, 0,0, 1,0, 1,1, 0,1};
    
    
    static GLuint texture (png_texture_load("/Users/Wolfie/Desktop/tile2.png", nullptr, nullptr));
    glEnable(GL_TEXTURE_2D);
    glClientActiveTexture(texture);
    
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_BYTE, indices);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

