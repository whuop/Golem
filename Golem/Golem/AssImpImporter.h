#pragma once

#include "IMeshImporter.h"

struct aiScene;
namespace Golem::Graphics::Importers
{
	class AssImpImporter : public Golem::Graphics::Importers::IMeshImporter
	{
	public:
		// Inherited via IMeshImporter
		virtual Mesh* LoadMesh(const char* meshPath) override;
	private:
		Mesh* ProcessData(const aiScene* scene);
	};
}


