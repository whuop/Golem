#include "Renderer.h"
#include "Window.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>>
#include <bx/bx.h>
#include <bx/mutex.h>
#include <bx/thread.h>

#include "bgfx_logo.h"
#include <dear-imgui/imgui.h>

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
	bgfx::init();

	bgfx::reset(window->GetWindowSize().X, window->GetWindowSize().Y, BGFX_RESET_VSYNC);

	//	Enable debug text
	//bgfx::setDebug(BGFX_DEBUG_TEXT);

	//	Set view 0 clear state
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);

}

Renderer::~Renderer()
{
	bgfx::shutdown();
}

void Renderer::Clear(Window* window)
{
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);
	//	This dummy draw call is there to make sure that view 0 is cleared if no other draw calls are submitted to view 0
	bgfx::touch(0);

	//	Use debug font to print infomration about this example
	//bgfx::dbgTextClear();
}

void Renderer::Draw(Window* window)
{
	/*bgfx::dbgTextImage(
		bx::max<uint16_t>(uint16_t(window->GetWindowSize().X / 2 / 8), 20) - 20
		, bx::max<uint16_t>(uint16_t(window->GetWindowSize().Y / 2 / 16), 6) - 6
		, 40
		, 12
		, s_logo
		, 160
	);

	bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");

	bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
	bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");

	const bgfx::Stats* stats = bgfx::getStats();
	bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters."
		, stats->width
		, stats->height
		, stats->textWidth
		, stats->textHeight
	);*/

	bgfx::frame();
}

void Renderer::SetViewRect(int viewID, int posX, int posY, int width, int height)
{
	bgfx::reset(width, height, BGFX_RESET_VSYNC);
	bgfx::setViewRect(viewID, posX, posY, width, height);
}
