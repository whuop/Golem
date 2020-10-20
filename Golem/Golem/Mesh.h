#pragma once
#include <bgfx/bgfx.h>
#include <vector>

#include "Math/Vector3f.h"
#include "Color.h"

namespace Golem::Math
{
	struct Matrix4x4;
}

namespace Golem::Graphics
{
	class Material;
	
	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		void Render(uint64_t state, const Golem::Math::Matrix4x4& transformMtx);
		void ConstructMesh();

		void AddVertex(const Golem::Math::Vector3f& vertex);
		void AddVertices(const std::vector<Golem::Math::Vector3f>& vertices);

		void AddColor(const Golem::Graphics::Color& color);
		void AddColors(const std::vector<Golem::Graphics::Color>& colors);
		
		void AddIndex(const int index);
		void AddIndices(const std::vector<uint16_t>& indices);
		void ClearMeshData();

		void SetMaterial(const Material* material);
 
	private:
		
		bgfx::VertexBufferHandle m_positionBufferHandle;
		bgfx::VertexBufferHandle m_colorBufferHandle;
		bgfx::IndexBufferHandle m_indexBufferHandle;

		const Material* m_material;

		std::vector<Golem::Math::Vector3f> m_vertices;
		std::vector<Golem::Graphics::Color> m_colors;
		std::vector<uint16_t> m_indices;
	};
}


