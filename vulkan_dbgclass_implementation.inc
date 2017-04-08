  function Tvk_Instance_DBG.vkCreateInstance(pCreateInfo: PVkInstanceCreateInfo; pAllocator: PVkAllocationCallbacks; pInstance: PVkInstance): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateInstance(pCreateInfo, pAllocator, pInstance);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INITIALIZATION_FAILED) or (Result = VK_ERROR_LAYER_NOT_PRESENT) or (Result = VK_ERROR_EXTENSION_NOT_PRESENT) or (Result = VK_ERROR_INCOMPATIBLE_DRIVER) then 
    begin
      raise Exception.Create('vkCreateInstance returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateInstance returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyInstance(instance: TVkInstance; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyInstance(instance, pAllocator);
  end;

  function Tvk_Instance_DBG.vkEnumeratePhysicalDevices(instance: TVkInstance; pPhysicalDeviceCount: Puint32_t; pPhysicalDevices: PVkPhysicalDevice): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INITIALIZATION_FAILED) then 
    begin
      raise Exception.Create('vkEnumeratePhysicalDevices returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumeratePhysicalDevices returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetDeviceProcAddr(device: TVkDevice; pName: Pchar): TPFN_vkVoidFunction;
  begin
    Result := Vulkan_Interface.vkGetDeviceProcAddr(device, pName);
  end;

  function Tvk_Instance_DBG.vkGetInstanceProcAddr(instance: TVkInstance; pName: Pchar): TPFN_vkVoidFunction;
  begin
    Result := Vulkan_Interface.vkGetInstanceProcAddr(instance, pName);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceProperties(physicalDevice: TVkPhysicalDevice; pProperties: PVkPhysicalDeviceProperties);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice: TVkPhysicalDevice; pQueueFamilyPropertyCount: Puint32_t; pQueueFamilyProperties: PVkQueueFamilyProperties);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceMemoryProperties(physicalDevice: TVkPhysicalDevice; pMemoryProperties: PVkPhysicalDeviceMemoryProperties);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceFeatures(physicalDevice: TVkPhysicalDevice; pFeatures: PVkPhysicalDeviceFeatures);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; pFormatProperties: PVkFormatProperties);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceImageFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; tiling: TVkImageTiling; usage: TVkImageUsageFlags; flags: TVkImageCreateFlags; pImageFormatProperties: PVkImageFormatProperties): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceImageFormatProperties(physicalDevice, format, type_, tiling, usage, flags, pImageFormatProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_FORMAT_NOT_SUPPORTED) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceImageFormatProperties returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceImageFormatProperties returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateDevice(physicalDevice: TVkPhysicalDevice; pCreateInfo: PVkDeviceCreateInfo; pAllocator: PVkAllocationCallbacks; pDevice: PVkDevice): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INITIALIZATION_FAILED) or (Result = VK_ERROR_EXTENSION_NOT_PRESENT) or (Result = VK_ERROR_FEATURE_NOT_PRESENT) or (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkCreateDevice returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDevice returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyDevice(device: TVkDevice; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyDevice(device, pAllocator);
  end;

  function Tvk_Instance_DBG.vkEnumerateInstanceLayerProperties(pPropertyCount: Puint32_t; pProperties: PVkLayerProperties): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkEnumerateInstanceLayerProperties returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumerateInstanceLayerProperties returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkEnumerateInstanceExtensionProperties(pLayerName: Pchar; pPropertyCount: Puint32_t; pProperties: PVkExtensionProperties): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_LAYER_NOT_PRESENT) then 
    begin
      raise Exception.Create('vkEnumerateInstanceExtensionProperties returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumerateInstanceExtensionProperties returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkEnumerateDeviceLayerProperties(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkLayerProperties): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumerateDeviceLayerProperties(physicalDevice, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkEnumerateDeviceLayerProperties returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumerateDeviceLayerProperties returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkEnumerateDeviceExtensionProperties(physicalDevice: TVkPhysicalDevice; pLayerName: Pchar; pPropertyCount: Puint32_t; pProperties: PVkExtensionProperties): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_LAYER_NOT_PRESENT) then 
    begin
      raise Exception.Create('vkEnumerateDeviceExtensionProperties returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumerateDeviceExtensionProperties returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetDeviceQueue(device: TVkDevice; queueFamilyIndex: uint32_t; queueIndex: uint32_t; pQueue: PVkQueue);
  begin
    Vulkan_Interface.vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
  end;

  function Tvk_Instance_DBG.vkQueueSubmit(queue: TVkQueue; submitCount: uint32_t; pSubmits: PVkSubmitInfo; fence: TVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkQueueSubmit(queue, submitCount, pSubmits, fence);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkQueueSubmit returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkQueueSubmit returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkQueueWaitIdle(queue: TVkQueue): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkQueueWaitIdle(queue);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkQueueWaitIdle returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkQueueWaitIdle returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkDeviceWaitIdle(device: TVkDevice): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkDeviceWaitIdle(device);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkDeviceWaitIdle returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkDeviceWaitIdle returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkAllocateMemory(device: TVkDevice; pAllocateInfo: PVkMemoryAllocateInfo; pAllocator: PVkAllocationCallbacks; pMemory: PVkDeviceMemory): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHX) then 
    begin
      raise Exception.Create('vkAllocateMemory returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkAllocateMemory returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkFreeMemory(device: TVkDevice; memory: TVkDeviceMemory; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkFreeMemory(device, memory, pAllocator);
  end;

  function Tvk_Instance_DBG.vkMapMemory(device: TVkDevice; memory: TVkDeviceMemory; offset: TVkDeviceSize; size: TVkDeviceSize; flags: TVkMemoryMapFlags; ppData: PPointer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkMapMemory(device, memory, offset, size, flags, ppData);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_MEMORY_MAP_FAILED) then 
    begin
      raise Exception.Create('vkMapMemory returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkMapMemory returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkUnmapMemory(device: TVkDevice; memory: TVkDeviceMemory);
  begin
    Vulkan_Interface.vkUnmapMemory(device, memory);
  end;

  function Tvk_Instance_DBG.vkFlushMappedMemoryRanges(device: TVkDevice; memoryRangeCount: uint32_t; pMemoryRanges: PVkMappedMemoryRange): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkFlushMappedMemoryRanges returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkFlushMappedMemoryRanges returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkInvalidateMappedMemoryRanges(device: TVkDevice; memoryRangeCount: uint32_t; pMemoryRanges: PVkMappedMemoryRange): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkInvalidateMappedMemoryRanges returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkInvalidateMappedMemoryRanges returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetDeviceMemoryCommitment(device: TVkDevice; memory: TVkDeviceMemory; pCommittedMemoryInBytes: PVkDeviceSize);
  begin
    Vulkan_Interface.vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
  end;

  procedure Tvk_Instance_DBG.vkGetBufferMemoryRequirements(device: TVkDevice; buffer: TVkBuffer; pMemoryRequirements: PVkMemoryRequirements);
  begin
    Vulkan_Interface.vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
  end;

  function Tvk_Instance_DBG.vkBindBufferMemory(device: TVkDevice; buffer: TVkBuffer; memory: TVkDeviceMemory; memoryOffset: TVkDeviceSize): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkBindBufferMemory(device, buffer, memory, memoryOffset);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkBindBufferMemory returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkBindBufferMemory returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetImageMemoryRequirements(device: TVkDevice; image: TVkImage; pMemoryRequirements: PVkMemoryRequirements);
  begin
    Vulkan_Interface.vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
  end;

  function Tvk_Instance_DBG.vkBindImageMemory(device: TVkDevice; image: TVkImage; memory: TVkDeviceMemory; memoryOffset: TVkDeviceSize): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkBindImageMemory(device, image, memory, memoryOffset);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkBindImageMemory returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkBindImageMemory returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetImageSparseMemoryRequirements(device: TVkDevice; image: TVkImage; pSparseMemoryRequirementCount: Puint32_t; pSparseMemoryRequirements: PVkSparseImageMemoryRequirements);
  begin
    Vulkan_Interface.vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; samples: TVkSampleCountFlagBits; usage: TVkImageUsageFlags; tiling: TVkImageTiling; pPropertyCount: Puint32_t; pProperties: PVkSparseImageFormatProperties);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type_, samples, usage, tiling, pPropertyCount, pProperties);
  end;

  function Tvk_Instance_DBG.vkQueueBindSparse(queue: TVkQueue; bindInfoCount: uint32_t; pBindInfo: PVkBindSparseInfo; fence: TVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkQueueBindSparse returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkQueueBindSparse returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateFence(device: TVkDevice; pCreateInfo: PVkFenceCreateInfo; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateFence(device, pCreateInfo, pAllocator, pFence);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateFence returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateFence returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyFence(device: TVkDevice; fence: TVkFence; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyFence(device, fence, pAllocator);
  end;

  function Tvk_Instance_DBG.vkResetFences(device: TVkDevice; fenceCount: uint32_t; pFences: PVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkResetFences(device, fenceCount, pFences);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkResetFences returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkResetFences returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetFenceStatus(device: TVkDevice; fence: TVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetFenceStatus(device, fence);
    if (Result = VK_SUCCESS) or (Result = VK_NOT_READY) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkGetFenceStatus returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetFenceStatus returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkWaitForFences(device: TVkDevice; fenceCount: uint32_t; pFences: PVkFence; waitAll: TVkBool32; timeout: uint64_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
    if (Result = VK_SUCCESS) or (Result = VK_TIMEOUT) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkWaitForFences returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkWaitForFences returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateSemaphore(device: TVkDevice; pCreateInfo: PVkSemaphoreCreateInfo; pAllocator: PVkAllocationCallbacks; pSemaphore: PVkSemaphore): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateSemaphore returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateSemaphore returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroySemaphore(device: TVkDevice; semaphore: TVkSemaphore; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroySemaphore(device, semaphore, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateEvent(device: TVkDevice; pCreateInfo: PVkEventCreateInfo; pAllocator: PVkAllocationCallbacks; pEvent: PVkEvent): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateEvent returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateEvent returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyEvent(device: TVkDevice; event: TVkEvent; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyEvent(device, event, pAllocator);
  end;

  function Tvk_Instance_DBG.vkGetEventStatus(device: TVkDevice; event: TVkEvent): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetEventStatus(device, event);
    if (Result = VK_EVENT_SET) or (Result = VK_EVENT_RESET) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkGetEventStatus returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetEventStatus returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkSetEvent(device: TVkDevice; event: TVkEvent): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkSetEvent(device, event);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkSetEvent returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkSetEvent returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkResetEvent(device: TVkDevice; event: TVkEvent): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkResetEvent(device, event);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkResetEvent returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkResetEvent returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateQueryPool(device: TVkDevice; pCreateInfo: PVkQueryPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pQueryPool: PVkQueryPool): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateQueryPool returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateQueryPool returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyQueryPool(device: TVkDevice; queryPool: TVkQueryPool; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyQueryPool(device, queryPool, pAllocator);
  end;

  function Tvk_Instance_DBG.vkGetQueryPoolResults(device: TVkDevice; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t; dataSize: size_t; pData: Pointer; stride: TVkDeviceSize; flags: TVkQueryResultFlags): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    if (Result = VK_SUCCESS) or (Result = VK_NOT_READY) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) then 
    begin
      raise Exception.Create('vkGetQueryPoolResults returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetQueryPoolResults returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateBuffer(device: TVkDevice; pCreateInfo: PVkBufferCreateInfo; pAllocator: PVkAllocationCallbacks; pBuffer: PVkBuffer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateBuffer returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateBuffer returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyBuffer(device: TVkDevice; buffer: TVkBuffer; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyBuffer(device, buffer, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateBufferView(device: TVkDevice; pCreateInfo: PVkBufferViewCreateInfo; pAllocator: PVkAllocationCallbacks; pView: PVkBufferView): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateBufferView returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateBufferView returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyBufferView(device: TVkDevice; bufferView: TVkBufferView; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyBufferView(device, bufferView, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateImage(device: TVkDevice; pCreateInfo: PVkImageCreateInfo; pAllocator: PVkAllocationCallbacks; pImage: PVkImage): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateImage(device, pCreateInfo, pAllocator, pImage);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateImage returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateImage returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyImage(device: TVkDevice; image: TVkImage; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyImage(device, image, pAllocator);
  end;

  procedure Tvk_Instance_DBG.vkGetImageSubresourceLayout(device: TVkDevice; image: TVkImage; pSubresource: PVkImageSubresource; pLayout: PVkSubresourceLayout);
  begin
    Vulkan_Interface.vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
  end;

  function Tvk_Instance_DBG.vkCreateImageView(device: TVkDevice; pCreateInfo: PVkImageViewCreateInfo; pAllocator: PVkAllocationCallbacks; pView: PVkImageView): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateImageView(device, pCreateInfo, pAllocator, pView);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateImageView returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateImageView returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyImageView(device: TVkDevice; imageView: TVkImageView; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyImageView(device, imageView, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateShaderModule(device: TVkDevice; pCreateInfo: PVkShaderModuleCreateInfo; pAllocator: PVkAllocationCallbacks; pShaderModule: PVkShaderModule): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INVALID_SHADER_NV) then 
    begin
      raise Exception.Create('vkCreateShaderModule returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateShaderModule returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyShaderModule(device: TVkDevice; shaderModule: TVkShaderModule; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyShaderModule(device, shaderModule, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreatePipelineCache(device: TVkDevice; pCreateInfo: PVkPipelineCacheCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelineCache: PVkPipelineCache): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreatePipelineCache returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreatePipelineCache returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyPipelineCache(device: TVkDevice; pipelineCache: TVkPipelineCache; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyPipelineCache(device, pipelineCache, pAllocator);
  end;

  function Tvk_Instance_DBG.vkGetPipelineCacheData(device: TVkDevice; pipelineCache: TVkPipelineCache; pDataSize: Psize_t; pData: Pointer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetPipelineCacheData returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPipelineCacheData returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkMergePipelineCaches(device: TVkDevice; dstCache: TVkPipelineCache; srcCacheCount: uint32_t; pSrcCaches: PVkPipelineCache): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkMergePipelineCaches returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkMergePipelineCaches returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateGraphicsPipelines(device: TVkDevice; pipelineCache: TVkPipelineCache; createInfoCount: uint32_t; pCreateInfos: PVkGraphicsPipelineCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelines: PVkPipeline): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INVALID_SHADER_NV) then 
    begin
      raise Exception.Create('vkCreateGraphicsPipelines returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateGraphicsPipelines returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateComputePipelines(device: TVkDevice; pipelineCache: TVkPipelineCache; createInfoCount: uint32_t; pCreateInfos: PVkComputePipelineCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelines: PVkPipeline): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INVALID_SHADER_NV) then 
    begin
      raise Exception.Create('vkCreateComputePipelines returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateComputePipelines returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyPipeline(device: TVkDevice; pipeline: TVkPipeline; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyPipeline(device, pipeline, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreatePipelineLayout(device: TVkDevice; pCreateInfo: PVkPipelineLayoutCreateInfo; pAllocator: PVkAllocationCallbacks; pPipelineLayout: PVkPipelineLayout): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreatePipelineLayout returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreatePipelineLayout returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyPipelineLayout(device: TVkDevice; pipelineLayout: TVkPipelineLayout; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateSampler(device: TVkDevice; pCreateInfo: PVkSamplerCreateInfo; pAllocator: PVkAllocationCallbacks; pSampler: PVkSampler): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_TOO_MANY_OBJECTS) then 
    begin
      raise Exception.Create('vkCreateSampler returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateSampler returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroySampler(device: TVkDevice; sampler: TVkSampler; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroySampler(device, sampler, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateDescriptorSetLayout(device: TVkDevice; pCreateInfo: PVkDescriptorSetLayoutCreateInfo; pAllocator: PVkAllocationCallbacks; pSetLayout: PVkDescriptorSetLayout): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateDescriptorSetLayout returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDescriptorSetLayout returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyDescriptorSetLayout(device: TVkDevice; descriptorSetLayout: TVkDescriptorSetLayout; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateDescriptorPool(device: TVkDevice; pCreateInfo: PVkDescriptorPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pDescriptorPool: PVkDescriptorPool): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateDescriptorPool returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDescriptorPool returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyDescriptorPool(device: TVkDevice; descriptorPool: TVkDescriptorPool; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
  end;

  function Tvk_Instance_DBG.vkResetDescriptorPool(device: TVkDevice; descriptorPool: TVkDescriptorPool; flags: TVkDescriptorPoolResetFlags): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkResetDescriptorPool(device, descriptorPool, flags);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkResetDescriptorPool returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkResetDescriptorPool returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkAllocateDescriptorSets(device: TVkDevice; pAllocateInfo: PVkDescriptorSetAllocateInfo; pDescriptorSets: PVkDescriptorSet): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_FRAGMENTED_POOL) or (Result = VK_ERROR_OUT_OF_POOL_MEMORY_KHR) then 
    begin
      raise Exception.Create('vkAllocateDescriptorSets returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkAllocateDescriptorSets returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkFreeDescriptorSets(device: TVkDevice; descriptorPool: TVkDescriptorPool; descriptorSetCount: uint32_t; pDescriptorSets: PVkDescriptorSet): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkFreeDescriptorSets returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkFreeDescriptorSets returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkUpdateDescriptorSets(device: TVkDevice; descriptorWriteCount: uint32_t; pDescriptorWrites: PVkWriteDescriptorSet; descriptorCopyCount: uint32_t; pDescriptorCopies: PVkCopyDescriptorSet);
  begin
    Vulkan_Interface.vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
  end;

  function Tvk_Instance_DBG.vkCreateFramebuffer(device: TVkDevice; pCreateInfo: PVkFramebufferCreateInfo; pAllocator: PVkAllocationCallbacks; pFramebuffer: PVkFramebuffer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateFramebuffer returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateFramebuffer returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyFramebuffer(device: TVkDevice; framebuffer: TVkFramebuffer; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyFramebuffer(device, framebuffer, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateRenderPass(device: TVkDevice; pCreateInfo: PVkRenderPassCreateInfo; pAllocator: PVkAllocationCallbacks; pRenderPass: PVkRenderPass): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateRenderPass returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateRenderPass returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyRenderPass(device: TVkDevice; renderPass: TVkRenderPass; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyRenderPass(device, renderPass, pAllocator);
  end;

  procedure Tvk_Instance_DBG.vkGetRenderAreaGranularity(device: TVkDevice; renderPass: TVkRenderPass; pGranularity: PVkExtent2D);
  begin
    Vulkan_Interface.vkGetRenderAreaGranularity(device, renderPass, pGranularity);
  end;

  function Tvk_Instance_DBG.vkCreateCommandPool(device: TVkDevice; pCreateInfo: PVkCommandPoolCreateInfo; pAllocator: PVkAllocationCallbacks; pCommandPool: PVkCommandPool): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateCommandPool returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateCommandPool returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyCommandPool(device: TVkDevice; commandPool: TVkCommandPool; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyCommandPool(device, commandPool, pAllocator);
  end;

  function Tvk_Instance_DBG.vkResetCommandPool(device: TVkDevice; commandPool: TVkCommandPool; flags: TVkCommandPoolResetFlags): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkResetCommandPool(device, commandPool, flags);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkResetCommandPool returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkResetCommandPool returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkAllocateCommandBuffers(device: TVkDevice; pAllocateInfo: PVkCommandBufferAllocateInfo; pCommandBuffers: PVkCommandBuffer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkAllocateCommandBuffers returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkAllocateCommandBuffers returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkFreeCommandBuffers(device: TVkDevice; commandPool: TVkCommandPool; commandBufferCount: uint32_t; pCommandBuffers: PVkCommandBuffer);
  begin
    Vulkan_Interface.vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
  end;

  function Tvk_Instance_DBG.vkBeginCommandBuffer(commandBuffer: TVkCommandBuffer; pBeginInfo: PVkCommandBufferBeginInfo): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkBeginCommandBuffer(commandBuffer, pBeginInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkBeginCommandBuffer returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkBeginCommandBuffer returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkEndCommandBuffer(commandBuffer: TVkCommandBuffer): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEndCommandBuffer(commandBuffer);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkEndCommandBuffer returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEndCommandBuffer returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkResetCommandBuffer(commandBuffer: TVkCommandBuffer; flags: TVkCommandBufferResetFlags): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkResetCommandBuffer(commandBuffer, flags);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkResetCommandBuffer returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkResetCommandBuffer returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkCmdBindPipeline(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; pipeline: TVkPipeline);
  begin
    Vulkan_Interface.vkCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetViewport(commandBuffer: TVkCommandBuffer; firstViewport: uint32_t; viewportCount: uint32_t; pViewports: PVkViewport);
  begin
    Vulkan_Interface.vkCmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetScissor(commandBuffer: TVkCommandBuffer; firstScissor: uint32_t; scissorCount: uint32_t; pScissors: PVkRect2D);
  begin
    Vulkan_Interface.vkCmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetLineWidth(commandBuffer: TVkCommandBuffer; lineWidth: float);
  begin
    Vulkan_Interface.vkCmdSetLineWidth(commandBuffer, lineWidth);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetDepthBias(commandBuffer: TVkCommandBuffer; depthBiasConstantFactor: float; depthBiasClamp: float; depthBiasSlopeFactor: float);
  begin
    Vulkan_Interface.vkCmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetBlendConstants(commandBuffer: TVkCommandBuffer; blendConstants: Tfloat_0_3);
  begin
    Vulkan_Interface.vkCmdSetBlendConstants(commandBuffer, blendConstants);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetDepthBounds(commandBuffer: TVkCommandBuffer; minDepthBounds: float; maxDepthBounds: float);
  begin
    Vulkan_Interface.vkCmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetStencilCompareMask(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; compareMask: uint32_t);
  begin
    Vulkan_Interface.vkCmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetStencilWriteMask(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; writeMask: uint32_t);
  begin
    Vulkan_Interface.vkCmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetStencilReference(commandBuffer: TVkCommandBuffer; faceMask: TVkStencilFaceFlags; reference: uint32_t);
  begin
    Vulkan_Interface.vkCmdSetStencilReference(commandBuffer, faceMask, reference);
  end;

  procedure Tvk_Instance_DBG.vkCmdBindDescriptorSets(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; layout: TVkPipelineLayout; firstSet: uint32_t; descriptorSetCount: uint32_t; pDescriptorSets: PVkDescriptorSet; dynamicOffsetCount: uint32_t; pDynamicOffsets: Puint32_t);
  begin
    Vulkan_Interface.vkCmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
  end;

  procedure Tvk_Instance_DBG.vkCmdBindIndexBuffer(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; indexType: TVkIndexType);
  begin
    Vulkan_Interface.vkCmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
  end;

  procedure Tvk_Instance_DBG.vkCmdBindVertexBuffers(commandBuffer: TVkCommandBuffer; firstBinding: uint32_t; bindingCount: uint32_t; pBuffers: PVkBuffer; pOffsets: PVkDeviceSize);
  begin
    Vulkan_Interface.vkCmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
  end;

  procedure Tvk_Instance_DBG.vkCmdDraw(commandBuffer: TVkCommandBuffer; vertexCount: uint32_t; instanceCount: uint32_t; firstVertex: uint32_t; firstInstance: uint32_t);
  begin
    Vulkan_Interface.vkCmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
  end;

  procedure Tvk_Instance_DBG.vkCmdDrawIndexed(commandBuffer: TVkCommandBuffer; indexCount: uint32_t; instanceCount: uint32_t; firstIndex: uint32_t; vertexOffset: int32_t; firstInstance: uint32_t);
  begin
    Vulkan_Interface.vkCmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
  end;

  procedure Tvk_Instance_DBG.vkCmdDrawIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; drawCount: uint32_t; stride: uint32_t);
  begin
    Vulkan_Interface.vkCmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
  end;

  procedure Tvk_Instance_DBG.vkCmdDrawIndexedIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; drawCount: uint32_t; stride: uint32_t);
  begin
    Vulkan_Interface.vkCmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
  end;

  procedure Tvk_Instance_DBG.vkCmdDispatch(commandBuffer: TVkCommandBuffer; groupCountX: uint32_t; groupCountY: uint32_t; groupCountZ: uint32_t);
  begin
    Vulkan_Interface.vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
  end;

  procedure Tvk_Instance_DBG.vkCmdDispatchIndirect(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize);
  begin
    Vulkan_Interface.vkCmdDispatchIndirect(commandBuffer, buffer, offset);
  end;

  procedure Tvk_Instance_DBG.vkCmdCopyBuffer(commandBuffer: TVkCommandBuffer; srcBuffer: TVkBuffer; dstBuffer: TVkBuffer; regionCount: uint32_t; pRegions: PVkBufferCopy);
  begin
    Vulkan_Interface.vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
  end;

  procedure Tvk_Instance_DBG.vkCmdCopyImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageCopy);
  begin
    Vulkan_Interface.vkCmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
  end;

  procedure Tvk_Instance_DBG.vkCmdBlitImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageBlit; filter: TVkFilter);
  begin
    Vulkan_Interface.vkCmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
  end;

  procedure Tvk_Instance_DBG.vkCmdCopyBufferToImage(commandBuffer: TVkCommandBuffer; srcBuffer: TVkBuffer; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkBufferImageCopy);
  begin
    Vulkan_Interface.vkCmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
  end;

  procedure Tvk_Instance_DBG.vkCmdCopyImageToBuffer(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstBuffer: TVkBuffer; regionCount: uint32_t; pRegions: PVkBufferImageCopy);
  begin
    Vulkan_Interface.vkCmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
  end;

  procedure Tvk_Instance_DBG.vkCmdUpdateBuffer(commandBuffer: TVkCommandBuffer; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; dataSize: TVkDeviceSize; pData: Pointer);
  begin
    Vulkan_Interface.vkCmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
  end;

  procedure Tvk_Instance_DBG.vkCmdFillBuffer(commandBuffer: TVkCommandBuffer; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; size: TVkDeviceSize; data: uint32_t);
  begin
    Vulkan_Interface.vkCmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
  end;

  procedure Tvk_Instance_DBG.vkCmdClearColorImage(commandBuffer: TVkCommandBuffer; image: TVkImage; imageLayout: TVkImageLayout; pColor: PVkClearColorValue; rangeCount: uint32_t; pRanges: PVkImageSubresourceRange);
  begin
    Vulkan_Interface.vkCmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
  end;

  procedure Tvk_Instance_DBG.vkCmdClearDepthStencilImage(commandBuffer: TVkCommandBuffer; image: TVkImage; imageLayout: TVkImageLayout; pDepthStencil: PVkClearDepthStencilValue; rangeCount: uint32_t; pRanges: PVkImageSubresourceRange);
  begin
    Vulkan_Interface.vkCmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
  end;

  procedure Tvk_Instance_DBG.vkCmdClearAttachments(commandBuffer: TVkCommandBuffer; attachmentCount: uint32_t; pAttachments: PVkClearAttachment; rectCount: uint32_t; pRects: PVkClearRect);
  begin
    Vulkan_Interface.vkCmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
  end;

  procedure Tvk_Instance_DBG.vkCmdResolveImage(commandBuffer: TVkCommandBuffer; srcImage: TVkImage; srcImageLayout: TVkImageLayout; dstImage: TVkImage; dstImageLayout: TVkImageLayout; regionCount: uint32_t; pRegions: PVkImageResolve);
  begin
    Vulkan_Interface.vkCmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetEvent(commandBuffer: TVkCommandBuffer; event: TVkEvent; stageMask: TVkPipelineStageFlags);
  begin
    Vulkan_Interface.vkCmdSetEvent(commandBuffer, event, stageMask);
  end;

  procedure Tvk_Instance_DBG.vkCmdResetEvent(commandBuffer: TVkCommandBuffer; event: TVkEvent; stageMask: TVkPipelineStageFlags);
  begin
    Vulkan_Interface.vkCmdResetEvent(commandBuffer, event, stageMask);
  end;

  procedure Tvk_Instance_DBG.vkCmdWaitEvents(commandBuffer: TVkCommandBuffer; eventCount: uint32_t; pEvents: PVkEvent; srcStageMask: TVkPipelineStageFlags; dstStageMask: TVkPipelineStageFlags; memoryBarrierCount: uint32_t; pMemoryBarriers: PVkMemoryBarrier; bufferMemoryBarrierCount: uint32_t; pBufferMemoryBarriers: PVkBufferMemoryBarrier; imageMemoryBarrierCount: uint32_t; pImageMemoryBarriers: PVkImageMemoryBarrier);
  begin
    Vulkan_Interface.vkCmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
  end;

  procedure Tvk_Instance_DBG.vkCmdPipelineBarrier(commandBuffer: TVkCommandBuffer; srcStageMask: TVkPipelineStageFlags; dstStageMask: TVkPipelineStageFlags; dependencyFlags: TVkDependencyFlags; memoryBarrierCount: uint32_t; pMemoryBarriers: PVkMemoryBarrier; bufferMemoryBarrierCount: uint32_t; pBufferMemoryBarriers: PVkBufferMemoryBarrier; imageMemoryBarrierCount: uint32_t; pImageMemoryBarriers: PVkImageMemoryBarrier);
  begin
    Vulkan_Interface.vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
  end;

  procedure Tvk_Instance_DBG.vkCmdBeginQuery(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; query: uint32_t; flags: TVkQueryControlFlags);
  begin
    Vulkan_Interface.vkCmdBeginQuery(commandBuffer, queryPool, query, flags);
  end;

  procedure Tvk_Instance_DBG.vkCmdEndQuery(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; query: uint32_t);
  begin
    Vulkan_Interface.vkCmdEndQuery(commandBuffer, queryPool, query);
  end;

  procedure Tvk_Instance_DBG.vkCmdResetQueryPool(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t);
  begin
    Vulkan_Interface.vkCmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
  end;

  procedure Tvk_Instance_DBG.vkCmdWriteTimestamp(commandBuffer: TVkCommandBuffer; pipelineStage: TVkPipelineStageFlagBits; queryPool: TVkQueryPool; query: uint32_t);
  begin
    Vulkan_Interface.vkCmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
  end;

  procedure Tvk_Instance_DBG.vkCmdCopyQueryPoolResults(commandBuffer: TVkCommandBuffer; queryPool: TVkQueryPool; firstQuery: uint32_t; queryCount: uint32_t; dstBuffer: TVkBuffer; dstOffset: TVkDeviceSize; stride: TVkDeviceSize; flags: TVkQueryResultFlags);
  begin
    Vulkan_Interface.vkCmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
  end;

  procedure Tvk_Instance_DBG.vkCmdPushConstants(commandBuffer: TVkCommandBuffer; layout: TVkPipelineLayout; stageFlags: TVkShaderStageFlags; offset: uint32_t; size: uint32_t; pValues: Pointer);
  begin
    Vulkan_Interface.vkCmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
  end;

  procedure Tvk_Instance_DBG.vkCmdBeginRenderPass(commandBuffer: TVkCommandBuffer; pRenderPassBegin: PVkRenderPassBeginInfo; contents: TVkSubpassContents);
  begin
    Vulkan_Interface.vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
  end;

  procedure Tvk_Instance_DBG.vkCmdNextSubpass(commandBuffer: TVkCommandBuffer; contents: TVkSubpassContents);
  begin
    Vulkan_Interface.vkCmdNextSubpass(commandBuffer, contents);
  end;

  procedure Tvk_Instance_DBG.vkCmdEndRenderPass(commandBuffer: TVkCommandBuffer);
  begin
    Vulkan_Interface.vkCmdEndRenderPass(commandBuffer);
  end;

  procedure Tvk_Instance_DBG.vkCmdExecuteCommands(commandBuffer: TVkCommandBuffer; commandBufferCount: uint32_t; pCommandBuffers: PVkCommandBuffer);
  begin
    Vulkan_Interface.vkCmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
  end;

{$IFDEF VK_USE_PLATFORM_ANDROID_KHR}
  function Tvk_Instance_DBG.vkCreateAndroidSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkAndroidSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR) then 
    begin
      raise Exception.Create('vkCreateAndroidSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateAndroidSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_ANDROID_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkDisplayPropertiesKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceDisplayPropertiesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceDisplayPropertiesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice: TVkPhysicalDevice; pPropertyCount: Puint32_t; pProperties: PVkDisplayPlanePropertiesKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceDisplayPlanePropertiesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceDisplayPlanePropertiesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice: TVkPhysicalDevice; planeIndex: uint32_t; pDisplayCount: Puint32_t; pDisplays: PVkDisplayKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetDisplayPlaneSupportedDisplaysKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetDisplayPlaneSupportedDisplaysKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetDisplayModePropertiesKHR(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR; pPropertyCount: Puint32_t; pProperties: PVkDisplayModePropertiesKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetDisplayModePropertiesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetDisplayModePropertiesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateDisplayModeKHR(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR; pCreateInfo: PVkDisplayModeCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pMode: PVkDisplayModeKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INITIALIZATION_FAILED) then 
    begin
      raise Exception.Create('vkCreateDisplayModeKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDisplayModeKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetDisplayPlaneCapabilitiesKHR(physicalDevice: TVkPhysicalDevice; mode: TVkDisplayModeKHR; planeIndex: uint32_t; pCapabilities: PVkDisplayPlaneCapabilitiesKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetDisplayPlaneCapabilitiesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetDisplayPlaneCapabilitiesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateDisplayPlaneSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkDisplaySurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateDisplayPlaneSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDisplayPlaneSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateSharedSwapchainsKHR(device: TVkDevice; swapchainCount: uint32_t; pCreateInfos: PVkSwapchainCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSwapchains: PVkSwapchainKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkCreateSharedSwapchainsKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateSharedSwapchainsKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$IFDEF VK_USE_PLATFORM_MIR_KHR}
  function Tvk_Instance_DBG.vkCreateMirSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkMirSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateMirSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateMirSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateMirSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_MIR_KHR}
{$IFDEF VK_USE_PLATFORM_MIR_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; connection: PMirConnection): TVkBool32;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceMirPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection);
  end;

{$ENDIF VK_USE_PLATFORM_MIR_KHR}
  procedure Tvk_Instance_DBG.vkDestroySurfaceKHR(instance: TVkInstance; surface: TVkSurfaceKHR; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroySurfaceKHR(instance, surface, pAllocator);
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; surface: TVkSurfaceKHR; pSupported: PVkBool32): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceSurfaceSupportKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceSurfaceSupportKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceCapabilities: PVkSurfaceCapabilitiesKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceSurfaceCapabilitiesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceSurfaceCapabilitiesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceFormatCount: Puint32_t; pSurfaceFormats: PVkSurfaceFormatKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceSurfaceFormatsKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceSurfaceFormatsKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pPresentModeCount: Puint32_t; pPresentModes: PVkPresentModeKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceSurfacePresentModesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceSurfacePresentModesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateSwapchainKHR(device: TVkDevice; pCreateInfo: PVkSwapchainCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSwapchain: PVkSwapchainKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_SURFACE_LOST_KHR) or (Result = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR) then 
    begin
      raise Exception.Create('vkCreateSwapchainKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateSwapchainKHR returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroySwapchainKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroySwapchainKHR(device, swapchain, pAllocator);
  end;

  function Tvk_Instance_DBG.vkGetSwapchainImagesKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; pSwapchainImageCount: Puint32_t; pSwapchainImages: PVkImage): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetSwapchainImagesKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetSwapchainImagesKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkAcquireNextImageKHR(device: TVkDevice; swapchain: TVkSwapchainKHR; timeout: uint64_t; semaphore: TVkSemaphore; fence: TVkFence; pImageIndex: Puint32_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    if (Result = VK_SUCCESS) or (Result = VK_TIMEOUT) or (Result = VK_NOT_READY) or (Result = VK_SUBOPTIMAL_KHR) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_OUT_OF_DATE_KHR) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkAcquireNextImageKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkAcquireNextImageKHR returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkQueuePresentKHR(queue: TVkQueue; pPresentInfo: PVkPresentInfoKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkQueuePresentKHR(queue, pPresentInfo);
    if (Result = VK_SUCCESS) or (Result = VK_SUBOPTIMAL_KHR) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_OUT_OF_DATE_KHR) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkQueuePresentKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkQueuePresentKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$IFDEF VK_USE_PLATFORM_VI_NN}
  function Tvk_Instance_DBG.vkCreateViSurfaceNN(instance: TVkInstance; pCreateInfo: PVkViSurfaceCreateInfoNN; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR) then 
    begin
      raise Exception.Create('vkCreateViSurfaceNN returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateViSurfaceNN returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_VI_NN}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
  function Tvk_Instance_DBG.vkCreateWaylandSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkWaylandSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateWaylandSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateWaylandSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WAYLAND_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; display: Pwl_display): TVkBool32;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
  end;

{$ENDIF VK_USE_PLATFORM_WAYLAND_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
  function Tvk_Instance_DBG.vkCreateWin32SurfaceKHR(instance: TVkInstance; pCreateInfo: PVkWin32SurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateWin32SurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateWin32SurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t): TVkBool32;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
  function Tvk_Instance_DBG.vkCreateXlibSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkXlibSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateXlibSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateXlibSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XLIB_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; dpy: PDisplay; visualID: TVisualID): TVkBool32;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
  end;

{$ENDIF VK_USE_PLATFORM_XLIB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
  function Tvk_Instance_DBG.vkCreateXcbSurfaceKHR(instance: TVkInstance; pCreateInfo: PVkXcbSurfaceCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateXcbSurfaceKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateXcbSurfaceKHR returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_XCB_KHR}
{$IFDEF VK_USE_PLATFORM_XCB_KHR}
  function Tvk_Instance_DBG.vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice: TVkPhysicalDevice; queueFamilyIndex: uint32_t; connection: Pxcb_connection_t; visual_id: Txcb_visualid_t): TVkBool32;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
  end;

{$ENDIF VK_USE_PLATFORM_XCB_KHR}
  function Tvk_Instance_DBG.vkCreateDebugReportCallbackEXT(instance: TVkInstance; pCreateInfo: PVkDebugReportCallbackCreateInfoEXT; pAllocator: PVkAllocationCallbacks; pCallback: PVkDebugReportCallbackEXT): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkCreateDebugReportCallbackEXT returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDebugReportCallbackEXT returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyDebugReportCallbackEXT(instance: TVkInstance; callback: TVkDebugReportCallbackEXT; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyDebugReportCallbackEXT(instance, callback, pAllocator);
  end;

  procedure Tvk_Instance_DBG.vkDebugReportMessageEXT(instance: TVkInstance; flags: TVkDebugReportFlagsEXT; objectType: TVkDebugReportObjectTypeEXT; object_: uint64_t; location: size_t; messageCode: int32_t; pLayerPrefix: Pchar; pMessage: Pchar);
  begin
    Vulkan_Interface.vkDebugReportMessageEXT(instance, flags, objectType, object_, location, messageCode, pLayerPrefix, pMessage);
  end;

  function Tvk_Instance_DBG.vkDebugMarkerSetObjectNameEXT(device: TVkDevice; pNameInfo: PVkDebugMarkerObjectNameInfoEXT): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkDebugMarkerSetObjectNameEXT(device, pNameInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkDebugMarkerSetObjectNameEXT returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkDebugMarkerSetObjectNameEXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkDebugMarkerSetObjectTagEXT(device: TVkDevice; pTagInfo: PVkDebugMarkerObjectTagInfoEXT): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkDebugMarkerSetObjectTagEXT(device, pTagInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkDebugMarkerSetObjectTagEXT returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkDebugMarkerSetObjectTagEXT returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkCmdDebugMarkerBeginEXT(commandBuffer: TVkCommandBuffer; pMarkerInfo: PVkDebugMarkerMarkerInfoEXT);
  begin
    Vulkan_Interface.vkCmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
  end;

  procedure Tvk_Instance_DBG.vkCmdDebugMarkerEndEXT(commandBuffer: TVkCommandBuffer);
  begin
    Vulkan_Interface.vkCmdDebugMarkerEndEXT(commandBuffer);
  end;

  procedure Tvk_Instance_DBG.vkCmdDebugMarkerInsertEXT(commandBuffer: TVkCommandBuffer; pMarkerInfo: PVkDebugMarkerMarkerInfoEXT);
  begin
    Vulkan_Interface.vkCmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice: TVkPhysicalDevice; format: TVkFormat; type_: TVkImageType; tiling: TVkImageTiling; usage: TVkImageUsageFlags; flags: TVkImageCreateFlags; externalHandleType: TVkExternalMemoryHandleTypeFlagsNV; pExternalImageFormatProperties: PVkExternalImageFormatPropertiesNV): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type_, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_FORMAT_NOT_SUPPORTED) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceExternalImageFormatPropertiesNV returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceExternalImageFormatPropertiesNV returned unexpected value"' + ErrorStr + '"');
  end;

{$IFDEF VK_USE_PLATFORM_WIN32_KHR}
  function Tvk_Instance_DBG.vkGetMemoryWin32HandleNV(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagsNV; pHandle: PHANDLE): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkGetMemoryWin32HandleNV returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetMemoryWin32HandleNV returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHR}
  procedure Tvk_Instance_DBG.vkCmdDrawIndirectCountAMD(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; countBuffer: TVkBuffer; countBufferOffset: TVkDeviceSize; maxDrawCount: uint32_t; stride: uint32_t);
  begin
    Vulkan_Interface.vkCmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  end;

  procedure Tvk_Instance_DBG.vkCmdDrawIndexedIndirectCountAMD(commandBuffer: TVkCommandBuffer; buffer: TVkBuffer; offset: TVkDeviceSize; countBuffer: TVkBuffer; countBufferOffset: TVkDeviceSize; maxDrawCount: uint32_t; stride: uint32_t);
  begin
    Vulkan_Interface.vkCmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
  end;

  procedure Tvk_Instance_DBG.vkCmdProcessCommandsNVX(commandBuffer: TVkCommandBuffer; pProcessCommandsInfo: PVkCmdProcessCommandsInfoNVX);
  begin
    Vulkan_Interface.vkCmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);
  end;

  procedure Tvk_Instance_DBG.vkCmdReserveSpaceForCommandsNVX(commandBuffer: TVkCommandBuffer; pReserveSpaceInfo: PVkCmdReserveSpaceForCommandsInfoNVX);
  begin
    Vulkan_Interface.vkCmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);
  end;

  function Tvk_Instance_DBG.vkCreateIndirectCommandsLayoutNVX(device: TVkDevice; pCreateInfo: PVkIndirectCommandsLayoutCreateInfoNVX; pAllocator: PVkAllocationCallbacks; pIndirectCommandsLayout: PVkIndirectCommandsLayoutNVX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateIndirectCommandsLayoutNVX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateIndirectCommandsLayoutNVX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyIndirectCommandsLayoutNVX(device: TVkDevice; indirectCommandsLayout: TVkIndirectCommandsLayoutNVX; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);
  end;

  function Tvk_Instance_DBG.vkCreateObjectTableNVX(device: TVkDevice; pCreateInfo: PVkObjectTableCreateInfoNVX; pAllocator: PVkAllocationCallbacks; pObjectTable: PVkObjectTableNVX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateObjectTableNVX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateObjectTableNVX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyObjectTableNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyObjectTableNVX(device, objectTable, pAllocator);
  end;

  function Tvk_Instance_DBG.vkRegisterObjectsNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; objectCount: uint32_t; ppObjectTableEntries: PPVkObjectTableEntryNVX; pObjectIndices: Puint32_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkRegisterObjectsNVX(device, objectTable, objectCount, ppObjectTableEntries, pObjectIndices);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkRegisterObjectsNVX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkRegisterObjectsNVX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkUnregisterObjectsNVX(device: TVkDevice; objectTable: TVkObjectTableNVX; objectCount: uint32_t; pObjectEntryTypes: PVkObjectEntryTypeNVX; pObjectIndices: Puint32_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkUnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkUnregisterObjectsNVX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkUnregisterObjectsNVX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice: TVkPhysicalDevice; pFeatures: PVkDeviceGeneratedCommandsFeaturesNVX; pLimits: PVkDeviceGeneratedCommandsLimitsNVX);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceFeatures2KHR(physicalDevice: TVkPhysicalDevice; pFeatures: PVkPhysicalDeviceFeatures2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceProperties2KHR(physicalDevice: TVkPhysicalDevice; pProperties: PVkPhysicalDeviceProperties2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; format: TVkFormat; pFormatProperties: PVkFormatProperties2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; pImageFormatInfo: PVkPhysicalDeviceImageFormatInfo2KHR; pImageFormatProperties: PVkImageFormatProperties2KHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_FORMAT_NOT_SUPPORTED) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceImageFormatProperties2KHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceImageFormatProperties2KHR returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice: TVkPhysicalDevice; pQueueFamilyPropertyCount: Puint32_t; pQueueFamilyProperties: PVkQueueFamilyProperties2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice: TVkPhysicalDevice; pMemoryProperties: PVkPhysicalDeviceMemoryProperties2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice: TVkPhysicalDevice; pFormatInfo: PVkPhysicalDeviceSparseImageFormatInfo2KHR; pPropertyCount: Puint32_t; pProperties: PVkSparseImageFormatProperties2KHR);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
  end;

  procedure Tvk_Instance_DBG.vkCmdPushDescriptorSetKHR(commandBuffer: TVkCommandBuffer; pipelineBindPoint: TVkPipelineBindPoint; layout: TVkPipelineLayout; set_: uint32_t; descriptorWriteCount: uint32_t; pDescriptorWrites: PVkWriteDescriptorSet);
  begin
    Vulkan_Interface.vkCmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set_, descriptorWriteCount, pDescriptorWrites);
  end;

  procedure Tvk_Instance_DBG.vkTrimCommandPoolKHR(device: TVkDevice; commandPool: TVkCommandPool; flags: TVkCommandPoolTrimFlagsKHR);
  begin
    Vulkan_Interface.vkTrimCommandPoolKHR(device, commandPool, flags);
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceExternalBufferPropertiesKHX(physicalDevice: TVkPhysicalDevice; pExternalBufferInfo: PVkPhysicalDeviceExternalBufferInfoKHX; pExternalBufferProperties: PVkExternalBufferPropertiesKHX);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceExternalBufferPropertiesKHX(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
  end;

{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkGetMemoryWin32HandleKHX(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; pHandle: PHANDLE): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetMemoryWin32HandleKHX(device, memory, handleType, pHandle);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkGetMemoryWin32HandleKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetMemoryWin32HandleKHX returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkGetMemoryWin32HandlePropertiesKHX(device: TVkDevice; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; handle: THANDLE; pMemoryWin32HandleProperties: PVkMemoryWin32HandlePropertiesKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetMemoryWin32HandlePropertiesKHX(device, handleType, handle, pMemoryWin32HandleProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHX) then 
    begin
      raise Exception.Create('vkGetMemoryWin32HandlePropertiesKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetMemoryWin32HandlePropertiesKHX returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkGetMemoryFdKHX(device: TVkDevice; memory: TVkDeviceMemory; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; pFd: Pint): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetMemoryFdKHX(device, memory, handleType, pFd);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkGetMemoryFdKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetMemoryFdKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetMemoryFdPropertiesKHX(device: TVkDevice; handleType: TVkExternalMemoryHandleTypeFlagBitsKHX; fd: int; pMemoryFdProperties: PVkMemoryFdPropertiesKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetMemoryFdPropertiesKHX(device, handleType, fd, pMemoryFdProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHX) then 
    begin
      raise Exception.Create('vkGetMemoryFdPropertiesKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetMemoryFdPropertiesKHX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetPhysicalDeviceExternalSemaphorePropertiesKHX(physicalDevice: TVkPhysicalDevice; pExternalSemaphoreInfo: PVkPhysicalDeviceExternalSemaphoreInfoKHX; pExternalSemaphoreProperties: PVkExternalSemaphorePropertiesKHX);
  begin
    Vulkan_Interface.vkGetPhysicalDeviceExternalSemaphorePropertiesKHX(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
  end;

{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkGetSemaphoreWin32HandleKHX(device: TVkDevice; semaphore: TVkSemaphore; handleType: TVkExternalSemaphoreHandleTypeFlagBitsKHX; pHandle: PHANDLE): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetSemaphoreWin32HandleKHX(device, semaphore, handleType, pHandle);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkGetSemaphoreWin32HandleKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetSemaphoreWin32HandleKHX returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
{$IFDEF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkImportSemaphoreWin32HandleKHX(device: TVkDevice; pImportSemaphoreWin32HandleInfo: PVkImportSemaphoreWin32HandleInfoKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkImportSemaphoreWin32HandleKHX(device, pImportSemaphoreWin32HandleInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHX) then 
    begin
      raise Exception.Create('vkImportSemaphoreWin32HandleKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkImportSemaphoreWin32HandleKHX returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_WIN32_KHX}
  function Tvk_Instance_DBG.vkGetSemaphoreFdKHX(device: TVkDevice; semaphore: TVkSemaphore; handleType: TVkExternalSemaphoreHandleTypeFlagBitsKHX; pFd: Pint): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetSemaphoreFdKHX(device, semaphore, handleType, pFd);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_TOO_MANY_OBJECTS) or (Result = VK_ERROR_OUT_OF_HOST_MEMORY) then 
    begin
      raise Exception.Create('vkGetSemaphoreFdKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetSemaphoreFdKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkImportSemaphoreFdKHX(device: TVkDevice; pImportSemaphoreFdInfo: PVkImportSemaphoreFdInfoKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkImportSemaphoreFdKHX(device, pImportSemaphoreFdInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHX) then 
    begin
      raise Exception.Create('vkImportSemaphoreFdKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkImportSemaphoreFdKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkReleaseDisplayEXT(physicalDevice: TVkPhysicalDevice; display: TVkDisplayKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkReleaseDisplayEXT(physicalDevice, display);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkReleaseDisplayEXT returned unexpected value"' + ErrorStr + '"');
  end;

{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
  function Tvk_Instance_DBG.vkAcquireXlibDisplayEXT(physicalDevice: TVkPhysicalDevice; dpy: PDisplay; display: TVkDisplayKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAcquireXlibDisplayEXT(physicalDevice, dpy, display);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkAcquireXlibDisplayEXT returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
{$IFDEF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
  function Tvk_Instance_DBG.vkGetRandROutputDisplayEXT(physicalDevice: TVkPhysicalDevice; dpy: PDisplay; rrOutput: TRROutput; pDisplay: PVkDisplayKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkGetRandROutputDisplayEXT returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_XLIB_XRANDR_EXT}
  function Tvk_Instance_DBG.vkDisplayPowerControlEXT(device: TVkDevice; display: TVkDisplayKHR; pDisplayPowerInfo: PVkDisplayPowerInfoEXT): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkDisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkDisplayPowerControlEXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkRegisterDeviceEventEXT(device: TVkDevice; pDeviceEventInfo: PVkDeviceEventInfoEXT; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkRegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkRegisterDeviceEventEXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkRegisterDisplayEventEXT(device: TVkDevice; display: TVkDisplayKHR; pDisplayEventInfo: PVkDisplayEventInfoEXT; pAllocator: PVkAllocationCallbacks; pFence: PVkFence): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkRegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkRegisterDisplayEventEXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetSwapchainCounterEXT(device: TVkDevice; swapchain: TVkSwapchainKHR; counter: TVkSurfaceCounterFlagBitsEXT; pCounterValue: Puint64_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    if (Result = VK_SUCCESS) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_OUT_OF_DATE_KHR) then Exit;
    WriteStr(ErrorStr, Result);
    raise Exception.Create('vkGetSwapchainCounterEXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pSurfaceCapabilities: PVkSurfaceCapabilities2EXT): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPhysicalDeviceSurfaceCapabilities2EXT returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDeviceSurfaceCapabilities2EXT returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkEnumeratePhysicalDeviceGroupsKHX(instance: TVkInstance; pPhysicalDeviceGroupCount: Puint32_t; pPhysicalDeviceGroupProperties: PVkPhysicalDeviceGroupPropertiesKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkEnumeratePhysicalDeviceGroupsKHX(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_INITIALIZATION_FAILED) then 
    begin
      raise Exception.Create('vkEnumeratePhysicalDeviceGroupsKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkEnumeratePhysicalDeviceGroupsKHX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkGetDeviceGroupPeerMemoryFeaturesKHX(device: TVkDevice; heapIndex: uint32_t; localDeviceIndex: uint32_t; remoteDeviceIndex: uint32_t; pPeerMemoryFeatures: PVkPeerMemoryFeatureFlagsKHX);
  begin
    Vulkan_Interface.vkGetDeviceGroupPeerMemoryFeaturesKHX(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
  end;

  function Tvk_Instance_DBG.vkBindBufferMemory2KHX(device: TVkDevice; bindInfoCount: uint32_t; pBindInfos: PVkBindBufferMemoryInfoKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkBindBufferMemory2KHX(device, bindInfoCount, pBindInfos);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkBindBufferMemory2KHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkBindBufferMemory2KHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkBindImageMemory2KHX(device: TVkDevice; bindInfoCount: uint32_t; pBindInfos: PVkBindImageMemoryInfoKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkBindImageMemory2KHX(device, bindInfoCount, pBindInfos);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkBindImageMemory2KHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkBindImageMemory2KHX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkCmdSetDeviceMaskKHX(commandBuffer: TVkCommandBuffer; deviceMask: uint32_t);
  begin
    Vulkan_Interface.vkCmdSetDeviceMaskKHX(commandBuffer, deviceMask);
  end;

  function Tvk_Instance_DBG.vkGetDeviceGroupPresentCapabilitiesKHX(device: TVkDevice; pDeviceGroupPresentCapabilities: PVkDeviceGroupPresentCapabilitiesKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetDeviceGroupPresentCapabilitiesKHX(device, pDeviceGroupPresentCapabilities);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetDeviceGroupPresentCapabilitiesKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetDeviceGroupPresentCapabilitiesKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetDeviceGroupSurfacePresentModesKHX(device: TVkDevice; surface: TVkSurfaceKHR; pModes: PVkDeviceGroupPresentModeFlagsKHX): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetDeviceGroupSurfacePresentModesKHX(device, surface, pModes);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetDeviceGroupSurfacePresentModesKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetDeviceGroupSurfacePresentModesKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkAcquireNextImage2KHX(device: TVkDevice; pAcquireInfo: PVkAcquireNextImageInfoKHX; pImageIndex: Puint32_t): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkAcquireNextImage2KHX(device, pAcquireInfo, pImageIndex);
    if (Result = VK_SUCCESS) or (Result = VK_TIMEOUT) or (Result = VK_NOT_READY) or (Result = VK_SUBOPTIMAL_KHR) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_OUT_OF_DATE_KHR) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkAcquireNextImage2KHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkAcquireNextImage2KHX returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkCmdDispatchBaseKHX(commandBuffer: TVkCommandBuffer; baseGroupX: uint32_t; baseGroupY: uint32_t; baseGroupZ: uint32_t; groupCountX: uint32_t; groupCountY: uint32_t; groupCountZ: uint32_t);
  begin
    Vulkan_Interface.vkCmdDispatchBaseKHX(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
  end;

  function Tvk_Instance_DBG.vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice: TVkPhysicalDevice; surface: TVkSurfaceKHR; pRectCount: Puint32_t; pRects: PVkRect2D): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPhysicalDevicePresentRectanglesKHX(physicalDevice, surface, pRectCount, pRects);
    if (Result = VK_SUCCESS) or (Result = VK_INCOMPLETE) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkGetPhysicalDevicePresentRectanglesKHX returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPhysicalDevicePresentRectanglesKHX returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkCreateDescriptorUpdateTemplateKHR(device: TVkDevice; pCreateInfo: PVkDescriptorUpdateTemplateCreateInfoKHR; pAllocator: PVkAllocationCallbacks; pDescriptorUpdateTemplate: PVkDescriptorUpdateTemplateKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) then 
    begin
      raise Exception.Create('vkCreateDescriptorUpdateTemplateKHR returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateDescriptorUpdateTemplateKHR returned unexpected value"' + ErrorStr + '"');
  end;

  procedure Tvk_Instance_DBG.vkDestroyDescriptorUpdateTemplateKHR(device: TVkDevice; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; pAllocator: PVkAllocationCallbacks);
  begin
    Vulkan_Interface.vkDestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
  end;

  procedure Tvk_Instance_DBG.vkUpdateDescriptorSetWithTemplateKHR(device: TVkDevice; descriptorSet: TVkDescriptorSet; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; pData: Pointer);
  begin
    Vulkan_Interface.vkUpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
  end;

  procedure Tvk_Instance_DBG.vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer: TVkCommandBuffer; descriptorUpdateTemplate: TVkDescriptorUpdateTemplateKHR; layout: TVkPipelineLayout; set_: uint32_t; pData: Pointer);
  begin
    Vulkan_Interface.vkCmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set_, pData);
  end;

  procedure Tvk_Instance_DBG.vkSetHdrMetadataEXT(device: TVkDevice; swapchainCount: uint32_t;   (*
    Number of swap chains to update in this call
  *)

pSwapchains: PVkSwapchainKHR;   (*
    Swapchains to present an image from
  *)

pMetadata: PVkHdrMetadataEXT);
  begin
    Vulkan_Interface.vkSetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
  end;

  function Tvk_Instance_DBG.vkGetRefreshCycleDurationGOOGLE(device: TVkDevice; swapchain: TVkSwapchainKHR; pDisplayTimingProperties: PVkRefreshCycleDurationGOOGLE): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetRefreshCycleDurationGOOGLE returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetRefreshCycleDurationGOOGLE returned unexpected value"' + ErrorStr + '"');
  end;

  function Tvk_Instance_DBG.vkGetPastPresentationTimingGOOGLE(device: TVkDevice; swapchain: TVkSwapchainKHR; pPresentationTimingCount: Puint32_t; pPresentationTimings: PVkPastPresentationTimingGOOGLE): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkGetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_DEVICE_LOST) or (Result = VK_ERROR_OUT_OF_DATE_KHR) or (Result = VK_ERROR_SURFACE_LOST_KHR) then 
    begin
      raise Exception.Create('vkGetPastPresentationTimingGOOGLE returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkGetPastPresentationTimingGOOGLE returned unexpected value"' + ErrorStr + '"');
  end;

{$IFDEF VK_USE_PLATFORM_IOS_MVK}
  function Tvk_Instance_DBG.vkCreateIOSSurfaceMVK(instance: TVkInstance; pCreateInfo: PVkIOSSurfaceCreateInfoMVK; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR) then 
    begin
      raise Exception.Create('vkCreateIOSSurfaceMVK returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateIOSSurfaceMVK returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_IOS_MVK}
{$IFDEF VK_USE_PLATFORM_MACOS_MVK}
  function Tvk_Instance_DBG.vkCreateMacOSSurfaceMVK(instance: TVkInstance; pCreateInfo: PVkMacOSSurfaceCreateInfoMVK; pAllocator: PVkAllocationCallbacks; pSurface: PVkSurfaceKHR): TVkResult;
  var ErrorStr: String;
  begin
    Result := Vulkan_Interface.vkCreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    if (Result = VK_SUCCESS) then Exit;
    WriteStr(ErrorStr, Result);
    if (Result = VK_ERROR_OUT_OF_HOST_MEMORY) or (Result = VK_ERROR_OUT_OF_DEVICE_MEMORY) or (Result = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR) then 
    begin
      raise Exception.Create('vkCreateMacOSSurfaceMVK returned "' + ErrorStr + '"');
      Exit;
    end;
    raise Exception.Create('vkCreateMacOSSurfaceMVK returned unexpected value"' + ErrorStr + '"');
  end;

{$ENDIF VK_USE_PLATFORM_MACOS_MVK}
  procedure Tvk_Instance_DBG.vkCmdSetViewportWScalingNV(commandBuffer: TVkCommandBuffer; firstViewport: uint32_t; viewportCount: uint32_t; pViewportWScalings: PVkViewportWScalingNV);
  begin
    Vulkan_Interface.vkCmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
  end;

  procedure Tvk_Instance_DBG.vkCmdSetDiscardRectangleEXT(commandBuffer: TVkCommandBuffer; firstDiscardRectangle: uint32_t; discardRectangleCount: uint32_t; pDiscardRectangles: PVkRect2D);
  begin
    Vulkan_Interface.vkCmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
  end;


