#pragma once

namespace Golem
{
	namespace Core
	{
		class Window;
		class Renderer;
	}

	class Application
	{
	public:
		Application(int windowPosX, int windowPosY, int windowWidth, int windowHeight);
		~Application();

		void Run();
		void Close();

		const bool GetIsRunning() const;

		const Core::Renderer& GetRenderer() const;
		const Core::Window& GetWindow() const;

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;

	private:

		bool m_isRunning;

		Core::Window* m_window;
		Core::Renderer* m_renderer;
	};
}



