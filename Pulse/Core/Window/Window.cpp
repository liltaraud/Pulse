#include "Window.h"
#include <iostream>

namespace Ps {

	GLFWwindow* Window::s_currentWindowHandle = nullptr;

	Window::Window()
	{
		m_Handle = nullptr;
		m_Width = 1280;
		m_Height = 720;
		m_Title = "No Title";
	}

	Window::~Window()
	{
		if (m_Handle)
			glfwDestroyWindow(m_Handle);
	}

	const Window::CreateInfo	 Window::GetCreateInfo(const int userWidth, const int userHeight, const char* userTitle)
	{
		CreateInfo		wInfo = { 
			userWidth,
			userHeight,
			userTitle
		};
		return wInfo;
	}

	PsResult Window::Init(const CreateInfo wInfo)
	{
		const int vkSupportErr = glfwVulkanSupported();
		PS_CORE_ASSERT(vkSupportErr, "Vulkan isn't supported");

		m_Width = wInfo.width;
		m_Height = wInfo.height;
		m_Title = wInfo.title;
		
		m_Handle = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, nullptr);
		PS_CORE_ASSERT(m_Handle, "GLFW window creation failed");
		
		s_currentWindowHandle = m_Handle;
		
		return PS_SUCCESS;
	}
	
	const vk::SurfaceKHR& Window::GetSurface() const
	{
		PS_CORE_ASSERT(m_Surface, "Surface hasn't been initialized");
		return m_Surface;
	}

	GLFWwindow* Window::GetWindowHandle()
	{
		return s_currentWindowHandle;
	}



}