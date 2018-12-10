#pragma once

#include "PsCommon.h"
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <set>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif


/* LAYERS 
 = {
	"VK_LAYER_LUNARG_standard_validation",
	"VK_LAYER_LUNARG_object_tracker"
};
*/
const std::vector<const char *>	requiredExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

namespace Ps {

	namespace vktools {

		struct PhsyicalDeviceRequiredProperties
		{
			const std::vector<const char *>	validationLayers;
			const std::vector<const char *>	requiredExtensions;
		};


		vk::PhysicalDevice		FindPhysicalDevice(vk::Instance& instance, const vk::SurfaceKHR& surface, const PhsyicalDeviceRequiredProperties& reqProperties)
		{
			vk::PhysicalDevice		physicalDevice = nullptr;
			std::vector<vk::PhysicalDevice> physicalDevicesList = instance.enumeratePhysicalDevices();

			for (const vk::PhysicalDevice dev : physicalDevicesList)
			{
				if (IsSuitableDevice(dev, surface))
				{
					physicalDevice = dev;
					break;
				}
			}
			if (physicalDevice == VK_NULL_HANDLE)
				PS_CORE_ERROR("Failed to find any GPUs with required functionnalities !");
			return physicalDevice;
		}
/*
		const bool		IsSuitableDevice(vk::PhysicalDevice device, vk::SurfaceKHR const& surface)
		{
			vk::PhysicalDeviceProperties		deviceProperties;
			vk::PhysicalDeviceFeatures			deviceFeatures;
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

		const bool		FindQueueFamilies(vk::PhysicalDevice& device, VkSurfaceKHR const& surface)
		{
			uint32_t					queueCount = 0;
			bool						queueFound = false;
			std::vector<vk::QueueFlags>	queueFlags(3);
			int							qidx = 1;
			uint32_t					idx;

			// Required queues flags ///////////////
			queueFlags[0] = VK_QUEUE_GRAPHICS_BIT;
			queueFlags[1] = VK_QUEUE_COMPUTE_BIT;
			queueFlags[2] = VK_QUEUE_TRANSFER_BIT;

			////////////////////////////////////////
			memset(queuesIndex, -1, NB_QUEUES);
			std::vector<vk::QueueFamilyProperties>	deviceQueues(queueCount);
			device.getQueueFamilyProperties(&queueCount, deviceQueues);
			if (!queueCount)
				return false;
			
			for (const auto& flags : queueFlags)
			{
				idx = 0;
				for (const auto& queues : deviceQueues)
				{
					if (queues.queueCount > 0 && queues.queueFlags & flags)
					{
						if (!(flags == VK_QUEUE_TRANSFER_BIT && queues.queueFlags & VK_QUEUE_GRAPHICS_BIT))
						{
							queueFound = true;
							queuesIndex[qidx] = idx;
							break;
						}
					}
					idx++;
				}
				if (!queueFound)
					return false;
				queueFound = false;
				qidx++;
			}

			VkBool32					presentationSupport = false;

			idx = 0;
			for (const auto& queues : deviceQueues) {
				vkGetPhysicalDeviceSurfaceSupportKHR(device, idx, surface, &presentationSupport);
				if (presentationSupport) {
					queuesIndex[0] = idx;
					break;
				}
				idx++;
			}
			if (!presentationSupport)
				return false;
			return true;
		}
*/
		const bool		CheckExtensionSupport(vk::PhysicalDevice& device)
		{
			uint32_t	extensionCount;
			std::vector<VkExtensionProperties>		deviceExtensions;


			device.enumerateDeviceExtensionProperties(nullptr, &extensionCount, deviceExtensions);
			if (extensionCount < 1)
				return false;

			std::set<std::string>	extensionList(requiredExtensions.begin(), requiredExtensions.end());
			for (const auto& extension : deviceExtensions) {
				extensionList.erase(extension.extensionName);
			}
			return (extensionList.empty());
		}
/*
		SwapChainSupportDetails		VkGPU::querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR const& surface)
		{
			uint32_t					formatCount;
			uint32_t					presentModesCount;
			SwapChainSupportDetails		scDetails;

			vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &scDetails.capabilities);

			vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);
			if (formatCount > 0) {
				scDetails.formats.resize(formatCount);
				vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, scDetails.formats.data());
			}

			vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModesCount, nullptr);
			if (presentModesCount > 1) {
				scDetails.presentModes.resize(presentModesCount);
				vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModesCount, scDetails.presentModes.data());
			}

			return scDetails;
		}
*/
	}
}
