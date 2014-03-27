//
//  Drawable.h
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__Drawable__
#define __Mahjonger__Drawable__

#include <iostream>
#include "ShaderProgram.h"
#include "Buffer.h"

namespace Mahjonger
{
	class Drawable
	{
	public:
		Drawable(ShaderProgram *program, ArrayBuffer *vbuffer, ElementArrayBuffer *ibuffer);
		virtual ~Drawable();
		virtual void draw() = 0;
		
	protected:
		ShaderProgram *program;
		ArrayBuffer *vbuffer;
		ElementArrayBuffer *ibuffer;
	};
};

#endif /* defined(__Mahjonger__Drawable__) */
