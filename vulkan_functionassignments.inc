      vkDestroyInstance := TvkDestroyInstance(GetProcAddress_vulkan('vkDestroyInstance'));
      vkEnumeratePhysicalDevices := TvkEnumeratePhysicalDevices(GetProcAddress_vulkan('vkEnumeratePhysicalDevices'));
      vkGetDeviceProcAddr := TvkGetDeviceProcAddr(GetProcAddress_vulkan('vkGetDeviceProcAddr'));
      vkGetPhysicalDeviceProperties := TvkGetPhysicalDeviceProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceProperties'));
      vkGetPhysicalDeviceQueueFamilyProperties := TvkGetPhysicalDeviceQueueFamilyProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceQueueFamilyProperties'));
      vkGetPhysicalDeviceMemoryProperties := TvkGetPhysicalDeviceMemoryProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceMemoryProperties'));
      vkGetPhysicalDeviceFeatures := TvkGetPhysicalDeviceFeatures(GetProcAddress_vulkan('vkGetPhysicalDeviceFeatures'));
      vkGetPhysicalDeviceFormatProperties := TvkGetPhysicalDeviceFormatProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceFormatProperties'));
      vkGetPhysicalDeviceImageFormatProperties := TvkGetPhysicalDeviceImageFormatProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceImageFormatProperties'));
      vkCreateDevice := TvkCreateDevice(GetProcAddress_vulkan('vkCreateDevice'));
      vkDestroyDevice := TvkDestroyDevice(GetProcAddress_vulkan('vkDestroyDevice'));
      vkEnumerateDeviceLayerProperties := TvkEnumerateDeviceLayerProperties(GetProcAddress_vulkan('vkEnumerateDeviceLayerProperties'));
      vkEnumerateDeviceExtensionProperties := TvkEnumerateDeviceExtensionProperties(GetProcAddress_vulkan('vkEnumerateDeviceExtensionProperties'));
      vkGetDeviceQueue := TvkGetDeviceQueue(GetProcAddress_vulkan('vkGetDeviceQueue'));
      vkQueueSubmit := TvkQueueSubmit(GetProcAddress_vulkan('vkQueueSubmit'));
      vkQueueWaitIdle := TvkQueueWaitIdle(GetProcAddress_vulkan('vkQueueWaitIdle'));
      vkDeviceWaitIdle := TvkDeviceWaitIdle(GetProcAddress_vulkan('vkDeviceWaitIdle'));
      vkAllocateMemory := TvkAllocateMemory(GetProcAddress_vulkan('vkAllocateMemory'));
      vkFreeMemory := TvkFreeMemory(GetProcAddress_vulkan('vkFreeMemory'));
      vkMapMemory := TvkMapMemory(GetProcAddress_vulkan('vkMapMemory'));
      vkUnmapMemory := TvkUnmapMemory(GetProcAddress_vulkan('vkUnmapMemory'));
      vkFlushMappedMemoryRanges := TvkFlushMappedMemoryRanges(GetProcAddress_vulkan('vkFlushMappedMemoryRanges'));
      vkInvalidateMappedMemoryRanges := TvkInvalidateMappedMemoryRanges(GetProcAddress_vulkan('vkInvalidateMappedMemoryRanges'));
      vkGetDeviceMemoryCommitment := TvkGetDeviceMemoryCommitment(GetProcAddress_vulkan('vkGetDeviceMemoryCommitment'));
      vkGetBufferMemoryRequirements := TvkGetBufferMemoryRequirements(GetProcAddress_vulkan('vkGetBufferMemoryRequirements'));
      vkBindBufferMemory := TvkBindBufferMemory(GetProcAddress_vulkan('vkBindBufferMemory'));
      vkGetImageMemoryRequirements := TvkGetImageMemoryRequirements(GetProcAddress_vulkan('vkGetImageMemoryRequirements'));
      vkBindImageMemory := TvkBindImageMemory(GetProcAddress_vulkan('vkBindImageMemory'));
      vkGetImageSparseMemoryRequirements := TvkGetImageSparseMemoryRequirements(GetProcAddress_vulkan('vkGetImageSparseMemoryRequirements'));
      vkGetPhysicalDeviceSparseImageFormatProperties := TvkGetPhysicalDeviceSparseImageFormatProperties(GetProcAddress_vulkan('vkGetPhysicalDeviceSparseImageFormatProperties'));
      vkQueueBindSparse := TvkQueueBindSparse(GetProcAddress_vulkan('vkQueueBindSparse'));
      vkCreateFence := TvkCreateFence(GetProcAddress_vulkan('vkCreateFence'));
      vkDestroyFence := TvkDestroyFence(GetProcAddress_vulkan('vkDestroyFence'));
      vkResetFences := TvkResetFences(GetProcAddress_vulkan('vkResetFences'));
      vkGetFenceStatus := TvkGetFenceStatus(GetProcAddress_vulkan('vkGetFenceStatus'));
      vkWaitForFences := TvkWaitForFences(GetProcAddress_vulkan('vkWaitForFences'));
      vkCreateSemaphore := TvkCreateSemaphore(GetProcAddress_vulkan('vkCreateSemaphore'));
      vkDestroySemaphore := TvkDestroySemaphore(GetProcAddress_vulkan('vkDestroySemaphore'));
      vkCreateEvent := TvkCreateEvent(GetProcAddress_vulkan('vkCreateEvent'));
      vkDestroyEvent := TvkDestroyEvent(GetProcAddress_vulkan('vkDestroyEvent'));
      vkGetEventStatus := TvkGetEventStatus(GetProcAddress_vulkan('vkGetEventStatus'));
      vkSetEvent := TvkSetEvent(GetProcAddress_vulkan('vkSetEvent'));
      vkResetEvent := TvkResetEvent(GetProcAddress_vulkan('vkResetEvent'));
      vkCreateQueryPool := TvkCreateQueryPool(GetProcAddress_vulkan('vkCreateQueryPool'));
      vkDestroyQueryPool := TvkDestroyQueryPool(GetProcAddress_vulkan('vkDestroyQueryPool'));
      vkGetQueryPoolResults := TvkGetQueryPoolResults(GetProcAddress_vulkan('vkGetQueryPoolResults'));
      vkCreateBuffer := TvkCreateBuffer(GetProcAddress_vulkan('vkCreateBuffer'));
      vkDestroyBuffer := TvkDestroyBuffer(GetProcAddress_vulkan('vkDestroyBuffer'));
      vkCreateBufferView := TvkCreateBufferView(GetProcAddress_vulkan('vkCreateBufferView'));
      vkDestroyBufferView := TvkDestroyBufferView(GetProcAddress_vulkan('vkDestroyBufferView'));
      vkCreateImage := TvkCreateImage(GetProcAddress_vulkan('vkCreateImage'));
      vkDestroyImage := TvkDestroyImage(GetProcAddress_vulkan('vkDestroyImage'));
      vkGetImageSubresourceLayout := TvkGetImageSubresourceLayout(GetProcAddress_vulkan('vkGetImageSubresourceLayout'));
      vkCreateImageView := TvkCreateImageView(GetProcAddress_vulkan('vkCreateImageView'));
      vkDestroyImageView := TvkDestroyImageView(GetProcAddress_vulkan('vkDestroyImageView'));
      vkCreateShaderModule := TvkCreateShaderModule(GetProcAddress_vulkan('vkCreateShaderModule'));
      vkDestroyShaderModule := TvkDestroyShaderModule(GetProcAddress_vulkan('vkDestroyShaderModule'));
      vkCreatePipelineCache := TvkCreatePipelineCache(GetProcAddress_vulkan('vkCreatePipelineCache'));
      vkDestroyPipelineCache := TvkDestroyPipelineCache(GetProcAddress_vulkan('vkDestroyPipelineCache'));
      vkGetPipelineCacheData := TvkGetPipelineCacheData(GetProcAddress_vulkan('vkGetPipelineCacheData'));
      vkMergePipelineCaches := TvkMergePipelineCaches(GetProcAddress_vulkan('vkMergePipelineCaches'));
      vkCreateGraphicsPipelines := TvkCreateGraphicsPipelines(GetProcAddress_vulkan('vkCreateGraphicsPipelines'));
      vkCreateComputePipelines := TvkCreateComputePipelines(GetProcAddress_vulkan('vkCreateComputePipelines'));
      vkDestroyPipeline := TvkDestroyPipeline(GetProcAddress_vulkan('vkDestroyPipeline'));
      vkCreatePipelineLayout := TvkCreatePipelineLayout(GetProcAddress_vulkan('vkCreatePipelineLayout'));
      vkDestroyPipelineLayout := TvkDestroyPipelineLayout(GetProcAddress_vulkan('vkDestroyPipelineLayout'));
      vkCreateSampler := TvkCreateSampler(GetProcAddress_vulkan('vkCreateSampler'));
      vkDestroySampler := TvkDestroySampler(GetProcAddress_vulkan('vkDestroySampler'));
      vkCreateDescriptorSetLayout := TvkCreateDescriptorSetLayout(GetProcAddress_vulkan('vkCreateDescriptorSetLayout'));
      vkDestroyDescriptorSetLayout := TvkDestroyDescriptorSetLayout(GetProcAddress_vulkan('vkDestroyDescriptorSetLayout'));
      vkCreateDescriptorPool := TvkCreateDescriptorPool(GetProcAddress_vulkan('vkCreateDescriptorPool'));
      vkDestroyDescriptorPool := TvkDestroyDescriptorPool(GetProcAddress_vulkan('vkDestroyDescriptorPool'));
      vkResetDescriptorPool := TvkResetDescriptorPool(GetProcAddress_vulkan('vkResetDescriptorPool'));
      vkAllocateDescriptorSets := TvkAllocateDescriptorSets(GetProcAddress_vulkan('vkAllocateDescriptorSets'));
      vkFreeDescriptorSets := TvkFreeDescriptorSets(GetProcAddress_vulkan('vkFreeDescriptorSets'));
      vkUpdateDescriptorSets := TvkUpdateDescriptorSets(GetProcAddress_vulkan('vkUpdateDescriptorSets'));
      vkCreateFramebuffer := TvkCreateFramebuffer(GetProcAddress_vulkan('vkCreateFramebuffer'));
      vkDestroyFramebuffer := TvkDestroyFramebuffer(GetProcAddress_vulkan('vkDestroyFramebuffer'));
      vkCreateRenderPass := TvkCreateRenderPass(GetProcAddress_vulkan('vkCreateRenderPass'));
      vkDestroyRenderPass := TvkDestroyRenderPass(GetProcAddress_vulkan('vkDestroyRenderPass'));
      vkGetRenderAreaGranularity := TvkGetRenderAreaGranularity(GetProcAddress_vulkan('vkGetRenderAreaGranularity'));
      vkCreateCommandPool := TvkCreateCommandPool(GetProcAddress_vulkan('vkCreateCommandPool'));
      vkDestroyCommandPool := TvkDestroyCommandPool(GetProcAddress_vulkan('vkDestroyCommandPool'));
      vkResetCommandPool := TvkResetCommandPool(GetProcAddress_vulkan('vkResetCommandPool'));
      vkAllocateCommandBuffers := TvkAllocateCommandBuffers(GetProcAddress_vulkan('vkAllocateCommandBuffers'));
      vkFreeCommandBuffers := TvkFreeCommandBuffers(GetProcAddress_vulkan('vkFreeCommandBuffers'));
      vkBeginCommandBuffer := TvkBeginCommandBuffer(GetProcAddress_vulkan('vkBeginCommandBuffer'));
      vkEndCommandBuffer := TvkEndCommandBuffer(GetProcAddress_vulkan('vkEndCommandBuffer'));
      vkResetCommandBuffer := TvkResetCommandBuffer(GetProcAddress_vulkan('vkResetCommandBuffer'));
      vkCmdBindPipeline := TvkCmdBindPipeline(GetProcAddress_vulkan('vkCmdBindPipeline'));
      vkCmdSetViewport := TvkCmdSetViewport(GetProcAddress_vulkan('vkCmdSetViewport'));
      vkCmdSetScissor := TvkCmdSetScissor(GetProcAddress_vulkan('vkCmdSetScissor'));
      vkCmdSetLineWidth := TvkCmdSetLineWidth(GetProcAddress_vulkan('vkCmdSetLineWidth'));
      vkCmdSetDepthBias := TvkCmdSetDepthBias(GetProcAddress_vulkan('vkCmdSetDepthBias'));
      vkCmdSetBlendConstants := TvkCmdSetBlendConstants(GetProcAddress_vulkan('vkCmdSetBlendConstants'));
      vkCmdSetDepthBounds := TvkCmdSetDepthBounds(GetProcAddress_vulkan('vkCmdSetDepthBounds'));
      vkCmdSetStencilCompareMask := TvkCmdSetStencilCompareMask(GetProcAddress_vulkan('vkCmdSetStencilCompareMask'));
      vkCmdSetStencilWriteMask := TvkCmdSetStencilWriteMask(GetProcAddress_vulkan('vkCmdSetStencilWriteMask'));
      vkCmdSetStencilReference := TvkCmdSetStencilReference(GetProcAddress_vulkan('vkCmdSetStencilReference'));
      vkCmdBindDescriptorSets := TvkCmdBindDescriptorSets(GetProcAddress_vulkan('vkCmdBindDescriptorSets'));
      vkCmdBindIndexBuffer := TvkCmdBindIndexBuffer(GetProcAddress_vulkan('vkCmdBindIndexBuffer'));
      vkCmdBindVertexBuffers := TvkCmdBindVertexBuffers(GetProcAddress_vulkan('vkCmdBindVertexBuffers'));
      vkCmdDraw := TvkCmdDraw(GetProcAddress_vulkan('vkCmdDraw'));
      vkCmdDrawIndexed := TvkCmdDrawIndexed(GetProcAddress_vulkan('vkCmdDrawIndexed'));
      vkCmdDrawIndirect := TvkCmdDrawIndirect(GetProcAddress_vulkan('vkCmdDrawIndirect'));
      vkCmdDrawIndexedIndirect := TvkCmdDrawIndexedIndirect(GetProcAddress_vulkan('vkCmdDrawIndexedIndirect'));
      vkCmdDispatch := TvkCmdDispatch(GetProcAddress_vulkan('vkCmdDispatch'));
      vkCmdDispatchIndirect := TvkCmdDispatchIndirect(GetProcAddress_vulkan('vkCmdDispatchIndirect'));
      vkCmdCopyBuffer := TvkCmdCopyBuffer(GetProcAddress_vulkan('vkCmdCopyBuffer'));
      vkCmdCopyImage := TvkCmdCopyImage(GetProcAddress_vulkan('vkCmdCopyImage'));
      vkCmdBlitImage := TvkCmdBlitImage(GetProcAddress_vulkan('vkCmdBlitImage'));
      vkCmdCopyBufferToImage := TvkCmdCopyBufferToImage(GetProcAddress_vulkan('vkCmdCopyBufferToImage'));
      vkCmdCopyImageToBuffer := TvkCmdCopyImageToBuffer(GetProcAddress_vulkan('vkCmdCopyImageToBuffer'));
      vkCmdUpdateBuffer := TvkCmdUpdateBuffer(GetProcAddress_vulkan('vkCmdUpdateBuffer'));
      vkCmdFillBuffer := TvkCmdFillBuffer(GetProcAddress_vulkan('vkCmdFillBuffer'));
      vkCmdClearColorImage := TvkCmdClearColorImage(GetProcAddress_vulkan('vkCmdClearColorImage'));
      vkCmdClearDepthStencilImage := TvkCmdClearDepthStencilImage(GetProcAddress_vulkan('vkCmdClearDepthStencilImage'));
      vkCmdClearAttachments := TvkCmdClearAttachments(GetProcAddress_vulkan('vkCmdClearAttachments'));
      vkCmdResolveImage := TvkCmdResolveImage(GetProcAddress_vulkan('vkCmdResolveImage'));
      vkCmdSetEvent := TvkCmdSetEvent(GetProcAddress_vulkan('vkCmdSetEvent'));
      vkCmdResetEvent := TvkCmdResetEvent(GetProcAddress_vulkan('vkCmdResetEvent'));
      vkCmdWaitEvents := TvkCmdWaitEvents(GetProcAddress_vulkan('vkCmdWaitEvents'));
      vkCmdPipelineBarrier := TvkCmdPipelineBarrier(GetProcAddress_vulkan('vkCmdPipelineBarrier'));
      vkCmdBeginQuery := TvkCmdBeginQuery(GetProcAddress_vulkan('vkCmdBeginQuery'));
      vkCmdEndQuery := TvkCmdEndQuery(GetProcAddress_vulkan('vkCmdEndQuery'));
      vkCmdResetQueryPool := TvkCmdResetQueryPool(GetProcAddress_vulkan('vkCmdResetQueryPool'));
      vkCmdWriteTimestamp := TvkCmdWriteTimestamp(GetProcAddress_vulkan('vkCmdWriteTimestamp'));
      vkCmdCopyQueryPoolResults := TvkCmdCopyQueryPoolResults(GetProcAddress_vulkan('vkCmdCopyQueryPoolResults'));
      vkCmdPushConstants := TvkCmdPushConstants(GetProcAddress_vulkan('vkCmdPushConstants'));
      vkCmdBeginRenderPass := TvkCmdBeginRenderPass(GetProcAddress_vulkan('vkCmdBeginRenderPass'));
      vkCmdNextSubpass := TvkCmdNextSubpass(GetProcAddress_vulkan('vkCmdNextSubpass'));
      vkCmdEndRenderPass := TvkCmdEndRenderPass(GetProcAddress_vulkan('vkCmdEndRenderPass'));
      vkCmdExecuteCommands := TvkCmdExecuteCommands(GetProcAddress_vulkan('vkCmdExecuteCommands'));
{$IFDEF VK_USE_PLATFORM_ANDROID_KHR}
      vkCreateAndroidSurfaceKHR := TvkCreateAndroidSurfaceKHR(GetProcAddress_vulkan('vkCreateAndroidSurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_ANDROID_KHR}
      vkGetPhysicalDeviceDisplayPropertiesKHR := TvkGetPhysicalDeviceDisplayPropertiesKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceDisplayPropertiesKHR'));
      vkGetPhysicalDeviceDisplayPlanePropertiesKHR := TvkGetPhysicalDeviceDisplayPlanePropertiesKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceDisplayPlanePropertiesKHR'));
      vkGetDisplayPlaneSupportedDisplaysKHR := TvkGetDisplayPlaneSupportedDisplaysKHR(GetProcAddress_vulkan('vkGetDisplayPlaneSupportedDisplaysKHR'));
      vkGetDisplayModePropertiesKHR := TvkGetDisplayModePropertiesKHR(GetProcAddress_vulkan('vkGetDisplayModePropertiesKHR'));
      vkCreateDisplayModeKHR := TvkCreateDisplayModeKHR(GetProcAddress_vulkan('vkCreateDisplayModeKHR'));
      vkGetDisplayPlaneCapabilitiesKHR := TvkGetDisplayPlaneCapabilitiesKHR(GetProcAddress_vulkan('vkGetDisplayPlaneCapabilitiesKHR'));
      vkCreateDisplayPlaneSurfaceKHR := TvkCreateDisplayPlaneSurfaceKHR(GetProcAddress_vulkan('vkCreateDisplayPlaneSurfaceKHR'));
      vkCreateSharedSwapchainsKHR := TvkCreateSharedSwapchainsKHR(GetProcAddress_vulkan('vkCreateSharedSwapchainsKHR'));
{$IFDEF VK_USE_PLATFORM_MIR_KHR}
      vkCreateMirSurfaceKHR := TvkCreateMirSurfaceKHR(GetProcAddress_vulkan('vkCreateMirSurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_MIR_KHR}
{$IFDEF VK_USE_PLATFORM_MIR_KHR}
      vkGetPhysicalDeviceMirPresentationSupportKHR := TvkGetPhysicalDeviceMirPresentationSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceMirPresentationSupportKHR'));
{$ENDIF VK_USE_PLATFORM_MIR_KHR}
      vkDestroySurfaceKHR := TvkDestroySurfaceKHR(GetProcAddress_vulkan('vkDestroySurfaceKHR'));
      vkGetPhysicalDeviceSurfaceSupportKHR := TvkGetPhysicalDeviceSurfaceSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceSurfaceSupportKHR'));
      vkGetPhysicalDeviceSurfaceCapabilitiesKHR := TvkGetPhysicalDeviceSurfaceCapabilitiesKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceSurfaceCapabilitiesKHR'));
      vkGetPhysicalDeviceSurfaceFormatsKHR := TvkGetPhysicalDeviceSurfaceFormatsKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceSurfaceFormatsKHR'));
      vkGetPhysicalDeviceSurfacePresentModesKHR := TvkGetPhysicalDeviceSurfacePresentModesKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceSurfacePresentModesKHR'));
      vkCreateSwapchainKHR := TvkCreateSwapchainKHR(GetProcAddress_vulkan('vkCreateSwapchainKHR'));
      vkDestroySwapchainKHR := TvkDestroySwapchainKHR(GetProcAddress_vulkan('vkDestroySwapchainKHR'));
      vkGetSwapchainImagesKHR := TvkGetSwapchainImagesKHR(GetProcAddress_vulkan('vkGetSwapchainImagesKHR'));
      vkAcquireNextImageKHR := TvkAcquireNextImageKHR(GetProcAddress_vulkan('vkAcquireNextImageKHR'));
      vkQueuePresentKHR := TvkQueuePresentKHR(GetProcAddress_vulkan('vkQueuePresentKHR'));
{$IFDEF VK_USE_PLATFORM_VI_NN}
      vkCreateViSurfaceNN := TvkCreateViSurfaceNN(GetProcAddress_vulkan('vkCreateViSurfaceNN'));
{$ENDIF VK_USE_PLATFORM_VI_NN}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
      vkCreateWaylandSurfaceKHR := TvkCreateWaylandSurfaceKHR(GetProcAddress_vulkan('vkCreateWaylandSurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
      vkGetPhysicalDeviceWaylandPresentationSupportKHR := TvkGetPhysicalDeviceWaylandPresentationSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceWaylandPresentationSupportKHR'));
{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
      vkCreateWin32SurfaceKHR := TvkCreateWin32SurfaceKHR(GetProcAddress_vulkan('vkCreateWin32SurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
      vkGetPhysicalDeviceWin32PresentationSupportKHR := TvkGetPhysicalDeviceWin32PresentationSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceWin32PresentationSupportKHR'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
      vkCreateXlibSurfaceKHR := TvkCreateXlibSurfaceKHR(GetProcAddress_vulkan('vkCreateXlibSurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
      vkGetPhysicalDeviceXlibPresentationSupportKHR := TvkGetPhysicalDeviceXlibPresentationSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceXlibPresentationSupportKHR'));
{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
      vkCreateXcbSurfaceKHR := TvkCreateXcbSurfaceKHR(GetProcAddress_vulkan('vkCreateXcbSurfaceKHR'));
{$ENDIF VK_USE_PLATFORM_XCB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
      vkGetPhysicalDeviceXcbPresentationSupportKHR := TvkGetPhysicalDeviceXcbPresentationSupportKHR(GetProcAddress_vulkan('vkGetPhysicalDeviceXcbPresentationSupportKHR'));
{$ENDIF VK_USE_PLATFORM_XCB_KHR}
      vkCreateDebugReportCallbackEXT := TvkCreateDebugReportCallbackEXT(GetProcAddress_vulkan('vkCreateDebugReportCallbackEXT'));
      vkDestroyDebugReportCallbackEXT := TvkDestroyDebugReportCallbackEXT(GetProcAddress_vulkan('vkDestroyDebugReportCallbackEXT'));
      vkDebugReportMessageEXT := TvkDebugReportMessageEXT(GetProcAddress_vulkan('vkDebugReportMessageEXT'));
      vkDebugMarkerSetObjectNameEXT := TvkDebugMarkerSetObjectNameEXT(GetProcAddress_vulkan('vkDebugMarkerSetObjectNameEXT'));
      vkDebugMarkerSetObjectTagEXT := TvkDebugMarkerSetObjectTagEXT(GetProcAddress_vulkan('vkDebugMarkerSetObjectTagEXT'));
      vkCmdDebugMarkerBeginEXT := TvkCmdDebugMarkerBeginEXT(GetProcAddress_vulkan('vkCmdDebugMarkerBeginEXT'));
      vkCmdDebugMarkerEndEXT := TvkCmdDebugMarkerEndEXT(GetProcAddress_vulkan('vkCmdDebugMarkerEndEXT'));
      vkCmdDebugMarkerInsertEXT := TvkCmdDebugMarkerInsertEXT(GetProcAddress_vulkan('vkCmdDebugMarkerInsertEXT'));
      vkGetPhysicalDeviceExternalImageFormatPropertiesNV := TvkGetPhysicalDeviceExternalImageFormatPropertiesNV(GetProcAddress_vulkan('vkGetPhysicalDeviceExternalImageFormatPropertiesNV'));
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
      vkGetMemoryWin32HandleNV := TvkGetMemoryWin32HandleNV(GetProcAddress_vulkan('vkGetMemoryWin32HandleNV'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
      vkCmdDrawIndirectCountAMD := TvkCmdDrawIndirectCountAMD(GetProcAddress_vulkan('vkCmdDrawIndirectCountAMD'));
      vkCmdDrawIndexedIndirectCountAMD := TvkCmdDrawIndexedIndirectCountAMD(GetProcAddress_vulkan('vkCmdDrawIndexedIndirectCountAMD'));
      vkCmdProcessCommandsNVX := TvkCmdProcessCommandsNVX(GetProcAddress_vulkan('vkCmdProcessCommandsNVX'));
      vkCmdReserveSpaceForCommandsNVX := TvkCmdReserveSpaceForCommandsNVX(GetProcAddress_vulkan('vkCmdReserveSpaceForCommandsNVX'));
      vkCreateIndirectCommandsLayoutNVX := TvkCreateIndirectCommandsLayoutNVX(GetProcAddress_vulkan('vkCreateIndirectCommandsLayoutNVX'));
      vkDestroyIndirectCommandsLayoutNVX := TvkDestroyIndirectCommandsLayoutNVX(GetProcAddress_vulkan('vkDestroyIndirectCommandsLayoutNVX'));
      vkCreateObjectTableNVX := TvkCreateObjectTableNVX(GetProcAddress_vulkan('vkCreateObjectTableNVX'));
      vkDestroyObjectTableNVX := TvkDestroyObjectTableNVX(GetProcAddress_vulkan('vkDestroyObjectTableNVX'));
      vkRegisterObjectsNVX := TvkRegisterObjectsNVX(GetProcAddress_vulkan('vkRegisterObjectsNVX'));
      vkUnregisterObjectsNVX := TvkUnregisterObjectsNVX(GetProcAddress_vulkan('vkUnregisterObjectsNVX'));
      vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX := TvkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(GetProcAddress_vulkan('vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX'));
      vkGetPhysicalDeviceFeatures2KHR := TvkGetPhysicalDeviceFeatures2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceFeatures2KHR'));
      vkGetPhysicalDeviceProperties2KHR := TvkGetPhysicalDeviceProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceProperties2KHR'));
      vkGetPhysicalDeviceFormatProperties2KHR := TvkGetPhysicalDeviceFormatProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceFormatProperties2KHR'));
      vkGetPhysicalDeviceImageFormatProperties2KHR := TvkGetPhysicalDeviceImageFormatProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceImageFormatProperties2KHR'));
      vkGetPhysicalDeviceQueueFamilyProperties2KHR := TvkGetPhysicalDeviceQueueFamilyProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceQueueFamilyProperties2KHR'));
      vkGetPhysicalDeviceMemoryProperties2KHR := TvkGetPhysicalDeviceMemoryProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceMemoryProperties2KHR'));
      vkGetPhysicalDeviceSparseImageFormatProperties2KHR := TvkGetPhysicalDeviceSparseImageFormatProperties2KHR(GetProcAddress_vulkan('vkGetPhysicalDeviceSparseImageFormatProperties2KHR'));
      vkCmdPushDescriptorSetKHR := TvkCmdPushDescriptorSetKHR(GetProcAddress_vulkan('vkCmdPushDescriptorSetKHR'));
      vkTrimCommandPoolKHR := TvkTrimCommandPoolKHR(GetProcAddress_vulkan('vkTrimCommandPoolKHR'));
      vkGetPhysicalDeviceExternalBufferPropertiesKHX := TvkGetPhysicalDeviceExternalBufferPropertiesKHX(GetProcAddress_vulkan('vkGetPhysicalDeviceExternalBufferPropertiesKHX'));
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
      vkGetMemoryWin32HandleKHX := TvkGetMemoryWin32HandleKHX(GetProcAddress_vulkan('vkGetMemoryWin32HandleKHX'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
      vkGetMemoryWin32HandlePropertiesKHX := TvkGetMemoryWin32HandlePropertiesKHX(GetProcAddress_vulkan('vkGetMemoryWin32HandlePropertiesKHX'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
      vkGetMemoryFdKHX := TvkGetMemoryFdKHX(GetProcAddress_vulkan('vkGetMemoryFdKHX'));
      vkGetMemoryFdPropertiesKHX := TvkGetMemoryFdPropertiesKHX(GetProcAddress_vulkan('vkGetMemoryFdPropertiesKHX'));
      vkGetPhysicalDeviceExternalSemaphorePropertiesKHX := TvkGetPhysicalDeviceExternalSemaphorePropertiesKHX(GetProcAddress_vulkan('vkGetPhysicalDeviceExternalSemaphorePropertiesKHX'));
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
      vkGetSemaphoreWin32HandleKHX := TvkGetSemaphoreWin32HandleKHX(GetProcAddress_vulkan('vkGetSemaphoreWin32HandleKHX'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
      vkImportSemaphoreWin32HandleKHX := TvkImportSemaphoreWin32HandleKHX(GetProcAddress_vulkan('vkImportSemaphoreWin32HandleKHX'));
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
      vkGetSemaphoreFdKHX := TvkGetSemaphoreFdKHX(GetProcAddress_vulkan('vkGetSemaphoreFdKHX'));
      vkImportSemaphoreFdKHX := TvkImportSemaphoreFdKHX(GetProcAddress_vulkan('vkImportSemaphoreFdKHX'));
      vkReleaseDisplayEXT := TvkReleaseDisplayEXT(GetProcAddress_vulkan('vkReleaseDisplayEXT'));
{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
      vkAcquireXlibDisplayEXT := TvkAcquireXlibDisplayEXT(GetProcAddress_vulkan('vkAcquireXlibDisplayEXT'));
{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
      vkGetRandROutputDisplayEXT := TvkGetRandROutputDisplayEXT(GetProcAddress_vulkan('vkGetRandROutputDisplayEXT'));
{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
      vkDisplayPowerControlEXT := TvkDisplayPowerControlEXT(GetProcAddress_vulkan('vkDisplayPowerControlEXT'));
      vkRegisterDeviceEventEXT := TvkRegisterDeviceEventEXT(GetProcAddress_vulkan('vkRegisterDeviceEventEXT'));
      vkRegisterDisplayEventEXT := TvkRegisterDisplayEventEXT(GetProcAddress_vulkan('vkRegisterDisplayEventEXT'));
      vkGetSwapchainCounterEXT := TvkGetSwapchainCounterEXT(GetProcAddress_vulkan('vkGetSwapchainCounterEXT'));
      vkGetPhysicalDeviceSurfaceCapabilities2EXT := TvkGetPhysicalDeviceSurfaceCapabilities2EXT(GetProcAddress_vulkan('vkGetPhysicalDeviceSurfaceCapabilities2EXT'));
      vkEnumeratePhysicalDeviceGroupsKHX := TvkEnumeratePhysicalDeviceGroupsKHX(GetProcAddress_vulkan('vkEnumeratePhysicalDeviceGroupsKHX'));
      vkGetDeviceGroupPeerMemoryFeaturesKHX := TvkGetDeviceGroupPeerMemoryFeaturesKHX(GetProcAddress_vulkan('vkGetDeviceGroupPeerMemoryFeaturesKHX'));
      vkBindBufferMemory2KHX := TvkBindBufferMemory2KHX(GetProcAddress_vulkan('vkBindBufferMemory2KHX'));
      vkBindImageMemory2KHX := TvkBindImageMemory2KHX(GetProcAddress_vulkan('vkBindImageMemory2KHX'));
      vkCmdSetDeviceMaskKHX := TvkCmdSetDeviceMaskKHX(GetProcAddress_vulkan('vkCmdSetDeviceMaskKHX'));
      vkGetDeviceGroupPresentCapabilitiesKHX := TvkGetDeviceGroupPresentCapabilitiesKHX(GetProcAddress_vulkan('vkGetDeviceGroupPresentCapabilitiesKHX'));
      vkGetDeviceGroupSurfacePresentModesKHX := TvkGetDeviceGroupSurfacePresentModesKHX(GetProcAddress_vulkan('vkGetDeviceGroupSurfacePresentModesKHX'));
      vkAcquireNextImage2KHX := TvkAcquireNextImage2KHX(GetProcAddress_vulkan('vkAcquireNextImage2KHX'));
      vkCmdDispatchBaseKHX := TvkCmdDispatchBaseKHX(GetProcAddress_vulkan('vkCmdDispatchBaseKHX'));
      vkGetPhysicalDevicePresentRectanglesKHX := TvkGetPhysicalDevicePresentRectanglesKHX(GetProcAddress_vulkan('vkGetPhysicalDevicePresentRectanglesKHX'));
      vkCreateDescriptorUpdateTemplateKHR := TvkCreateDescriptorUpdateTemplateKHR(GetProcAddress_vulkan('vkCreateDescriptorUpdateTemplateKHR'));
      vkDestroyDescriptorUpdateTemplateKHR := TvkDestroyDescriptorUpdateTemplateKHR(GetProcAddress_vulkan('vkDestroyDescriptorUpdateTemplateKHR'));
      vkUpdateDescriptorSetWithTemplateKHR := TvkUpdateDescriptorSetWithTemplateKHR(GetProcAddress_vulkan('vkUpdateDescriptorSetWithTemplateKHR'));
      vkCmdPushDescriptorSetWithTemplateKHR := TvkCmdPushDescriptorSetWithTemplateKHR(GetProcAddress_vulkan('vkCmdPushDescriptorSetWithTemplateKHR'));
      vkSetHdrMetadataEXT := TvkSetHdrMetadataEXT(GetProcAddress_vulkan('vkSetHdrMetadataEXT'));
      vkGetRefreshCycleDurationGOOGLE := TvkGetRefreshCycleDurationGOOGLE(GetProcAddress_vulkan('vkGetRefreshCycleDurationGOOGLE'));
      vkGetPastPresentationTimingGOOGLE := TvkGetPastPresentationTimingGOOGLE(GetProcAddress_vulkan('vkGetPastPresentationTimingGOOGLE'));
{$IFDEF VK_USE_PLATFORM_IOS_MVK}
      vkCreateIOSSurfaceMVK := TvkCreateIOSSurfaceMVK(GetProcAddress_vulkan('vkCreateIOSSurfaceMVK'));
{$ENDIF VK_USE_PLATFORM_IOS_MVK}
{$IFDEF VK_USE_PLATFORM_MACOS_MVK}
      vkCreateMacOSSurfaceMVK := TvkCreateMacOSSurfaceMVK(GetProcAddress_vulkan('vkCreateMacOSSurfaceMVK'));
{$ENDIF VK_USE_PLATFORM_MACOS_MVK}
      vkCmdSetViewportWScalingNV := TvkCmdSetViewportWScalingNV(GetProcAddress_vulkan('vkCmdSetViewportWScalingNV'));
      vkCmdSetDiscardRectangleEXT := TvkCmdSetDiscardRectangleEXT(GetProcAddress_vulkan('vkCmdSetDiscardRectangleEXT'));

