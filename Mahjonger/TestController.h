//
//  TestController.h
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__TestController__
#define __Mahjonger__TestController__

#include <iostream>
#include "Controller.h"
#include "TestDrawable.h"

namespace Mahjonger
{
	class TestController : public Controller
	{
	public:
		TestController(App *app);
		virtual ~TestController();
		
		virtual Mode mode() const { return DefaultMode; }
		
		virtual void tick();
		virtual void draw();
		
	protected:
		VertexShader *vsh;
		FragmentShader *fsh;
		ShaderProgram *program;
		
		ElementArrayBuffer *squareIBuffer;
		ArrayBuffer *squareVBuffer;
		
		TestDrawable *thing;
	};
}

#endif /* defined(__Mahjonger__TestController__) */
