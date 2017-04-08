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

unit VulkanTest;

{$mode objfpc}{$H+}

interface

uses
  Forms, Classes, SysUtils, sdl2, typinfo, vulkan;

type

  { TVulkanTest }

  TVulkanTest = class
    ChosenGPU: Tvk_Device;
    VulkanInstance: Tvk_Instance;
    vk_Device: Tvk_Device;
    GraphicsQueue, ComputeQueue, PresentQueue: Tvk_Queue;
    aSwapChain: Tvk_Swapchain;

    GraphicsCommandBuffer: array of Tvk_CommandBuffer;
    SubCommandBuffer: Tvk_CommandBuffer;
    aSurface, aSurface2: Tvk_Surface;
    imageAvailableSemaphore, renderFinishedSemaphore: Tvk_Semaphore;
    aGraphicsPipeline: TVk_GraphicsPipeline;
    aComputePipeline: Tvk_ComputePipeline;
    aRenderPass: Tvk_RenderPass;
    aImageIndex: uint32_t;
    aViewport: TvkViewport;
    tvibd: TVk_PipelineVertexInputStateCreateInfo;
    ti: PtypeInfo;
    aVertexBuffer: Tvk_Buffer;
    aVertexBufferMem: Pointer;
    aOffset: TVkDeviceSize;
    aLayout: Tvk_PipelineLayout;
    sdlEvent: TSDL_Event;
    ss: String;

    procedure Initialize;
    procedure HandleSDLInput(var Continue: Boolean);
    procedure TestLoop;
    destructor Destroy; override;
  end;

  vec2 = packed record
    case Integer of
      1: (x, y: Single; );
      2: (d: array[0..1] of Single;);
  end;
  vec3 = packed record
    case Integer of
      1: (x, y, z: Single;);
      2: (d: array[0..2] of Single;);
      3: (r, g, b: Single;);
  end;


  TTestVertex = packed record
    pos: vec2;
    color: vec3;
  end;

var Vertices: array[0..14] of Single = (
0, -0.5, 1, 0, 0,
0.5, 0.5, 0, 1, 0,
-0.5, 0.5, 0, 0, 1);


const
  WINDOW_WIDTH = 300;
  WINDOW_HEIGHT = 300;


implementation

{ TVulkanTest }

procedure TVulkanTest.Initialize;
var ii: Integer;
  DeviceExtensions: TvkExtensions;
begin
  VulkanInstance := Tvk_Instance.Create;
  VulkanInstance.LoadDevices('Hello world', [VK_KHR_surface, {$IFDEF WINDOWS}VK_KHR_win32_surface{$ENDIF WINDOWS}{$IFDEF UNIX}VK_KHR_xlib_surface{$ENDIF UNIX},
    VK_EXT_debug_report],
      ['VK_LAYER_LUNARG_standard_validation']);
  VulkanInstance.AttachDebugCallback([VK_DEBUG_REPORT_WARNING_BIT_EXT, VK_DEBUG_REPORT_ERROR_BIT_EXT]);
  vk_Device := VulkanInstance.Devices[0];
  with vk_Device do
  begin
    aSurface := CreateSurface(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT);

    DeviceExtensions := [VK_KHR_swapchain];
    if HasExtension(VK_EXT_debug_marker) then
      DeviceExtensions += [VK_EXT_debug_marker];
    GraphicsQueue := RequestQueue([VK_QUEUE_GRAPHICS_BIT, VK_QUEUE_COMPUTE_BIT], aSurface);
    CreateLogicalDevice(DeviceExtensions, []);

    tvibd := NewPipelineVertexInputStateCreateInfo;
    tvibd.LoadType(TypeInfo(TTestVertex), 0);
    aVertexBuffer := GetBuffer(SizeOf(TTestVertex)*3, [], [VK_BUFFER_USAGE_VERTEX_BUFFER_BIT], [], True);
    with aVertexBuffer.BufferMemory do
    begin
      MapMemory;
      Move(Vertices[0], MappedAddress^, vkMemoryAllocateInfo.allocationSize);
    end;

    aSwapChain := aSurface.CreateSwapchain;

    SubCommandBuffer := GraphicsQueue.GetCommandBuffer(VK_COMMAND_BUFFER_LEVEL_SECONDARY);

    imageAvailableSemaphore := GetSemaphore;
    renderFinishedSemaphore := GetSemaphore;

    aRenderPass := GetRenderPass(aSwapChain.vkSwapchainCreateInfo.imageFormat);

    aLayout := CreatePipelineLayout;

    aGraphicsPipeline := GetGraphicsPipeline;
    with aGraphicsPipeline do
    begin
      vkVertexInputStateCreateInfo := tvibd.GetVKPipelineVertexInputStateCreateInfo;
      AddShader([VK_SHADER_STAGE_VERTEX_BIT], 'vert.spv');
      AddShader([VK_SHADER_STAGE_FRAGMENT_BIT], 'frag.spv');
      AddStaticViewportAndScissor(WINDOW_WIDTH, WINDOW_HEIGHT);
      RefreshPipeline;
    end;
    aSwapChain.CreateFramebuffers(aRenderPass);

    with aViewport do
    begin
      height := WINDOW_HEIGHT;
      width := WINDOW_WIDTH;
      x := 0;
      y := 0;
      minDepth := 0.0;
      maxDepth := 1.0;
    end;

    aOffset := 0;

    SetLength(GraphicsCommandBuffer, aSwapChain.Framebuffers_SwapChain.Count);

    with SubCommandBuffer do
    begin
      BeginRecording([VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT, VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT], aRenderPass, 0, nil);
      BindPipeline(aGraphicsPipeline);
      BindVertexBuffer(0, @aVertexBuffer.vkBuffer, @aOffset);
      SetViewport(aViewport);
      Draw(3, 1, 0, 0);
      EndRecording;
    end;

    for ii := Low(GraphicsCommandBuffer) to High(GraphicsCommandBuffer) do
    begin
      GraphicsCommandBuffer[ii] := GraphicsQueue.GetCommandBuffer;

      with GraphicsCommandBuffer[ii] do
      begin
        BeginRecording([VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT], aRenderPass, 0, aSwapChain.Framebuffers_SwapChain[ii]);
        BeginRenderPass(aRenderPass, aSwapChain.Framebuffers_SwapChain[ii], VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS);
        ExecuteSubCommandBuffer(SubCommandBuffer);
        EndRenderPass;
        EndRecording;
      end;
    end;
  end;
