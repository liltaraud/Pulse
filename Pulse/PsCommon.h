#pragma once

// SHARED CORE COMPONENTS -----------------------
#include "Core/Log/Log.h"

#define PULSE_API

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