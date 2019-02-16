#include "Pulse.h"
#include <iostream>

int		main()
{
	Ps::Core::InitInfo		info = Ps::Core::GetInitInfo(false, 1280, 720, "Pulse");
	Ps::Core		Pulse;

	PsResult psErr = Pulse.Init(info);
	PS_ASSERT(psErr == PS_SUCCESS, "Pulse Initalization failed");

	while (!glfwWindowShouldClose(Ps::Window::GetWindowHandle()))
	{
		glfwPollEvents();
	}
	return 0;
}