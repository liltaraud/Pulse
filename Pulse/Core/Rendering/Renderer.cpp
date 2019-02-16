#include "Renderer.h"

namespace Ps {

	Renderer::Renderer()
	{
	}

	
	Renderer::~Renderer()
	{
	}

	PsResult		Renderer::Init(Ps::Window& ext_Window)
	{
		m_TargetWindowHandle = &ext_Window;
		graphicsAPI.Init();
		return PS_SUCCESS;
	}

}