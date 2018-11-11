#include "PsCore.h"

namespace Ps {

	bool		Core::initialized = false;


	Core::Core()
	{
	}

	Core::~Core()
	{
		TerminateLibrairies();
	}

	PULSE_CORE PsResult Ps::Core::Init(const InitInfo engineInfo)
	{
		if (initialized == false)
		{
			if (InitLibrairies() != PS_SUCCESS)
				return PS_FAILURE;

			std::cout << "Lib init ok\n";

			window = new Ps::Window;

			Ps::Window::CreateInfo		wInfo = Ps::Window::GetCreateInfo(
				engineInfo.windowWidth,
				engineInfo.windowHeight,
				engineInfo.windowTitle.c_str());

			if (window->Init(wInfo) != PS_SUCCESS)
				return PS_FAILURE;

			std::cout << "Window init ok\n";

			initialized = true;
		}
		return PS_SUCCESS;
	}

	PULSE_CORE const Core::InitInfo		Core::GetInitInfo(
		const bool inputfs,
		const int inputWidth,
		const int inputHeight,
		const std::string inputTitle,
		const PsRenderingMode inputRenderMode)
	{
		const InitInfo engineInfo = {
			inputfs,
			inputWidth,
			inputHeight,
			inputTitle,
			inputRenderMode
		};

		return  engineInfo;
	}

	PsResult	Ps::Core::InitLibrairies()
	{
		if (glfwInit() == GLFW_FALSE)
			return PS_FAILURE;
		return PS_SUCCESS;
	}

	void Ps::Core::TerminateLibrairies()
	{
		glfwTerminate();
	}
}