#include "VkAPI.h"

namespace Ps {

	bool VkAPI::s_Initialized = false;


	VkAPI::VkAPI()
	{

	}

	VkAPI::~VkAPI()
	{
		m_Instance.destroy();
	}

	const PsResult VkAPI::Init()
	{
		PS_ASSERT(s_Initialized = true, "Vk API has already been initialized");
		CreateInstance();
		InitSurface();

		s_Initialized = true;
		return PS_SUCCESS;
	}

	VkSurfaceKHR VkAPI::GetSurface() const
	{
		return m_Surface;
	}

	const PsResult VkAPI::CreateInstance()
	{
		vk::ApplicationInfo appInfo("Application Name", VK_MAKE_VERSION(0, 1, 0),
			"Pulse", VK_MAKE_VERSION(0, 1, 0), VK_MAKE_VERSION(1, 1, 85));

		vk::InstanceCreateInfo	instanceInfo({}, &appInfo, 0, nullptr, 0, nullptr);

		vk::Result instErr = vk::createInstance(&instanceInfo, nullptr, &m_Instance);
		PS_CORE_ASSERT(instErr == vk::Result::eSuccess, "Vk instance creation failed");
		return PS_SUCCESS;
	}

	const PsResult VkAPI::InitSurface()
	{
		VkSurfaceKHR		tmp_Surface;
		
		VkResult err = glfwCreateWindowSurface(m_Instance, Window::GetWindowHandle(), NULL, &tmp_Surface);
		PS_CORE_ASSERT(err == VK_SUCCESS, "Failed to create the window surface");
		m_Surface = tmp_Surface;
		return PS_SUCCESS;
	}
}