//
//  tile.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "tile.h"
#include "libpngHook.h"

Tile::Tile(int type){
    _visible=1;
    _type=type;
}

void Tile::flip(){
    _visible=!_visible;
}

void Tile::render(){

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_BYTE, indices);
    
    glDisableClientState(GL_VERTEX_ARRAY);
}
