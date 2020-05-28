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

			//void Run();

			SDL_Window* GetSDLWindow() const;

			//const bool GetIsRunning() const;
			//void SetIsRunning(const bool value);

		private:
			SDL_Window* m_sdlWindow;

			//bool m_isRunning;

		};
	}
}


