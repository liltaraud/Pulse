#pragma once

#include "PsCommon.h"
#define GLFW_INCLUDE_VULKAN
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
		static CreateInfo		GetCreateInfo(const int userWidth, const int userHeight, const char* userTitle);
		PsResult				Init(const CreateInfo wInfo);


	private:
		GLFWwindow*		wHandle;
		int				wWidth;
		int				wHeight;
		std::string		wTitle;

	};
}