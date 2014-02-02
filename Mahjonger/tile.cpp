//
//  tile.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "tile.h"

Tile::Tile(int type){
    
}

void Tile::flip(){
    visible=!visible;
}

void Tile::render(){
    GLfloat vertices[] =
        {1,1,0, 1,0,0,
        0,1,0, 0,0,0,
        0,0,1, 1,0,1,
        1,1,1, 0,1,1};
    GLubyte indices[] = {0,1,2,3,4,1,5,6,4,7,2,6,0,1};
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_BYTE, indices);
}