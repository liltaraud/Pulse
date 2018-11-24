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
	
	void		VkGPU::findPhysicalDevice(VkSurfaceKHR const& surface)
	{
		uint32_t	deviceCount = 0;

		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
		if (deviceCount == 0)
			throw std::runtime_error("Failed to find any GPUs with Vulkan support !");
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
		for (const auto& dev : devices) {
			if (isSuitableDevice(dev, surface)) {
				physicalDevice = dev;
				break;
			}
		}
		if (physicalDevice == VK_NULL_HANDLE)
			throw std::runtime_error("Failed to find a suitable GPU");
	}


	void Renderer::DestroyVulkanObjects()
	{
		m_Instance.destroy();
	}
}