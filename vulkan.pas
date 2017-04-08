{
  Vulkan Library for FreePascal
  Copyright (c) 2017 by James McJohnson

  <Public Service Announcement>:

    "For I am not ashamed of the Good News of Christ, for it is the power of God for salvation for everyone who believes..." - Romans 1:16
    "For God so loved the world, that He gave His only begotten Son, that whosoever believeth in Him should not perish, but have everlasting life." - John 3:16

    Hear: "So faith comes by hearing, and hearing by the word of God." - Romans 10:17
    Believe: "...for unless you believe that I am He, you will die in your sins." - John 8:24
    Repent: "The times of ignorance therefore God overlooked. But now He commands that all people everywhere should repent, because He has appointed a day in which
     He will judge the world in righteousness by the Man Whom He has ordained; of which He has given assurance to all men, in that He has raised Him from the dead.” - Acts 17:30-31
    Confess: "Everyone therefore who confesses Me before men, him I will also confess before My Father Who is in heaven.
      But whoever denies Me before men, him I will also deny before My Father Who is in heaven." - Matthew 10:32-33
    Be Baptized: "Go, and make disciples of all nations, baptizing them in the name of the Father and of the Son and of the Holy Spirit" - Matthew 28:19

  </Public Service Announcement>:

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
  persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice, the above public service announcement (in its entirety), and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
  OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
}

unit vulkan;


{.$DEFINE VULKAN_FLAT}
{$DEFINE INCLUDE_DBG}
{$DEFINE FILE_SAVE}

{$mode objfpc}{$H+}
{$modeswitch advancedrecords}
{$packset 4}

{$IFDEF WINDOWS}
  {$DEFINE VK_USE_PLATFORM_WIN32_KHR}
{$ENDIF WINDOWS}
{$IFDEF UNIX}
  {$DEFINE VK_USE_PLATFORM_XLIB_KHR}
{$ENDIF UNIX}
{$IFDEF ANDROID}
  {$DEFINE VK_USE_PLATFORM_ANDROID_KHR}
{$ENDIF ANDROID}
interface

uses
  Classes, Dialogs, SysUtils, fgl, GVector, typinfo, SDL2, dynlibs,
{$IFDEF FILE_SAVE}
  BGRABitmap,
{$ENDIF FILE_SAVE}
{$IFDEF WINDOWS}jwawinbase, windows{$ENDIF WINDOWS}
{$IFDEF UNIX}math, Xlib, x, xutil{$ENDIF UNIX}
{$IFDEF ANDROID}jdk15, native_window { not sure about these...}{$ENDIF ANDROID}
;


const
{$IFDEF WINDOWS}DEFAULT_VULKAN_LIB_NAME = 'vulkan-1.dll';{$ENDIF WINDOWS}
{$IFDEF UNIX}DEFAULT_VULKAN_LIB_NAME = 'libvulkan.so';{$ENDIF UNIX}
{$IFDEF ANDROID}DEFAULT_VULKAN_LIB_NAME = 'libvulkan.so';{$ENDIF ANDROID}
DefaultDevice = 0;


type
//{$IFDEF WINDOWS}HINSTANCE = HINST;{$ENDIF WINDOWS}


{$include vulkan_constants_and_types.inc}

{$IFDEF VULKAN_FLAT}
var
{$ELSE}


type
TVkResult_Set_Reset = (VK_EVENT_SET_SNS, VK_EVENT_RESET_SNS, VK_ERROR_OUT_OF_HOST_MEMORY_SNS, VK_ERROR_OUT_OF_DEVICE_MEMORY_SNS, VK_ERROR_DEVICE_LOST_SNS);

TVkResultArray = array of TVkResult;
PVkResultArray = ^TVkResultArray;

const
  Results_AcquireNextImage_Success: array[0..3] of TVkResult = (VK_SUCCESS, VK_TIMEOUT, VK_NOT_READY, VK_SUBOPTIMAL_KHR);

type


Tvk_Instance = class;
Tvk_Device = class;
Tvk_Surface = class;
Tvk_Queue = class;
Tvk_QueueFamily = class;
Tvk_CommandPool = class;
Tvk_DescriptorPool = class;
Tvk_CommandBuffer = class;
Tvk_Semaphore = class;
Tvk_Fence = class;
Tvk_Event = class;
Tvk_Buffer = class;
Tvk_BufferView = class;
Tvk_Image = class;
Tvk_ImageView = class;
Tvk_Swapchain = class;
Tvk_GraphicsPipeline = class;
Tvk_ComputePipeline = class;
Tvk_RenderPass = class;
Tvk_Framebuffer = class;
Tvk_SubmitInfo = class;
Tvk_DeviceMemory = class;
Tvk_PipelineLayout = class;
TVk_PipelineVertexInputStateCreateInfo = class;

TExtensionName = array[0..VK_MAX_EXTENSION_NAME_SIZE] of Char;

TName_List = specialize TVector<String>;
TVkExtensionProperties_List = specialize TVector<TVkExtensionProperties>;
TVkLayerProperties_List = specialize TVector<TVkLayerProperties>;
TVkPhysicalDevice_List = specialize TVector<TVkPhysicalDevice>;
TVkQueueFamilyProperties_List = specialize TVector<TVkQueueFamilyProperties>;
TVkDeviceQueueCreateInfo_List = specialize TVector<TVkDeviceQueueCreateInfo>;
TFloat_List = specialize TVector<Single>;
TFloat_List_List = specialize TFPGObjectList<TFloat_List>;
TVkCommandBuffer_List = specialize TVector<TVkCommandBuffer>;
TVkFence_List = specialize TVector<TvkFence>;
TVkSurfaceFormatKHR_List = specialize TVector<TVkSurfaceFormatKHR>;
TVkPresentModeKHR_List = specialize TVector<TVkPresentModeKHR>;
TvkImage_List = specialize TVector<TvkImage>;
TvkImageView_List = specialize TVector<TvkImageView>;
TVkPipelineShaderStageCreateInfo_List = specialize TVector<TVkPipelineShaderStageCreateInfo>;
TvkSubmitInfo_List = specialize TVector<TvkSubmitInfo>;
TvkPipelineStageFlags_List = specialize TVector<TvkPipelineStageFlags>;
TvkSemaphore_List = specialize TVector<TVkSemaphore>;
TvkDynamicState_List = specialize TVector<TVkDynamicState>;
TvkDeviceMemory_List = specialize TVector<TvkDeviceMemory>;
TVkViewport_List = specialize TVector<TVkViewport>;
TVkRect2D_List = specialize TVector<TVkRect2D>;
TVkVertexInputBindingDescription_List = specialize TVector<TVkVertexInputBindingDescription>;
TVkVertexInputAttributeDescription_List = specialize TVector<TVkVertexInputAttributeDescription>;

TVk_CommandBuffer_List = specialize TFPGObjectList<TVk_CommandBuffer>;
Tvk_Semaphore_List = specialize TFPGObjectList<Tvk_Semaphore>;
Tvk_Fence_List = specialize TFPGObjectList<Tvk_Fence>;
Tvk_Event_List = specialize TFPGObjectList<Tvk_Event>;
TVk_Device_List = specialize TFPGObjectList<TVk_Device>;
Tvk_Queue_List = specialize TFPGObjectList<Tvk_Queue>;
Tvk_QueueFamily_List = specialize TFPGObjectList<Tvk_QueueFamily>;
Tvk_Surface_List = specialize TFPGObjectList<Tvk_Surface>;
Tvk_Buffer_List = specialize TFPGObjectList<Tvk_Buffer>;
Tvk_BufferView_List = specialize TFPGObjectList<Tvk_BufferView>;
Tvk_ImageView_List = specialize TFPGObjectList<Tvk_ImageView>;
Tvk_Image_List = specialize TFPGObjectList<Tvk_Image>;
Tvk_GraphicsPipeline_List = specialize TFPGObjectList<Tvk_GraphicsPipeline>;
Tvk_ComputePipeline_List = specialize TFPGObjectList<Tvk_ComputePipeline>;
Tvk_Framebuffer_List = specialize TFPGObjectList<Tvk_Framebuffer>;
Tvk_SubmitInfo_list = specialize TFPGObjectList<Tvk_SubmitInfo>;
Tvk_DeviceMemory_List = specialize TFPGObjectList<Tvk_DeviceMemory>;
Tvk_PipelineLayout_List = specialize TFPGObjectList<Tvk_PipelineLayout>;
TVk_PipelineVertexInputStateCreateInfo_List = specialize TFPGObjectList<TVk_PipelineVertexInputStateCreateInfo>;

Tvk_DebugCallback = function(flags: TVkDebugReportFlagsEXT; objectType: TVkDebugReportObjectTypeEXT;
  object_: uint64_t; location: size_t; messageCode: int32_t; pLayerPrefix: Pchar; pMessage: Pchar): TVkBool32;

Tvk_QueueFamilyIndex = Integer;
Tvk_QueueFamilyIndex_List = specialize TFPGList<Tvk_QueueFamilyIndex>;
Tvk_QueueIndex = Integer;
Tvk_QueueFamily_Array = array of TVk_QueueFamily;

{ Tvk_DescriptorPool }

Tvk_DescriptorPool = class
  vk_Device: Tvk_Device;
  vkDescriptorPool: TVkDescriptorPool;


  constructor Create(const aDevice: Tvk_Device);
  destructor Destroy; override;
end;

{ TVk_PipelineVertexInputStateCreateInfo }

TVk_PipelineVertexInputStateCreateInfo = class
  vk_Device: Tvk_Device;

  VkVertexInputBindingDescriptions: TVkVertexInputBindingDescription_List;
  vkVertexInputAttributeDescriptions: TVkVertexInputAttributeDescription_List;


  procedure AddBinding(const aBinding: uint32_t; const aStride: uint32_t; const aInputRate: TvkVertexInputRate = VK_VERTEX_INPUT_RATE_VERTEX);
  procedure AddAttribute(const aBinding: uint32_t; const aFormat: TvkFormat; const aOffset: uint32_t; const aLocation: uint32_t);
  procedure LoadType(const aTypeInfo: PTypeInfo; const aBinding: uint32_t; const aInputRate: TVkVertexInputRate = VK_VERTEX_INPUT_RATE_VERTEX; const aStartingLocation: uint32_t = 0);
  function GetVKPipelineVertexInputStateCreateInfo: TVkPipelineVertexInputStateCreateInfo;

  constructor Create(const aDevice: Tvk_Device);
  destructor Destroy; override;
end;

{ Tvk_PipelineLayout }

Tvk_PipelineLayout = class
  vk_Device: Tvk_Device;
  vkPipelineLayout: TVkPipelineLayout;

  vkPipelineLayoutCreateInfo: TVkPipelineLayoutCreateInfo;

  procedure Refresh;
  constructor Create(const aDevice: Tvk_Device);
  destructor Destroy; override;
end;

TVk_ViewportScissorInfo = record
  Viewport: PVkViewport;
  Scissor: PVkRect2D;
end;

{ Tvk_ComputePipeline }

Tvk_ComputePipeline = class
  vk_Device: Tvk_Device;
  vk_PipelineLayout: Tvk_PipelineLayout;
  vkPipeline: TVkPipeline;


  vkComputePipelineCreateInfo: TVkComputePipelineCreateInfo;
  constructor Create(const aDevice: Tvk_Device; const aLayout: Tvk_PipelineLayout; const aComputeStageFileName: String; const aEntryPoint: String);
  destructor Destroy; override;
end;

{ Tvk_GraphicsPipeline }

Tvk_GraphicsPipeline = class
  vk_Device: Tvk_Device;
  vk_CompatibleRenderPass: Tvk_RenderPass;
  vk_PipelineLayout: Tvk_PipelineLayout;

  vkPipeline: TVkPipeline;

  ShaderStageCreateInfos: TVkPipelineShaderStageCreateInfo_List;
  LoadedStages: TVkShaderStageFlags;

  vkGraphicsPipelineCreateInfo: TVkGraphicsPipelineCreateInfo;

  vkVertexInputStateCreateInfo: TVkPipelineVertexInputStateCreateInfo;
  vkInputAssemblyStateCreateInfo: TVkPipelineInputAssemblyStateCreateInfo;
  vkTessellationStateCreateInfo: TVkPipelineTessellationStateCreateInfo;
  vkViewportStateCreateInfo: TVkPipelineViewportStateCreateInfo;
  vkRasterizationStateCreateInfo: TVkPipelineRasterizationStateCreateInfo;
  vkMultisampleStateCreateInfo: TVkPipelineMultisampleStateCreateInfo;
  vkDepthStencilStateCreateInfo: TVkPipelineDepthStencilStateCreateInfo;
  vkColorBlendAttachmentState: TVkPipelineColorBlendAttachmentState;
  vkColorBlendStateCreateInfo: TVkPipelineColorBlendStateCreateInfo;
  vkDynamicStateCreateInfo: TVkPipelineDynamicStateCreateInfo;

  vkDynamicStates: TVkDynamicState_List;

  vkViewports: TVkViewport_List;
  vkScissors: TVkRect2D_List;

  function AddStaticViewportAndScissor(const aWidth, aHeight: uint32_t): TVk_ViewportScissorInfo;
  procedure AddShader(const aStage: TVkShaderStageFlagBits; const aFileName: String; const aEntryPoint: String='main');
  procedure RefreshPipeline;
  constructor Create(const aDevice: Tvk_Device; const aCompatibleRenderPass: Tvk_RenderPass);
  destructor Destroy; override;
end;

{ Tvk_ImageView }

Tvk_ImageView = class
  vk_Image: Tvk_Image;
  vkImageView: TVkImageView;

  vkImageViewCreateInfo: TVkImageViewCreateInfo;
  constructor Create(const aImage: Tvk_Image;
    const aViewType: TVkImageViewType = VK_IMAGE_VIEW_TYPE_2D;
    const aFormat: TVkFormat = VK_FORMAT_B8G8R8A8_UNORM);
  constructor CreateEx(const aImage: Tvk_Image; const aImageViewCreateInfo: TVkImageViewCreateInfo);
  destructor Destroy; override;
end;

{ Tvk_Image }

Tvk_Image = class
  vk_Device: Tvk_Device;

  vkImage: TVkImage;
  vkImageCreateInfo: TVkImageCreateInfo;
  QueueFamilies: Tvk_QueueFamilyIndex_List;
  ImageViews: Tvk_ImageView_List;

  ImageMemory: Tvk_DeviceMemory;

  function GetImageView(const aViewType: TVkImageViewType = VK_IMAGE_VIEW_TYPE_2D; const aFormat: TVkFormat = VK_FORMAT_B8G8R8A8_UNORM): Tvk_ImageView;
  function GetImageViewEx(const aImageViewCreateInfo: TVkImageViewCreateInfo): TVk_ImageView;

  {$IFDEF FILE_SAVE}
  procedure SaveToFile(const aFilename: String);
  {$ENDIF FILE_SAVE}
  procedure UnmapMemory;
  function MapMemory(const MemoryProperties: TVkMemoryPropertyFlags =
        [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT]): Pointer;

  constructor Create(const aDevice: TVk_Device; const aFlags: TVkImageCreateFlags;
      const aImageType: TVkImageType; const aFormat: TvkFormat;
      const aWidth, aHeight: uint32_t; const aUsage: TVkImageUsageFlags;
      const aQueues: array of Tvk_Queue;
      const aMipLevels: uint32_t = 1; const aArrayLayers: uint32_t = 1;
      const aSamples: TVkSampleCountFlagBits = [VK_SAMPLE_COUNT_1_BIT];
      const aTiling: TVkImageTiling = VK_IMAGE_TILING_OPTIMAL);
  constructor CreateEx(const aDevice: TVk_Device; const aImageCreateinfo: TVkImageCreateInfo);

  destructor Destroy; override;
end;

{ Tvk_SwapChainImage }

Tvk_SwapChainImage = class(Tvk_Image)
  vk_Swapchain: Tvk_Swapchain;
  constructor CreateFromSwapchain(const aSwapchain: Tvk_Swapchain; const aImage: TvkImage);
end;

{ Tvk_BufferView }

Tvk_BufferView = class
  vk_Buffer: Tvk_Buffer;
  vkBufferView: TVkBufferView;

  vkBufferViewCreateInfo: TVkBufferViewCreateInfo;
  constructor Create(const aBuffer: Tvk_Buffer; const aFormat: TvkFormat; const aOffset: TVkDeviceSize = 0; const aRange: TVkDeviceSize = VK_WHOLE_SIZE);
  destructor Destroy; override;
end;

{ Tvk_Buffer }

Tvk_Buffer = class
  Destroying: Boolean;
  vk_Device: Tvk_Device;
  vkBuffer: TVkBuffer;

  BufferMemory: Tvk_DeviceMemory;

  vkBufferCreateInfo: TVkBufferCreateInfo;
  QueueFamilies: Tvk_QueueFamilyIndex_List;

  BufferViews: Tvk_BufferView_List;

  function GetBufferView(const aFormat: TvkFormat; const aOffset: TVkDeviceSize = 0; const aRange: TVkDeviceSize = VK_WHOLE_SIZE): Tvk_BufferView;
  constructor Create(const aDevice: TVk_Device; const aSize: TVkDeviceSize;
    const aCreateFlags: TVkBufferCreateFlags; const aUsageFlags: TVkBufferUsageFlags;
    const aQueues: array of Tvk_Queue;
    const AllocMemFlag: Boolean = False;
//    const MemoryTypesFilter: uint32_t = $FFFF; // TVkMemoryPropertyFlagBits = [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT];
    const MemoryProperties: TVkMemoryPropertyFlags = [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT]);
  destructor Destroy; override;
end;

{ Tvk_Framebuffer }

Tvk_Framebuffer = class
  vk_Device: Tvk_Device;
  vkFramebuffer: TVkFramebuffer;
  vkFramebufferCreateInfo: TVkFramebufferCreateInfo;

  vkImageViewList: TvkImageView_List;
  constructor Create(const aDevice: TVk_Device; const aCompatibleRenderPass: Tvk_RenderPass; const ImageViews: array of Tvk_ImageView; const aWidth, aHeight, aLayers: uint32_t);
  destructor Destroy; override;
