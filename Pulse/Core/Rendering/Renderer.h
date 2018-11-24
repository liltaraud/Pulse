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

		const PsResult		Init();

	private:
		vk::Instance		m_Instance;


		const PsResult		CreateInstance();
		void				DestroyVulkanObjects();
	};

}