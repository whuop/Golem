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

			void Clear(Window* window);
			void Draw(Window* window);

			void SetViewRect(int viewID, int posX, int posY, int width, int height);
		private:

		};
	}
}


