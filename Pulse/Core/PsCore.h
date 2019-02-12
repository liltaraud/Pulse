#pragma once

#include "PsCommon.h"
#include "Window/Window.h"
#include "Rendering/Renderer.h"

namespace Ps {

	class PULSE_API Core
	{

	public:

		PULSE_API struct InitInfo
		{
			bool			fullscreen;
			int				windowWidth;
			int				windowHeight;
			std::string		applicationName;
		};

		PULSE_API Core();
		PULSE_API ~Core();
		PULSE_API PsResult Init(const InitInfo info);
		PULSE_API static const InitInfo GetInitInfo(const bool inputfs, const int inputWidth, const int inputHeight, const std::string inputTitle);
		

	
	private:
		static bool s_Initialized;
		
		Ps::Window		*m_Window;
		Ps::Renderer	*m_Renderer;


		PsResult	InitLibrairies();
		void		TerminateLibrairies();
	};


}