end;

{ Tvk_RenderPass }

Tvk_RenderPass = class
  vk_Device: Tvk_Device;
  vkRenderPass: TVkRenderPass;

  vkColorAttachmentDescription: TVkAttachmentDescription;
  vkColorAttachmentRef: TVkAttachmentReference;
  vkSubPassDescription: TVkSubpassDescription;
  vkRenderPassCreateInfo: TVkRenderPassCreateInfo;

  vkSubpassDependency: TVkSubpassDependency;

  constructor Create(const aDevice: TVk_Device; const aFormat: TVkFormat);
  destructor Destroy; override;
end;

{ Tvk_Swapchain }

Tvk_Swapchain = class
  vk_Surface: Tvk_Surface;
  vkSwapChain: TVkSwapchainKHR;

  vkSwapchainCreateInfo: TVkSwapchainCreateInfoKHR;
  PresentModes: TVkPresentModeKHR_List;

  vkImages_SwapChain: TvkImage_List;
  Images_SwapChain: TVk_Image_List;
  Framebuffers_SwapChain: Tvk_Framebuffer_List;

  PrePresentCommandBuffers: TVk_CommandBuffer_List;
  PostPresentCommandBuffers: TVk_CommandBuffer_List;

  procedure CreateFramebuffers(const aRenderPass: Tvk_RenderPass);
  procedure PresentQueue(const aQueue: Tvk_Queue; const ImageIndex: uint32_t; const semaphore: TVk_Semaphore = nil);
  function  AcquireNextImage(out ImageIndex: uint32_t; const timeout: uint64_t = 0; const semaphore: TVk_Semaphore = nil; const fence: TVk_Fence = nil): TvkResult;
  procedure CleanupSwapchain(var aSwapchain: TVkSwapchainKHR);
  procedure RefreshSwapchain;
  constructor Create(const aSurface: TVk_Surface);
  destructor Destroy; override;
end;

{ Tvk_Surface }

Tvk_Surface = class
  vk_Device: Tvk_Device;

  vkSurface: TVkSurfaceKHR;
  SurfaceFormats: TVkSurfaceFormatKHR_List;

  SwapChain: Tvk_Swapchain;

{$IFDEF WINDOWS}
	WindowHandle: HWND;
	WindowsApplicationInstance: HINST;
{$ENDIF WINDOWS}
{$IFDEF UNIX}
  X11_display: PDisplay;
  X11_window: TWindow;
{$ENDIF UNIX}
{$IFDEF ANDROID}
	androidApp: Pandroid_app;
	// true if application has focused, false if moved to background
	focused: Boolean;
{$ENDIF ANDROID}


  WindowName: String;
  X, Y: uint32_t;
  Width: uint32_t;
  Height: uint32_t;
  SDLWindow: PSDL_Window;
  procedure Resize(const aWidth, aHeight: uint32_t);
{$IFDEF WINDOWS}
  function WndProc(const hWnd: HWND; const uMsg: UINT; const wParam: WPARAM; const lParam: LPARAM
    ): LRESULT;
{$ENDIF WINDOWS}

  function SupportsPresentForQueueFamilyIndex(const aQueueFamilyIndex: uint32_t): Boolean;
  function CreateSwapchain: Tvk_Swapchain;
  procedure CreateSurface;
  procedure Initialize(const aX, aY, aWidth, aHeight: uint32_t; const fullscreen: Boolean = False);
  constructor Create(const aDevice: Tvk_Device; const aX, aY, aWidth, aHeight: uint32_t);
  destructor Destroy; override;
end;

{ Tvk_Instance }

Tvk_Instance = class
  private
    FVulkan_LibHandle: TLibHandle;

    function LoadLibrary_vulkan(const Name: PChar): Boolean;
    function FreeLibrary_vulkan: Boolean;
    function GetProcAddress_vulkan(const ProcName: PAnsiChar): Pointer;
    function Vulkan_InitLoader(const LibName: String = DEFAULT_VULKAN_LIB_NAME): Boolean;
  public
{$ENDIF VULKAN_FLAT}

  {$include vulkan_functionvariables.inc}

  vkInstance: TVkInstance;

  ReportedInstanceExtensions: TVkExtensionProperties_List;
  ReportedInstanceLayers: TVkLayerProperties_List;
  ReportedDevices: TVkPhysicalDevice_List;

  RequestedInstanceExtensions: TName_List;
  RequestedInstanceLayers: TName_List;

  vkInstanceCreateInfo: TVkInstanceCreateInfo;
  vkApplicationInfo: TVkApplicationInfo;

  vkDebugReportCallback: TVkDebugReportCallbackEXT;
  DebugCallback: Tvk_DebugCallback;

  Devices: TVk_Device_List;
  {$IFNDEF VULKAN_FLAT}
  procedure AttachDebugCallback(const aFlags: TVkDebugReportFlagsEXT = [VK_DEBUG_REPORT_ERROR_BIT_EXT, VK_DEBUG_REPORT_WARNING_BIT_EXT]; const aCallback: Tvk_DebugCallback = nil);
  function HasValidVulkanLibraryHandle: Boolean;
  function HasExtension(const aExtension: TvkExtension): Boolean;
  function HasLayer(const aLayer: String): Boolean;
  function RequestLayer(const aLayer: String): Boolean;
  function RequestExtension(const aExtension: TvkExtension): Boolean;
  function LoadDevices(const aApplicationName: String;
    const aRequestedExtensions: TvkExtensions; const aRequestedLayers: array of string): Boolean;
  {$ENDIF VULKAN_FLAT}
  function Vulkan_InitFunctions(const VulkanAppName: String = 'VulkanApp'): Boolean;
  constructor Create(const LibName: String = DEFAULT_VULKAN_LIB_NAME);
  destructor Destroy; override;
{$IFNDEF VULKAN_FLAT}
end;
{$ENDIF VULKAN_FLAT}

{$IFDEF INCLUDE_DBG}

{ Tvk_Instance_DBG }

Tvk_Instance_DBG = class
   Vulkan_Interface: Tvk_Instance;

   function Vulkan_Instance: TVkInstance;
   function Vulkan_InitFunctions(const VulkanAppName: String = 'VulkanApp'): Boolean;
   function Vulkan_InitLoader(const LibName: String = DEFAULT_VULKAN_LIB_NAME): Boolean;
  {$include vulkan_dbgclass_type.inc}
  constructor Create(const LibName: String = DEFAULT_VULKAN_LIB_NAME);
  destructor Destroy; override;
end;
{$ENDIF}

{ Tvk_SubmitInfo }

Tvk_SubmitInfo = class
  vk_Queue: Tvk_Queue;
  WaitSemaphores: TvkSemaphore_List;
  PipelineStageFlagsAtWhichToWait: TvkPipelineStageFlags_List;
  SignalSemaphores: TvkSemaphore_List;
  CommandBuffers: TvkCommandBuffer_List;

  procedure AddCommandBuffer(const aCommandBuffer: Tvk_CommandBuffer);
  procedure AddWaitSemaphore(const aWaitSemaphore: Tvk_Semaphore; const aPipelineStageFlags: TVkPipelineStageFlags);
  procedure AddSignalSemaphore(const aSignalSemaphore: Tvk_Semaphore);
  constructor Create(const aQueue: Tvk_Queue);
  destructor Destroy; override;
end;

{ Tvk_Queue }

Tvk_Queue = class
//  vk_Device: Tvk_Device;
  vk_QueueFamily: Tvk_QueueFamily;

  vkQueue: TVkQueue;
  QueueFamilyIndex: Cardinal;
  QueueIndex: Cardinal;
  Priority: Single;

  SubmitInfo: Tvk_SubmitInfo;
  vkSubmitInfos: TvkSubmitInfo_List;


  procedure QueueSubmitInfo;
  procedure SubmitQueuedSubmitInfos(const aFence: Tvk_Fence = nil);
  procedure SubmitSimpleCommandBuffer(const aBuffer: Tvk_CommandBuffer; const WaitSemaphore: Tvk_Semaphore; const aPipelineStageFlags: TVkPipelineStageFlags; const SignalSemaphore: Tvk_Semaphore);
//    pQueueFamilyProperties: PVkQueueFamilyProperties;
  procedure Present(const aSwapChain: Tvk_Swapchain; const ImageIndex: uint32_t; const semaphore: TVk_Semaphore = nil);
  function GetCommandBuffer(const aCommandBufferLevel: TVkCommandBufferLevel = VK_COMMAND_BUFFER_LEVEL_PRIMARY): Tvk_CommandBuffer;
  constructor Create(const aQueueFamily: Tvk_QueueFamily; const aQueueFamilyIndex, aQueueIndex: Cardinal; const aPriority: Single);
  destructor Destroy; override;
end;

{ Tvk_CommandBuffer }

Tvk_CommandBuffer = class
  vk_CommandPool: Tvk_CommandPool;
  vkCommandBuffer: TVkCommandBuffer;
  vkCommandBufferLevel: TVkCommandBufferLevel;

  procedure ExecuteSubCommandBuffer(const aSecondaryBuffer: Tvk_CommandBuffer);
  procedure BeginRecording(const CommandBufferUsageFlags: TVkCommandBufferUsageFlags; const aRenderPass: Tvk_RenderPass; const aSubPassIndex: uint32_t;
    const aFrameBuffer: Tvk_FrameBuffer);
  procedure BeginRenderPass(const aRenderPass: Tvk_RenderPass; const aFrameBuffer: Tvk_FrameBuffer; const aContents: TVkSubpassContents = VK_SUBPASS_CONTENTS_INLINE);
  procedure BindPipeline(const aPipeline: Tvk_GraphicsPipeline);
  procedure BindVertexBuffer(const Binding: uint32_t; const pBuffer: PVkBuffer; const pOffset: PVkDeviceSize);
  procedure Draw(const aVertexCount, aInstanceCount, aFirstVertex, aFirstInstance: uint32_t);
  procedure CopyImage(const SourceImage: Tvk_Image; const DestImage: Tvk_Image; const Regions: array of TVkImageCopy);
  procedure CopyImageComplete(const SourceImage: Tvk_Image; const DestImage: Tvk_Image);
  procedure EndRenderPass;
  procedure EndRecording;
  procedure Reset(const flags: TVkCommandBufferResetFlags = [VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT]);
  procedure SetViewport(const aViewport: TVkViewport);
  constructor Create(const aCommandPool: Tvk_CommandPool; const aCommandBufferLevel: TvkCommandBufferLevel; const aCommandBuffer: TVkCommandBuffer);
  destructor Destroy; override;
end;


{ Tvk_CommandPool }

Tvk_CommandPool = class
  vk_QueueFamily: Tvk_QueueFamily;

  vkCommandPool: TVkCommandPool;
  vkCommandPoolCreateInfo: TVkCommandPoolCreateInfo;

  DefaultAllocationSize: Cardinal;
  CommandBufferPool: array[TVkCommandBufferLevel] of TVkCommandBuffer_List;
  CommandBuffers: TVk_CommandBuffer_List;

  function GetCommandBuffer(const aCommandBufferLevel: TVkCommandBufferLevel): Tvk_CommandBuffer;
  procedure Reset(const aFlags: TVkCommandPoolResetFlags);
  constructor Create(const aQueueFamily: Tvk_QueueFamily; const aFlags: TVkCommandPoolCreateFlags);
  destructor Destroy; override;
end;

{ Tvk_QueueFamily }

Tvk_QueueFamily = class
  vk_Device: Tvk_Device;

  Queues: Tvk_Queue_List;
  vk_CommandPool: Tvk_CommandPool;

  pQueueFamilyProperties: PVkQueueFamilyProperties;
  QueueFamilyIndex: Cardinal;

  vkCommandPoolCreateFlags: TVkCommandPoolCreateFlags;

  SupportsPresent: Boolean;

  procedure Initialize;
  constructor Create(const aDevice: Tvk_Device; const aQueueFamilyIndex: Cardinal; const aWindow: Tvk_Surface = nil; const aCommandPoolCreateFlags: TVkCommandPoolCreateFlags = [VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT]);
  destructor Destroy; override;
end;

{ Tvk_Event }

Tvk_Event = class
   vk_Device: Tvk_Device;

   vkEvent: TVkEvent;
   function Status: TVkResult_Set_Reset;
   procedure ResetEvent;
   procedure SetEvent;
   constructor Create(const aDevice: Tvk_Device);
   destructor Destroy; override;
end;

{ Tvk_Fence }

Tvk_Fence = class
  vk_Device: Tvk_Device;

  vkFence: TVkFence;

  procedure WaitForSignalled(aTimeoutInNanoseconds: uint64_t);
  procedure Reset;
  function Status: TVkResult;
  constructor Create(const aDevice: Tvk_Device; const aVkFenceCreateFlags: TVkFenceCreateFlags);
  destructor Destroy; override;
end;


{ Tvk_Semaphore }

Tvk_Semaphore = class
  vk_Device: Tvk_Device;
  vkSemaphore: TVkSemaphore;

  constructor Create(const aDevice: Tvk_Device);
  destructor Destroy; override;
end;

{ Tvk_DeviceMemory }

Tvk_DeviceMemory = class
  const ENTIRE_MEMORY = $7FFFFFFFFFFFFFFF;
  var
  vk_Device: Tvk_Device;
  vkDeviceMemory: TvkDeviceMemory;
  vkMemoryAllocateInfo: TVkMemoryAllocateInfo;

  MappedAddress: Pointer;

  function MapMemory(const offset: TvkDeviceSize = 0; size: TVkDeviceSize = ENTIRE_MEMORY): Pointer;
  procedure UnMapMemory;

  constructor Create(const aDevice: Tvk_Device; const aSize: TvkDeviceSize; const MemoryTypesFilter: uint32_t; const MemoryProperties: TVkMemoryPropertyFlags);
  destructor Destroy; override;
end;

{ Tvk_Device }

Tvk_Device = class
  public
    vk_Instance: Tvk_Instance;

    // Physical Device info
    vkPhysicalDevice: TVkPhysicalDevice;
    vkPhysicalDeviceProperties: TVkPhysicalDeviceProperties;
    vkPhysicalDeviceFeatures: TVkPhysicalDeviceFeatures;
    vkPhysicalDeviceMemoryProperties: TVkPhysicalDeviceMemoryProperties;

    ReportedQueueFamilies: TVkQueueFamilyProperties_List;
    ReportedDeviceLayers: TVkLayerProperties_List;
    ReportedDeviceExtensions: TVkExtensionProperties_List;

    // Logical Device info
//    vk_QueueFamilies: array of Tvk_QueueFamily;
//      vk_Queues: array of Tvk_Queue;
//      vk_CommandPools: array of Tvk_CommandPool;

    vkDeviceCreateInfo: TVkDeviceCreateInfo;
    vkDevice: TVkDevice;

    RequestedDeviceFeatures: TVkPhysicalDeviceFeatures;
    RequestedDeviceExtensions: TName_List;
    RequestedDeviceLayers: TName_List;

    vkFormat: TVkFormat;

//    vk_CommandQueue: TVk_CommandQueue;

    DeviceQueueCreateInfos: TVkDeviceQueueCreateInfo_List;
    QueuePrioritiesForCreateInfos: TFloat_List;

    //
    RenderPass: Tvk_RenderPass;
    Semaphores: Tvk_Semaphore_List;
    Fences: Tvk_Fence_List;
    Events: Tvk_Event_List;
    Surfaces: Tvk_Surface_List;
    QueueFamilies: Tvk_QueueFamily_List;
    GraphicsPipelines: Tvk_GraphicsPipeline_List;
    ComputePipelines: Tvk_ComputePipeline_List;
    Images: Tvk_Image_List;
    Buffers: Tvk_Buffer_List;
    DeviceMemories: Tvk_DeviceMemory_List;
    FrameBuffers: Tvk_Framebuffer_List;
    PipelineLayouts: Tvk_PipelineLayout_List;
    PipelineVertexInputStateCreateInfos: TVk_PipelineVertexInputStateCreateInfo_List;

{$IFDEF WINDOWS}
    wndClass: WNDCLASSEX;
{$ENDIF WINDOWS}

    function GetValidDepthFormat: TVkFormat;
    function CreateSurface(const aX, aY, aWidth, aHeight: uint32_t): Tvk_Surface;
    function HasExtension(const aExtension: TvkExtension): Boolean;
    function HasLayer(const aLayer: String): Boolean;
    procedure CreateDeviceQueueCreateInfos;

    function RequestQueue(const queueFlags: TVkQueueFlags; const aWindow: Tvk_Surface = nil; const aPriority: Single = 0.0): Tvk_Queue;
    function RequestLayer(const aLayer: String): Boolean;
    function RequestExtension(const aExtension: TvkExtension): Boolean;
    function GetQueueFamilyIndex(const queueFlags: TVkQueueFlags = [VK_QUEUE_GRAPHICS_BIT, VK_QUEUE_COMPUTE_BIT]; const aWindow: Tvk_Surface = nil): Integer;

    function AllocMemory(const aSize: TvkDeviceSize; const MemoryTypesFilter: uint32_t; const MemoryProperties: TVkMemoryPropertyFlags): Tvk_DeviceMemory;
    function FindMemoryType(const MemoryTypesFilter: uint32_t; properties: TVkMemoryPropertyFlags): uint32_t;

