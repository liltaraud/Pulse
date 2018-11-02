#pragma once

#include "PsCommon.h"
#include <string>
#include <exception>

namespace Ps {



	class Window {


	public:
		
		struct CreateInfo {
			int 			width;
			int				height;
			std::string 	title;
		};
		
		Window();
		~Window();
		static CreateInfo		getCreateInfo(const int userWidth, const int userHeight, const char* userTitle);
		PsResult					Init(const CreateInfo wInfo);





	private:
		static bool		initialized;
		GLFWwindow*		wHandle;
		int				wWidth;
		int				wHeight;
		std::string		wTitle;

	};
}