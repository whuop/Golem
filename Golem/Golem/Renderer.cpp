#include "Renderer.h"
#include "Window.h"
#include "SDL.h"
#include "SDL_syswm.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>>
#include <bx/bx.h>
#include <bx/mutex.h>
#include <bx/thread.h>

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

	int width, height;
	SDL_GetWindowSize(window->GetSDLWindow(), &width, &height);

	bgfx::reset(width, height, BGFX_RESET_VSYNC);

	//	Enable debug text
	bgfx::setDebug(BGFX_DEBUG_TEXT);

	//	Set view 0 clear state
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x303030ff, 1.0f, 0);


	//bgfx::frame();

}

Renderer::~Renderer()
{
}

void Renderer::Draw(Window* window)
{
	int width, height;
	SDL_GetWindowSize(window->GetSDLWindow(), &width, &height);

	bgfx::reset(width, height, BGFX_RESET_VSYNC);

	//	Set view 0 default viewport
	bgfx::setViewRect(0, 0, 0, width, height);

	//	This dummy draw call is there to make sure that view 0 is cleared if no other draw calls are submitted to view 0
	bgfx::touch(0);

	//	Use debug font to print infomration about this example
	bgfx::dbgTextClear();
	/*bgfx::dbgTextImage(bx::uint32_max(width / 2 / 8, 20) - 20
		, bx::uint32_max(height / 2 / 16, 6) - 6
		, 40
		, 12
		, s_logo
		, 160
	);*/

	bgfx::frame();
}
