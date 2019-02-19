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

namespace Ps {

	namespace vktools {

		/* LAYERS
		 = {
			"VK_LAYER_LUNARG_standard_validation",
			"VK_LAYER_LUNARG_object_tracker"
		};
		*/
		const std::vector<std::string>	requiredExtensions = {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};


		struct PhysicalDeviceRequiredProperties
		{
			const std::vector<std::string>	validationLayers;
			const std::vector<std::string>	requiredExtensions;
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
