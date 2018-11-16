#include "Renderer.h"
#include <assert.h>

namespace Ps {

	Renderer::Renderer()
	{
	}

	
	Renderer::~Renderer()
	{
		DestroyVulkanObjects();
	}

	const PsResult		Renderer::Init()
	{
		if (CreateInstance() != PS_SUCCESS)
		{
			PS_CORE_CRITICAL("Failed to initialize renderer");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}
	const PsResult Renderer::CreateInstance()
	{
		m_Instance = new vk::Instance;

		vk::ApplicationInfo appInfo("Application Name", VK_MAKE_VERSION(0, 1, 0),
			"Pulse", VK_MAKE_VERSION(0, 1, 0), VK_MAKE_VERSION(1, 1, 85));

		vk::InstanceCreateInfo	instanceInfo({}, &appInfo, 0, nullptr, 0, nullptr);

		vk::Result res = vk::createInstance(&instanceInfo, nullptr, m_Instance);
		if (res != vk::Result::eSuccess)
		{
			PS_CORE_CRITICAL("Failed create a Vulkan instance");
			return PS_FAILURE;
		}
		return PS_SUCCESS;
	}
	
	void Renderer::DestroyVulkanObjects()
	{
		m_Instance->destroy();
		delete m_Instance;
	}
}