//    function NewBuffer_ForVertex(const aSize: TVkDeviceSize);
    function NewPipelineVertexInputStateCreateInfo: TVk_PipelineVertexInputStateCreateInfo;
    function GetBuffer(const aSize: TVkDeviceSize; const aCreateFlags: TVkBufferCreateFlags; const aUsageFlags: TVkBufferUsageFlags; const aQueues: array of Tvk_Queue;
    const AllocMemFlag: Boolean = False;
//    const MemoryTypesFilter: uint32_t = $FFFF; //TVkMemoryPropertyFlagBits = [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT];
    const MemoryProperties: TVkMemoryPropertyFlags = [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT]): Tvk_Buffer;
    function GetImage(const aFlags: TVkImageCreateFlags;
      const aImageType: TVkImageType; const aFormat: TvkFormat;
      const aWidth, aHeight: uint32_t; const aUsage: TVkImageUsageFlags;
      const aQueues: array of Tvk_Queue;
      const aMipLevels: uint32_t = 1; const aArrayLayers: uint32_t = 1;
      const aSamples: TVkSampleCountFlagBits = [VK_SAMPLE_COUNT_1_BIT];
      const aTiling: TVkImageTiling = VK_IMAGE_TILING_OPTIMAL): TVk_Image;
    function GetImageEx(const aImageCreateinfo: TVkImageCreateInfo): TVk_Image;

    procedure WaitUntilIdle;
    procedure WaitForFences(const aFenceList: TvkFence_List; const WaitForAll: TVkBool32=VK_TRUE; const TimeoutInNanoseconds: Uint64_t=0);
    procedure ResetFences(const aFenceList: TvkFence_List);
    function GetFence(const aFlags: TVkFenceCreateFlags = []): Tvk_Fence;
    function GetSemaphore: Tvk_Semaphore;
    function GetEvent: Tvk_Event;
    function GetRenderPass(const aImageFormat: TVkFormat): Tvk_RenderPass;
    function GetGraphicsPipeline: Tvk_GraphicsPipeline;
    function GetComputePipeline(const aLayout: Tvk_PipelineLayout; const aComputeStageFileName: String; const aEntryPoint: String='main'): Tvk_ComputePipeline;
    function CreatePipelineLayout: Tvk_PipelineLayout;
    function GetFramebuffer(const aCompatibleRenderPass: Tvk_RenderPass; const ImageViews: array of Tvk_ImageView; const aWidth, aHeight, aLayers: uint32_t): Tvk_Framebuffer;
    procedure CreateLogicalDevice(const aRequestedExtensions: TvkExtensions; const aRequestedLayers: array of String);
    constructor Create(const aInstance: Tvk_Instance; const aPhysicalDevice: TVkPhysicalDevice);
    destructor Destroy; override;
end;

function VK_MAKE_VERSION(const major, minor, patch: Integer): Integer;
function VK_API_VERSION(): Integer;
function VK_VERSION_MAJOR(const version: Cardinal): Integer;
function VK_VERSION_MINOR(const version: Cardinal): Integer;
function VK_VERSION_PATCH(const version: Cardinal): Integer;
procedure CheckVulkanCall(const vkResult: TVkResult; const SuccessCodes: PVkResultArray = nil; const FailureCodes: PVkResultArray = nil);
function FlagsSet32(const pSet: Pointer): Integer;

{$IFDEF WINDOWS}
type
  TWNDProcMap = specialize TFPGMap<HINST, Tvk_Surface>;
var
  WndProcMap: TWNDProcMap;
{$ENDIF WINDOWS}
procedure FillByte(const x: Pointer; const count: SizeInt; const value: byte); inline;
procedure SDL_Acquire;
procedure SDL_Release;

var SDL_Loaded: Integer = 0;
implementation

function DebugCallbackDispatch(
  flags: TVkDebugReportFlagsEXT;
  objectType: TVkDebugReportObjectTypeEXT;
  object_: uint64_t;
  location: size_t;
  messageCode: int32_t;
  pLayerPrefix: Pchar;
  pMessage: Pchar;
  pUserData: Pointer
): TVkBool32;
begin
  Result := VK_FALSE;
  if Assigned(pUserData) and Assigned(Tvk_Instance(pUserData).DebugCallback) then
    Result := Tvk_Instance(pUserData).DebugCallback(flags, objectType, object_, location, messageCode, pLayerPrefix, pMessage)
  else
    ShowMessage('Validation layer: ' + pMessage);
end;


procedure GetSharingModeInfo(const Queues: array of Tvk_Queue; var QueueFamilies: Tvk_QueueFamilyIndex_List;
  var sharingMode: TVkSharingMode; var queueFamilyIndexCount: uint32_t; var pQueueFamilyIndices: Puint32_t);
var aQueue: Tvk_Queue;
begin
  if Length(Queues) > 1 then
  begin
    QueueFamilies := Tvk_QueueFamilyIndex_List.Create;
    for aQueue in Queues do
    with aQueue do
      if QueueFamilies.IndexOf(QueueFamilyIndex) = -1 then
        QueueFamilies.Add(QueueFamilyIndex);

    queueFamilyIndexCount := QueueFamilies.Count;

    if QueueFamilies.Count > 1 then
    begin
      sharingmode := VK_SHARING_MODE_CONCURRENT;
      queueFamilyIndexCount := QueueFamilies.Count;
      pQueueFamilyIndices := @QueueFamilies.List^;
    end;
  end;

end;

procedure FillByte(const x: Pointer; const count: SizeInt; const value: byte);
begin
  System.FillByte(x^, count, value);
end;

procedure SDL_Acquire;
begin
  if SDL_Loaded = 0 then
  begin
    if SDL_Init(SDL_INIT_EVERYTHING) < 0 then
      raise Exception.Create('Could not initialize SDL2.0!');
  end;
  Inc(SDL_Loaded);
end;

procedure SDL_Release;
begin
  Dec(SDL_Loaded);
  if SDL_Loaded = 0 then
    SDL_Quit;
end;

function FlagsSet32(const pSet: Pointer): Integer;
var ii: Integer;
    mask: uint32_t;
    test: uint32_t;
begin
  Result := 0;
  mask := $1;
  test := Puint32_t(pSet)^;
  for ii := 0 to 31 do
  begin
    if (mask and test) <> 0 then Inc(Result);
    mask := mask shl 1;
  end;

end;

{ Tvk_DescriptorPool }

constructor Tvk_DescriptorPool.Create(const aDevice: Tvk_Device);
begin
  vk_Device := aDevice;
end;

destructor Tvk_DescriptorPool.Destroy;
begin
  inherited Destroy;
end;

{ Tvk_ComputePipeline }

constructor Tvk_ComputePipeline.Create(const aDevice: Tvk_Device; const aLayout: Tvk_PipelineLayout; const aComputeStageFileName: String; const aEntryPoint: String);
var Code: array of Byte;
  aShaderCreateInfo: TVkShaderModuleCreateInfo;
  aStageCreateInfo: TVkPipelineShaderStageCreateInfo;
begin
  vk_Device := aDevice;
  vk_PipelineLayout := aLayout;

  if not FileExists(aComputeStageFileName) then
    raise Exception.Create('File "' + aComputeStageFileName + '" not found');
  with TFileStream.Create(aComputeStageFileName, fmOpenRead or fmShareDenyNone) do
  try
    SetLength(Code, Size);
    Read(Code[0], Length(Code));
  finally
    Free;
  end;

  FillByte(@aShaderCreateInfo, SizeOf(aShaderCreateInfo), 0);
  with aShaderCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    codeSize := Length(Code);
    pCode := @Code[0];
  end;

  FillByte(@aStageCreateInfo, SizeOf(aStageCreateInfo), 0);
  with aStageCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stage := [VK_SHADER_STAGE_COMPUTE_BIT];
    with vk_Device do
      CheckVulkanCall(vk_Instance.vkCreateShaderModule(vkDevice, @aShaderCreateInfo, nil, @module));
    pName := PChar(aEntryPoint);
    pSpecializationInfo := nil;
  end;

  FillByte(@vkComputePipelineCreateInfo, SizeOf(vkComputePipelineCreateInfo), 0);
  with vkComputePipelineCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    stage := aStageCreateInfo;
    layout := vk_PipelineLayout.vkPipelineLayout;
    basePipelineHandle := 0;
    basePipelineIndex := -1;
  end;



  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateComputePipelines(vkDevice, 0, 1, @vkComputePipelineCreateInfo, nil, @vkPipeline));

end;

destructor Tvk_ComputePipeline.Destroy;
begin
  with vk_Device do
  begin
    vk_Instance.vkDestroyShaderModule(vkDevice, vkComputePipelineCreateInfo.stage.module, nil);
    vk_Instance.vkDestroyPipeline(vkDevice, vkPipeline, nil);
  end;

  inherited Destroy;
end;

{ TVk_PipelineVertexInputStateCreateInfo }

procedure TVk_PipelineVertexInputStateCreateInfo.AddBinding(const aBinding: uint32_t; const aStride: uint32_t; const aInputRate: TvkVertexInputRate);
var aBindingDescription: TVkVertexInputBindingDescription;
begin
  with aBindingDescription do
  begin
    inputRate := aInputRate;
    binding := aBinding;
    stride := aStride;
  end;
  VkVertexInputBindingDescriptions.PushBack(aBindingDescription);
end;

procedure TVk_PipelineVertexInputStateCreateInfo.AddAttribute(const aBinding: uint32_t; const aFormat: TvkFormat; const aOffset: uint32_t; const aLocation: uint32_t);
var VkVertexInputAttributeDescription: TVkVertexInputAttributeDescription;
begin
  with VkVertexInputAttributeDescription do
  begin
    location := aLocation;
    offset := aOffset;
    format := aFormat;
    binding := aBinding;
  end;
  vkVertexInputAttributeDescriptions.PushBack(VkVertexInputAttributeDescription);
end;

procedure TVk_PipelineVertexInputStateCreateInfo.LoadType(const aTypeInfo: PTypeInfo; const aBinding: uint32_t; const aInputRate: TVkVertexInputRate;
  const aStartingLocation: uint32_t);
var td: PTypeData;
    p: Pointer;
    mf: PManagedField;
    ii: Integer;
    vkFormat: TVkFormat;
begin
  td := GetTypeData(aTypeInfo);

  AddBinding(aBinding, td^.RecSize, aInputRate);

  p := @(td^.ManagedFldCount);
  Inc(p, SizeOf(td^.ManagedFldCount));
  mf := p;
  for ii := 0 to td^.ManagedFldCount - 1 do
  begin
    case Lowercase(mf^.TypeRef^.Name) of
      'float', 'single': vkFormat := VK_FORMAT_R32_SFLOAT;
      'vec2': vkFormat := VK_FORMAT_R32G32_SFLOAT;
      'vec3': vkFormat := VK_FORMAT_R32G32B32_SFLOAT;
      'vec4': vkFormat := VK_FORMAT_R32G32B32A32_SFLOAT;
      else
        raise Exception.Create('unhandled type in TVk_VertexInputBindingDescription.Create');
    end;
    AddAttribute(aBinding, vkFormat, mf^.FldOffset, ii + aStartingLocation);

    Inc(mf);
  end;
end;

function TVk_PipelineVertexInputStateCreateInfo.GetVKPipelineVertexInputStateCreateInfo: TVkPipelineVertexInputStateCreateInfo;
begin
  FillByte(@Result, SizeOf(Result), 0);
  with Result do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertexBindingDescriptionCount := VkVertexInputBindingDescriptions.Size;
    pVertexBindingDescriptions := VkVertexInputBindingDescriptions.Mutable[0];
    vertexAttributeDescriptionCount := vkVertexInputAttributeDescriptions.Size;
    pVertexAttributeDescriptions := vkVertexInputAttributeDescriptions.Mutable[0];
  end;
end;

constructor TVk_PipelineVertexInputStateCreateInfo.Create(const aDevice: Tvk_Device);
begin
  vk_Device := aDevice;
  VkVertexInputBindingDescriptions := TVkVertexInputBindingDescription_List.Create;
  vkVertexInputAttributeDescriptions := TVkVertexInputAttributeDescription_List.Create;
end;

destructor TVk_PipelineVertexInputStateCreateInfo.Destroy;
begin
  FreeAndNil(vkVertexInputAttributeDescriptions);
  FreeAndNil(VkVertexInputBindingDescriptions);
  inherited Destroy;
end;

{ Tvk_SwapChainImage }

constructor Tvk_SwapChainImage.CreateFromSwapchain(const aSwapchain: Tvk_Swapchain; const aImage: TvkImage);
begin
  vk_Swapchain := aSwapchain;
  vk_Device := vk_Swapchain.vk_Surface.vk_Device;

  vkImage := aImage;
  ImageViews := Tvk_ImageView_List.Create;
end;

{ Tvk_DeviceMemory }

function Tvk_DeviceMemory.MapMemory(const offset: TvkDeviceSize; size: TVkDeviceSize): Pointer;
begin
  if size = ENTIRE_MEMORY then
    size := vkMemoryAllocateInfo.allocationSize;
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkMapMemory(vkDevice, vkDeviceMemory, offset, size, 0, @MappedAddress));

  Result := MappedAddress;
end;

procedure Tvk_DeviceMemory.UnMapMemory;
begin
  if Assigned(MappedAddress) then
  with vk_Device do
    vk_Instance.vkUnmapMemory(vkDevice, vkDeviceMemory);
  MappedAddress := nil;
end;

constructor Tvk_DeviceMemory.Create(const aDevice: Tvk_Device;
  const aSize: TvkDeviceSize; const MemoryTypesFilter: uint32_t;
  const MemoryProperties: TVkMemoryPropertyFlags);
begin
  vk_Device := aDevice;
  FillByte(@VkMemoryAllocateInfo, SizeOf(VkMemoryAllocateInfo), 0);
  with VkMemoryAllocateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocationSize := aSize;
    memoryTypeIndex := vk_Device.FindMemoryType(MemoryTypesFilter, MemoryProperties);
  end;

  with vk_Device do
    CheckVulkanCall(vk_Instance.vkAllocateMemory(vkDevice, @VkMemoryAllocateInfo, nil, @vkDeviceMemory));
end;

destructor Tvk_DeviceMemory.Destroy;
begin
  UnMapMemory;
  with vk_Device do
    vk_Instance.vkFreeMemory(vkDevice, vkDeviceMemory, nil);
  inherited Destroy;
end;

{ Tvk_SubmitInfo }

procedure Tvk_SubmitInfo.AddCommandBuffer(const aCommandBuffer: Tvk_CommandBuffer);
begin
  CommandBuffers.PushBack(aCommandBuffer.vkCommandBuffer);
end;

procedure Tvk_SubmitInfo.AddWaitSemaphore(const aWaitSemaphore: Tvk_Semaphore; const aPipelineStageFlags: TVkPipelineStageFlags);
begin
  WaitSemaphores.PushBack(aWaitSemaphore.vkSemaphore);
  PipelineStageFlagsAtWhichToWait.PushBack(aPipelineStageFlags);
end;

procedure Tvk_SubmitInfo.AddSignalSemaphore(const aSignalSemaphore: Tvk_Semaphore);
begin
  SignalSemaphores.PushBack(aSignalSemaphore.vkSemaphore);
end;

constructor Tvk_SubmitInfo.Create(const aQueue: Tvk_Queue);
begin
  WaitSemaphores := TvkSemaphore_List.Create;
  PipelineStageFlagsAtWhichToWait := TvkPipelineStageFlags_List.Create;
  SignalSemaphores := TvkSemaphore_List.Create;
  CommandBuffers := TvkCommandBuffer_List.Create;
  vk_Queue := aQueue;
end;

destructor Tvk_SubmitInfo.Destroy;
begin
  FreeAndNil(WaitSemaphores);
  FreeAndNil(PipelineStageFlagsAtWhichToWait);
  FreeAndNil(SignalSemaphores);
  FreeAndNil(CommandBuffers);
  inherited Destroy;
end;

{ Tvk_PipelineLayout }

procedure Tvk_PipelineLayout.Refresh;
begin
  with vkPipelineLayoutCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    setLayoutCount := 0;
    pushConstantRangeCount := 0;
  end;
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreatePipelineLayout(vkDevice, @vkPipelineLayoutCreateInfo, nil, @vkPipelineLayout));
end;

constructor Tvk_PipelineLayout.Create(const aDevice: Tvk_Device);
begin
  vk_Device := aDevice;
end;

destructor Tvk_PipelineLayout.Destroy;
begin
  with vk_Device do
    vk_Instance.vkDestroyPipelineLayout(vkDevice, vkPipelineLayout, nil);
  inherited Destroy;
end;

{ Tvk_GraphicsPipeline }

function Tvk_GraphicsPipeline.AddStaticViewportAndScissor(const aWidth, aHeight: uint32_t): TVk_ViewportScissorInfo;
var vkScissor: TVkRect2D;
    vkViewport: TVkViewport;
begin
  FillByte(@vkScissor, SizeOf(vkScissor), 0);
  FillByte(@vkViewport, SizeOf(vkViewport), 0);
  with vkScissor do
  begin
    extent.width := aWidth;
    extent.height := aHeight;
  end;
  vkScissors.PushBack(vkScissor);
  Result.Scissor := vkScissors.Mutable[vkScissors.Size - 1];

  with vkViewport do
  begin
    width := aWidth;
    height := aHeight;
    maxDepth := 1.0;
  end;
  vkViewports.PushBack(vkViewport);
  Result.Viewport := vkViewports.Mutable[vkViewports.Size - 1];
end;


procedure Tvk_GraphicsPipeline.AddShader(const aStage: TVkShaderStageFlagBits; const aFileName: String; const aEntryPoint: String);
var Code: array of Byte;
  aShaderCreateInfo: TVkShaderModuleCreateInfo;
  aStageCreateInfo: TVkPipelineShaderStageCreateInfo;
begin
  if (aStage * LoadedStages) = aStage then
    raise Exception.Create('Already loaded stage');

  if not FileExists(aFileName) then
    raise Exception.Create('File "' + aFileName + '" not found');
  with TFileStream.Create(aFileName, fmOpenRead or fmShareDenyNone) do
  try
    SetLength(Code, Size);
    Read(Code[0], Length(Code));
  finally
    Free;
  end;

  FillByte(@aShaderCreateInfo, SizeOf(aShaderCreateInfo), 0);
  with aShaderCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    codeSize := Length(Code);
    pCode := @Code[0];
  end;

  FillByte(@aStageCreateInfo, SizeOf(aStageCreateInfo), 0);
  with aStageCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stage := aStage;
    with vk_Device do
      CheckVulkanCall(vk_Instance.vkCreateShaderModule(vkDevice, @aShaderCreateInfo, nil, @module));
    pName := PChar(aEntryPoint);
    pSpecializationInfo := nil;
  end;
  ShaderStageCreateInfos.PushBack(aStageCreateInfo);
  LoadedStages += aStage;

