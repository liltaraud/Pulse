#include "Pulse.h"
#include <iostream>

int		main()
{
	Ps::Core::InitInfo		info = Ps::Core::GetInitInfo(false, 1280, 720, "Pulse-v0.1", PS_RENDERINGMODE_DEFERRED);
	Ps::Core		Pulse;

	if (Pulse.Init(info) != PS_SUCCESS)
		PS_TRACE("Couldn't Initialize Pulse Engine\n");

	for (;;);

	return 0;
}