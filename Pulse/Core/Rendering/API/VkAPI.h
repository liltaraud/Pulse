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
		const PsResult		Init();
		VkSurfaceKHR		GetSurface() const;


	private:
		vk::Instance		m_Instance;
		vk::SurfaceKHR		m_Surface;


		const PsResult CreateInstance();
		const PsResult InitSurface();


		static bool			s_Initialized;
	};

}


