#include "Window.h"
#include "SDL.h"
#include <iostream>

using namespace Golem::Core;

Window::Window(int posX, int posY, int width, int height):
	m_sdlWindow(nullptr)/*,
	m_isRunning(false)*/
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL Could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		m_sdlWindow = SDL_CreateWindow("Golem", posX, posY, width, height, SDL_WINDOW_SHOWN);
		if (m_sdlWindow == nullptr)
		{
			printf("SDL Window could not be created! SDL_Error: %s", SDL_GetError());
			return;
		}
	}
}

Window::~Window()
{
	SDL_DestroyWindow(m_sdlWindow);
	m_sdlWindow = nullptr;
	SDL_Quit();
}

/*void Window::Run()
{
	m_isRunning = true;
	SDL_Event e;
	while (m_isRunning)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				this->SetIsRunning(false);
			}
		}
	}
}*/

SDL_Window* Window::GetSDLWindow() const
{
	return m_sdlWindow;
}

/*const bool Window::GetIsRunning() const
{
	return m_isRunning;
}

void Window::SetIsRunning(const bool value)
{
	m_isRunning = value;
}*/
