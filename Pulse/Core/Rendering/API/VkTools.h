#pragma once

#include "PsCommon.h"
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>
#include <set>

#ifdef PS_DEBUG
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
const std::vector<std::string>	requiredExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};


namespace Ps {

	namespace vktools {

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

		vk::PhysicalDevice		FindPhysicalDevice(vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequiredProperties& reqProperties)
		{
			std::vector<vk::PhysicalDevice> physicalDevicesList = instance.enumeratePhysicalDevices();

			for (const vk::PhysicalDevice dev : physicalDevicesList)
			{
				if ( IsSuitableDevice(dev, surface, reqProperties) )
					return (dev);
			}
			return nullptr;
		}

		const bool		CheckExtensionSupport(vk::PhysicalDevice& device)
		{
			uint32_t	extensionCount;
			std::vector<vk::ExtensionProperties>		deviceExtensions;


			device.enumerateDeviceExtensionProperties(nullptr, &extensionCount, deviceExtensions);
			if (extensionCount < 1)
				return false;

			std::set<std::string>	extensionList(requiredExtensions.begin(), requiredExtensions.end());
			for (const auto& extension : deviceExtensions) {
				extensionList.erase(extension.extensionName);
			}
			return (extensionList.empty());
		}

		SwapChainSupportDetails		QuerySwapChainSupport(vk::PhysicalDevice& device, vk::SurfaceKHR const& surface)
		{
			uint32_t					formatCount;
			uint32_t					presentModesCount;
			SwapChainSupportDetails		scDetails;

			device.getSurfaceCapabilitiesKHR(surface, &scDetails.capabilities);

			device.getSurfaceFormatsKHR(surface, &formatCount, nullptr);
			if (formatCount > 0)
			{
				scDetails.formats.resize(formatCount);
				device.getSurfaceFormatsKHR(surface, &formatCount, scDetails.formats.data());
			}

			device.getSurfacePresentModesKHR(surface, &presentModesCount, nullptr);
			if (presentModesCount > 1)
			{
				scDetails.presentModes.resize(presentModesCount);
				device.getSurfacePresentModesKHR(surface, &presentModesCount, scDetails.presentModes.data());
			}

			return scDetails;
		}

		const bool		IsSuitableDevice(vk::PhysicalDevice device, vk::SurfaceKHR const& surface, const PhysicalDeviceRequiredProperties& reqProperties)
		{
			vk::PhysicalDeviceProperties		deviceProperties;
			vk::PhysicalDeviceFeatures			deviceFeatures;
			SwapChainSupportDetails				scDetails = {};

			device.getProperties(deviceProperties);
			device.getFeatures(deviceFeatures);
			scDetails = QuerySwapChainSupport(device, surface);

			// TODO: Extension support verification QueueFamilies operation support and gathering
			
			if (deviceProperties.deviceType != vk::PhysicalDeviceType::eDiscreteGpu ||
				!deviceFeatures.geometryShader || scDetails.formats.empty()
				|| scDetails.presentModes.empty())
				return false;
			return true;
		}


	}
}
