#include "PsCore.h"

namespace Ps {

	PULSE_API Core::Core(const int userWidth, const int userHeight, const std::string& userTitle) :
									m_window(userWidth, userHeight, userTitle)
	{
	}

	PULSE_API Core::~Core()
	{
		terminateLibrairies();
	}

	PULSE_API PsResult	 Core::init(const int windowWidth, const int windowHeight, const std::string& applicationName)
	{
		PS_CORE_ASSERT(m_initialized == false, "Core has already been initalized");
		
		PsResult	libErr = initLibrairies();
		PS_CORE_ASSERT(libErr == PS_SUCCESS, "Librairies initialization failed");

		PsResult rendererErr = m_renderer.init(m_window);
		PS_CORE_ASSERT(rendererErr == PS_SUCCESS, "Renderer initialization failed");

		PsResult winErr = m_window.init(m_renderer.getGraphicsAPI().getInstance());
		PS_CORE_ASSERT(winErr == PS_SUCCESS, "Window initialization failed");

		m_initialized = true;

		return PS_SUCCESS;
	}

	PsResult	Core::initLibrairies()
	{
		int err = glfwInit();
		PS_CORE_ASSERT(err == GLFW_TRUE, "Failed to initalize GLFW");
		
		checkVulkanSupport();

		Log::init();
		coreLogger = Log::getCoreLogger();
		clientLogger = Log::getClientLogger();
		
		return PS_SUCCESS;
	}

	void	Core::checkVulkanSupport()
	{
		const int vkSupportErr = glfwVulkanSupported();
		PS_CORE_ASSERT(vkSupportErr == GLFW_TRUE, "Vulkan isn't supported");
	}

	void	Core::terminateLibrairies()
	{
		glfwTerminate();
	}
}