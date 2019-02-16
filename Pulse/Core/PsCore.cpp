#include "PsCore.h"

namespace Ps {

	bool		Core::s_Initialized = false;


	PULSE_API Core::Core()
	{
	}

	PULSE_API Core::~Core()
	{
		TerminateLibrairies();
	}

	PULSE_API PsResult	 Core::Init(const InitInfo engineInfo)
	{
		PS_CORE_ASSERT(s_Initialized == false, "Core has already been initalized");
		
		PsResult	libErr = InitLibrairies();
		PS_CORE_ASSERT(libErr == PS_SUCCESS, "Librairies initialization failed");

		Window::CreateInfo		wInfo = Window::GetCreateInfo(
			engineInfo.windowWidth,
			engineInfo.windowHeight,
			engineInfo.applicationName.c_str());

		PsResult winErr = m_Window.Init(wInfo);
		PS_CORE_ASSERT(winErr == PS_SUCCESS, "Window initialization failed");

		PsResult rendererErr = m_Renderer.Init(m_Window);
		PS_CORE_ASSERT(rendererErr == PS_SUCCESS, "Renderer initialization failed");

		s_Initialized = true;

		return PS_SUCCESS;
	}

	PULSE_API const Core::InitInfo		Core::GetInitInfo(
											const bool inputfs,
											const int inputWidth,
											const int inputHeight,
											const std::string inputTitle)
	{
		const InitInfo engineInfo = {
			inputfs,
			inputWidth,
			inputHeight,
			inputTitle,
		};

		return  engineInfo;
	}

	PsResult	Core::InitLibrairies()
	{
		int err = glfwInit();
		PS_CORE_ASSERT(err == GLFW_TRUE, "Failed to initalize GLFW");
		
		Log::Init();
	
		return PS_SUCCESS;
	}

	void	Core::TerminateLibrairies()
	{
		glfwTerminate();
	}
}