#include "Renderer.h"

#include <cstdio>

#include "Window.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>>
#include <bx/bx.h>

#include "bgfx_logo.h"

using namespace Golem::Core;

Renderer::Renderer(Window* window)
{
	SDL_SysWMinfo wmi;
	SDL_VERSION(&wmi.version);
	if (!SDL_GetWindowWMInfo(window->GetSDLWindow(), &wmi))
	{
		return;
	}

	bgfx::PlatformData pd;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	pd.ndt = wmi.info.x11.display;
	pd.nwh = (void*)(uintptr_t)wmi.info.x11.window;
#elif BX_PLATFORM_OSX
	pd.ndt = NULL;
	pd.nwh = wmi.info.cocoa.window;
#elif BX_PLATFORM_WINDOWS
	pd.ndt = NULL;
	pd.nwh = wmi.info.win.window;
#elif BX_PLATFORM_STEAMLINK
	pd.ndt = wmi.info.vivante.display;
	pd.nwh = wmi.info.vivante.window;
#endif // BX_PLATFORM_
	pd.context = nullptr;
	pd.backBuffer = nullptr;
	pd.backBufferDS = nullptr;
	bgfx::setPlatformData(pd);

	bgfx::RenderFrame();

	bgfx::Init bgfxInit;
	bgfxInit.type = bgfx::RendererType::Count;
	bgfxInit.resolution.width = window->GetWindowSize().X;
	bgfxInit.resolution.height = window->GetWindowSize().Y;
	bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
	bgfx::init(bgfxInit);

	SetViewRect(0, 0, 0, window->GetWindowSize().X, window->GetWindowSize().Y);
	//	Set view 0 clear state
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
}

Renderer::~Renderer()
{
	bgfx::shutdown();
}

void Renderer::Clear(Window* window)
{
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
	//	This dummy draw call is there to make sure that view 0 is cleared if no other draw calls are submitted to view 0
	bgfx::touch(0);
}

void Renderer::Draw(Window* window)
{
	bgfx::frame();
}

void Renderer::SetViewRect(int viewID, int posX, int posY, int width, int height)
{
	bgfx::reset(width, height, BGFX_RESET_VSYNC);
	bgfx::setViewRect(viewID, posX, posY, width, height);
}
