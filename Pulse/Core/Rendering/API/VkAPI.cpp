#include "VkAPI.h"
#include <iostream>

// Run on discrete GPUs in Nvidia equipped laptops
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

namespace Ps {

	VkAPI::VkAPI()
	{
		createInstance();
	}

	VkAPI::~VkAPI()
	{
		m_instance.destroy();
	}

	PsResult VkAPI::init(const Window& extWindow)
	{
		PS_CORE_ASSERT(m_initialized = true, "Vk API has already been initialized");
		
		m_windowHandle = &extWindow;
		m_initialized = true;
		return PS_SUCCESS;
	}

	const vk::Instance & VkAPI::getInstance() const
	{
		return m_instance;
	}

	PsResult VkAPI::createInstance()
	{
		vk::ApplicationInfo appInfo("Application Name", VK_MAKE_VERSION(0, 1, 0),
			"Pulse", VK_MAKE_VERSION(0, 1, 0), VK_MAKE_VERSION(1, 1, 85));

		vk::InstanceCreateInfo	instanceInfo({},
									&appInfo,
									static_cast<uint32_t>(vktools::requiredValidationLayers.size()),
									vktools::requiredValidationLayers.data(),
									static_cast<uint32_t>(vktools::requiredExtensions.size()),
									vktools::requiredExtensions.data());

		vk::Result instErr = vk::createInstance(&instanceInfo, nullptr, &m_instance);
		PS_CORE_ASSERT(instErr == vk::Result::eSuccess, "Vk instance creation failed");
		return PS_SUCCESS;
	}


}