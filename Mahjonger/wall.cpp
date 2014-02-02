//
//  wall.cpp
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "wall.h"

Wall& Wall::get(){
    static Wall wall;
    return wall;
}

void Wall::setup(bool redfives){
    wall.clear();
    dead.clear();
    
    for (int i = 0; i<136; ++i){
        wall.push_back(Tile(0.25*i));
    }
}