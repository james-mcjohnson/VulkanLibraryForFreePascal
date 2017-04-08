    function vkCreateInstance(pCreateInfo: PVkInstanceCreateInfo; pAllocator: PVkAllocationCallbacks; pInstance: PVkInstance): TVkResult;
    procedure vkDestroyInstance(instance: TVkInstance; pAllocator: PVkAllocationCallbacks);
    function vkEnumeratePhysicalDevices(instance: TVkInstance; pPhysicalDeviceCount: Puint32_t; pPhysicalDevices: PVkPhysicalDevice): TVkResult;
    function vkGetDeviceProcAddr(device: TVkDevice; pName: Pchar): TPFN_vkVoidFunction;
    function vkGetInstanceProcAddr(instance: TVkInstance; pName: Pchar): TPFN_vkVoidFunction;
    procedure vkGetPhysicalDeviceProperties(physicalDevice: TVkPhysicalDevice; pProperties: PVkPhysicalDeviceProperties);
    procedure vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice: TVkPhysicalDevice; pQueueFamilyPropertyCount: Puint32_t; pQueueFamilyProperties: PVkQueueFamilyProperties);
    procedure vkGetPhysicalDeviceMemoryProperties(physicalDevice: TVkPhysicalDevice; pMemoryProperties: PVkPhysicalDeviceMemoryProperties);
    procedure vkGetPhysicalDeviceFeatures(physicalDevice: TVkPhysicalDevice; pFeatures: PVkPhysicalDeviceFeatures);
    procedure vkGetPhysicalDeviceFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; pFormatProperties: PVkFormatProperties);
    function vkGetPhysicalDeviceImageFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; tiling: TVkImageTiling; usage: TVkImageUsageFlags; flags: TVkImageCreateFlags; pImageFormatProperties: PVkImageFormatProperties): TVkResult;
    function vkCreateDevice(physicalDevice: TVkPhysicalDevice; pCreateInfo: PVkDeviceCreateInfo; pAllocator: PVkAllocationCallbacks; pDevice: PVkDevice): TVkResult;
    procedure vkDestroyDevice(device: TVkDevice; pAllocator: PVkAllocationCallbacks);
    function vkEnumerateInstanceLayerProperties(pPropertyCount: Puint32_t; pProperties: PVkLayerProperties): TVkResult;
    function vkEnumerateInstanceExtensionProperties(pLayerName: Pchar; pPropertyCount: Puint32_t; pProperties: PVkExtensionProperties): TVkResult;
    function vkEnumerateDeviceLayerProperties(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkLayerProperties): TVkResult;
    function vkEnumerateDeviceExtensionProperties(physicalDevice: TVkPhysicalDevice; pLayerName: Pchar; pPropertyCount: Puint32_t; pProperties: PVkExtensionProperties): TVkResult;
    procedure vkGetDeviceQueue(device: TVkDevice; queueFamilyIndex: uint32_t; queueIndex: uint32_t; pQueue: PVkQueue);
    function vkQueueSubmit(queue: TVkQueue; submitCount: uint32_t; pSubmits: PVkSubmitInfo; fence: TVkFence): TVkResult;
    function vkQueueWaitIdle(queue: TVkQueue): TVkResult;
    function vkDeviceWaitIdle(device: TVkDevice): TVkResult;
    function vkAllocateMemory(device: TVkDevice; pAllocateInfo: PVkMemoryAllocateInfo; pAllocator: PVkAllocationCallbacks; pMemory: PVkDeviceMemory): TVkResult;
    procedure vkFreeMemory(device: TVkDevice; memory: TVkDeviceMemory; pAllocator: PVkAllocationCallbacks);
    function vkMapMemory(device: TVkDevice; memory: TVkDeviceMemory; offset: TVkDeviceSize; size: TVkDeviceSize; flags: TVkMemoryMapFlags; ppData: PPointer): TVkResult;
    procedure vkUnmapMemory(device: TVkDevice; memory: TVkDeviceMemory);
    function vkFlushMappedMemoryRanges(device: TVkDevice; memoryRangeCount: uint32_t; pMemoryRanges: PVkMappedMemoryRange): TVkResult;
    function vkInvalidateMappedMemoryRanges(device: TVkDevice; memoryRangeCount: uint32_t; pMemoryRanges: PVkMappedMemoryRange): TVkResult;
    procedure vkGetDeviceMemoryCommitment(device: TVkDevice; memory: TVkDeviceMemory; pCommittedMemoryInBytes: PVkDeviceSize);
    procedure vkGetBufferMemoryRequirements(device: TVkDevice; buffer: TVkBuffer; pMemoryRequirements: PVkMemoryRequirements);
    function vkBindBufferMemory(device: TVkDevice; buffer: TVkBuffer; memory: TVkDeviceMemory; memoryOffset: TVkDeviceSize): TVkResult;
    procedure vkGetImageMemoryRequirements(device: TVkDevice; image: TVkImage; pMemoryRequirements: PVkMemoryRequirements);
    function vkBindImageMemory(device: TVkDevice; image: TVkImage; memory: TVkDeviceMemory; memoryOffset: TVkDeviceSize): TVkResult;
    procedure vkGetImageSparseMemoryRequirements(device: TVkDevice; image: TVkImage; pSparseMemoryRequirementCount: Puint32_t; pSparseMemoryRequirements: PVkSparseImageMemoryRequirements);
    procedure vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; samples: TVkSampleCountFlagBits; usage: TVkImageUsageFlags; tiling: TVkImageTiling; pPropertyCount: Puint32_t; pProperties: PVkSparseImageFormatProperties);
    function vkQueueBindSparse(queue: TVkQueue; bindInfoCount: uint32_t; pBindInfo: PVkBindSparseInfo; fence: TVkFence): TVkResult;
    function vkCreateFence(device: TVkDevice; pCreateInfo: PVkFenceCreateInfo; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
    procedure vkDestroyFence(device: TVkDevice; fence: TVkFence; pAllocator: PVkAllocationCallbacks);
    function vkResetFences(device: TVkDevice; fenceCount: uint32_t; pFences: PVkFence): TVkResult;
    function vkGetFenceStatus(device: TVkDevice; fence: TVkFence): TVkResult;
    function vkWaitForFences(device: TVkDevice; fenceCount: uint32_t; pFences: PVkFence; waitAll: TVkBool32; timeout: uint64_t): TVkResult;
    function vkCreateSemaphore(device: TVkDevice; pCreateInfo: PVkSemaphoreCreateInfo; pAllocator: PVkAllocationCallbacks; pSemaphore: PVkSemaphore): TVkResult;
    procedure vkDestroySemaphore(device: TVkDevice; semaphore: TVkSemaphore; pAllocator: PVkAllocationCallbacks);
    function vkCreateEvent(device: TVkDevice; pCreateInfo: PVkEventCreateInfo; pAllocator: PVkAllocationCallbacks; pEvent: PVkEvent): TVkResult;
    procedure vkDestroyEvent(device: TVkDevice; event: TVkEvent; pAllocator: PVkAllocationCallbacks);
    function vkGetEventStatus(device: TVkDevice; event: TVkEvent): TVkResult;
    function vkSetEvent(device: TVkDevice; event: TVkEvent): TVkResult;
    function vkResetEvent(device: TVkDevice; event: TVkEvent): TVkResult;
    function vkCreateQueryPool(device: TVkDevice; pCreateInfo: PVkQueryPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pQueryPool: PVkQueryPool): TVkResult;
    procedure vkDestroyQueryPool(device: TVkDevice; queryPool: TVkQueryPool; pAllocator: PVkAllocationCallbacks);
    function vkGetQueryPoolResults(device: TVkDevice; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t; dataSize: size_t; pData: Pointer; stride: TVkDeviceSize; flags: TVkQueryResultFlags): TVkResult;
    function vkCreateBuffer(device: TVkDevice; pCreateInfo: PVkBufferCreateInfo; pAllocator: PVkAllocationCallbacks; pBuffer: PVkBuffer): TVkResult;
    procedure vkDestroyBuffer(device: TVkDevice; buffer: TVkBuffer; pAllocator: PVkAllocationCallbacks);
    function vkCreateBufferView(device: TVkDevice; pCreateInfo: PVkBufferViewCreateInfo; pAllocator: PVkAllocationCallbacks; pView: PVkBufferView): TVkResult;
    procedure vkDestroyBufferView(device: TVkDevice; bufferView: TVkBufferView; pAllocator: PVkAllocationCallbacks);
    function vkCreateImage(device: TVkDevice; pCreateInfo: PVkImageCreateInfo; pAllocator: PVkAllocationCallbacks; pImage: PVkImage): TVkResult;
    procedure vkDestroyImage(device: TVkDevice; image: TVkImage; pAllocator: PVkAllocationCallbacks);
    procedure vkGetImageSubresourceLayout(device: TVkDevice; image: TVkImage; pSubresource: PVkImageSubresource; pLayout: PVkSubresourceLayout);
    function vkCreateImageView(device: TVkDevice; pCreateInfo: PVkImageViewCreateInfo; pAllocator: PVkAllocationCallbacks; pView: PVkImageView): TVkResult;
    procedure vkDestroyImageView(device: TVkDevice; imageView: TVkImageView; pAllocator: PVkAllocationCallbacks);
    function vkCreateShaderModule(device: TVkDevice; pCreateInfo: PVkShaderModuleCreateInfo; pAllocator: PVkAllocationCallbacks; pShaderModule: PVkShaderModule): TVkResult;
    procedure vkDestroyShaderModule(device: TVkDevice; shaderModule: TVkShaderModule; pAllocator: PVkAllocationCallbacks);
    function vkCreatePipelineCache(device: TVkDevice; pCreateInfo: PVkPipelineCacheCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelineCache: PVkPipelineCache): TVkResult;
    procedure vkDestroyPipelineCache(device: TVkDevice; pipelineCache: TVkPipelineCache; pAllocator: PVkAllocationCallbacks);
    function vkGetPipelineCacheData(device: TVkDevice; pipelineCache: TVkPipelineCache; pDataSize: Psize_t; pData: Pointer): TVkResult;
    function vkMergePipelineCaches(device: TVkDevice; dstCache: TVkPipelineCache; srcCacheCount: uint32_t; pSrcCaches: PVkPipelineCache): TVkResult;
    function vkCreateGraphicsPipelines(device: TVkDevice; pipelineCache: TVkPipelineCache; createInfoCount: uint32_t; pCreateInfos: PVkGraphicsPipelineCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelines: PVkPipeline): TVkResult;
    function vkCreateComputePipelines(device: TVkDevice; pipelineCache: TVkPipelineCache; createInfoCount: uint32_t; pCreateInfos: PVkComputePipelineCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelines: PVkPipeline): TVkResult;
    procedure vkDestroyPipeline(device: TVkDevice; pipeline: TVkPipeline; pAllocator: PVkAllocationCallbacks);
    function vkCreatePipelineLayout(device: TVkDevice; pCreateInfo: PVkPipelineLayoutCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelineLayout: PVkPipelineLayout): TVkResult;
    procedure vkDestroyPipelineLayout(device: TVkDevice; pipelineLayout: TVkPipelineLayout; pAllocator: PVkAllocationCallbacks);
    function vkCreateSampler(device: TVkDevice; pCreateInfo: PVkSamplerCreateInfo; pAllocator: PVkAllocationCallbacks; pSampler: PVkSampler): TVkResult;
    procedure vkDestroySampler(device: TVkDevice; sampler: TVkSampler; pAllocator: PVkAllocationCallbacks);
    function vkCreateDescriptorSetLayout(device: TVkDevice; pCreateInfo: PVkDescriptorSetLayoutCreateInfo; pAllocator: PVkAllocationCallbacks; pSetLayout: PVkDescriptorSetLayout): TVkResult;
    procedure vkDestroyDescriptorSetLayout(device: TVkDevice; descriptorSetLayout: TVkDescriptorSetLayout; pAllocator: PVkAllocationCallbacks);
    function vkCreateDescriptorPool(device: TVkDevice; pCreateInfo: PVkDescriptorPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pDescriptorPool: PVkDescriptorPool): TVkResult;
    procedure vkDestroyDescriptorPool(device: TVkDevice; descriptorPool: TVkDescriptorPool; pAllocator: PVkAllocationCallbacks);
    function vkResetDescriptorPool(device: TVkDevice; descriptorPool: TVkDescriptorPool; flags: TVkDescriptorPoolResetFlags): TVkResult;
    function vkAllocateDescriptorSets(device: TVkDevice; pAllocateInfo: PVkDescriptorSetAllocateInfo; pDescriptorSets: PVkDescriptorSet): TVkResult;
    function vkFreeDescriptorSets(device: TVkDevice; descriptorPool: TVkDescriptorPool; descriptorSetCount: uint32_t; pDescriptorSets: PVkDescriptorSet): TVkResult;
    procedure vkUpdateDescriptorSets(device: TVkDevice; descriptorWriteCount: uint32_t; pDescriptorWrites: PVkWriteDescriptorSet; descriptorCopyCount: uint32_t; pDescriptorCopies: PVkCopyDescriptorSet);
    function vkCreateFramebuffer(device: TVkDevice; pCreateInfo: PVkFramebufferCreateInfo; pAllocator: PVkAllocationCallbacks; pFramebuffer: PVkFramebuffer): TVkResult;
    procedure vkDestroyFramebuffer(device: TVkDevice; framebuffer: TVkFramebuffer; pAllocator: PVkAllocationCallbacks);
    function vkCreateRenderPass(device: TVkDevice; pCreateInfo: PVkRenderPassCreateInfo; pAllocator: PVkAllocationCallbacks; pRenderPass: PVkRenderPass): TVkResult;
    procedure vkDestroyRenderPass(device: TVkDevice; renderPass: TVkRenderPass; pAllocator: PVkAllocationCallbacks);
    procedure vkGetRenderAreaGranularity(device: TVkDevice; renderPass: TVkRenderPass; pGranularity: PVkExtent2D);
    function vkCreateCommandPool(device: TVkDevice; pCreateInfo: PVkCommandPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pCommandPool: PVkCommandPool): TVkResult;
    procedure vkDestroyCommandPool(device: TVkDevice; commandPool: TVkCommandPool; pAllocator: PVkAllocationCallbacks);
    function vkResetCommandPool(device: TVkDevice; commandPool: TVkCommandPool; flags: TVkCommandPoolResetFlags): TVkResult;
    function vkAllocateCommandBuffers(device: TVkDevice; pAllocateInfo: PVkCommandBufferAllocateInfo; pCommandBuffers: PVkCommandBuffer): TVkResult;
    procedure vkFreeCommandBuffers(device: TVkDevice; commandPool: TVkCommandPool; commandBufferCount: uint32_t; pCommandBuffers: PVkCommandBuffer);
    function vkBeginCommandBuffer(commandBuffer: TVkCommandBuffer; pBeginInfo: PVkCommandBufferBeginInfo): TVkResult;
    function vkEndCommandBuffer(commandBuffer: TVkCommandBuffer): TVkResult;
    function vkResetCommandBuffer(commandBuffer: TVkCommandBuffer; flags: TVkCommandBufferResetFlags): TVkResult;
    procedure vkCmdBindPipeline(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; pipeline: TVkPipeline);
    procedure vkCmdSetViewport(commandBuffer: TVkCommandBuffer; firstViewport: uint32_t; viewportCount: uint32_t; pViewports: PVkViewport);
    procedure vkCmdSetScissor(commandBuffer: TVkCommandBuffer; firstScissor: uint32_t; scissorCount: uint32_t; pScissors: PVkRect2D);
    procedure vkCmdSetLineWidth(commandBuffer: TVkCommandBuffer; lineWidth: float);
    procedure vkCmdSetDepthBias(commandBuffer: TVkCommandBuffer; depthBiasConstantFactor: float; depthBiasClamp: float; depthBiasSlopeFactor: float);
    procedure vkCmdSetBlendConstants(commandBuffer: TVkCommandBuffer; blendConstants: Tfloat_0_3);
    procedure vkCmdSetDepthBounds(commandBuffer: TVkCommandBuffer; minDepthBounds: float; maxDepthBounds: float);
    procedure vkCmdSetStencilCompareMask(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; compareMask: uint32_t);
    procedure vkCmdSetStencilWriteMask(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; writeMask: uint32_t);
    procedure vkCmdSetStencilReference(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; reference: uint32_t);
    procedure vkCmdBindDescriptorSets(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; layout: TVkPipelineLayout; firstSet: uint32_t; descriptorSetCount: uint32_t; pDescriptorSets: PVkDescriptorSet; dynamicOffsetCount: uint32_t; pDynamicOffsets: Puint32_t);
    procedure vkCmdBindIndexBuffer(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; indexType: TVkIndexType);
    procedure vkCmdBindVertexBuffers(commandBuffer: TVkCommandBuffer; firstBinding: uint32_t; bindingCount: uint32_t; pBuffers: PVkBuffer; pOffsets: PVkDeviceSize);
    procedure vkCmdDraw(commandBuffer: TVkCommandBuffer; vertexCount: uint32_t; instanceCount: uint32_t; firstVertex: uint32_t; firstInstance: uint32_t);
    procedure vkCmdDrawIndexed(commandBuffer: TVkCommandBuffer; indexCount: uint32_t; instanceCount: uint32_t; firstIndex: uint32_t; vertexOffset: int32_t; firstInstance: uint32_t);
    procedure vkCmdDrawIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; drawCount: uint32_t; stride: uint32_t);
    procedure vkCmdDrawIndexedIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; drawCount: uint32_t; stride: uint32_t);
    procedure vkCmdDispatch(commandBuffer: TVkCommandBuffer; groupCountX: uint32_t; groupCountY: uint32_t; groupCountZ: uint32_t);
    procedure vkCmdDispatchIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize);
    procedure vkCmdCopyBuffer(commandBuffer: TVkCommandBuffer; srcBuffer: TVkBuffer; dstBuffer: TVkBuffer; regionCount: uint32_t; pRegions: PVkBufferCopy);
    procedure vkCmdCopyImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageCopy);
    procedure vkCmdBlitImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageBlit; filter: TVkFilter);
    procedure vkCmdCopyBufferToImage(commandBuffer: TVkCommandBuffer; srcBuffer: TVkBuffer; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkBufferImageCopy);
    procedure vkCmdCopyImageToBuffer(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstBuffer: TVkBuffer; regionCount: uint32_t; pRegions: PVkBufferImageCopy);
    procedure vkCmdUpdateBuffer(commandBuffer: TVkCommandBuffer; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; dataSize: TVkDeviceSize; pData: Pointer);
    procedure vkCmdFillBuffer(commandBuffer: TVkCommandBuffer; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; size: TVkDeviceSize; data: uint32_t);
    procedure vkCmdClearColorImage(commandBuffer: TVkCommandBuffer; image: TVkImage; imageLayout: TVkImageLayout; pColor: PVkClearColorValue; rangeCount: uint32_t; pRanges: PVkImageSubresourceRange);
    procedure vkCmdClearDepthStencilImage(commandBuffer: TVkCommandBuffer; image: TVkImage; imageLayout: TVkImageLayout; pDepthStencil: PVkClearDepthStencilValue; rangeCount: uint32_t; pRanges: PVkImageSubresourceRange);
    procedure vkCmdClearAttachments(commandBuffer: TVkCommandBuffer; attachmentCount: uint32_t; pAttachments: PVkClearAttachment; rectCount: uint32_t; pRects: PVkClearRect);
    procedure vkCmdResolveImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageResolve);
    procedure vkCmdSetEvent(commandBuffer: TVkCommandBuffer; event: TVkEvent; stageMask: TVkPipelineStageFlags);
    procedure vkCmdResetEvent(commandBuffer: TVkCommandBuffer; event: TVkEvent; stageMask: TVkPipelineStageFlags);
    procedure vkCmdWaitEvents(commandBuffer: TVkCommandBuffer; eventCount: uint32_t; pEvents: PVkEvent; srcStageMask: TVkPipelineStageFlags; dstStageMask: TVkPipelineStageFlags; memoryBarrierCount: uint32_t; pMemoryBarriers: PVkMemoryBarrier; bufferMemoryBarrierCount: uint32_t; pBufferMemoryBarriers: PVkBufferMemoryBarrier; imageMemoryBarrierCount: uint32_t; pImageMemoryBarriers: PVkImageMemoryBarrier);
    procedure vkCmdPipelineBarrier(commandBuffer: TVkCommandBuffer; srcStageMask: TVkPipelineStageFlags; dstStageMask: TVkPipelineStageFlags; dependencyFlags: TVkDependencyFlags; memoryBarrierCount: uint32_t; pMemoryBarriers: PVkMemoryBarrier; bufferMemoryBarrierCount: uint32_t; pBufferMemoryBarriers: PVkBufferMemoryBarrier; imageMemoryBarrierCount: uint32_t; pImageMemoryBarriers: PVkImageMemoryBarrier);
    procedure vkCmdBeginQuery(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; query: uint32_t; flags: TVkQueryControlFlags);
    procedure vkCmdEndQuery(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; query: uint32_t);
    procedure vkCmdResetQueryPool(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t);
    procedure vkCmdWriteTimestamp(commandBuffer: TVkCommandBuffer; pipelineStage: TVkPipelineStageFlagBits; queryPool: TVkQueryPool; query: uint32_t);
    procedure vkCmdCopyQueryPoolResults(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; stride: TVkDeviceSize; flags: TVkQueryResultFlags);
    procedure vkCmdPushConstants(commandBuffer: TVkCommandBuffer; layout: TVkPipelineLayout; stageFlags: TVkShaderStageFlags; offset: uint32_t; size: uint32_t; pValues: Pointer);
    procedure vkCmdBeginRenderPass(commandBuffer: TVkCommandBuffer; pRenderPassBegin: PVkRenderPassBeginInfo; contents: TVkSubpassContents);
    procedure vkCmdNextSubpass(commandBuffer: TVkCommandBuffer; contents: TVkSubpassContents);
    procedure vkCmdEndRenderPass(commandBuffer: TVkCommandBuffer);
    procedure vkCmdExecuteCommands(commandBuffer: TVkCommandBuffer; commandBufferCount: uint32_t; pCommandBuffers: PVkCommandBuffer);
{$IFDEF VK_USE_PLATFORM_ANDROID_KHR}
    function vkCreateAndroidSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkAndroidSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_ANDROID_KHR}
    function vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkDisplayPropertiesKHR): TVkResult;
    function vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkDisplayPlanePropertiesKHR): TVkResult;
    function vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice: TVkPhysicalDevice; planeIndex: uint32_t; pDisplayCount: Puint32_t; pDisplays: PVkDisplayKHR): TVkResult;
    function vkGetDisplayModePropertiesKHR(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR; pPropertyCount: Puint32_t; pProperties: PVkDisplayModePropertiesKHR): TVkResult;
    function vkCreateDisplayModeKHR(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR; pCreateInfo: PVkDisplayModeCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pMode: PVkDisplayModeKHR): TVkResult;
    function vkGetDisplayPlaneCapabilitiesKHR(physicalDevice: TVkPhysicalDevice; mode: TVkDisplayModeKHR; planeIndex: uint32_t; pCapabilities: PVkDisplayPlaneCapabilitiesKHR): TVkResult;
    function vkCreateDisplayPlaneSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkDisplaySurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
    function vkCreateSharedSwapchainsKHR(device: TVkDevice; swapchainCount: uint32_t; pCreateInfos: PVkSwapchainCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSwapchains: PVkSwapchainKHR): TVkResult;
{$IFDEF VK_USE_PLATFORM_MIR_KHR}
    function vkCreateMirSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkMirSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_MIR_KHR}
{$IFDEF VK_USE_PLATFORM_MIR_KHR}
    function vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; connection: PMirConnection): TVkBool32;
{$ENDIF VK_USE_PLATFORM_MIR_KHR}
    procedure vkDestroySurfaceKHR(instance: TVkInstance; surface: TVkSurfaceKHR; pAllocator: PVkAllocationCallbacks);
    function vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; surface: TVkSurfaceKHR; pSupported: PVkBool32): TVkResult;
    function vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceCapabilities: PVkSurfaceCapabilitiesKHR): TVkResult;
    function vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceFormatCount: Puint32_t; pSurfaceFormats: PVkSurfaceFormatKHR): TVkResult;
    function vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pPresentModeCount: Puint32_t; pPresentModes: PVkPresentModeKHR): TVkResult;
    function vkCreateSwapchainKHR(device: TVkDevice; pCreateInfo: PVkSwapchainCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSwapchain: PVkSwapchainKHR): TVkResult;
    procedure vkDestroySwapchainKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; pAllocator: PVkAllocationCallbacks);
    function vkGetSwapchainImagesKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; pSwapchainImageCount: Puint32_t; pSwapchainImages: PVkImage): TVkResult;
    function vkAcquireNextImageKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; timeout: uint64_t; semaphore: TVkSemaphore; fence: TVkFence; pImageIndex: Puint32_t): TVkResult;
    function vkQueuePresentKHR(queue: TVkQueue; pPresentInfo: PVkPresentInfoKHR): TVkResult;
{$IFDEF VK_USE_PLATFORM_VI_NN}
    function vkCreateViSurfaceNN(instance: TVkInstance; pCreateInfo: PVkViSurfaceCreateInfoNN; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_VI_NN}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
    function vkCreateWaylandSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkWaylandSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
    function vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; display: Pwl_display): TVkBool32;
{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
    function vkCreateWin32SurfaceKHR(instance: TVkInstance; pCreateInfo: PVkWin32SurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
    function vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t): TVkBool32;
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
    function vkCreateXlibSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkXlibSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
    function vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; dpy: PDisplay; visualID: TVisualID): TVkBool32;
{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
    function vkCreateXcbSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkXcbSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_XCB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
    function vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; connection: Pxcb_connection_t; visual_id: Txcb_visualid_t): TVkBool32;
{$ENDIF VK_USE_PLATFORM_XCB_KHR}
    function vkCreateDebugReportCallbackEXT(instance: TVkInstance; pCreateInfo: PVkDebugReportCallbackCreateInfoEXT; pAllocator: PVkAllocationCallbacks; pCallback: PVkDebugReportCallbackEXT): TVkResult;
    procedure vkDestroyDebugReportCallbackEXT(instance: TVkInstance; callback: TVkDebugReportCallbackEXT; pAllocator: PVkAllocationCallbacks);
    procedure vkDebugReportMessageEXT(instance: TVkInstance; flags: TVkDebugReportFlagsEXT; objectType: TVkDebugReportObjectTypeEXT; object_: uint64_t; location: size_t; messageCode: int32_t; pLayerPrefix: Pchar; pMessage: Pchar);
    function vkDebugMarkerSetObjectNameEXT(device: TVkDevice; pNameInfo: PVkDebugMarkerObjectNameInfoEXT): TVkResult;
    function vkDebugMarkerSetObjectTagEXT(device: TVkDevice; pTagInfo: PVkDebugMarkerObjectTagInfoEXT): TVkResult;
    procedure vkCmdDebugMarkerBeginEXT(commandBuffer: TVkCommandBuffer; pMarkerInfo: PVkDebugMarkerMarkerInfoEXT);
    procedure vkCmdDebugMarkerEndEXT(commandBuffer: TVkCommandBuffer);
    procedure vkCmdDebugMarkerInsertEXT(commandBuffer: TVkCommandBuffer; pMarkerInfo: PVkDebugMarkerMarkerInfoEXT);
    function vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; tiling: TVkImageTiling; usage: TVkImageUsageFlags; flags: TVkImageCreateFlags; externalHandleType: TVkExternalMemoryHandleTypeFlagsNV; pExternalImageFormatProperties: PVkExternalImageFormatPropertiesNV): TVkResult;
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
    function vkGetMemoryWin32HandleNV(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagsNV; pHandle: PHANDLE): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
    procedure vkCmdDrawIndirectCountAMD(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; countBuffer: TVkBuffer; countBufferOffset: TVkDeviceSize; maxDrawCount: uint32_t; stride: uint32_t);
    procedure vkCmdDrawIndexedIndirectCountAMD(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; countBuffer: TVkBuffer; countBufferOffset: TVkDeviceSize; maxDrawCount: uint32_t; stride: uint32_t);
    procedure vkCmdProcessCommandsNVX(commandBuffer: TVkCommandBuffer; pProcessCommandsInfo: PVkCmdProcessCommandsInfoNVX);
    procedure vkCmdReserveSpaceForCommandsNVX(commandBuffer: TVkCommandBuffer; pReserveSpaceInfo: PVkCmdReserveSpaceForCommandsInfoNVX);
    function vkCreateIndirectCommandsLayoutNVX(device: TVkDevice; pCreateInfo: PVkIndirectCommandsLayoutCreateInfoNVX; pAllocator: PVkAllocationCallbacks; pIndirectCommandsLayout: PVkIndirectCommandsLayoutNVX): TVkResult;
    procedure vkDestroyIndirectCommandsLayoutNVX(device: TVkDevice; indirectCommandsLayout: TVkIndirectCommandsLayoutNVX; pAllocator: PVkAllocationCallbacks);
    function vkCreateObjectTableNVX(device: TVkDevice; pCreateInfo: PVkObjectTableCreateInfoNVX; pAllocator: PVkAllocationCallbacks; pObjectTable: PVkObjectTableNVX): TVkResult;
    procedure vkDestroyObjectTableNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; pAllocator: PVkAllocationCallbacks);
    function vkRegisterObjectsNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; objectCount: uint32_t; ppObjectTableEntries: PPVkObjectTableEntryNVX; pObjectIndices: Puint32_t): TVkResult;
    function vkUnregisterObjectsNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; objectCount: uint32_t; pObjectEntryTypes: PVkObjectEntryTypeNVX; pObjectIndices: Puint32_t): TVkResult;
    procedure vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice: TVkPhysicalDevice; pFeatures: PVkDeviceGeneratedCommandsFeaturesNVX; pLimits: PVkDeviceGeneratedCommandsLimitsNVX);
    procedure vkGetPhysicalDeviceFeatures2KHR(physicalDevice: TVkPhysicalDevice; pFeatures: PVkPhysicalDeviceFeatures2KHR);
    procedure vkGetPhysicalDeviceProperties2KHR(physicalDevice: TVkPhysicalDevice; pProperties: PVkPhysicalDeviceProperties2KHR);
    procedure vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; format: TVkFormat; pFormatProperties: PVkFormatProperties2KHR);
    function vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; pImageFormatInfo: PVkPhysicalDeviceImageFormatInfo2KHR; pImageFormatProperties: PVkImageFormatProperties2KHR): TVkResult;
    procedure vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice: TVkPhysicalDevice; pQueueFamilyPropertyCount: Puint32_t; pQueueFamilyProperties: PVkQueueFamilyProperties2KHR);
    procedure vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice: TVkPhysicalDevice; pMemoryProperties: PVkPhysicalDeviceMemoryProperties2KHR);
    procedure vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; pFormatInfo: PVkPhysicalDeviceSparseImageFormatInfo2KHR; pPropertyCount: Puint32_t; pProperties: PVkSparseImageFormatProperties2KHR);
    procedure vkCmdPushDescriptorSetKHR(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; layout: TVkPipelineLayout; set_: uint32_t; descriptorWriteCount: uint32_t; pDescriptorWrites: PVkWriteDescriptorSet);
    procedure vkTrimCommandPoolKHR(device: TVkDevice; commandPool: TVkCommandPool; flags: TVkCommandPoolTrimFlagsKHR);
    procedure vkGetPhysicalDeviceExternalBufferPropertiesKHX(physicalDevice: TVkPhysicalDevice; pExternalBufferInfo: PVkPhysicalDeviceExternalBufferInfoKHX; pExternalBufferProperties: PVkExternalBufferPropertiesKHX);
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
    function vkGetMemoryWin32HandleKHX(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; pHandle: PHANDLE): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
    function vkGetMemoryWin32HandlePropertiesKHX(device: TVkDevice; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; handle: THANDLE; pMemoryWin32HandleProperties: PVkMemoryWin32HandlePropertiesKHX): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
    function vkGetMemoryFdKHX(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; pFd: Pint): TVkResult;
    function vkGetMemoryFdPropertiesKHX(device: TVkDevice; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; fd: int; pMemoryFdProperties: PVkMemoryFdPropertiesKHX): TVkResult;
    procedure vkGetPhysicalDeviceExternalSemaphorePropertiesKHX(physicalDevice: TVkPhysicalDevice; pExternalSemaphoreInfo: PVkPhysicalDeviceExternalSemaphoreInfoKHX; pExternalSemaphoreProperties: PVkExternalSemaphorePropertiesKHX);
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
    function vkGetSemaphoreWin32HandleKHX(device: TVkDevice; semaphore: TVkSemaphore; handleType: TVkExternalSemaphoreHandleTypeFlagBitsKHX; pHandle: PHANDLE): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
    function vkImportSemaphoreWin32HandleKHX(device: TVkDevice; pImportSemaphoreWin32HandleInfo: PVkImportSemaphoreWin32HandleInfoKHX): TVkResult;
{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
    function vkGetSemaphoreFdKHX(device: TVkDevice; semaphore: TVkSemaphore; handleType: TVkExternalSemaphoreHandleTypeFlagBitsKHX; pFd: Pint): TVkResult;
    function vkImportSemaphoreFdKHX(device: TVkDevice; pImportSemaphoreFdInfo: PVkImportSemaphoreFdInfoKHX): TVkResult;
    function vkReleaseDisplayEXT(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR): TVkResult;
{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
    function vkAcquireXlibDisplayEXT(physicalDevice: TVkPhysicalDevice; dpy: PDisplay; display: TVkDisplayKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
    function vkGetRandROutputDisplayEXT(physicalDevice: TVkPhysicalDevice; dpy: PDisplay; rrOutput: TRROutput; pDisplay: PVkDisplayKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
    function vkDisplayPowerControlEXT(device: TVkDevice; display: TVkDisplayKHR; pDisplayPowerInfo: PVkDisplayPowerInfoEXT): TVkResult;
    function vkRegisterDeviceEventEXT(device: TVkDevice; pDeviceEventInfo: PVkDeviceEventInfoEXT; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
    function vkRegisterDisplayEventEXT(device: TVkDevice; display: TVkDisplayKHR; pDisplayEventInfo: PVkDisplayEventInfoEXT; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
    function vkGetSwapchainCounterEXT(device: TVkDevice; swapchain: TVkSwapchainKHR; counter: TVkSurfaceCounterFlagBitsEXT; pCounterValue: Puint64_t): TVkResult;
    function vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceCapabilities: PVkSurfaceCapabilities2EXT): TVkResult;
    function vkEnumeratePhysicalDeviceGroupsKHX(instance: TVkInstance; pPhysicalDeviceGroupCount: Puint32_t; pPhysicalDeviceGroupProperties: PVkPhysicalDeviceGroupPropertiesKHX): TVkResult;
    procedure vkGetDeviceGroupPeerMemoryFeaturesKHX(device: TVkDevice; heapIndex: uint32_t; localDeviceIndex: uint32_t; remoteDeviceIndex: uint32_t; pPeerMemoryFeatures: PVkPeerMemoryFeatureFlagsKHX);
    function vkBindBufferMemory2KHX(device: TVkDevice; bindInfoCount: uint32_t; pBindInfos: PVkBindBufferMemoryInfoKHX): TVkResult;
    function vkBindImageMemory2KHX(device: TVkDevice; bindInfoCount: uint32_t; pBindInfos: PVkBindImageMemoryInfoKHX): TVkResult;
    procedure vkCmdSetDeviceMaskKHX(commandBuffer: TVkCommandBuffer; deviceMask: uint32_t);
    function vkGetDeviceGroupPresentCapabilitiesKHX(device: TVkDevice; pDeviceGroupPresentCapabilities: PVkDeviceGroupPresentCapabilitiesKHX): TVkResult;
    function vkGetDeviceGroupSurfacePresentModesKHX(device: TVkDevice; surface: TVkSurfaceKHR; pModes: PVkDeviceGroupPresentModeFlagsKHX): TVkResult;
    function vkAcquireNextImage2KHX(device: TVkDevice; pAcquireInfo: PVkAcquireNextImageInfoKHX; pImageIndex: Puint32_t): TVkResult;
    procedure vkCmdDispatchBaseKHX(commandBuffer: TVkCommandBuffer; baseGroupX: uint32_t; baseGroupY: uint32_t; baseGroupZ: uint32_t; groupCountX: uint32_t; groupCountY: uint32_t; groupCountZ: uint32_t);
    function vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pRectCount: Puint32_t; pRects: PVkRect2D): TVkResult;
    function vkCreateDescriptorUpdateTemplateKHR(device: TVkDevice; pCreateInfo: PVkDescriptorUpdateTemplateCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pDescriptorUpdateTemplate: PVkDescriptorUpdateTemplateKHR): TVkResult;
    procedure vkDestroyDescriptorUpdateTemplateKHR(device: TVkDevice; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; pAllocator: PVkAllocationCallbacks);
    procedure vkUpdateDescriptorSetWithTemplateKHR(device: TVkDevice; descriptorSet: TVkDescriptorSet; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; pData: Pointer);
    procedure vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer: TVkCommandBuffer; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; layout: TVkPipelineLayout; set_: uint32_t; pData: Pointer);
    procedure vkSetHdrMetadataEXT(device: TVkDevice; swapchainCount: uint32_t;     (*
      Number of swap chains to update in this call
    *)

pSwapchains: PVkSwapchainKHR;     (*
      Swapchains to present an image from
    *)

pMetadata: PVkHdrMetadataEXT);
    function vkGetRefreshCycleDurationGOOGLE(device: TVkDevice; swapchain: TVkSwapchainKHR; pDisplayTimingProperties: PVkRefreshCycleDurationGOOGLE): TVkResult;
    function vkGetPastPresentationTimingGOOGLE(device: TVkDevice; swapchain: TVkSwapchainKHR; pPresentationTimingCount: Puint32_t; pPresentationTimings: PVkPastPresentationTimingGOOGLE): TVkResult;
{$IFDEF VK_USE_PLATFORM_IOS_MVK}
    function vkCreateIOSSurfaceMVK(instance: TVkInstance; pCreateInfo: PVkIOSSurfaceCreateInfoMVK; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_IOS_MVK}
{$IFDEF VK_USE_PLATFORM_MACOS_MVK}
    function vkCreateMacOSSurfaceMVK(instance: TVkInstance; pCreateInfo: PVkMacOSSurfaceCreateInfoMVK; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
{$ENDIF VK_USE_PLATFORM_MACOS_MVK}
    procedure vkCmdSetViewportWScalingNV(commandBuffer: TVkCommandBuffer; firstViewport: uint32_t; viewportCount: uint32_t; pViewportWScalings: PVkViewportWScalingNV);
    procedure vkCmdSetDiscardRectangleEXT(commandBuffer: TVkCommandBuffer; firstDiscardRectangle: uint32_t; discardRectangleCount: uint32_t; pDiscardRectangles: PVkRect2D);

