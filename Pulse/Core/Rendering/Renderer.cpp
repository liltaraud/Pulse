#include "Renderer.h"

namespace Ps {

	Renderer::Renderer()
	{
	}

	
	Renderer::~Renderer()
	{
		DestroyVulkanObjects();
	}

	const PsResult		Renderer::Init(Ps::Window& ext_Window)
	{
		if (CreateInstance() != PS_SUCCESS)
		{
			PS_CORE_CRITICAL("Failed to initialize renderer");
			return PS_FAILURE;
		}
		m_TargetWindowHandle = &ext_Window;
		m_TargetWindowHandle->InitSurface(m_Instance);
		return PS_SUCCESS;
	}

	const PsResult Renderer::CreateInstance()
	{
		vk::ApplicationInfo appInfo("Application Name", VK_MAKE_VERSION(0, 1, 0),
			"Pulse", VK_MAKE_VERSION(0, 1, 0), VK_MAKE_VERSION(1, 1, 85));

		vk::InstanceCreateInfo	instanceInfo({}, &appInfo, 0, nullptr, 0, nullptr);

		if (vk::createInstance(&instanceInfo, nullptr, &m_Instance) != vk::Result::eSuccess)
		{
			PS_CORE_CRITICAL("Failed create a Vulkan instance");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}

	void Renderer::DestroyVulkanObjects()
	{
		m_Instance.destroy();
	}
}