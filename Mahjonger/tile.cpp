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

void Tile::render(gprog pkg){

    pkg.program->use();
	pkg.program->setUniform("fade_factor", (GLfloat)pkg.fadefactor);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, pkg.program->uniformLocation("textures[0]"));
    pkg.program->setUniform("textures[0]", (GLint)0);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, pkg.program->uniformLocation("textures[1]"));
    pkg.program->setUniform("textures[1]", (GLint)1);
    
    glBindBuffer(GL_ARRAY_BUFFER, pkg.vbuffer);
    glEnableVertexAttribArray(pkg.uniforms.position);
    glVertexAttribPointer(pkg.uniforms.position, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, (void*)0);
 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pkg.ibuffer);
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_BYTE, (void*)0);
    
    glDisableVertexAttribArray(pkg.uniforms.position);

}