end;

procedure Tvk_GraphicsPipeline.RefreshPipeline;
begin
  vk_PipelineLayout.Refresh;
  with vkGraphicsPipelineCreateInfo do
  begin
    layout := vk_PipelineLayout.vkPipelineLayout;
    renderPass := vk_CompatibleRenderPass.vkRenderPass;
    stageCount := ShaderStageCreateInfos.Size;
    pStages := ShaderStageCreateInfos.Mutable[0];
  end;

  with vkViewportStateCreateInfo do
  begin
    viewportCount := vkViewports.Size;
    pViewports := vkViewports.Mutable[0];
    scissorCount := vkScissors.Size;
    pScissors := vkScissors.Mutable[0];
  end;


  with vk_Device do
  begin
    if vkPipeline <> 0 then
      vk_Instance.vkDestroyPipeline(vkDevice, vkPipeline, nil);

    CheckVulkanCall(vk_Instance.vkCreateGraphicsPipelines(vkDevice, 0, 1, @vkGraphicsPipelineCreateInfo, nil, @vkPipeline));
  end;
end;

constructor Tvk_GraphicsPipeline.Create(const aDevice: Tvk_Device; const aCompatibleRenderPass: Tvk_RenderPass);
begin
  vk_Device := aDevice;
  vk_CompatibleRenderPass := aCompatibleRenderPass;

  vkViewports := TVkViewport_List.Create;
  vkScissors := TVkRect2D_List.Create;

  ShaderStageCreateInfos := TVkPipelineShaderStageCreateInfo_List.Create;
  vkDynamicStates := TVkDynamicState_List.Create;

  vkVertexInputStateCreateInfo.sType := VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
  with vkInputAssemblyStateCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    topology := VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    primitiveRestartEnable := VK_FALSE;
  end;
  vkTessellationStateCreateInfo.sType := VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;

  vkViewportStateCreateInfo.sType := VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;

  with vkRasterizationStateCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    depthClampEnable := VK_FALSE;
    rasterizerDiscardEnable := VK_FALSE;
    polygonMode := VK_POLYGON_MODE_FILL;
    lineWidth := 1.0;
    cullMode := [VK_CULL_MODE_BACK_BIT];
    frontFace := VK_FRONT_FACE_CLOCKWISE;
    depthBiasEnable := VK_FALSE;
  end;

  with vkMultisampleStateCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    sampleShadingEnable := VK_FALSE;
    rasterizationSamples := [VK_SAMPLE_COUNT_1_BIT];
  end;

  vkDepthStencilStateCreateInfo.sType := VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
  with vkColorBlendAttachmentState do
  begin
    colorWriteMask := [VK_COLOR_COMPONENT_R_BIT, VK_COLOR_COMPONENT_G_BIT,
              VK_COLOR_COMPONENT_B_BIT, VK_COLOR_COMPONENT_A_BIT];
    blendEnable := VK_FALSE;
  end;
  with vkColorBlendStateCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    logicOpEnable := VK_FALSE;
    logicOp := VK_LOGIC_OP_COPY;
    attachmentCount := 1;
    pAttachments := @vkColorBlendAttachmentState;
    blendConstants[0] := 0.0;
    blendConstants[1] := 0.0;
    blendConstants[2] := 0.0;
    blendConstants[3] := 0.0;
  end;
  vkDynamicStates.PushBack(VK_DYNAMIC_STATE_VIEWPORT);
  with vkDynamicStateCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamicStateCount := vkDynamicStates.Size;
    pDynamicStates := vkDynamicStates.Mutable[0];
  end;

  vk_PipelineLayout := Tvk_PipelineLayout.Create(vk_Device);

  with vkGraphicsPipelineCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;

    pVertexInputState := @vkVertexInputStateCreateInfo;
    pInputAssemblyState := @vkInputAssemblyStateCreateInfo;
    pTessellationState := nil; //@vkTessellationStateCreateInfo;
    pViewportState := @vkViewportStateCreateInfo;
    pRasterizationState := @vkRasterizationStateCreateInfo;
    pMultisampleState := @vkMultisampleStateCreateInfo;
    pDepthStencilState := @vkDepthStencilStateCreateInfo;
    pColorBlendState := @vkColorBlendStateCreateInfo;
    pDynamicState := nil; //@vkDynamicStateCreateInfo;
  end;
end;

destructor Tvk_GraphicsPipeline.Destroy;
var aCreateInfo: TVkPipelineShaderStageCreateInfo;
begin
  FreeAndNil(vkViewports);
  FreeAndNil(vkScissors);
  FreeAndNil(vkDynamicStates);
  with vk_Device do
  for aCreateInfo in ShaderStageCreateInfos do
    vk_Instance.vkDestroyShaderModule(vkDevice, aCreateInfo.module, nil);

  FreeAndNil(vk_PipelineLayout);
  FreeAndNil(ShaderStageCreateInfos);
  with vk_Device do
    vk_Instance.vkDestroyPipeline(vkDevice, vkPipeline, nil);
  inherited Destroy;
end;

{ Tvk_ImageView }

constructor Tvk_ImageView.Create(const aImage: Tvk_Image; const aViewType: TVkImageViewType; const aFormat: TVkFormat);
begin
  vk_Image := aImage;

  FillByte(@vkImageViewCreateInfo, SizeOf(vkImageViewCreateInfo), 0);
  with vkImageViewCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    image := aImage.vkImage;
    viewType := aViewType;
    format := aFormat;
    with components do
    begin
      r := VK_COMPONENT_SWIZZLE_IDENTITY;
      g := VK_COMPONENT_SWIZZLE_IDENTITY;
      b := VK_COMPONENT_SWIZZLE_IDENTITY;
      a := VK_COMPONENT_SWIZZLE_IDENTITY;
    end;
    with subresourceRange do
    begin
      aspectMask := [VK_IMAGE_ASPECT_COLOR_BIT];
      baseMipLevel := 0;
      levelCount := 1;
      baseArrayLayer := 0;
      layerCount := 1;
    end;
  end;
  with vk_Image.vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateImageView(vkDevice, @vkImageViewCreateInfo, nil, @vkImageView));
end;

constructor Tvk_ImageView.CreateEx(const aImage: Tvk_Image; const aImageViewCreateInfo: TVkImageViewCreateInfo);
begin
  vk_Image := aImage;
  vkImageViewCreateInfo := aImageViewCreateInfo;
  with vk_Image.vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateImageView(vkDevice, @vkImageViewCreateInfo, nil, @vkImageView));
end;

destructor Tvk_ImageView.Destroy;
begin
  with vk_Image.vk_Device do
    vk_Instance.vkDestroyImageView(vkDevice, vkImageView, nil);
  inherited Destroy;
end;

{ Tvk_Image }

function Tvk_Image.GetImageView(const aViewType: TVkImageViewType; const aFormat: TVkFormat): Tvk_ImageView;
begin
  Result := Tvk_ImageView.Create(Self, aViewType, aFormat);
  ImageViews.Add(Result);
end;

function Tvk_Image.GetImageViewEx(const aImageViewCreateInfo: TVkImageViewCreateInfo): TVk_ImageView;
begin
  Result := Tvk_ImageView.CreateEx(Self, aImageViewCreateInfo);
  ImageViews.Add(Result);
end;

procedure Tvk_Image.SaveToFile(const aFilename: String);
var aBitmap: TBGRABitmap;
begin
  MapMemory;
  aBitmap := TBGRABitmap.Create(vkImageCreateInfo.extent.width, vkImageCreateInfo.extent.height);
  Move(ImageMemory.MappedAddress^, aBitmap.Data^, ImageMemory.vkMemoryAllocateInfo.allocationSize);
  aBitmap.SaveToFile(aFileName);
  FreeAndNil(aBitmap);
end;

procedure Tvk_Image.UnmapMemory;
begin
  if Assigned(ImageMemory) and Assigned(ImageMemory.MappedAddress) then
  with vk_Device do
  begin
//    vk_Instance.bin vkUnBindImageMemory(vkDevice, vkImage, ImageMemory.vkDeviceMemory, 0));
    ImageMemory.UnMapMemory;
  end;
end;

function Tvk_Image.MapMemory(const MemoryProperties: TVkMemoryPropertyFlags): Pointer;
var vkMemoryRequirements: TVkMemoryRequirements;
begin
  with vk_Device do
  begin
    if not Assigned(ImageMemory) then
    begin
      vk_Instance.vkGetImageMemoryRequirements(vkDevice, vkImage, @vkMemoryRequirements);
//      ImageMemory := AllocMemory(vkMemoryRequirements.size, [VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT], MemoryProperties);
      ImageMemory := AllocMemory(vkMemoryRequirements.size, vkMemoryRequirements.memoryTypeBits, MemoryProperties);
    end;
    Result := ImageMemory.MappedAddress;
    if Assigned(Result) then Exit;
    Result := ImageMemory.MapMemory;
    CheckVulkanCall(vk_Instance.vkBindImageMemory(vkDevice, vkImage, ImageMemory.vkDeviceMemory, 0));
  end;
end;

constructor Tvk_Image.Create(const aDevice: TVk_Device; const aFlags: TVkImageCreateFlags; const aImageType: TVkImageType; const aFormat: TvkFormat; const aWidth,
  aHeight: uint32_t; const aUsage: TVkImageUsageFlags; const aQueues: array of Tvk_Queue; const aMipLevels: uint32_t; const aArrayLayers: uint32_t;
  const aSamples: TVkSampleCountFlagBits; const aTiling: TVkImageTiling);
begin
  vk_Device := aDevice;
  ImageViews := Tvk_ImageView_List.Create;

  FillByte(@vkImageCreateInfo, SizeOf(vkImageCreateInfo), 0);
  with vkImageCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    flags := aFlags;
    imageType := aImageType;
    format := aFormat;
    extent.width := aWidth;
    extent.height := aHeight;
    extent.depth := 1;
    mipLevels := aMipLevels;
    arrayLayers := aArrayLayers;
    samples := aSamples;
    tiling := aTiling;
    usage := aUsage;

    GetSharingModeInfo(aQueues, QueueFamilies, sharingmode, queueFamilyIndexCount, pQueueFamilyIndices);
  end;

  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateImage(vkDevice, @vkImageCreateInfo, nil, @vkImage));
end;

constructor Tvk_Image.CreateEx(const aDevice: TVk_Device; const aImageCreateinfo: TVkImageCreateInfo);
begin
  vk_Device := aDevice;
  ImageViews := Tvk_ImageView_List.Create;

  vkImageCreateInfo := aImageCreateinfo;
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateImage(vkDevice, @vkImageCreateInfo, nil, @vkImage));
end;

destructor Tvk_Image.Destroy;
begin
  if not (Self is Tvk_SwapChainImage) then
    with vk_Device do
      vk_Instance.vkDestroyImage(vkDevice, vkImage, nil);
  FreeAndNil(ImageViews);
  FreeAndNil(QueueFamilies);
  FreeAndNil(ImageMemory);
  inherited Destroy;
end;

{ Tvk_BufferView }

constructor Tvk_BufferView.Create(const aBuffer: Tvk_Buffer; const aFormat: TvkFormat; const aOffset: TVkDeviceSize; const aRange: TVkDeviceSize);
begin
  vk_Buffer := aBuffer;
  FillByte(@vkBufferViewCreateInfo, SizeOf(vkBufferViewCreateInfo), 0);
  with vkBufferViewCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
    buffer := vk_Buffer.vkBuffer;
    format := aFormat;
    offset := aOffset;
    range := aRange;
  end;

  with vk_Buffer.vk_Device do
    vk_Instance.vkCreateBufferView(vkDevice, @vkBufferViewCreateInfo, nil, @vkBufferView);
end;

destructor Tvk_BufferView.Destroy;
begin
  with vk_Buffer.vk_Device do
    vk_Instance.vkDestroyBufferView(vkDevice, vkBufferView, nil);
  with vk_Buffer do
    if not Destroying then
      BufferViews.Remove(Self);
  inherited Destroy;
end;

{ Tvk_Buffer }

function Tvk_Buffer.GetBufferView(const aFormat: TvkFormat; const aOffset: TVkDeviceSize; const aRange: TVkDeviceSize): Tvk_BufferView;
begin
  for Result in BufferViews do
  with Result.vkBufferViewCreateInfo do
    if (format = aFormat) and (offset = aOffset) and (range = aRange) then Exit;

  Result := Tvk_BufferView.Create(Self, aFormat, aOffset, aRange);
  BufferViews.Add(Result);
end;

constructor Tvk_Buffer.Create(const aDevice: TVk_Device;
  const aSize: TVkDeviceSize; const aCreateFlags: TVkBufferCreateFlags;
  const aUsageFlags: TVkBufferUsageFlags; const aQueues: array of Tvk_Queue;
  const AllocMemFlag: Boolean;
  const MemoryProperties: TVkMemoryPropertyFlags);
var MemoryRequirements: TVkMemoryRequirements;
begin
  vk_Device := aDevice;

  BufferViews := Tvk_BufferView_List.Create(True);

  FillByte(@vkBufferCreateInfo, SizeOf(vkBufferCreateInfo), 0);
  with vkBufferCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    flags := aCreateFlags;
    size := aSize;
    usage := aUsageFlags;

    GetSharingModeInfo(aQueues, QueueFamilies, sharingmode, queueFamilyIndexCount, pQueueFamilyIndices);
  end;

  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateBuffer(vkDevice, @vkBufferCreateInfo, nil, @vkBuffer));

  with vk_Device do
    vk_Instance.vkGetBufferMemoryRequirements(vkDevice, vkBuffer, @MemoryRequirements);

  if AllocMemFlag then
  begin
    BufferMemory := vk_Device.AllocMemory(MemoryRequirements.size, MemoryRequirements.memoryTypeBits, MemoryProperties);
    with vk_Device do
      CheckVulkanCall(vk_Instance.vkBindBufferMemory(vkDevice, vkBuffer, BufferMemory.vkDeviceMemory, 0));
  end;
end;

destructor Tvk_Buffer.Destroy;
begin
  Destroying := True;
  FreeAndNil(BufferMemory);
  FreeAndNil(BufferViews);
  with vk_Device do
    vk_Instance.vkDestroyBuffer(vkDevice, vkBuffer, nil);
  FreeAndNil(QueueFamilies);

  inherited Destroy;
end;

{ Tvk_Framebuffer }

constructor Tvk_Framebuffer.Create(const aDevice: TVk_Device; const aCompatibleRenderPass: Tvk_RenderPass; const ImageViews: array of Tvk_ImageView; const aWidth, aHeight, aLayers: uint32_t);
var ii: Integer;
begin
  vk_Device := aDevice;
  vkImageViewList := TvkImageView_List.Create;
  for ii := 0 to High(ImageViews) do
    vkImageViewList.PushBack(ImageViews[ii].vkImageView);

  with vkFramebufferCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    renderPass := aCompatibleRenderPass.vkRenderPass;
    attachmentCount := vkImageViewList.Size;
    pAttachments := vkImageViewList.Mutable[0];
    width := aWidth;
    height := aHeight;
    layers := aLayers;
  end;
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateFramebuffer(vkDevice, @vkFramebufferCreateInfo, nil, @vkFramebuffer));
end;

destructor Tvk_Framebuffer.Destroy;
begin
  FreeAndNil(vkImageViewList);
  with vk_Device do
    vk_Instance.vkDestroyFramebuffer(vkDevice, vkFramebuffer, nil);
  inherited Destroy;
end;

{ Tvk_RenderPass }

constructor Tvk_RenderPass.Create(const aDevice: TVk_Device; const aFormat: TVkFormat);
begin
  vk_Device := aDevice;

  with vkColorAttachmentDescription do
  begin
    format := aFormat;
    samples := [VK_SAMPLE_COUNT_1_BIT];
    loadOp := VK_ATTACHMENT_LOAD_OP_CLEAR;
    storeOp := VK_ATTACHMENT_STORE_OP_STORE;
    stencilLoadOp := VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    stencilStoreOp := VK_ATTACHMENT_STORE_OP_DONT_CARE;
    initialLayout := VK_IMAGE_LAYOUT_UNDEFINED;
    finalLayout := VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
  end;

  with vkColorAttachmentRef do
  begin
    attachment := 0;
    layout := VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
  end;

  with vkSubPassDescription do
  begin
    pipelineBindPoint := VK_PIPELINE_BIND_POINT_GRAPHICS;
    colorAttachmentCount := 1;
    pColorAttachments := @vkColorAttachmentRef;
  end;

  with vkSubpassDependency do
  begin
    srcSubpass := $FFFFFFFF; //Ord(VK_SUBPASS_EXTERNAL);
    dstSubpass := 0;
    srcStageMask := [VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT];
    srcAccessMask := [VK_ACCESS_MEMORY_READ_BIT];
    dstStageMask := [VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT];
    dstAccessMask := [VK_ACCESS_COLOR_ATTACHMENT_READ_BIT, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT];
  end;

  with vkRenderPassCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    attachmentCount := 1;
    pAttachments := @vkColorAttachmentDescription;
    subpassCount := 1;
    pSubpasses := @vkSubPassDescription;
    dependencyCount := 1;
    pDependencies := @vkSubpassDependency;
  end;


  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateRenderPass(vkDevice, @vkRenderPassCreateInfo, nil, @vkRenderPass));
end;

destructor Tvk_RenderPass.Destroy;
begin
  with vk_Device do
    vk_Instance.vkDestroyRenderPass(vkDevice, vkRenderPass, nil);
  inherited Destroy;
end;

{ Tvk_Swapchain }

procedure Tvk_Swapchain.CreateFramebuffers(const aRenderPass: Tvk_RenderPass);
var aImage: Tvk_Image;
begin

  for aImage in Images_SwapChain do
  with vk_Surface do
    Framebuffers_SwapChain.Add(Tvk_Framebuffer.Create(vk_Device, aRenderPass, [aImage.ImageViews[0]], width, height, 1));
end;

