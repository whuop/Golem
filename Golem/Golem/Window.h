#pragma once

struct SDL_Window;
namespace Golem
{
	namespace Core
	{
		class Window
		{
		public:
			Window(int posX, int posY, int width, int height);
			~Window();
			
			SDL_Window* GetSDLWindow() const;
		private:
			SDL_Window* m_sdlWindow;
		};
	}
}


