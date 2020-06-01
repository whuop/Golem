#pragma once
#include "Vector2i.h"

struct SDL_Window;
namespace Golem::Core
{

	class Window
	{
	public:
		Window(const char* title, const Golem::Math::Vector2i& position, const Golem::Math::Vector2i& size);
		~Window();

		SDL_Window* GetSDLWindow() const;
		const Golem::Math::Vector2i& GetWindowPosition() const;
		const Golem::Math::Vector2i& GetWindowSize() const;

	private:
		SDL_Window* m_sdlWindow;
		Golem::Math::Vector2i m_position;
		Golem::Math::Vector2i m_size;
	};
}


