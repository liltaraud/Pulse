#include "Window.h"

namespace Ps {

	Window::Window()
	{
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

	const PsResult Window::Init(const CreateInfo wInfo)
	{
		if (!glfwVulkanSupported()) //Any Vulkan-related function requires GLFW initialized
		{
			PS_CORE_CRITICAL("Vulkan isn't supported");
			return PS_FAILURE;
		}

		m_Width = wInfo.width;
		m_Height = wInfo.height;
		m_Handle = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, nullptr);
		if (!m_Handle)
		{
			PS_CORE_ERROR("GLFW window creation failed");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}

	const vk::SurfaceKHR& Window::GetSurface()
	{
		if (!m_Surface)
			PS_CORE_ERROR("Surface hasn't been initialized");
		return m_Surface;
	}

	const PsResult Window::InitSurface(const vk::Instance& instance)
	{
		VkSurfaceKHR	pSurface = VkSurfaceKHR(m_Surface);
		VkResult err = glfwCreateWindowSurface(instance, m_Handle, NULL, &pSurface);
		if (err != VK_SUCCESS)
		{
			PS_CORE_ERROR("Failed to create the window surface");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}

}