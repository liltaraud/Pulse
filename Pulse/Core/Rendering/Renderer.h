#pragma once

#include "PsCommon.h"
#include "Window/Window.h"
#include "API/VkAPI.h"

namespace Ps {

	class PULSE_API Renderer
	{
	public:
		Renderer();
		~Renderer();

		PsResult		Init(Ps::Window& ext_Window);

	private:
		Ps::VkAPI			graphicsAPI;
		Ps::Window			*m_TargetWindowHandle;

	};

}