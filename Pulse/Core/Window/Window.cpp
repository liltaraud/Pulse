#include "Window.h"

namespace Ps {

	Window::Window()
	{
	}

	Window::~Window()
	{
		if (wHandle)
			glfwDestroyWindow(wHandle);
	}

	Window::CreateInfo	 Window::GetCreateInfo(const int userWidth, const int userHeight, const char* userTitle)
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
		wWidth = wInfo.width;
		wHeight = wInfo.height;
		wHandle = glfwCreateWindow(wWidth, wHeight, wTitle.c_str(), NULL, nullptr);
		if (!wHandle)
			return PS_FAILURE;
		return PS_SUCCESS;
	}

}