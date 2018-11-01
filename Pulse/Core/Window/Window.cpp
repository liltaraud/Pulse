#include "Window.h"
#include <iostream>

namespace Ps {

	Window::Window()
	{
		wHandle = nullptr;
	}

	Window::~Window()
	{
		if (wHandle)
			glfwDestroyWindow(wHandle);
	}

	WindowCreateInfo Window::CreateInfo(const int userWidth, const int userHeight, const char* userTitle)
	{
		WindowCreateInfo		wInfo = { 
			userWidth,
			userHeight,
			userTitle
		};
		return wInfo;
	}

	PsResult Window::Init(const WindowCreateInfo wInfo)
	{
		std::cout << wInfo.title << "width=" << wInfo.width << " Height=" << wInfo.height << std::endl;
		wWidth = wInfo.width;
		wHeight = wInfo.height;
		wHandle = glfwCreateWindow(wWidth, wHeight, wTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
		if (!wHandle)
		{
			throw std::exception("GLFW Couldn't create a window");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}

}