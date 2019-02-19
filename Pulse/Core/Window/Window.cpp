#include "Window.h"
#include <iostream>

namespace Ps {

	Window::Window(const int userWidth, const int userHeight, const std::string& userTitle) :
										m_width(userWidth),
										m_height(userHeight),
										m_title(userTitle)
	{

	}

	Window::~Window()
	{
		if (m_GLFWwindowHandle)
			glfwDestroyWindow(m_GLFWwindowHandle);
	}

	PsResult Window::init(const vk::Instance vkInstance)
	{
		m_GLFWwindowHandle = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		PS_CORE_ASSERT(m_GLFWwindowHandle, "GLFW window creation failed");
		
		initSurface(vkInstance);
		return PS_SUCCESS;
	}
	
	const vk::SurfaceKHR& Window::getSurface() const
	{
		PS_CORE_ASSERT(m_surface, "Surface hasn't been initialized");
		return m_surface;
	}

	const GLFWwindow* Window::getGLFWWindowHandle() const
	{
		return m_GLFWwindowHandle;
	}

	PsResult Window::initSurface(const vk::Instance vkInstance)
	{
		VkSurfaceKHR		tmp_Surface;

		VkResult err = glfwCreateWindowSurface(vkInstance, m_GLFWwindowHandle, nullptr, &tmp_Surface);
		PS_CORE_ASSERT(err == VK_SUCCESS, "Failed to create the window surface");
		m_surface = tmp_Surface;
		return PS_SUCCESS;
	}
}