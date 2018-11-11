#pragma once

#include <vulkan/vulkan.hpp>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>
#include <string>


#define PULSE_CORE

enum PsResult
{
	PS_SUCCESS = 1,
	PS_FAILURE = 0
};

enum PsRenderingMode
{
	PS_RENDERINGMODE_FORWARD,
	PS_RENDERINGMODE_DEFERRED,
	PS_RENDERINGMODE_VR
};