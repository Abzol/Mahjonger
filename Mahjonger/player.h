//
//  player.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__player__
#define __Mahjonger__player__

#include "tile.h"
#include <vector>

class Player {
    Player();
    ~Player();
    int getScore();
    std::vector<Tile> getHand();
public:
    int score;
    std::vector<Tile> hand;
};

#endif /* defined(__Mahjonger__player__) */