end;

procedure TVulkanTest.HandleSDLInput(var Continue: Boolean);
var ii: Integer;
begin
  if SDL_PollEvent(@sdlEvent) = 1 then
  case sdlEvent.type_ of
    SDL_WINDOWEVENT:
    with sdlEvent.window do
    case event of
      SDL_WINDOWEVENT_CLOSE: Continue := False;
      SDL_WINDOWEVENT_RESIZED:
      begin
        aSurface.Resize(data1, data2);
        aSurface.SwapChain.CreateFramebuffers(aRenderPass);
        aViewport.width := data1;
        aViewport.height := data2;
        for ii := Low(GraphicsCommandBuffer) to High(GraphicsCommandBuffer) do
        with GraphicsCommandBuffer[ii] do
        begin
          vk_Device.WaitUntilIdle;
          Reset;
          BeginRecording([VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT], aRenderPass, 0, aSwapChain.Framebuffers_SwapChain[ii]);
          BeginRenderPass(aRenderPass, aSwapChain.Framebuffers_SwapChain[ii], VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS);
          ExecuteSubCommandBuffer(SubCommandBuffer);
          EndRenderPass;
          EndRecording;
        end;

      end;
    end;
    SDL_KEYDOWN:
    with sdlEvent.key.keysym do
    begin
      ss := 'Key pressed:' + #13#10 +
                   '  Key code: ' + IntToHex(sym, 8) + #13#10 +
                   '  Key name: "' + SDL_GetKeyName(sym) + '"' + #13#10 +
                   '  Scancode: ' + IntToHex(scancode, 8) + #13#10 +
                   '  Scancode name: "' + SDL_GetScancodeName(scancode) + '"' + #13#10 +
                   '  Key modifiers: ' + IntToHex(_mod, 4);
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
        'Just FYI:',
        PChar(ss), nil);
    end;
  end;
end;

procedure TVulkanTest.TestLoop;
var Continue: Boolean;
begin
  Continue := True;
  while Continue do
  begin
    Application.ProcessMessages;
    HandleSDLInput(Continue);
    aSwapChain.AcquireNextImage(aImageIndex, 0, imageAvailableSemaphore);

    with GraphicsQueue.SubmitInfo do
    begin
      AddCommandBuffer(GraphicsCommandBuffer[aImageIndex]);
      AddWaitSemaphore(imageAvailableSemaphore, [VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT]);
      AddSignalSemaphore(renderFinishedSemaphore);
    end;
    GraphicsQueue.SubmitQueuedSubmitInfos;
    GraphicsQueue.Present(aSwapchain, aImageIndex, renderFinishedSemaphore);
  end;
end;

destructor TVulkanTest.Destroy;
begin
  vk_Device.WaitUntilIdle;
  FreeAndNil(VulkanInstance);
  inherited Destroy;
end;

end.

