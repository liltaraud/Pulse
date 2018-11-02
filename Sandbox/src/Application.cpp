#include "Pulse.h"
#include <iostream>

int		main()
{
	Ps::Core::InitInfo		info = {false};
	Ps::Core		Pulse;

	if (Pulse.Init(info) != PS_SUCCESS)
		throw std::exception("Couldn't Initialize Pulse Engine");

	std::cin.get();
	return 0;
}