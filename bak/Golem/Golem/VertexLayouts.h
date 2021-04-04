#pragma once
#include <bgfx/bgfx.h>

namespace Golem::Graphics
{
	struct PositionVertex
	{
		static void Init()
		{
			Layout.begin()
				.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
				.end();
		}

		static bgfx::VertexLayout Layout;
	};

	struct ColorVertex
	{
		static void Init()
		{
			Layout.begin()
				.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
				.end();
		}

		static bgfx::VertexLayout Layout;
	};

	
}
