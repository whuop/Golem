#pragma once
#include <bgfx/bgfx.h>
#include <vector>

#include "Vector3f.h"
#include "Color.h"

namespace Golem::Graphics
{
	class Material;
	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void ConstructMesh();

		void AddVertex(const Golem::Math::Vector3f& vertex);
		void AddColor(const Golem::Graphics::Color& color);
		void AddIndex(const int index);
		void ClearMeshData();

		void SetMaterial(const Material* material);
 
	private:
		bgfx::VertexBufferHandle m_vbo;
		bgfx::IndexBufferHandle m_ibo;
		bgfx::ProgramHandle m_program;
		bgfx::VertexLayout m_vertexLayout;

		const Material* m_material;

		std::vector<Golem::Math::Vector3f> m_vertices;
		std::vector<Golem::Graphics::Color> m_colors;
		std::vector<int> m_indices;
	};
}


