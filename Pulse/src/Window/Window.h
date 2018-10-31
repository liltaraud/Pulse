#pragma once

#include "PsCommon.h"
#include <string>
#include <exception>

namespace Ps {

	PULSE_API struct WindowCreateInfo {
		int 			width;
		int				height;
		std::string 	title;
	};

	PULSE_API class Window {

	public:
		PULSE_API Window();
		PULSE_API ~Window();
		PULSE_API static WindowCreateInfo		CreateInfo(const int userWidth, const int userHeight, const char* userTitle);
		PULSE_API PsResult					Init(const WindowCreateInfo wInfo);

	private:
		GLFWwindow*		wHandle;
		int				wWidth;
		int				wHeight;
		std::string		wTitle;

	};
}