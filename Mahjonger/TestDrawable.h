//
//  TestDrawable.h
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-27.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__TestDrawable__
#define __Mahjonger__TestDrawable__

#include <iostream>
#include "Drawable.h"

namespace Mahjonger
{
	class TestDrawable : public Drawable
	{
	public:
		TestDrawable(ShaderProgram *program, ArrayBuffer *ibuffer, ElementArrayBuffer *vbuffer);
		virtual ~TestDrawable();
		
		virtual void draw();
	};
}

#endif /* defined(__Mahjonger__TestDrawable__) */
