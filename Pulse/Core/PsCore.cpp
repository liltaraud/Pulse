#include "PsCore.h"

namespace Ps {

	bool		Core::initialized = false;


	PULSE_API Core::Core()
	{
	}

	PULSE_API Core::~Core()
	{
		TerminateLibrairies();
	}

	PULSE_API PsResult	 Ps::Core::Init(const InitInfo engineInfo)
	{
		if (initialized == false)
		{
			if (InitLibrairies() != PS_SUCCESS)
			{
				PS_CORE_ERROR("Librairies init failed\n");
				return PS_FAILURE;
			}

			

			window = new Ps::Window;

			Ps::Window::CreateInfo		wInfo = Ps::Window::GetCreateInfo(
				engineInfo.windowWidth,
				engineInfo.windowHeight,
				engineInfo.windowTitle.c_str());

			if (window->Init(wInfo) != PS_SUCCESS)
			{
				PS_CORE_ERROR("Window initialisation failed\n");
				return PS_FAILURE;
			}

			initialized = true;
		}
		return PS_SUCCESS;
	}

	PULSE_API const Core::InitInfo		Core::GetInitInfo(
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
		Log::Init();
		if (glfwInit() == GLFW_FALSE)
			return PS_FAILURE;
		return PS_SUCCESS;
	}

	void	Ps::Core::TerminateLibrairies()
	{
		glfwTerminate();
	}
}