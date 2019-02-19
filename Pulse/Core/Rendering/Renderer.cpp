#include "Renderer.h"

namespace Ps {

	Renderer::Renderer()
	{
	}

	
	Renderer::~Renderer()
	{
	}

	PsResult		Renderer::init(const Window& ext_Window)
	{
		m_targetWindowHandle = &ext_Window;
		m_graphicsAPI.init(ext_Window);
		return PS_SUCCESS;
	}

	const VkAPI& Renderer::getGraphicsAPI() const
	{
		return m_graphicsAPI;
	}

}