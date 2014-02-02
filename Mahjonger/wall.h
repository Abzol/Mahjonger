//
//  wall.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__wall__
#define __Mahjonger__wall__

#include <vector>
#include "tile.h"

class Wall {
public:
    static Wall& get();
    void setup(bool redfives);   //sets the walls up.
    Tile* draw();   //draws a tile
    Tile* dora();   //flips a new dora, checks for abortive draws, then does the dead wall draw thing. You know. Ironically doesn't tell you the new dora.
    void render();  //renders the entire wall
    
    
private:
    Wall(){};
    Wall(const Wall&);
    Wall operator= (const Wall&);
    std::vector<Tile> wall;
    std::vector<Tile> dead;
};
#endif /* defined(__Mahjonger__wall__) */
