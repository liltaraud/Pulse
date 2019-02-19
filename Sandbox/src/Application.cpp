#include "Pulse.h"
#include <iostream>

int		main()
{
	Ps::Core		Pulse;

	PsResult psErr = Pulse.init(1280, 720, "Pulse");
	PS_ASSERT(psErr == PS_SUCCESS, "Pulse Initalization failed");

	for (;;)
	{
		glfwPollEvents();
	}
	return 0;
}