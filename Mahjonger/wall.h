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

class Wall {
public:
    static Wall& get();
private:
    Wall();
    Wall(const Wall&);
    Wall operator= (const Wall&);
    
};

#endif /* defined(__Mahjonger__wall__) */
