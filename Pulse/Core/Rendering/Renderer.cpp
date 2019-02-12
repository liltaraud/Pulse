#include "Renderer.h"

namespace Ps {

	Renderer::Renderer()
	{
	}

	
	Renderer::~Renderer()
	{
	}

	const PsResult		Renderer::Init(Ps::Window& ext_Window)
	{
		PS_CORE_ASSERT(CreateInstance() != PS_SUCCESS, "Failed to initialize renderer");
		m_TargetWindowHandle = &ext_Window;
		m_TargetWindowHandle->InitSurface(m_Instance);
		return PS_SUCCESS;
	}

	const PsResult Renderer::CreateInstance()
	{
		vk::ApplicationInfo appInfo("Application Name", VK_MAKE_VERSION(0, 1, 0),
			"Pulse", VK_MAKE_VERSION(0, 1, 0), VK_MAKE_VERSION(1, 1, 85));

		vk::InstanceCreateInfo	instanceInfo({}, &appInfo, 0, nullptr, 0, nullptr);

		PS_ASSERT(vk::createInstance(&instanceInfo, nullptr, &m_Instance) == vk::Result::eSuccess, "Vk instance creation failed");
		return PS_SUCCESS;
	}

	void Renderer::DestroyVulkanObjects()
	{
		m_Instance.destroy();
	}
}