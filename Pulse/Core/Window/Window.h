#pragma once

#include "PsCommon.h"
#include "vulkan/vulkan.hpp"
#include <GLFW/glfw3.h>
#include <string>


namespace Ps {

	class Window {


	public:
		
		struct CreateInfo
		{
			int 			width;
			int				height;
			std::string 	title;
		};
		
		Window();
		~Window();
		static const CreateInfo	GetCreateInfo(const int userWidth, const int userHeight, const char* userTitle);
		PsResult				Init(const CreateInfo wInfo);
		const vk::SurfaceKHR&	GetSurface() const;
		static GLFWwindow*		GetWindowHandle();


	private:
		GLFWwindow*		m_Handle;
		int				m_Width;
		int				m_Height;
		std::string		m_Title;
		vk::SurfaceKHR	m_Surface;

		static GLFWwindow*	s_currentWindowHandle;
	};

}