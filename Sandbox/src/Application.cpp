#include "Pulse.h"
#include <iostream>

int		main()
{
	Ps::Core::InitInfo		info = Ps::Core::GetInitInfo(false, 1280, 720, "Pulse", PS_RENDERINGMODE_DEFERRED);
	Ps::Core		Pulse;

	if (Pulse.Init(info) != PS_SUCCESS)
		PS_CRITICAL("Couldn't Initialize Pulse Engine");

	for (;;);

	return 0;
}