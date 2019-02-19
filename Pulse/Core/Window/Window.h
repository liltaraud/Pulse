#pragma once

#include "PsCommon.h"
#include "vulkan/vulkan.hpp"
#include <GLFW/glfw3.h>
#include <string>


namespace Ps {

	class Window
	{

	public:
		
		Window(const int userWidth, const int userHeight, const std::string& userTitle);
		~Window();
		PsResult				init(const vk::Instance vkInstance);
		const vk::SurfaceKHR&	getSurface() const;
		const GLFWwindow*		getGLFWWindowHandle() const;


	private:

		PsResult				initSurface(const vk::Instance vkInstance);


		GLFWwindow*		m_GLFWwindowHandle = nullptr;
		int				m_width;
		int				m_height;
		std::string		m_title;
		vk::SurfaceKHR	m_surface;
	};

}