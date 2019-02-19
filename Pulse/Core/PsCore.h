#pragma once

#include "PsCommon.h"
#include "Window/Window.h"
#include "Rendering/Renderer.h"

namespace Ps {

	class PULSE_API Core
	{

	public:

		PULSE_API Core(const int userWidth = 1280, const int userHeight = 720, const std::string& userTitle = "No Title");
		PULSE_API ~Core();
		PULSE_API PsResult init(const int windowWidth, const int windowHeight, const std::string& applicationName);

	
	private:
		
		Window		m_window;
		Renderer	m_renderer;
		bool		m_initialized;
		std::shared_ptr<spdlog::logger>		coreLogger;
		std::shared_ptr<spdlog::logger>		clientLogger;


		PsResult	initLibrairies();
		void		terminateLibrairies();
		void		checkVulkanSupport();

	};


}
