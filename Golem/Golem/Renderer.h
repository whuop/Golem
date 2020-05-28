#pragma once
#include <bx/bx.h>
#include <bx/thread.h>

namespace Golem
{
	namespace Core
	{
		class Window;
		class Renderer
		{
		public:
			Renderer(Window* window);
			~Renderer();

			void Draw(Window* window);
		private:

		};
	}
}


