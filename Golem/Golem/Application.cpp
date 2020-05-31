#include "Application.h"
#include "Window.h"
#include "Renderer.h"

#include <SDL.h>
#include <stdio.h>

using namespace Golem;
using namespace Golem::Core;

Application::Application(int windowPosX, int windowPosY, int windowWidth, int windowHeight):
	m_window(nullptr),
	m_renderer(nullptr),
	m_isRunning(false)
{
	m_window = new Window(windowPosX, windowPosY, windowWidth, windowHeight);
	m_renderer = new Renderer(m_window);
}

Application::~Application()
{
	if (m_window != nullptr)
	{
		delete m_renderer;
		delete m_window;
		m_renderer = nullptr;
		m_window = nullptr;
	}
}

void Application::Run()
{
	m_isRunning = true;

	this->OnInitialize();

	SDL_Event e;
	while (m_isRunning)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				this->m_isRunning = false;
			}
		}

		this->OnUpdate();

		m_renderer->Clear(m_window);

		this->OnRender();

		m_renderer->Draw(m_window);
	}
}

void Application::Close()
{
	m_isRunning = false;
}

const bool Application::GetIsRunning() const
{
	return m_isRunning;
}

const Core::Renderer& Golem::Application::GetRenderer() const
{
	return *this->m_renderer;
}

const Core::Window& Golem::Application::GetWindow() const
{
	return *this->m_window;
}