procedure Tvk_Swapchain.PresentQueue(const aQueue: Tvk_Queue; const ImageIndex: uint32_t; const semaphore: TVk_Semaphore);
var aPresentInfo: TVkPresentInfoKHR;
begin
  // mostly duplicate of Tvk_Queue.Present
  FillByte(@aPresentInfo, SizeOf(aPresentInfo), 0);
  with aPresentInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    if Assigned(semaphore) then
    begin
      waitSemaphoreCount := 1;
      pWaitSemaphores := @semaphore.vkSemaphore;
    end;
    swapchainCount := 1;
    pSwapchains := @vkSwapChain;
    pImageIndices := @ImageIndex;
  end;
  with vk_Surface.vk_Device do
    CheckVulkanCall(vk_Instance.vkQueuePresentKHR(aQueue.vkQueue, @aPresentInfo));
end;

function Tvk_Swapchain.AcquireNextImage(out ImageIndex: uint32_t; const timeout: uint64_t; const semaphore: TVk_Semaphore; const fence: TVk_Fence): TvkResult;
var aSemaphore: TvkSemaphore;
    aFence: TvkFence;
begin
  if Assigned(Semaphore) then aSemaphore := Semaphore.vkSemaphore
  else aSemaphore := 0;

  if Assigned(fence) then aFence := Fence.vkFence
  else aFence := 0;

  with vk_Surface, vk_Device do
    Result := vk_Instance.vkAcquireNextImageKHR(vkDevice, vkSwapChain, timeout, aSemaphore, aFence, @ImageIndex);

  CheckVulkanCall(Result, @Results_AcquireNextImage_Success);
end;

procedure Tvk_Swapchain.CleanupSwapchain(var aSwapchain: TVkSwapchainKHR);
var aImage: TVk_Image;
    aFramebuffer: Tvk_Framebuffer;
begin
  with vk_Surface, vk_Device, vk_Instance do
  begin
    vkDeviceWaitIdle(vkDevice);

    for aImage in Images_SwapChain do
      aImage.Free;
    Images_SwapChain.Clear;

    for aFramebuffer in Framebuffers_SwapChain do
      aFramebuffer.Free;
    Framebuffers_SwapChain.Clear;

    vkDestroySwapchainKHR(vkDevice, aSwapChain, nil);
    aSwapChain := 0;
  end;
end;

procedure Tvk_Swapchain.RefreshSwapchain;
var aOldSwapchain: TVkSwapchainKHR;
  vkSurfaceCapabilities: TVkSurfaceCapabilitiesKHR;
  aCount: uint32_t;
  aPresentMode: TVkPresentModeKHR;
  aSurfaceFormat: TVkSurfaceFormatKHR;
  aImage: TVkImage;
  a_Image: Tvk_Image;
  aCreateInfo: TVkImageViewCreateInfo;
begin
  aOldSwapchain := vkSwapChain;


  with vk_Surface, vk_Device, vk_Instance do
  begin
    CheckVulkanCall(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(vkPhysicalDevice, vkSurface, @vkSurfaceCapabilities));

    aCount := 0;
    CheckVulkanCall(vkGetPhysicalDeviceSurfacePresentModesKHR(vkPhysicalDevice, vkSurface, @aCount, nil));
    PresentModes.Resize(aCount);
    CheckVulkanCall(vkGetPhysicalDeviceSurfacePresentModesKHR(vkPhysicalDevice, vkSurface, @aCount, PresentModes.Mutable[0]));
  end;



  with vkSwapchainCreateInfo do
  begin
    with vk_Surface.SurfaceFormats do
    begin
      if (Size = 1) and (Items[0].Format = VK_FORMAT_UNDEFINED) then
      begin
        ImageFormat := VK_FORMAT_B8G8R8A8_UNORM;
        imageColorSpace := VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
      end
      else
      begin
        ImageFormat := Items[0].Format;
        ImageColorSpace := Items[0].colorSpace;
        for aSurfaceFormat in vk_Surface.SurfaceFormats do
        with aSurfaceFormat do
        begin
          if (format = VK_FORMAT_B8G8R8A8_UNORM) and (colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) then
          begin
            ImageFormat := format;
            ImageColorSpace := colorSpace;
            break;
          end;
        end;
      end;
    end;

    PresentMode := VK_PRESENT_MODE_FIFO_KHR;
    for aPresentMode in PresentModes do
      case aPresentMode of
        VK_PRESENT_MODE_MAILBOX_KHR:
          begin
            PresentMode := VK_PRESENT_MODE_MAILBOX_KHR;
            break;
          end;
        VK_PRESENT_MODE_IMMEDIATE_KHR:
          PresentMode := VK_PRESENT_MODE_IMMEDIATE_KHR;
      end;

    with vkSurfaceCapabilities do
  	if (currentExtent.width = High(currentExtent.width)) then
  	begin
  		imageExtent.width := vk_Surface.Width;
  		imageExtent.height := vk_Surface.Height;
      imageExtent.width := Max(minImageExtent.width, Min(maxImageExtent.width, imageExtent.width));
      imageExtent.height := Max(minImageExtent.height, Min(maxImageExtent.height, imageExtent.height));
  	end
  	else
  	begin
  		// If the surface size is defined, the swap chain size must match
  		imageExtent := currentExtent;
  		vk_Surface.width := currentExtent.width;
  		vk_Surface.height := currentExtent.height;
  	end;


    minImageCount := vkSurfaceCapabilities.minImageCount + 1;
    if (vkSurfaceCapabilities.maxImageCount > 0) and (minImageCount > vkSurfaceCapabilities.maxImageCount) then
      minImageCount := vkSurfaceCapabilities.maxImageCount;

    if VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR in vkSurfaceCapabilities.supportedTransforms then
      preTransform := [VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR]
    else
      preTransform := vkSurfaceCapabilities.currentTransform;

    compositeAlpha := [VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR];

    oldSwapchain := aOldSwapchain;
  end;

  with vk_Surface.vk_Device, vk_Instance do
  begin
    CheckVulkanCall(vkCreateSwapchainKHR(vkDevice, @vkSwapchainCreateInfo, nil, @vkSwapChain));

    if aOldSwapchain <> 0 then
      CleanupSwapchain(aOldSwapchain);

		CheckVulkanCall(vkGetSwapchainImagesKHR(vkDevice, vkSwapChain, @aCount, nil));
    vkImages_SwapChain.Resize(aCount);
		CheckVulkanCall(vkGetSwapchainImagesKHR(vkDevice, vkSwapChain, @aCount, vkImages_SwapChain.Mutable[0]));


    FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
    for aImage in vkImages_SwapChain do
    begin
      a_Image := Tvk_SwapChainImage.CreateFromSwapchain(Self, aImage);
      a_Image.GetImageView;
      Images_SwapChain.Add(a_Image);
    end;
  end;
end;

constructor Tvk_Swapchain.Create(const aSurface: TVk_Surface);
begin
  vk_Surface := aSurface;
  Images_SwapChain := TVk_Image_List.Create(False);
  vkImages_SwapChain := TVkImage_List.Create;
  with vkSwapchainCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    surface := vk_Surface.vkSurface;
		imageUsage := [VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT, VK_IMAGE_USAGE_TRANSFER_SRC_BIT];
		imageArrayLayers := 1;
		imageSharingMode := VK_SHARING_MODE_EXCLUSIVE;
		queueFamilyIndexCount := 0;
		pQueueFamilyIndices := nil;
		clipped := VK_TRUE;
		compositeAlpha := [VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR];

  end;
  PresentModes := TVkPresentModeKHR_List.Create;
  PrePresentCommandBuffers := TVk_CommandBuffer_List.Create;
  PostPresentCommandBuffers := TVk_CommandBuffer_List.Create;
  Framebuffers_SwapChain := Tvk_Framebuffer_List.Create(False);
  RefreshSwapchain;

end;

destructor Tvk_Swapchain.Destroy;
begin
  CleanupSwapchain(vkSwapChain);
  FreeAndNil(Framebuffers_SwapChain);
  FreeAndNil(PrePresentCommandBuffers);
  FreeAndNil(PostPresentCommandBuffers);
  FreeAndNil(PresentModes);

  FreeAndNil(vkImages_SwapChain);
  FreeAndNil(Images_SwapChain);
  inherited Destroy;
end;

{ Tvk_Event }

function Tvk_Event.Status: TVkResult_Set_Reset;
var aVKResult: TVKResult;
begin
  with vk_Device do
    aVKResult := vk_Instance.vkGetEventStatus(vkDevice, vkEvent);
  case aVKResult of
    VK_EVENT_SET, VK_EVENT_RESET,
        VK_ERROR_OUT_OF_HOST_MEMORY, VK_ERROR_OUT_OF_DEVICE_MEMORY, VK_ERROR_DEVICE_LOST: Result := TVkResult_Set_Reset(aVKResult);
    else
      raise Exception.Create('Unexpected result in Tvk_Event.Status');
  end;
end;

procedure Tvk_Event.ResetEvent;
begin
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkResetEvent(vkDevice, vkEvent));
end;

procedure Tvk_Event.SetEvent;
begin
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkSetEvent(vkDevice, vkEvent));
end;

constructor Tvk_Event.Create(const aDevice: Tvk_Device);
var aCreateInfo: TVkEventCreateInfo;
begin
  vk_Device := aDevice;
  FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
  aCreateInfo.sType := VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;

  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateEvent(vkDevice, @aCreateInfo, nil, @vkEvent));
end;

destructor Tvk_Event.Destroy;
begin
  with vk_Device do
    vk_Instance.vkDestroyEvent(vkDevice, vkEvent, nil);
  inherited Destroy;
end;

{ Tvk_Fence }

procedure Tvk_Fence.WaitForSignalled(aTimeoutInNanoseconds: uint64_t);
begin
  with vk_Device do
    vk_Instance.vkWaitForFences(vkDevice, 1, @vkFence, VK_FALSE, aTimeoutInNanoseconds);
end;

procedure Tvk_Fence.Reset;
begin
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkResetFences(vkDevice, 1, @vkFence));
end;

function Tvk_Fence.Status: TVkResult;
begin
  with vk_Device do
    Result := vk_Instance.vkGetFenceStatus(vkDevice, vkFence);
end;

constructor Tvk_Fence.Create(const aDevice: Tvk_Device; const aVkFenceCreateFlags: TVkFenceCreateFlags);
var aCreateInfo: TVkFenceCreateInfo;
begin
  vk_Device := aDevice;

  FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
  with aCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    flags := aVkFenceCreateFlags;
  end;
  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateFence(vkDevice, @aCreateInfo, nil, @vkFence));
end;

destructor Tvk_Fence.Destroy;
begin
  with vk_Device do
    vk_Instance.vkDestroyFence(vkDevice, vkFence, nil);
  inherited Destroy;
end;

{ Tvk_Semaphore }

constructor Tvk_Semaphore.Create(const aDevice: Tvk_Device);
var vkSemaphoreCreateInfo: TVkSemaphoreCreateInfo;
begin
  vk_Device := aDevice;
  FillByte(@vkSemaphoreCreateInfo, SizeOf(vkSemaphoreCreateInfo), 0);
  vkSemaphoreCreateInfo.sType := VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

  with vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateSemaphore(vkDevice, @vkSemaphoreCreateInfo, nil, @vkSemaphore));
end;

destructor Tvk_Semaphore.Destroy;
begin
  with vk_Device do
    vk_Instance.vkDestroySemaphore(vkDevice, vkSemaphore, nil);
  inherited Destroy;
end;

{ Tvk_CommandBuffer }

procedure Tvk_CommandBuffer.ExecuteSubCommandBuffer(const aSecondaryBuffer: Tvk_CommandBuffer);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdExecuteCommands(vkCommandBuffer, 1, @aSecondaryBuffer.vkCommandBuffer);
end;

procedure Tvk_CommandBuffer.BeginRecording(const CommandBufferUsageFlags: TVkCommandBufferUsageFlags; const aRenderPass: Tvk_RenderPass; const aSubPassIndex: uint32_t; const aFrameBuffer: Tvk_FrameBuffer);
var VkCommandBufferBeginInfo: TVkCommandBufferBeginInfo;
    VkCommandBufferInheritanceInfo: TVkCommandBufferInheritanceInfo;
begin
  FillByte(@VkCommandBufferInheritanceInfo, SizeOf(VkCommandBufferInheritanceInfo), 0);
  with VkCommandBufferInheritanceInfo do
  begin
    sType := VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
    if Assigned(aRenderPass) then
      renderPass := aRenderPass.vkRenderPass;
    subpass := aSubPassIndex;
    if Assigned(aFrameBuffer) then
      framebuffer := aFrameBuffer.vkFramebuffer;
  end;
  FillByte(@VkCommandBufferBeginInfo, SizeOf(VkCommandBufferBeginInfo), 0);
  with VkCommandBufferBeginInfo do
  begin
    sType := VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    flags := CommandBufferUsageFlags;
    pInheritanceInfo := @VkCommandBufferInheritanceInfo;
  end;
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkBeginCommandBuffer(vkCommandBuffer, @VkCommandBufferBeginInfo);
end;

procedure Tvk_CommandBuffer.BeginRenderPass(const aRenderPass: Tvk_RenderPass; const aFrameBuffer: Tvk_FrameBuffer; const aContents: TVkSubpassContents);
var vkRenderPassBeginInfo: TVkRenderPassBeginInfo;
    vkClearValue: TVkClearValue;
begin
  vkClearValue.color.float32[0] := 0;
  vkClearValue.color.float32[1] := 0;
  vkClearValue.color.float32[2] := 0;
  vkClearValue.color.float32[3] := 0;

  FillByte(@vkRenderPassBeginInfo, SizeOf(vkRenderPassBeginInfo), 0);
  with vkRenderPassBeginInfo do
  begin
    sType := VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPass := aRenderPass.vkRenderPass;
    framebuffer := aFrameBuffer.vkFramebuffer;
    RenderArea.offset.x := 0;
    RenderArea.offset.y := 0;
    RenderArea.extent.width := aFramebuffer.vkFramebufferCreateInfo.width;
    RenderArea.extent.height := aFramebuffer.vkFramebufferCreateInfo.height;
    clearValueCount := 1;
    pClearValues := @vkClearValue;
  end;
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdBeginRenderPass(vkCommandBuffer, @vkRenderPassBeginInfo, aContents);
end;

procedure Tvk_CommandBuffer.BindPipeline(const aPipeline: Tvk_GraphicsPipeline);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdBindPipeline(vkCommandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, aPipeline.vkPipeline);
end;

procedure Tvk_CommandBuffer.BindVertexBuffer(const Binding: uint32_t; const pBuffer: PVkBuffer; const pOffset: PVkDeviceSize);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdBindVertexBuffers(vkCommandBuffer, Binding, 1, pBuffer, pOffset);
end;

procedure Tvk_CommandBuffer.Draw(const aVertexCount, aInstanceCount, aFirstVertex, aFirstInstance: uint32_t);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdDraw(vkCommandBuffer, aVertexCount, aInstanceCount, aFirstVertex, aFirstInstance);
end;

procedure Tvk_CommandBuffer.CopyImage(const SourceImage: Tvk_Image; const DestImage: Tvk_Image; const Regions: array of TVkImageCopy);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdCopyImage(vkCommandBuffer, SourceImage.vkImage, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
        DestImage.vkImage, VK_IMAGE_LAYOUT_GENERAL, Length(Regions), @Regions[0]);
end;

procedure Tvk_CommandBuffer.CopyImageComplete(const SourceImage: Tvk_Image; const DestImage: Tvk_Image);
var aRegion: TvkImageCopy;
    VkImageSubresourceLayers: TVkImageSubresourceLayers;
begin
  FillByte(@VkImageSubresourceLayers, SizeOf(VkImageSubresourceLayers), 0);
  with VkImageSubresourceLayers do
  begin
    aspectMask := [VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_ASPECT_DEPTH_BIT,
      VK_IMAGE_ASPECT_STENCIL_BIT, VK_IMAGE_ASPECT_METADATA_BIT];
    mipLevel := 0;
    baseArrayLayer := 0;
    layerCount := 1;
  end;
  FillByte(@aRegion, SizeOf(aRegion), 0);
  with aRegion do
  begin
    srcSubresource := VkImageSubresourceLayers;
    dstSubresource := VkImageSubresourceLayers;
    extent := DestImage.vkImageCreateInfo.extent;
  end;
  CopyImage(SourceImage, DestImage, [aRegion]);
end;

procedure Tvk_CommandBuffer.EndRenderPass;
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdEndRenderPass(vkCommandBuffer);
end;

procedure Tvk_CommandBuffer.EndRecording;
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkEndCommandBuffer(vkCommandBuffer));
end;

procedure Tvk_CommandBuffer.Reset(const flags: TVkCommandBufferResetFlags);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkResetCommandBuffer(vkCommandBuffer, flags));
end;

procedure Tvk_CommandBuffer.SetViewport(const aViewport: TVkViewport);
begin
  with vk_CommandPool.vk_QueueFamily.vk_Device do
    vk_Instance.vkCmdSetViewport(vkCommandBuffer, 0, 1, @aViewport);
end;

constructor Tvk_CommandBuffer.Create(const aCommandPool: Tvk_CommandPool; const aCommandBufferLevel: TvkCommandBufferLevel; const aCommandBuffer: TVkCommandBuffer);
begin
  vk_CommandPool := aCommandPool;
  vkCommandBuffer := aCommandBuffer;
  vkCommandBufferLevel := aCommandBufferLevel;
end;

destructor Tvk_CommandBuffer.Destroy;
begin
  vk_CommandPool.CommandBufferPool[vkCommandBufferLevel].PushBack(vkCommandBuffer);
  if Assigned(vk_CommandPool.CommandBuffers) then
    vk_CommandPool.CommandBuffers.Remove(Self);
  inherited Destroy;
end;

{ Tvk_CommandPool }

