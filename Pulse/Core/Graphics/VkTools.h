#pragma once

#define VK_CHECK_RESULT(f)																				\
{																										\
	VkResult res = (f);																					\
	if (res != VK_SUCCESS)																				\
	{																									\
		assert(res == VK_SUCCESS);																		\
	}																									\
}
