#pragma once

#include "PsCommon.h"
#include <string>
#include <exception>

namespace Ps {

	struct WindowCreateInfo {
		int 			width;
		int				height;
		std::string 	title;
	};

	class Window {


	public:
		Window();
		~Window();
		static WindowCreateInfo		CreateInfo(const int userWidth, const int userHeight, const char* userTitle);
		PsResult					Init(const WindowCreateInfo wInfo);

	private:
		GLFWwindow*		wHandle;
		int				wWidth;
		int				wHeight;
		std::string		wTitle;

	};
}