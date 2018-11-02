#pragma once

#include "PsCommon.h"
#include "Core/Window/Window.h"
#include "Core/PsCore.h"

namespace Ps {

	class Core {

	public:

		PULSE_CORE struct InitInfo {
			bool	fullscreen;
		};

		PULSE_CORE PsResult Init(const InitInfo info);
		

	
	private:
		Ps::Window	*window;
	};


}
