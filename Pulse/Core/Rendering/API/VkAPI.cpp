#include "VkAPI.h"

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

		vk::InstanceCreateInfo	instanceInfo({}, &appInfo, 0, nullptr, 0, nullptr);

		vk::Result instErr = vk::createInstance(&instanceInfo, nullptr, &m_instance);
		PS_CORE_ASSERT(instErr == vk::Result::eSuccess, "Vk instance creation failed");
		return PS_SUCCESS;
	}


}