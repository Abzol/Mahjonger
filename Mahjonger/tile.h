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

class Tile {
public:
    Tile(int type, GLuint* texture);
    void render();
    void flip();
    
private:
    int _type;
    bool _visible;
    GLuint* _texture;
};

#endif /* defined(__Mahjonger__tile__) */
