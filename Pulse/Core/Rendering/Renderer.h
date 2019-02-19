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

		PsResult		init(const Window& extWindow);
		const VkAPI&	getGraphicsAPI() const;

	private:
		VkAPI			m_graphicsAPI;
		const Window	*m_targetWindowHandle;

	};

}