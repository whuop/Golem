#include "Window.h"
#include "SDL.h"
#include <iostream>

using namespace Golem::Core;
using namespace Golem::Math;

Window::Window(const char* title, const Vector2i& position, const Vector2i& size) :
	m_sdlWindow(nullptr),
	m_size(0, 0),
	m_position(position.X, position.Y)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	m_sdlWindow = SDL_CreateWindow(title, position.X, position.Y, size.X, size.Y, flags);
	if (m_sdlWindow == nullptr)
	{
		printf("SDL Window could not be created! SDL_Error: %s", SDL_GetError());
		return;
	}

	SDL_GetWindowSize(m_sdlWindow, &m_size.X, &m_size.Y);
}

Window::~Window()
{
	SDL_DestroyWindow(m_sdlWindow);
	m_sdlWindow = nullptr;
	SDL_Quit();
}

void Window::RefreshPositionAndSize()
{
	SDL_GetWindowPosition(m_sdlWindow, &m_position.X, &m_position.Y);
	SDL_GetWindowSize(m_sdlWindow, &m_size.X, &m_size.Y);
}

SDL_Window* Window::GetSDLWindow() const
{
	return m_sdlWindow;
}

const Vector2i& Window::GetWindowPosition() const
{
	return m_position;
}

const Vector2i& Window::GetWindowSize() const
{
	return m_size;
}
