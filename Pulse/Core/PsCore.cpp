#include "PsCore.h"

PULSE_CORE PsResult Ps::Core::Init(const InitInfo info)
{
	window = new Ps::Window;

	Ps::Window::CreateInfo		wInfo = Ps::Window::getCreateInfo(1280, 720, "Pulse");
	if (window->Init(wInfo) != PS_SUCCESS)
		return PS_FAILURE;
	return PS_SUCCESS;
}
