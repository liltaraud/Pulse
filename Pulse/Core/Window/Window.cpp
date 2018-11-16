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

	PsResult Window::Init(const CreateInfo wInfo)
	{
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

}