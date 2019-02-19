#pragma once

#include "PsCommon.h"
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <string>
#include <algorithm>


#ifdef PS_DEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	// TODO: Port whole physical device system to a class system to allow for simpler access to device information 
	//		 As well as creation and interfacing with multiple devices

namespace Ps {

	namespace vktools {

		const std::vector<const char*> requiredValidationLayers= {
//			"VK_LAYER_LUNARG_standard_validation",
//			"VK_LAYER_LUNARG_object_tracker"
		};

		const std::vector<const char*>	requiredInstanceExtensions = {
			VK_KHR_WIN32_SURFACE_EXTENSION_NAME
		};

		const std::vector<const char*>	requiredDeviceExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};


		struct PhysicalDeviceRequiredProperties
		{
			const std::vector<std::string>	validationLayers;
			const std::vector<std::string>	instanceExtensions;
		};

		struct SwapChainSupportDetails
		{
			vk::SurfaceCapabilitiesKHR			capabilities;
			std::vector<vk::SurfaceFormatKHR>	formats;
			std::vector<vk::PresentModeKHR>		presentModes;
		};

		// VKTOOLS FUNCTIONS

		SwapChainSupportDetails		querySwapChainSupport(const vk::PhysicalDevice& device, const vk::SurfaceKHR& surface);
		const bool					isSuitableDevice(const vk::PhysicalDevice& device, const vk::SurfaceKHR& surface, const PhysicalDeviceRequiredProperties& reqProperties);
		vk::PhysicalDevice			findPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequiredProperties& reqProperties);

	}
}
