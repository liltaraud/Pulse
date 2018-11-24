#pragma once

#include "PsCommon.h"
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

namespace Ps {

	namespace vktools {

		vk::PhysicalDevice		FindPhysicalDevice(vk::Instance& instance, vk::SurfaceKHR const& surface)
		{
			vk::PhysicalDevice		physicalDevice = nullptr;

			std::vector<vk::PhysicalDevice> physicalDevicesList = instance.enumeratePhysicalDevices();

			for (const auto& dev : physicalDevicesList) {
				if (IsSuitableDevice(dev, surface))
				{
					physicalDevice = dev;
					break;
				}
			}
			if (physicalDevice == VK_NULL_HANDLE)
			{
				PS_CORE_ERROR("Failed to find any GPUs with Vulkan support !");
				return physicalDevice;
			}
		}

		const bool		IsSuitableDevice(vk::PhysicalDevice device, vk::SurfaceKHR const& surface)
		{
			VkPhysicalDeviceProperties			deviceProperties;
			VkPhysicalDeviceFeatures			deviceFeatures;
			SwapChainSupportDetails				scDetails = {};

			vk::GetPhysicalDeviceProperties(device, &deviceProperties);
			vk::GetPhysicalDeviceFeatures(device, &deviceFeatures);
			scDetails = querySwapChainSupport(device, surface);
			if (deviceProperties.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU
				|| !deviceFeatures.geometryShader || !findQueueFamilies(device, surface)
				|| !checkExtensionSupport(device) || scDetails.formats.empty()
				|| scDetails.presentModes.empty())
				return false;
			return true;
		}


	}
}
