#pragma once

#include "PsCommon.h"
#include "Core/Window/Window.h"
#include "Core/PsCore.h"

namespace Ps {

	class Core {

	public:

		PULSE_CORE struct InitInfo
		{
			bool			fullscreen;
			int				windowWidth;
			int				windowHeight;
			std::string		windowTitle;
			PsRenderingMode	renderingMode;
		};

		PULSE_CORE Core();
		PULSE_CORE ~Core();
		PULSE_CORE PsResult Init(const InitInfo info);
		PULSE_CORE static const InitInfo GetInitInfo(const bool inputfs, const int inputWidth, const int inputHeight, const std::string inputTitle, const PsRenderingMode inputRenderMode);
		

	
	private:
		Ps::Window	*window;
		static bool initialized;


		PsResult	InitLibrairies();
		void		TerminateLibrairies();
	};


}
