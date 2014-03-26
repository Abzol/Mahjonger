//
//  Controller.h
//  Mahjonger
//
//  Created by Johannes Ekberg on 2014-03-26.
//  Copyright (c) 2014 Hakurou46. All rights reserved.
//

#ifndef __Mahjonger__Controller__
#define __Mahjonger__Controller__

#include <iostream>

namespace Mahjonger
{
	class App;
	class Controller
	{
	public:
		friend class App;
		
		enum Mode {
			PassthroughTick = 0x01,		///< Let the next controller in the chain update as well
			PassthroughDraw = 0x02,		///< Let the next controller in the chain draw as well
			
			DefaultMode = 0x0			///< Default mode flags; may change later, maybe
		};
		
		Controller(App *app);
		virtual ~Controller();
		
		virtual Mode mode() const { return DefaultMode; }
		
		virtual void tick() = 0;
		virtual void draw() = 0;
		
	protected:
		App *app;
	};
}

#endif /* defined(__Mahjonger__Controller__) */
