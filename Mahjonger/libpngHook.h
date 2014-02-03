//
//  libpngHook.h
//  Mahjonger
//
//  Created by Felix Mossberg on 2014-02-03.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__libpngHook__
#define __Mahjonger__libpngHook__

#include <glfw3.h>
#include <png.h>
#include <cstdlib>

GLuint png_texture_load(const char * file_name, int * width, int * height);

#endif /* defined(__Mahjonger__libpngHook__) */
