#pragma once
#include "Vector2i.h"
#include "NonCopyable.h"

struct SDL_Window;
namespace Golem::Core
{
	class Window : public NonCopyable
	{
	public:
		Window(const char* title, const Golem::Math::Vector2i& position, const Golem::Math::Vector2i& size);
		~Window();

		void RefreshPositionAndSize();

		SDL_Window* GetSDLWindow() const;
		const Golem::Math::Vector2i& GetWindowPosition() const;
		const Golem::Math::Vector2i& GetWindowSize() const;

	private:
		SDL_Window* m_sdlWindow;
		Golem::Math::Vector2i m_position;
		Golem::Math::Vector2i m_size;
	};
}


