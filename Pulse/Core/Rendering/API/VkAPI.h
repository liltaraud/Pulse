#pragma once

#include "PsCommon.h"
#include "Window/Window.h"
#include "VkTools.h"

namespace Ps {

	class VkAPI
	{


	public:
		VkAPI();
		~VkAPI();
		PsResult				init(const Window& extWindow);
		const vk::Instance&		getInstance() const;

	private:
		const Window*		m_windowHandle = nullptr;
		vk::Instance		m_instance;
		vk::SurfaceKHR		m_surface;
		bool				m_initialized;



		PsResult createInstance();

	};

}


