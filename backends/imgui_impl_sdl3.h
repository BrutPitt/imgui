// dear imgui: Platform Backend for SDL3
// This needs to be used along with a Renderer (e.g. SDL_GPU, DirectX11, OpenGL3, Vulkan..)
// (Info: SDL3 is a cross-platform general purpose library for handling windows, inputs, graphics context creation, etc.)

// Implemented features:
//  [X] Platform: Clipboard support.
//  [X] Platform: Mouse support. Can discriminate Mouse/TouchScreen.
//  [X] Platform: Keyboard support. Since 1.87 we are using the io.AddKeyEvent() function. Pass ImGuiKey values to all key functions e.g. ImGui::IsKeyPressed(ImGuiKey_Space). [Legacy SDL_SCANCODE_* values are obsolete since 1.87 and not supported since 1.91.5]
//  [X] Platform: Gamepad support.
//  [X] Platform: Mouse cursor shape and visibility (ImGuiBackendFlags_HasMouseCursors). Disable with 'io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange'.
//  [X] Platform: IME support.

// You can use unmodified imgui_impl_* files in your project. See examples/ folder for examples of using this.
// Prefer including the entire imgui/ repository into your project (either as a copy or as a submodule), and only build the backends you need.
// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#pragma once
#include "imgui.h"      // IMGUI_IMPL_API
#ifndef IMGUI_DISABLE

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Gamepad;
typedef union SDL_Event SDL_Event;

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForOpenGL(SDL_Window* window, void* sdl_gl_context);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForVulkan(SDL_Window* window);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForD3D(SDL_Window* window);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForMetal(SDL_Window* window);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForSDLRenderer(SDL_Window* window, SDL_Renderer* renderer);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForSDLGPU(SDL_Window* window);
IMGUI_IMPL_API bool     ImGui_ImplSDL3_InitForOther(SDL_Window* window);
IMGUI_IMPL_API void     ImGui_ImplSDL3_Shutdown();
IMGUI_IMPL_API void     ImGui_ImplSDL3_NewFrame();
IMGUI_IMPL_API bool     ImGui_ImplSDL3_ProcessEvent(const SDL_Event* event);

// Gamepad selection automatically starts in AutoFirst mode, picking first available SDL_Gamepad. You may override this.
// When using manual mode, caller is responsible for opening/closing gamepad.
enum ImGui_ImplSDL3_GamepadMode { ImGui_ImplSDL3_GamepadMode_AutoFirst, ImGui_ImplSDL3_GamepadMode_AutoAll, ImGui_ImplSDL3_GamepadMode_Manual };
IMGUI_IMPL_API void     ImGui_ImplSDL3_SetGamepadMode(ImGui_ImplSDL3_GamepadMode mode, SDL_Gamepad** manual_gamepads_array = nullptr, int manual_gamepads_count = -1);

// SDL3 helper to create a WebGPU surface for Native/Desktop applications: available only with WebGPU/WGPU backend
#if defined(IMGUI_IMPL_WEBGPU_BACKEND_WGPU) || defined(IMGUI_IMPL_WEBGPU_BACKEND_DAWN) && !defined(__EMSCRIPTEN__)
#include <webgpu/webgpu.h>
WGPUSurface ImGui_ImplSDL3_CreateWGPUSurface_Helper(WGPUInstance instance, SDL_Window* window);
#endif

#endif // #ifndef IMGUI_DISABLE
