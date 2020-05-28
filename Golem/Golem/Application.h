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
	private:

		bool m_isRunning;

		Core::Window* m_window;
		Core::Renderer* m_renderer;
	};
}



