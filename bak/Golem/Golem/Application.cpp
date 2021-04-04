#include "Application.h"
#include "Window.h"
#include "Renderer.h"

#include "Math/Vector2i.h"

#include <SDL.h>
#include <stdio.h>

using namespace Golem;
using namespace Golem::Core;
using namespace Golem::Math;


Golem::Application::Application(const char* windowTitle, const Golem::Math::Vector2i& windowPosition, const Golem::Math::Vector2i windowSize):
m_window(nullptr),
m_renderer(nullptr),
m_isRunning(false)
{
	m_window = new Window(windowTitle, windowPosition, windowSize);
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

			//	Mouse Events
			switch(e.type)
			{
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&m_mouse.Position.X, &m_mouse.Position.Y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
					m_mouse.LeftButton = true;
				else if (e.button.button == SDL_BUTTON_RIGHT)
					m_mouse.RightButton = true;
				break;
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT)
					m_mouse.LeftButton = false;
				else if (e.button.button == SDL_BUTTON_RIGHT)
					m_mouse.RightButton = false;
				break;
			}

			//	Keyboard Events


			//	Window Events
			if (e.type == SDL_WINDOWEVENT)
			{
				switch (e.window.event)
				{
				case SDL_WINDOWEVENT_SHOWN:
					printf("WindowEvent Shown\n");
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					printf("WindowEvent Hidden\n");
					break;
				case SDL_WINDOWEVENT_MOVED:
					this->WindowMoved(Vector2i(e.window.data1, e.window.data2));
					break;
				case SDL_WINDOWEVENT_RESIZED:
					this->WindowResized(Vector2i(e.window.data1, e.window.data2));
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					this->WindowResized(Vector2i(e.window.data1, e.window.data2));
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					printf("WindowEvent Minimized\n");
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					printf("WindowEvent Maximized\n");
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					printf("WindowEvent Focus Gained\n");
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					printf("WindowEvent Focus Lost\n");
					break;
				default:

					break;
				}
			}
		}

		DrawUI();
		
		this->OnUpdate();

 		m_renderer->Clear(m_window);
		
		
		this->OnRender();

		m_renderer->Draw(m_window);
	}
}

void Application::DrawUI()
{
	/*imguiBeginFrame(m_mouseState.m_mx
		, m_mouseState.m_my
		, (m_mouseState.m_buttons[entry::MouseButton::Left] ? IMGUI_MBUT_LEFT : 0)
		| (m_mouseState.m_buttons[entry::MouseButton::Right] ? IMGUI_MBUT_RIGHT : 0)
		| (m_mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0)
		, m_mouseState.m_mz
		, uint16_t(m_window->GetWindowSize().X)
		, uint16_t(m_window->GetWindowSize().Y)
	);

	m_performanceDialog->show();
	
	imguiEndFrame();*/
}

void Application::Close()
{
	m_isRunning = false;
}

void Application::WindowMoved(const Vector2i& position)
{
	this->OnWindowMoved(position);
}

void Application::WindowResized(const Vector2i& size)
{
	m_renderer->SetViewRect(0, 0, 0, size.X, size.Y);

	this->OnWindowResized(size);
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
