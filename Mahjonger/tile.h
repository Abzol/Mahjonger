//
//  tile.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-02.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__tile__
#define __Mahjonger__tile__

class Tile {
public:
    Tile(int type);
    void draw();
private:
    int type;
};

#endif /* defined(__Mahjonger__tile__) */
