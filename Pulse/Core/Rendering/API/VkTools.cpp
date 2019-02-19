#include "VkTools.h"

namespace Ps {

	namespace vktools {


		// TO DO : Refactor this crap to make it work with vulkan.hpp
		
		const bool		checkExtensionSupport(const vk::PhysicalDevice& device)
		{
			uint32_t	extensionCount;
			std::vector<vk::ExtensionProperties>		deviceExtensions;


			vk::Result extErr = device.enumerateDeviceExtensionProperties(nullptr, &extensionCount, deviceExtensions.data());
			PS_CORE_ASSERT(extErr == vk::Result::eSuccess, "Device extension enumeration failed");
			if (extensionCount < 1)
				return false;

			std::vector<std::string>	extensionList(requiredInstanceExtensions.begin(), requiredInstanceExtensions.end());
			
			for (const vk::ExtensionProperties& currExt : deviceExtensions) {
				
				if (std::find(extensionList.begin(), extensionList.end(), std::string(currExt.extensionName)) == extensionList.end())
					return false;
			}
			return true;
		}

		SwapChainSupportDetails		querySwapChainSupport(const vk::PhysicalDevice& device, const vk::SurfaceKHR& surface)
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


		const bool		isSuitableDevice(const vk::PhysicalDevice& device, const vk::SurfaceKHR& surface, const PhysicalDeviceRequiredProperties& reqProperties)
		{
			vk::PhysicalDeviceProperties		deviceProperties;
			vk::PhysicalDeviceFeatures			deviceFeatures;
			SwapChainSupportDetails				scDetails = {};

			deviceProperties = device.getProperties();
			deviceFeatures = device.getFeatures();
			scDetails = querySwapChainSupport(device, surface);

			// TODO: Extension support verification QueueFamilies operation support and gathering

			if (deviceProperties.deviceType != vk::PhysicalDeviceType::eDiscreteGpu ||
				!deviceFeatures.geometryShader || scDetails.formats.empty()
				|| scDetails.presentModes.empty())
				return false;
			return true;
		}

		vk::PhysicalDevice		findPhysicalDevice(const vk::Instance& instance, const vk::SurfaceKHR& surface, const PhysicalDeviceRequiredProperties& reqProperties)
		{
			std::vector<vk::PhysicalDevice> physicalDevicesList = instance.enumeratePhysicalDevices();

			for (const vk::PhysicalDevice dev : physicalDevicesList)
			{
				if (isSuitableDevice(dev, surface, reqProperties))
					return (dev);
			}
			return nullptr;
		}

	}
}
