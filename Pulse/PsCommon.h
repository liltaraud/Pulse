#pragma once

// SHARED CORE COMPONENTS -----------------------
#include "Core/Log/Log.h"

#define PULSE_API

#ifdef PS_DEBUG
	#define PS_ASSERT(x, ...) { if(!(x)) { PS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PS_CORE_ASSERT(x, ...) { if(!(x)) { PS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PS_ASSERT(x, ...)
	#define PS_CORE_ASSERT(x, ...)
#endif

enum PsResult
{
	PS_SUCCESS,
	PS_FAILURE
};