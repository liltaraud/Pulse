#pragma once

#include "PsCommon.h"
#include "Window/Window.h"

namespace Ps {

	class PULSE_API Core
	{

	public:

		PULSE_API struct InitInfo
		{
			bool			fullscreen;
			int				windowWidth;
			int				windowHeight;
			std::string		windowTitle;
			PsRenderingMode	renderingMode;
		};

		PULSE_API Core();
		PULSE_API ~Core();
		PULSE_API PsResult Init(const InitInfo info);
		PULSE_API static const InitInfo GetInitInfo(const bool inputfs, const int inputWidth, const int inputHeight, const std::string inputTitle, const PsRenderingMode inputRenderMode);
		

	
	private:
		Ps::Window	*window;
		static bool initialized;


		PsResult	InitLibrairies();
		void		TerminateLibrairies();
	};


}
