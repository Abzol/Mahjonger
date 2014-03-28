//
//  Drawable.cpp
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#include "Drawable.h"

using namespace Mahjonger;

Drawable::Drawable(ShaderProgram program, ArrayBuffer vbuffer, ElementArrayBuffer ibuffer):
	program(program), vbuffer(vbuffer), ibuffer(ibuffer)
{
	
}

Drawable::~Drawable()
{
	
}