function Tvk_CommandPool.GetCommandBuffer(const aCommandBufferLevel: TVkCommandBufferLevel): Tvk_CommandBuffer;
var vkCommandBufferAllocateInfo: TVkCommandBufferAllocateInfo;
begin
  if CommandBufferPool[aCommandBufferLevel].Size = 0 then
  begin
    with vkCommandBufferAllocateInfo do
    begin
      sType := VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
      commandPool := vkCommandPool;
      level := aCommandBufferLevel;
      commandBufferCount := DefaultAllocationSize;
      pNext := nil;
    end;
    CommandBufferPool[aCommandBufferLevel].Resize(DefaultAllocationSize);
    with vk_QueueFamily.vk_Device do
      CheckVulkanCall(vk_Instance.vkAllocateCommandBuffers(vkDevice, @vkCommandBufferAllocateInfo, CommandBufferPool[aCommandBufferLevel].Mutable[0]));
  end;
  Result := Tvk_CommandBuffer.Create(Self, aCommandBufferLevel, CommandBufferPool[aCommandBufferLevel].Back);
  CommandBufferPool[aCommandBufferLevel].PopBack;

  CommandBuffers.Add(Result);
end;

procedure Tvk_CommandPool.Reset(const aFlags: TVkCommandPoolResetFlags);
begin
  with vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkResetCommandPool(vkDevice, vkCommandPool, aFlags));
end;

constructor Tvk_CommandPool.Create(const aQueueFamily: Tvk_QueueFamily; const aFlags: TVkCommandPoolCreateFlags);
var aCBL: TVkCommandBufferLevel;
begin
  DefaultAllocationSize := 10;
  for aCBL := Low(TVkCommandBufferLevel) to High(TVkCommandBufferLevel) do
    CommandBufferPool[aCBL] := TvkCommandbuffer_List.Create;

  CommandBuffers := TVk_CommandBuffer_List.Create;
  vk_QueueFamily := aQueueFamily;
  with vkCommandPoolCreateInfo do
  begin
  	sType := VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
  	queueFamilyIndex := vk_QueueFamily.QueueFamilyIndex;
  	flags := aFlags;
    pNext := nil;
  end;
  with vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkCreateCommandPool(vkDevice, @vkCommandPoolCreateInfo, nil, @vkCommandPool));
end;

destructor Tvk_CommandPool.Destroy;
var aCBL: TVkCommandBufferLevel;
begin
  FreeAndNil(CommandBuffers);

  with vk_QueueFamily.vk_Device do
  for aCBL := Low(TVkCommandBufferLevel) to High(TVkCommandBufferLevel) do
  begin
    if CommandBufferPool[aCBL].Size > 0 then
      vk_Instance.vkFreeCommandBuffers(vkDevice, vkCommandPool, CommandBufferPool[aCBL].Size, CommandBufferPool[aCBL].Mutable[0]);
    FreeAndNil(CommandBufferPool[aCBL]);
  end;

  with vk_QueueFamily.vk_Device do
    vk_Instance.vkDestroyCommandPool(vkDevice, vkCommandPool, nil);
  inherited Destroy;
end;

{ Tvk_QueueFamily }

procedure Tvk_QueueFamily.Initialize;
var aQueue: Tvk_Queue;
begin
  for aQueue in Queues do
    with vk_Device, aQueue do
      vk_Instance.vkGetDeviceQueue(vkDevice, QueueFamilyIndex, QueueIndex, @vkQueue);
  vk_CommandPool := Tvk_CommandPool.Create(Self, vkCommandPoolCreateFlags);
end;

constructor Tvk_QueueFamily.Create(const aDevice: Tvk_Device; const aQueueFamilyIndex: Cardinal; const aWindow: Tvk_Surface;
  const aCommandPoolCreateFlags: TVkCommandPoolCreateFlags);
begin
  vk_Device := aDevice;
  QueueFamilyIndex := aQueueFamilyIndex;
  vkCommandPoolCreateFlags := aCommandPoolCreateFlags;
  pQueueFamilyProperties := aDevice.ReportedQueueFamilies.Mutable[QueueFamilyIndex];
  if Assigned(aWindow) then
    SupportsPresent := aWindow.SupportsPresentForQueueFamilyIndex(QueueFamilyIndex);


  Queues := Tvk_Queue_List.Create;
end;

destructor Tvk_QueueFamily.Destroy;
begin
  FreeAndNil(Queues);
  FreeAndNil(vk_CommandPool);
  inherited Destroy;
end;

{ Tvk_Queue }

procedure Tvk_Queue.QueueSubmitInfo;
var vkSubmitInfo: TVkSubmitInfo;
begin
  if SubmitInfo.CommandBuffers.Size = 0 then Exit;
  FillByte(@vkSubmitInfo, SizeOf(vkSubmitInfo), 0);
  with vkSubmitInfo do
  begin
    sType := VK_STRUCTURE_TYPE_SUBMIT_INFO;
    waitSemaphoreCount := SubmitInfo.WaitSemaphores.Size;
    if waitSemaphoreCount > 0 then
    begin
      pWaitSemaphores := SubmitInfo.WaitSemaphores.Mutable[0];
      pWaitDstStageMask := SubmitInfo.PipelineStageFlagsAtWhichToWait.Mutable[0];
    end;

    commandBufferCount := SubmitInfo.CommandBuffers.Size;
    pCommandBuffers := SubmitInfo.CommandBuffers.Mutable[0];

    signalSemaphoreCount := SubmitInfo.SignalSemaphores.Size;
    if signalSemaphoreCount > 0 then
      pSignalSemaphores := SubmitInfo.SignalSemaphores.Mutable[0];
  end;
  vkSubmitInfos.PushBack(vkSubmitInfo);
  with SubmitInfo do
  begin
    WaitSemaphores.Clear;
    PipelineStageFlagsAtWhichToWait.Clear;
    SignalSemaphores.Clear;
    CommandBuffers.Clear;
  end;
end;

procedure Tvk_Queue.SubmitQueuedSubmitInfos(const aFence: Tvk_Fence);
var avkFence: TvkFence;
begin
  if Assigned(aFence) then avkFence := aFence.vkFence
  else avkFence := 0;

  QueueSubmitInfo;

  with vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkQueueSubmit(vkQueue, vkSubmitInfos.Size, vkSubmitInfos.Mutable[0], avkFence));
  vkSubmitInfos.Clear;
end;

procedure Tvk_Queue.SubmitSimpleCommandBuffer(const aBuffer: Tvk_CommandBuffer; const WaitSemaphore: Tvk_Semaphore; const aPipelineStageFlags: TVkPipelineStageFlags;
  const SignalSemaphore: Tvk_Semaphore);
var vkSubmitInfo: TVkSubmitInfo;
begin
  FillByte(@vkSubmitInfo, SizeOf(vkSubmitInfo), 0);
  with vkSubmitInfo do
  begin
    sType := VK_STRUCTURE_TYPE_SUBMIT_INFO;
    if Assigned(waitSemaphore) then
    begin
      waitSemaphoreCount := 1;
      pWaitSemaphores := @waitSemaphore.vkSemaphore;
    end;
    pWaitDstStageMask := @aPipelineStageFlags;

    commandBufferCount := 1;
    pCommandBuffers := @aBuffer.vkCommandBuffer;

    if Assigned(signalSemaphore) then
    begin
      signalSemaphoreCount := 1;
      pSignalSemaphores := @signalSemaphore.vkSemaphore;
    end;
  end;
  with vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkQueueSubmit(vkQueue, 1, @vkSubmitInfo, 0));
end;

procedure Tvk_Queue.Present(const aSwapChain: Tvk_Swapchain; const ImageIndex: uint32_t; const semaphore: TVk_Semaphore);
var aPresentInfo: TVkPresentInfoKHR;
begin
  // mostly duplicate of Tvk_Swapchain.PresentQueue
  FillByte(@aPresentInfo, SizeOf(aPresentInfo), 0);
  with aPresentInfo do
  begin
    sType := VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    if Assigned(semaphore) then
    begin
      waitSemaphoreCount := 1;
      pWaitSemaphores := @semaphore.vkSemaphore;
    end;
    swapchainCount := 1;
    pSwapchains := @aSwapChain.vkSwapChain;
    pImageIndices := @ImageIndex;
  end;
  with vk_QueueFamily.vk_Device do
    CheckVulkanCall(vk_Instance.vkQueuePresentKHR(vkQueue, @aPresentInfo));
end;

function Tvk_Queue.GetCommandBuffer(const aCommandBufferLevel: TVkCommandBufferLevel): Tvk_CommandBuffer;
begin
  Result := vk_QueueFamily.vk_CommandPool.GetCommandBuffer(aCommandBufferLevel);
end;

constructor Tvk_Queue.Create(const aQueueFamily: Tvk_QueueFamily; const aQueueFamilyIndex, aQueueIndex: Cardinal; const aPriority: Single);
begin
  vk_QueueFamily := aQueueFamily;
  QueueFamilyIndex := aQueueFamilyIndex;
  QueueIndex := aQueueIndex;
  Priority := aPriority;

  SubmitInfo := Tvk_SubmitInfo.Create(Self);
  vkSubmitInfos := TvkSubmitInfo_List.Create;
end;

destructor Tvk_Queue.Destroy;
begin
  FreeAndNil(vkSubmitInfos);
  FreeAndNil(SubmitInfo);
  inherited Destroy;
end;

{ Tvk_Surface }

{$IFDEF WINDOWS}
function WndProc_Lookup(hWnd: HWND; uMsg: UINT; wParam: WPARAM; lParam: LPARAM): LRESULT;stdcall;
var ii: Integer;
begin
  ii := WndProcMap.IndexOf(hWnd);
  if ii > 0 then
    Result := WndProcMap.Data[ii].WndProc(hWnd, uMsg, wParam, lParam)
  else
    Result := DefWindowProc(hWnd, uMsg, wParam, lParam);
end;

function Tvk_Surface.WndProc(const hWnd: HWND; const uMsg: UINT; const wParam: WPARAM; const lParam: LPARAM): LRESULT;
begin
  Result := DefWindowProc(hWnd, uMsg, wParam, lParam);
end;
{$ENDIF WINDOWS}

procedure Tvk_Surface.Resize(const aWidth, aHeight: uint32_t);
begin
  Width := aWidth;
  Height := aHeight;
  SwapChain.RefreshSwapchain;
end;

function Tvk_Surface.SupportsPresentForQueueFamilyIndex(const aQueueFamilyIndex: uint32_t): Boolean;
{$IFDEF UNIX}
var vinfo: TXVisualInfo;
{$ENDIF UNIX}
begin
  Result := False;
  {$IFDEF WINDOWS}
  with vk_Device, vk_Instance do
  case vkGetPhysicalDeviceWin32PresentationSupportKHR(vkPhysicalDevice, aQueueFamilyIndex) of
    VK_FALSE: Result := False;
    VK_TRUE: Result := True;
    else raise Exception.Create('Unexpected result in queuefamily create');
  end;
  {$ENDIF WINDOWS}
  {$IFDEF UNIX}

  XMatchVisualInfo(X11_display, XDefaultScreen(X11_display), 32, TrueColor, @vinfo);


  with vk_Device, vk_Instance do
  case vkGetPhysicalDeviceXlibPresentationSupportKHR(vkPhysicalDevice, aQueueFamilyIndex, X11_display, vinfo.visualid) of
    VK_FALSE: Result := False;
    VK_TRUE: Result := True;
    else raise Exception.Create('Unexpected result in queuefamily create');
  end;
  {$ENDIF UNIX}

end;

function Tvk_Surface.CreateSwapchain: Tvk_Swapchain;
begin
  SwapChain := Tvk_Swapchain.Create(Self);
  Result := SwapChain;
end;

procedure Tvk_Surface.CreateSurface;
{$IFDEF WINDOWS}
var aCreateInfo: TVkWin32SurfaceCreateInfoKHR;
{$ENDIF WINDOWS}
{$IFDEF UNIX}
var aCreateInfo: TVkXlibSurfaceCreateInfoKHR;
{$ENDIF UNIX}
var aCount: uint32_t;
begin
{$IFDEF WINDOWS}
  FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
  with aCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    hinstance := WindowsApplicationInstance;
    hwnd := WindowHandle;
  end;
  with vk_Device, vk_Instance do
  begin
    CheckVulkanCall(vkCreateWin32SurfaceKHR(vkInstance, @aCreateInfo, nil, @vkSurface));
  end;
{$ENDIF WINDOWS}
{$IFDEF UNIX}
  FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
  with aCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
    dpy := X11_display;
    window := X11_window;
  end;
  with vk_Device, vk_Instance do
  begin
    CheckVulkanCall(vkCreateXlibSurfaceKHR(vkInstance, @aCreateInfo, nil, @vkSurface));
  end;
{$ENDIF UNIX}
{$IFDEF ANDROID}
  raise Exception.Create('unimplemented createsurface');
{$ENDIF ANDROID}

  with vk_Device, vk_Instance do
  begin
    aCount := 0;
    CheckVulkanCall(vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, vkSurface, @aCount, nil));
    SurfaceFormats.Resize(aCount);
    CheckVulkanCall(vkGetPhysicalDeviceSurfaceFormatsKHR(vkPhysicalDevice, vkSurface, @aCount, SurfaceFormats.Mutable[0]));
  end;

end;

procedure Tvk_Surface.Initialize(const aX, aY, aWidth, aHeight: uint32_t;
  const fullscreen: Boolean);
var

{$IFDEF WINDOWS}
    screenWidth: Integer;
    screenHeight: Integer;
    dmScreenSettings: DEVMODE;
    dwExStyle: DWORD;
	  dwStyle: DWORD;
    windowRect: RECT;
//    wce: WNDCLASS;
    WindowTitle: String;
{$ENDIF WINDOWS}
    SDLWMInfo: TSDL_SysWMinfo;
