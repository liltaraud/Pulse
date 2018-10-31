#include "Pulse.h"
#include <iostream>


int		main()
{
	glfwInit();


	Ps::Window		w;
	Ps::WindowCreateInfo		wInfo = Ps::Window::CreateInfo(1280, 720, "Pulse");
	w.Init(wInfo);
	std::cin.get();
	std::cin.get();
	return 0;
}