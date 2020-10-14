#pragma once
#include "NonCopyable.h"

namespace Golem
{
	namespace Core
	{
		class Window;
		class Renderer;
	}

	namespace Math
	{
		struct Vector2i;
	}

	class Application : public Golem::Core::NonCopyable
	{
	public:
		Application(const char* windowTitle, const Golem::Math::Vector2i& windowPosition, const Golem::Math::Vector2i windowSize);
		virtual ~Application();

		void Run();
		void Close();

		const bool GetIsRunning() const;
		const Core::Renderer& GetRenderer() const;
		const Core::Window& GetWindow() const;

	protected:
		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;

		virtual void OnWindowMoved(const Golem::Math::Vector2i& position) {}
		virtual void OnWindowResized(const Golem::Math::Vector2i& size) {}

	private:
		bool m_isRunning;

		Core::Window* m_window;
		Core::Renderer* m_renderer;

		void WindowMoved(const Golem::Math::Vector2i& position);
		void WindowResized(const Golem::Math::Vector2i& size);
	};
}



