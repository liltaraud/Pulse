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

	PULSE_API PsResult	 Ps::Core::Init(const InitInfo engineInfo)
	{
		if (s_Initialized == false)
		{
			if (InitLibrairies() != PS_SUCCESS)
				return PS_FAILURE;


			m_Window = new Ps::Window;
			if (!m_Window)
			{
				PS_CORE_ERROR("Window Creation failed");
				return PS_FAILURE;
			}

			Ps::Window::CreateInfo		wInfo = Ps::Window::GetCreateInfo(
				engineInfo.windowWidth,
				engineInfo.windowHeight,
				engineInfo.applicationName.c_str());

			if (m_Window->Init(wInfo) != PS_SUCCESS)
				return PS_FAILURE;


			m_Renderer = new Ps::Renderer;
			if (!m_Renderer)
			{
				PS_CORE_ERROR("Renderer object creation failed");
				return PS_FAILURE;
			}
			if (m_Renderer->Init() != PS_SUCCESS)
				return PS_FAILURE;

			s_Initialized = true;
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
		{
			PS_CORE_CRITICAL("GLFW failed to initialize");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}

	void	Ps::Core::TerminateLibrairies()
	{
		glfwTerminate();
	}
}