#pragma once

namespace Golem::Graphics
{
	class Mesh;
}

namespace Golem::Graphics::Importers
{
	class IMeshImporter
	{
	public:
		virtual Mesh* LoadMesh(const char* meshPath) = 0;
	};
}