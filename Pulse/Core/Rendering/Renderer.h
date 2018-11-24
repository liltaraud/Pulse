#pragma once

#include "PsCommon.h"
#include "Window/Window.h"
#include <vulkan/vulkan.hpp>

namespace Ps {

	class PULSE_API Renderer
	{
	public:
		Renderer();
		~Renderer();

		const PsResult		Init(Ps::Window& ext_Window);

	private:
		vk::Instance		m_Instance;
		Ps::Window			*m_TargetWindowHandle;


		const PsResult		CreateInstance();
		void				DestroyVulkanObjects();
	};

}