//    CN: String;
//    len: Integer;
begin
  FillByte(@SDLWMInfo, SizeOf(SDLWMInfo), 0);
  SDLWindow := SDL_CreateWindow('Vulkan SDL Window', aX, aY, //SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    aWidth, aHeight,
    SDL_WINDOW_SHOWN or SDL_WINDOW_RESIZABLE or SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_VERSION(SDLWMInfo.version);
  SDL_GetWindowWMInfo(SDLWindow, @SDLWMInfo);
{  CN := IntToStr(Ord(SDLWMInfo.subsystem));
  SetLength(CN, 256);
  len := GetClassName(SDLWMInfo.win.window, @CN[1], 256);
  SetLength(CN, len);
  GetClassInfo(GetModuleHandle(nil), @CN[1], wce);  }

  {$IFDEF WINDOWS}
  WindowsApplicationInstance := SDLWMInfo.win.hdc; //wce.hInstance; // HINSTANCE; //GetModuleHandle(nil);
  WindowHandle := SDLWMInfo.win.window;
  {$ENDIF WINDOWS}
  {$IFDEF UNIX}
  X11_display := SDLWMInfo.x11.display;
  X11_window := SDLWMInfo.x11.window;
  {$ENDIF UNIX}
  CreateSurface;
  Exit;

{$IFDEF WINDOWS}
  WindowsApplicationInstance := HINSTANCE;

  if not Assigned(vk_Device.wndClass.lpszClassName) then
  begin
    FillByte(@vk_Device.wndClass, SizeOf(vk_Device.wndClass), 0);
    with vk_Device.wndClass do
    begin
	    cbSize := sizeof(WNDCLASSEX);
	    style := CS_HREDRAW or CS_VREDRAW;
	    lpfnWndProc := @WndProc_Lookup;
	    cbClsExtra := 0;
	    cbWndExtra := 0;
	    hInstance := WindowsApplicationInstance;
	    hIcon := LoadIcon(0, IDI_APPLICATION);
	    hCursor := LoadCursor(0, IDC_ARROW);
	    hbrBackground := HBRUSH(GetStockObject(BLACK_BRUSH));
	    lpszMenuName := nil;
	    lpszClassName := PChar(WindowName);
	    hIconSm := LoadIcon(0, IDI_WINLOGO);
    end;

	  if RegisterClassEx(vk_Device.wndClass) = 0 then
      raise Exception.Create('Error registering window class');
  end;

  ScreenWidth := GetSystemMetrics(SM_CXSCREEN);
	ScreenHeight := GetSystemMetrics(SM_CYSCREEN);

	if fullscreen then
  begin
    FillByte(@dmScreenSettings, SizeOf(dmScreenSettings), 0);
    with dmScreenSettings do
    begin
		  dmSize := sizeof(dmScreenSettings);
		  dmPelsWidth := screenWidth;
		  dmPelsHeight := screenHeight;
		  dmBitsPerPel := 32;
		  dmFields := DM_BITSPERPEL or DM_PELSWIDTH or DM_PELSHEIGHT;
    end;

		if ((width <> screenWidth) and (height <> screenHeight)) then
		begin
			if (ChangeDisplaySettings(@dmScreenSettings, CDS_FULLSCREEN) <> DISP_CHANGE_SUCCESSFUL) then
			begin
        raise Exception.Create('unable to change to fullscreen mode');
{				if (MessageBox(NULL, "Fullscreen Mode not supported!\n Switch to WindowHandle mode?", "Error", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
				begin
					fullscreen = FALSE;
				end
				else
				begin
					return FALSE;
				end; }
			end;
		end;
  end;

  if (fullscreen) then
	begin
		dwExStyle := WS_EX_APPWINDOW;
		dwStyle := WS_POPUP or WS_CLIPSIBLINGS or WS_CLIPCHILDREN;
	end
	else
	begin
		dwExStyle := WS_EX_APPWINDOW or WS_EX_WINDOWEDGE;
		dwStyle := WS_OVERLAPPEDWINDOW or WS_CLIPSIBLINGS or WS_CLIPCHILDREN;
	end;

  with windowRect do
  begin
    left := 0;
	  top := 0;
    if fullscreen then
    begin
      right := screenWidth;
      bottom := screenHeight;
    end
    else
    begin
      right := width;
      bottom := height;
    end;
  end;

	AdjustWindowRectEx(@windowRect, dwStyle, FALSE, dwExStyle);


	windowTitle := 'Uninitialized window title'; //getWindowTitle;
	WindowHandle := CreateWindowEx(0,
		vk_Device.wndClass.lpszClassName,
		PChar(windowTitle),
		dwStyle or WS_CLIPSIBLINGS or WS_CLIPCHILDREN,
		0,
		0,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		0,
		0,
		WindowsApplicationInstance,
		nil);

	if not fullscreen then
	begin
		// Center on screen
		SetWindowPos(WindowHandle, 0, (GetSystemMetrics(SM_CXSCREEN) - windowRect.right) div 2, (GetSystemMetrics(SM_CYSCREEN) - windowRect.bottom) div 2, 0, 0, SWP_NOZORDER or SWP_NOSIZE);
	end;

	if WindowHandle = 0 then
    raise Exception.Create('Could not create window!');

	ShowWindow(WindowHandle, SW_SHOW);
	SetForegroundWindow(WindowHandle);
	SetFocus(WindowHandle);

  CreateSurface;
  {$ENDIF WINDOWS}
end;

constructor Tvk_Surface.Create(const aDevice: Tvk_Device; const aX, aY, aWidth,
  aHeight: uint32_t);
begin
  vk_Device := aDevice;
  WindowName := 'Vulkan test';
  X := aX;
  Y := aY;
	Width := aWidth;
	Height := aHeight;

  SurfaceFormats := TVkSurfaceFormatKHR_List.Create;

  SDL_Acquire;

  Initialize(aX, aY, aWidth, aHeight);
end;

destructor Tvk_Surface.Destroy;
begin
  FreeAndNil(SwapChain);
  FreeAndNil(SurfaceFormats);
  if vkSurface <> 0 then
    with vk_Device.vk_Instance do
      vkDestroySurfaceKHR(vkInstance, vkSurface, nil);
{$IFDEF WINDOWS}
  DestroyWindow(WindowHandle);
  UnregisterClass(vk_Device.wndClass.lpszClassName, hinstance);
{$ENDIF WINDOWS}
  SDL_Release;
  inherited Destroy;
end;


{ Tvk_Device }

function Tvk_Device.GetValidDepthFormat: TVkFormat;
const depthFormats: array[0..4] of TVkFormat = (
			VK_FORMAT_D32_SFLOAT_S8_UINT,
			VK_FORMAT_D32_SFLOAT,
			VK_FORMAT_D24_UNORM_S8_UINT,
			VK_FORMAT_D16_UNORM_S8_UINT,
			VK_FORMAT_D16_UNORM);
var ii: Integer;
    formatprops: TVkFormatProperties;
begin
  for ii := Low(depthFormats) to High(depthFormats) do
  begin
    vk_Instance.vkGetPhysicalDeviceFormatProperties(vkPhysicalDevice, depthFormats[ii], @formatProps);
		if VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT in formatProps.optimalTilingFeatures then
		begin
			Result := depthFormats[ii];
      Exit;
		end;
  end;
  Result := VK_FORMAT_UNDEFINED;
end;

function Tvk_Device.CreateSurface(const aX, aY, aWidth, aHeight: uint32_t
  ): Tvk_Surface;
begin
  Result := Tvk_Surface.Create(Self, aX, aY, aWidth, aHeight);
  Surfaces.Add(Result);
end;

function Tvk_Device.HasExtension(const aExtension: TvkExtension): Boolean;
var aExtensionProperties: TVkExtensionProperties;
begin
  Result := True;
  for aExtensionProperties in ReportedDeviceExtensions do
    if aExtensionProperties.extensionName = vkExtension_Names[aExtension] then Exit;
  Result := False;
end;

function Tvk_Device.HasLayer(const aLayer: String): Boolean;
var aLayerProperties: TVkLayerProperties;
begin
  Result := True;
  for aLayerProperties in ReportedDeviceLayers do
    if aLayerProperties.layerName = aLayer then Exit;
  Result := False;
end;

procedure Tvk_Device.CreateDeviceQueueCreateInfos;
var aQueueFamily: Tvk_QueueFamily;
    aQueueCreateInfo: TVkDeviceQueueCreateInfo;
    aQueue: Tvk_Queue;
    CurQueue: Integer;
begin
  DeviceQueueCreateInfos.Clear;
  QueuePrioritiesForCreateInfos.Clear;

  for aQueueFamily in QueueFamilies do
    for aQueue in aQueueFamily.Queues do
      QueuePrioritiesForCreateInfos.PushBack(aQueue.Priority);

  CurQueue := 0;
  for aQueueFamily in QueueFamilies do
  begin
    FillByte(@aQueueCreateInfo, SizeOf(aQueueCreateInfo), 0);
    with aQueueCreateInfo do
    begin
      sType := VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      queueFamilyIndex := aQueueFamily.QueueFamilyIndex;
      queueCount := aQueueFamily.Queues.Count;

      pNext := nil;
      flags := 0;
      pQueuePriorities := QueuePrioritiesForCreateInfos.Mutable[CurQueue];
      Inc(CurQueue, queueCount);
    end;
    DeviceQueueCreateInfos.PushBack(aQueueCreateInfo);
  end;
end;

function Tvk_Device.RequestQueue(const queueFlags: TVkQueueFlags; const aWindow: Tvk_Surface; const aPriority: Single): Tvk_Queue;
var
    aFamilyIndex: Tvk_QueueFamilyIndex;
    aQueueFamily: Tvk_QueueFamily;
    procedure AddQueue;
    begin
      Result := Tvk_Queue.Create(aQueueFamily, aFamilyIndex, aQueueFamily.Queues.Count, aPriority);
      aQueueFamily.Queues.Add(Result);
    end;
begin
  aFamilyIndex := GetQueueFamilyIndex(queueFlags, aWindow);
  if aFamilyIndex = -1 then
    raise Exception.Create('unable to find appropriate queue');

  Result := nil;

  for aQueueFamily in QueueFamilies do
    if aQueueFamily.QueueFamilyIndex = aFamilyIndex then
    begin
      AddQueue;
      Exit;
    end;

  aQueueFamily := Tvk_QueueFamily.Create(Self, aFamilyIndex, aWindow);
  QueueFamilies.Add(aQueueFamily);
  AddQueue;
  Exit;

(*  with RequestedDeviceQueues do
  begin
//  for aQueueCreateInfo in DeviceQueueCreateInfos do // no access to FPosition of enumerator { may be related to Bug #0030007 and fixed in changeset 33595
//  for ii := 0 to DeviceQueueCreateInfos.Size - 1 do // this causes a compiler error

    aCount := DeviceQueueCreateInfos.Size;
    for ii := 0 to aCount - 1 do
    with DeviceQueueCreateInfos.Items[ii] do
    if queueFamilyIndex = aFamilyIndex then
    begin
      QueuePrioritiesForCreateInfos[ii].PushBack(aPriority);
      Result := Tvk_Queue.Create(Self, aFamilyIndex, QueuePrioritiesForCreateInfos[ii].Size - 1, aPriority);
      Queues.Add(Result);
      Inc(queueCount);
      Exit;
    end;


    FillByte(aQueueCreateInfo, SizeOf(aQueueCreateInfo), 0);
    with aQueueCreateInfo do
    begin
      sType := VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      queueFamilyIndex := aFamilyIndex;
      queueCount := 1;

      pNext := nil;
      flags := 0;
      pQueuePriorities := nil;
    end;

    DeviceQueueCreateInfos.PushBack(aQueueCreateInfo);

    aPriorityList := TFloat_List.Create;
    aPriorityList.PushBack(aPriority);
    QueuePrioritiesForCreateInfos.Add(aPriorityList);
    Result := Tvk_Queue.Create(Self, aFamilyIndex, 0, aPriority);
    Queues.Add(Result);
  end;*)
end;

function Tvk_Device.RequestLayer(const aLayer: String): Boolean;
begin
  Result := HasLayer(aLayer);
  if not Result then Exit;
  RequestedDeviceLayers.PushBack(aLayer);
end;

function Tvk_Device.RequestExtension(const aExtension: TvkExtension): Boolean;
begin
  Result := HasExtension(aExtension);
  if not Result then Exit;
  RequestedDeviceExtensions.PushBack(vkExtension_Names[aExtension]);
end;

function Tvk_Device.GetQueueFamilyIndex(const queueFlags: TVkQueueFlags; const aWindow: Tvk_Surface): Integer;
var aQueueFamilyProperties: TVkQueueFamilyProperties;
    BestScore: Integer;
    aCount: Integer;
    Value: TVkQueueFlags;
    FamilyIndex: uint32_t;
    aSupportsPresent: TVkBool32;
begin
  Result := -1;
  BestScore := 33;

  FamilyIndex := 0;
  for aQueueFamilyProperties in ReportedQueueFamilies do
  begin
    aSupportsPresent := VK_FALSE;
    if Assigned(aWindow) then
      vk_Instance.vkGetPhysicalDeviceSurfaceSupportKHR(vkPhysicalDevice, FamilyIndex, aWindow.vkSurface, @aSupportsPresent);
    Value := queueFlags * aQueueFamilyProperties.queueFlags;
    if (Value = queueFlags) and ((not Assigned(aWindow)) or (aSupportsPresent = VK_TRUE)) then
    begin
      aCount := FlagsSet32(@aQueueFamilyProperties.queueFlags);
      if aCount < BestScore then
      begin
        Result := FamilyIndex;
        BestScore := aCount;
      end;
    end;
    Inc(FamilyIndex);
  end;
end;

function Tvk_Device.AllocMemory(const aSize: TvkDeviceSize;
  const MemoryTypesFilter: uint32_t;
  const MemoryProperties: TVkMemoryPropertyFlags): Tvk_DeviceMemory;
begin
  Result := Tvk_DeviceMemory.Create(Self, aSize, MemoryTypesFilter, MemoryProperties);
  DeviceMemories.Add(Result);
end;

function Tvk_Device.FindMemoryType(const MemoryTypesFilter: uint32_t;
  properties: TVkMemoryPropertyFlags): uint32_t;
var ii: Integer;
  aMemoryType: TVkMemoryType;
begin
  ii := 0;
  for aMemoryType in vkPhysicalDeviceMemoryProperties.memoryTypes do
  begin
    if ((uint32_t(MemoryTypesFilter) and (1 shl ii)) <> 0) and
      ((aMemoryType.propertyFlags * properties) = properties) then
    begin
      Result := ii;
      Exit;
    end;
    Inc(ii);
  end;
  raise Exception.Create('Cannot find requested memory type');
end;

function Tvk_Device.NewPipelineVertexInputStateCreateInfo: TVk_PipelineVertexInputStateCreateInfo;
begin
  Result := TVk_PipelineVertexInputStateCreateInfo.Create(Self);
  PipelineVertexInputStateCreateInfos.Add(Result);
end;


function Tvk_Device.GetBuffer(const aSize: TVkDeviceSize;
  const aCreateFlags: TVkBufferCreateFlags;
  const aUsageFlags: TVkBufferUsageFlags; const aQueues: array of Tvk_Queue;
  const AllocMemFlag: Boolean;
  const MemoryProperties: TVkMemoryPropertyFlags): Tvk_Buffer;
begin
  Result := Tvk_Buffer.Create(Self, aSize, aCreateFlags, aUsageFlags, aQueues, AllocMemFlag, {MemoryTypesFilter,} MemoryProperties);
  Buffers.Add(Result);
end;

function Tvk_Device.GetImage(const aFlags: TVkImageCreateFlags; const aImageType: TVkImageType; const aFormat: TvkFormat; const aWidth, aHeight: uint32_t;
  const aUsage: TVkImageUsageFlags; const aQueues: array of Tvk_Queue; const aMipLevels: uint32_t; const aArrayLayers: uint32_t; const aSamples: TVkSampleCountFlagBits;
  const aTiling: TVkImageTiling): TVk_Image;
begin
  Result := Tvk_Image.Create(Self, aFlags, aImageType, aFormat, aWidth, aHeight, aUsage, aQueues, aMipLevels, aArrayLayers, aSamples, aTiling);
  Images.Add(Result);
end;

function Tvk_Device.GetImageEx(const aImageCreateinfo: TVkImageCreateInfo): TVk_Image;
begin
  Result := Tvk_Image.CreateEx(Self, aImageCreateinfo);
  Images.Add(Result);
end;


procedure Tvk_Device.WaitUntilIdle;
begin
  vk_Instance.vkDeviceWaitIdle(vkDevice);
end;

procedure Tvk_Device.WaitForFences(const aFenceList: TvkFence_List; const WaitForAll: TVkBool32; const TimeoutInNanoseconds: Uint64_t);
begin
  vk_Instance.vkWaitForFences(vkDevice, aFenceList.Size, aFenceList.Mutable[0], WaitForAll, TimeoutInNanoseconds);
end;

procedure Tvk_Device.ResetFences(const aFenceList: TvkFence_List);
begin
  vk_Instance.vkResetFences(vkDevice, aFenceList.Size, aFenceList.Mutable[0]);
end;

function Tvk_Device.GetFence(const aFlags: TVkFenceCreateFlags): Tvk_Fence;
begin
  Result := Tvk_Fence.Create(Self, aFlags);
  Fences.Add(Result);
end;

function Tvk_Device.GetSemaphore: Tvk_Semaphore;
begin
  Result := Tvk_Semaphore.Create(Self);
  Semaphores.Add(Result);
end;

function Tvk_Device.GetEvent: Tvk_Event;
begin
  Result := Tvk_Event.Create(Self);
  Events.Add(Result);
end;

function Tvk_Device.GetRenderPass(const aImageFormat: TVkFormat): Tvk_RenderPass;
begin
  Result := Tvk_RenderPass.Create(Self, aImageFormat);
  RenderPass := Result;
end;

function Tvk_Device.GetGraphicsPipeline: Tvk_GraphicsPipeline;
begin
  Result := Tvk_GraphicsPipeline.Create(Self, RenderPass);
  GraphicsPipelines.Add(Result);
end;

function Tvk_Device.GetComputePipeline(const aLayout: Tvk_PipelineLayout; const aComputeStageFileName: String;
  const aEntryPoint: String): Tvk_ComputePipeline;
begin
  Result := Tvk_ComputePipeline.Create(Self, aLayout, aComputeStageFileName, aEntryPoint);
  ComputePipelines.Add(Result);
end;

function Tvk_Device.CreatePipelineLayout: Tvk_PipelineLayout;
begin
  Result := Tvk_PipelineLayout.Create(Self);
  PipelineLayouts.Add(Result);
end;

function Tvk_Device.GetFramebuffer(const aCompatibleRenderPass: Tvk_RenderPass; const ImageViews: array of Tvk_ImageView; const aWidth, aHeight, aLayers: uint32_t
  ): Tvk_Framebuffer;
begin
  Result := Tvk_Framebuffer.Create(Self, aCompatibleRenderPass, ImageViews, aWidth, aHeight, aLayers);
  FrameBuffers.Add(Result);
end;

procedure Tvk_Device.CreateLogicalDevice(const aRequestedExtensions: TvkExtensions; const aRequestedLayers: array of String);
var
  aExtension: TvkExtension;
  ss: String;
  aQueueFamily: Tvk_QueueFamily;
begin

  for aExtension in aRequestedExtensions do
    if not HasExtension(aExtension) then raise Exception.Create('Unsupported Device Extension "' + vkExtension_Names[aExtension] + '"')
      else RequestExtension(aExtension);

  for ss in aRequestedLayers do
    if not HasLayer(ss) then raise Exception.Create('Unsupported Device Layer "' + ss + '"')
      else RequestLayer(ss);

  CreateDeviceQueueCreateInfos;

  with vkDeviceCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    queueCreateInfoCount := DeviceQueueCreateInfos.Size;
    pQueueCreateInfos := DeviceQueueCreateInfos.Mutable[0];
    pEnabledFeatures := @RequestedDeviceFeatures;
  	if RequestedDeviceExtensions.size > 0 then
    begin
  		enabledExtensionCount := RequestedDeviceExtensions.size;
  		ppEnabledExtensionNames := PPChar(RequestedDeviceExtensions.Mutable[0]);
  	end;
    if RequestedDeviceLayers.Size > 0 then
    begin
      enabledLayerCount := RequestedDeviceLayers.Size;
      ppEnabledLayerNames := PPChar(RequestedDeviceLayers.Mutable[0]);
    end;
    flags := 0;
    pNext := nil;
  end;

  CheckVulkanCall(vk_Instance.vkCreateDevice(vkPhysicalDevice, @vkDeviceCreateInfo, nil, @vkDevice));

  for aQueueFamily in QueueFamilies do
  begin
    aQueueFamily.Initialize;
  end;

end;

constructor Tvk_Device.Create(const aInstance: Tvk_Instance; const aPhysicalDevice: TVkPhysicalDevice);
var Count: uint32_t;
begin
  vk_Instance := aInstance;
  vkPhysicalDevice := aPhysicalDevice;

  ReportedQueueFamilies := TVkQueueFamilyProperties_List.Create;
  ReportedDeviceLayers := TVkLayerProperties_List.Create;
  ReportedDeviceExtensions := TVkExtensionProperties_List.Create;

  RequestedDeviceExtensions := TName_List.Create;
  RequestedDeviceLayers := TName_List.Create;

  QueueFamilies := Tvk_QueueFamily_List.Create(True);
  DeviceQueueCreateInfos := TVkDeviceQueueCreateInfo_List.Create;
  QueuePrioritiesForCreateInfos := TFloat_List.Create;
  Surfaces := Tvk_Surface_List.Create;
  Semaphores := Tvk_Semaphore_List.Create;
  Fences := Tvk_Fence_List.Create;
  Events := Tvk_Event_List.Create;
  GraphicsPipelines := Tvk_GraphicsPipeline_List.Create;
  ComputePipelines := Tvk_ComputePipeline_List.Create;
  Images := Tvk_Image_List.Create(True);
  Buffers := Tvk_Buffer_List.Create;
  DeviceMemories := Tvk_DeviceMemory_List.Create(False);
  FrameBuffers := Tvk_Framebuffer_List.Create;
  PipelineLayouts := Tvk_PipelineLayout_List.Create;
  PipelineVertexInputStateCreateInfos := TVk_PipelineVertexInputStateCreateInfo_List.Create;

  with vk_Instance do
  begin
    vkGetPhysicalDeviceProperties(vkPhysicalDevice, @vkPhysicalDeviceProperties);

    Count := 0;
    vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, @Count, nil);
    ReportedQueueFamilies.Resize(Count);
    if Count > 0 then
      vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, @Count, ReportedQueueFamilies.Mutable[0]);

    vkGetPhysicalDeviceFeatures(vkPhysicalDevice, @vkPhysicalDeviceFeatures);
    vkGetPhysicalDeviceMemoryProperties(vkPhysicalDevice, @vkPhysicalDeviceMemoryProperties);

    Count := 0;
    CheckVulkanCall(vkEnumerateDeviceLayerProperties(vkPhysicalDevice, @Count, nil));
    ReportedDeviceLayers.Resize(Count);
    if Count > 0 then
      CheckVulkanCall(vkEnumerateDeviceLayerProperties(vkPhysicalDevice, @Count, ReportedDeviceLayers.Mutable[0]));


    Count := 0;
    CheckVulkanCall(vkEnumerateDeviceExtensionProperties(vkPhysicalDevice, nil, @Count, nil));
    ReportedDeviceExtensions.Resize(Count);
    if Count > 0 then
      CheckVulkanCall(vkEnumerateDeviceExtensionProperties(vkPhysicalDevice, nil, @Count, ReportedDeviceExtensions.Mutable[0]));
  end;

end;

destructor Tvk_Device.Destroy;
begin
  FreeAndNil(PipelineVertexInputStateCreateInfos);
  FreeAndnIl(PipelineLayouts);
  FreeAndNil(FrameBuffers);
  FreeAndNil(DeviceMemories);
  FreeAndNil(Images);
  FreeAndNil(Buffers);
  FreeAndNil(RenderPass);
  FreeAndNil(ComputePipelines);
  FreeAndNil(GraphicsPipelines);
  FreeAndNil(Events);
  FreeAndNil(Fences);
  FreeAndNil(Semaphores);
  FreeAndNil(DeviceQueueCreateInfos);
  FreeAndNil(QueuePrioritiesForCreateInfos);
  FreeAndNil(QueueFamilies);
  FreeAndNil(RequestedDeviceExtensions);
  FreeAndNil(RequestedDeviceLayers);
  FreeAndNil(ReportedQueueFamilies);
  FreeAndNil(ReportedDeviceLayers);
  FreeAndNil(ReportedDeviceExtensions);
  FreeAndNil(Surfaces);
{$IFDEF Surfaces}
  UnregisterClass(wndClass.lpszClassName, HINSTANCE);
{$ENDIF Surfaces}

  if (vkDevice <> 0) then
    vk_Instance.vkDestroyDevice(vkDevice, nil);
  inherited Destroy;
end;

{class operator TVkLayerProperties.= (const a,b: TVkLayerProperties): Boolean;
begin
  Result := False;
  if a.implementationVersion <> b.implementationVersion then Exit;
  if a.specVersion <> b.specVersion then Exit;
  if strlcomp(a.description, b.description, VK_MAX_DESCRIPTION_SIZE) <> 0 then Exit;
  if strlcomp(a.layerName, b.layerName, VK_MAX_EXTENSION_NAME_SIZE) <> 0 then Exit;
  Result := True;
end;

class operator TVkExtensionProperties.= (const a,b: TVkExtensionProperties): Boolean;
begin
  Result := False;
  if a.specVersion <> b.specVersion then Exit;
  if strlcomp(a.extensionName, b.extensionName, VK_MAX_EXTENSION_NAME_SIZE) <> 0 then Exit;
  Result := True;
end;

class operator TVkQueueFamilyProperties.= (const a,b: TVkQueueFamilyProperties): Boolean;
begin
  Result := False;
  with a.minImageTransferGranularity do
  begin
    if b.minImageTransferGranularity.width <> width then Exit;
    if b.minImageTransferGranularity.height <> height then Exit;
    if b.minImageTransferGranularity.depth <> depth then Exit;
  end;
  if a.queueCount <> b.queueCount then Exit;
  if a.queueFlags <> b.queueFlags then Exit;
  if a.timestampValidBits <> b.timestampValidBits then Exit;
  Result := True;
end;
}


procedure CheckVulkanCall(const vkResult: TVkResult; const SuccessCodes: PVkResultArray; const FailureCodes: PVkResultArray);
var ResultInfo: String;
    aResult: TVkResult;
begin
  if vkResult = VK_SUCCESS then Exit;
  if Assigned(SuccessCodes) then
    for aResult in SuccessCodes^ do
      if vkResult = aResult then Exit;

  if Assigned(FailureCodes) then
    for aResult in FailureCodes^ do
      if vkResult = aResult then
      begin
        writestr(ResultInfo,vkResult);
        raise Exception.Create('"' + ResultInfo + '" received instead of VK_SUCCESS');
        Exit;
      end;

  writestr(ResultInfo,vkResult);
  raise Exception.Create('Unexpected result: "' + ResultInfo + '" received instead of VK_SUCCESS');
end;


function VK_MAKE_VERSION(const major, minor, patch: Integer): Integer;
begin
  Result := (((major) shl 22) or ((minor) shl 12) or (patch));
end;

function VK_API_VERSION(): Integer;
begin
  Result := VK_MAKE_VERSION(1, 0, 3);
end;

function VK_VERSION_MAJOR(const version: Cardinal): Integer;
begin
  Result := version shr 22;
end;

function VK_VERSION_MINOR(const version: Cardinal): Integer;
begin
  Result := ((version shr 12) and $3ff);
end;

function VK_VERSION_PATCH(const version: Cardinal): Integer;
begin
  Result := (version and $fff);
end;

{$IFNDEF VULKAN_FLAT}
constructor Tvk_Instance.Create(const LibName: String);
var Count: Integer;
  ss: String;
begin
  if not LoadLibrary_vulkan(PChar(LibName)) then
  begin
    ss := 'Unable to load vulkan library "' + LibName + '"';
    if LibName <> DEFAULT_VULKAN_LIB_NAME then
      ss += #13#10 + '(Default vulkan library for this platform is "' + DEFAULT_VULKAN_LIB_NAME + '")';
    raise Exception.Create(ss);
  end;

  vkGetInstanceProcAddr := TvkGetInstanceProcAddr(GetProcedureAddress(FVulkan_LibHandle, 'vkGetInstanceProcAddr'));
  if not Assigned(vkGetInstanceProcAddr) then raise Exception.Create('Error loading function "vkGetInstanceProcAddr" from vulkan library');

  vkCreateInstance := TvkCreateInstance(vkGetInstanceProcAddr(0, 'vkCreateInstance'));
  if not Assigned(vkCreateInstance) then raise Exception.Create('Error loading function "vkCreateInstance" from vulkan library');

  vkEnumerateInstanceExtensionProperties := TvkEnumerateInstanceExtensionProperties(vkGetInstanceProcAddr(0, 'vkEnumerateInstanceExtensionProperties'));
  if not Assigned(vkEnumerateInstanceExtensionProperties) then raise Exception.Create('Error loading function "vkEnumerateInstanceExtensionProperties" from vulkan library');

  vkEnumerateInstanceLayerProperties := TvkEnumerateInstanceLayerProperties(vkGetInstanceProcAddr(0, 'vkEnumerateInstanceLayerProperties'));
  if not Assigned(vkEnumerateInstanceLayerProperties) then raise Exception.Create('Error loading function "vkEnumerateInstanceLayerProperties" from vulkan library');

  ReportedInstanceLayers := TVkLayerProperties_List.Create;
  ReportedInstanceExtensions := TVkExtensionProperties_List.Create;
  RequestedInstanceExtensions := TName_List.Create;
  RequestedInstanceLayers := TName_List.Create;
  ReportedDevices := TVkPhysicalDevice_List.Create;
  Devices := TVk_Device_List.Create;


  Count := 0;
  CheckVulkanCall(vkEnumerateInstanceLayerProperties(@Count, nil));
  ReportedInstanceLayers.Resize(Count);
  if Count > 0 then
    CheckVulkanCall(vkEnumerateInstanceLayerProperties(@Count, ReportedInstanceLayers.Mutable[0]));

  Count := 0;
  CheckVulkanCall(vkEnumerateInstanceExtensionProperties(nil, @Count, nil));
  ReportedInstanceExtensions.Resize(Count);
  if Count > 0 then
    CheckVulkanCall(vkEnumerateInstanceExtensionProperties(nil, @Count, ReportedInstanceExtensions.Mutable[0]));
end;

destructor Tvk_Instance.Destroy;
begin
  FreeAndNil(Devices);
  FreeAndNil(ReportedInstanceExtensions);
  FreeAndNil(ReportedInstanceLayers);
  FreeAndNil(RequestedInstanceExtensions);
  FreeAndNil(RequestedInstanceLayers);
  FreeAndNil(ReportedDevices);
//  FreeArray(@vk_Devices);

  if (vkDebugReportCallback <> 0) then
    vkDestroyDebugReportCallbackEXT(vkInstance, vkDebugReportCallback, nil);

  if (vkInstance <> 0) then
    vkDestroyInstance(vkInstance, nil);
  inherited Destroy;
end;

function Tvk_Instance.HasValidVulkanLibraryHandle: Boolean;
begin
  Result := FVulkan_LibHandle <> dynlibs.NilHandle;
end;

function Tvk_Instance.HasExtension(const aExtension: TvkExtension): Boolean;
var aExtensionProperties: TVkExtensionProperties;
begin
  Result := True;
  for aExtensionProperties in ReportedInstanceExtensions do
    if aExtensionProperties.extensionName = vkExtension_Names[aExtension] then Exit;
  Result := False;
end;

function Tvk_Instance.HasLayer(const aLayer: String): Boolean;
var aLayerProperties: TVkLayerProperties;
begin
  Result := True;
  for aLayerProperties in ReportedInstanceLayers do
    if aLayerProperties.layerName = aLayer then Exit;
  Result := False;
end;

function Tvk_Instance.RequestLayer(const aLayer: String): Boolean;
begin
  Result := HasLayer(aLayer);
  if not Result then Exit;
  RequestedInstanceLayers.PushBack(aLayer);
end;

function Tvk_Instance.RequestExtension(const aExtension: TvkExtension): Boolean;
begin
  Result := HasExtension(aExtension);
  if not Result then Exit;
  RequestedInstanceExtensions.PushBack(vkExtension_Names[aExtension]);
end;

function Tvk_Instance.LoadDevices(const aApplicationName: String; const aRequestedExtensions: TvkExtensions; const aRequestedLayers: array of string): Boolean;
var aExtension: TvkExtension;
    aLayer: String;
    Count: uint32_t;
    ii: Integer;
begin
  Result := False;
  for aExtension in aRequestedExtensions do
    if not RequestExtension(aExtension) then
      raise Exception.Create('Extension "' + vkExtension_Names[aExtension] + '" requested but not available');

  for aLayer in aRequestedLayers do
    if not RequestLayer(aLayer) then
      raise Exception.Create('Layer "' + aLayer + '" requested but not available');

  vkApplicationInfo.sType := VK_STRUCTURE_TYPE_APPLICATION_INFO;
  vkApplicationInfo.pApplicationName := PChar(aApplicationName);
  vkApplicationInfo.apiVersion := VK_MAKE_VERSION(1, 0, 0);
  with vkInstanceCreateInfo do
  begin
    sType :=  VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    pApplicationInfo := @vkApplicationInfo;

    enabledLayerCount := RequestedInstanceLayers.Size;
    if enabledLayerCount > 0 then
      ppEnabledLayerNames := PPCHar(RequestedInstanceLayers.Mutable[0]);
    enabledExtensionCount := RequestedInstanceExtensions.Size;
    if enabledExtensionCount > 0 then
      ppEnabledExtensionNames := PPChar(RequestedInstanceExtensions.Mutable[0]);
  end;


  CheckVulkanCall(vkCreateInstance(@vkInstanceCreateInfo, nil, @vkInstance));

  Vulkan_InitFunctions;

  Count := 0;
  CheckVulkanCall(vkEnumeratePhysicalDevices(vkInstance, @Count, nil));
  ReportedDevices.Resize(Count);
  if Count > 0 then
    CheckVulkanCall(vkEnumeratePhysicalDevices(vkInstance, @Count, ReportedDevices.Mutable[0]));

  for ii := 0 to count - 1 do
    Devices.Add(Tvk_Device.Create(Self, ReportedDevices.Items[ii]));
end;

{$ENDIF VULKAN_FLAT}

function Tvk_Instance.Vulkan_InitFunctions(const VulkanAppName: String): Boolean;
begin
  Result := False;

  if vkInstance = 0 then
  begin
    FillByte(@vkInstanceCreateInfo, SizeOf(vkInstanceCreateInfo), 0);
    FillByte(@vkApplicationInfo, SizeOf(vkApplicationInfo), 0);
    vkApplicationInfo.sType := VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vkApplicationInfo.pApplicationName := PChar(VulkanAppName);
    with vkInstanceCreateInfo do
    begin
      sType :=  VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
      pApplicationInfo := @vkApplicationInfo;
    end;

    vkCreateInstance(@vkInstanceCreateInfo, nil, @vkInstance);
  end;

  if HasValidVulkanLibraryHandle then
  begin
    {$include vulkan_functionassignments.inc}
    Result := True;
  end;
end;
function Tvk_Instance.Vulkan_InitLoader(const LibName: String): Boolean;
var Count: Integer;
begin
  Result := False;

  if HasValidVulkanLibraryHandle then FreeLibrary_vulkan;
  if not LoadLibrary_vulkan(PChar(LibName)) then Exit;

  vkGetInstanceProcAddr := TvkGetInstanceProcAddr(GetProcedureAddress(FVulkan_LibHandle, 'vkGetInstanceProcAddr'));
  if not Assigned(vkGetInstanceProcAddr) then Exit;

  vkCreateInstance := TvkCreateInstance(vkGetInstanceProcAddr(0, 'vkCreateInstance'));
  if not Assigned(vkCreateInstance) then Exit;
  vkEnumerateInstanceExtensionProperties := TvkEnumerateInstanceExtensionProperties(vkGetInstanceProcAddr(0, 'vkEnumerateInstanceExtensionProperties'));
  if not Assigned(vkEnumerateInstanceExtensionProperties) then Exit;
  vkEnumerateInstanceLayerProperties := TvkEnumerateInstanceLayerProperties(vkGetInstanceProcAddr(0, 'vkEnumerateInstanceLayerProperties'));
  if not Assigned(vkEnumerateInstanceLayerProperties) then Exit;

  ReportedInstanceLayers := TVkLayerProperties_List.Create;
  ReportedInstanceExtensions := TVkExtensionProperties_List.Create;
  RequestedInstanceExtensions := TName_List.Create;
  RequestedInstanceLayers := TName_List.Create;


  Count := 0;
  CheckVulkanCall(vkEnumerateInstanceLayerProperties(@Count, nil));
  ReportedInstanceLayers.Resize(Count);
  if Count > 0 then
    CheckVulkanCall(vkEnumerateInstanceLayerProperties(@Count, ReportedInstanceLayers.Mutable[0]));

  Count := 0;
  CheckVulkanCall(vkEnumerateInstanceExtensionProperties(nil, @Count, nil));
  ReportedInstanceExtensions.Resize(Count);
  if Count > 0 then
    CheckVulkanCall(vkEnumerateInstanceExtensionProperties(nil, @Count, ReportedInstanceExtensions.Mutable[0]));

  Result := True;
end;

procedure Tvk_Instance.AttachDebugCallback(const aFlags: TVkDebugReportFlagsEXT; const aCallback: Tvk_DebugCallback);
var aCreateInfo: TVkDebugReportCallbackCreateInfoEXT;
begin
  DebugCallback := aCallback;
  FillByte(@aCreateInfo, SizeOf(aCreateInfo), 0);
  with aCreateInfo do
  begin
    sType := VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
    flags := aFlags;
    pfnCallback := @DebugCallbackDispatch;
    pUserData := Self;
  end;
  CheckVulkanCall(vkCreateDebugReportCallbackEXT(vkInstance, @aCreateInfo, nil, @vkDebugReportCallback));
end;


function Tvk_Instance.LoadLibrary_vulkan(const Name: PChar): Boolean;
begin
  FVulkan_LibHandle := LoadLibrary(Name);
  Result := HasValidVulkanLibraryHandle;
end;

function {$IFNDEF VULKAN_FLAT}Tvk_Instance.{$ENDIF}FreeLibrary_vulkan: Boolean;
begin
  Result := False;
  if not HasValidVulkanLibraryHandle then Exit;

  if FVulkan_LibHandle <>  DynLibs.NilHandle then if FreeLibrary(FVulkan_LibHandle) then FVulkan_LibHandle := DynLibs.NilHandle;
end;

function Tvk_Instance.GetProcAddress_vulkan(const ProcName: PAnsiChar): Pointer;
begin
  Result := vkGetInstanceProcAddr(vkInstance, ProcName);
end;


{$IFDEF INCLUDE_DBG}
constructor Tvk_Instance_DBG.Create(const LibName: String);
begin
  Vulkan_Interface := Tvk_Instance.Create(LibName);
end;

destructor Tvk_Instance_DBG.Destroy;
begin
  FreeAndNil(Vulkan_Interface);
  inherited Destroy;
end;

function Tvk_Instance_DBG.Vulkan_Instance: TVkInstance;
begin
  Result := Vulkan_Interface.vkInstance;
end;

function Tvk_Instance_DBG.Vulkan_InitFunctions(const VulkanAppName: String): Boolean;
begin
  Result := Vulkan_Interface.Vulkan_InitFunctions(VulkanAppName);
end;

function Tvk_Instance_DBG.Vulkan_InitLoader(const LibName: String): Boolean;
begin
  Result := Vulkan_Interface.Vulkan_InitLoader(LibName);
end;

  {$include vulkan_dbgclass_implementation.inc}
{$ENDIF}

initialization
{$IFDEF WINDOWS}
  WndProcMap := TWNDProcMap.Create;
{$ENDIF WINDOWS}
  {$include vulkan_headerinitialization.inc}

finalization
{$IFDEF WINDOWS}
  FreeAndNil(WndProcMap);
{$ENDIF WINDOWS}
end.

