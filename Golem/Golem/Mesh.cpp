#include "Mesh.h"

#include "VertexLayouts.h"

using namespace Golem;
using namespace Golem::Graphics;

Mesh::Mesh():
	m_positionBufferHandle(),
	m_colorBufferHandle(),
	m_indexBufferHandle(),
	m_material(nullptr)
{

}

Mesh::~Mesh()
{
	bgfx::destroy(m_positionBufferHandle);
	bgfx::destroy(m_colorBufferHandle);
	bgfx::destroy(m_indexBufferHandle);
}

void Mesh::Render(uint64_t state, float mtx[16])
{
	//	Set rendering model matrix
	bgfx::setTransform(mtx);

	//	Set vertex and index buffer
	bgfx::setVertexBuffer(0, m_positionBufferHandle);
	bgfx::setVertexBuffer(1, m_colorBufferHandle);
	bgfx::setIndexBuffer(m_indexBufferHandle);

	//	Set render states
	bgfx::setState(state);
}

void Mesh::ConstructMesh()
{
	const bgfx::Memory* positionBufferMem = bgfx::copy(m_vertices.data(), m_vertices.size() * PositionVertex::Layout.getStride());
	const bgfx::Memory* colorBufferMem = bgfx::copy(m_colors.data(), m_colors.size() * ColorVertex::Layout.getStride());
	const bgfx::Memory* indexBufferMem = bgfx::copy(m_indices.data(), m_indices.size() * sizeof(uint16_t));

	m_positionBufferHandle = bgfx::createVertexBuffer(positionBufferMem, PositionVertex::Layout);
	m_colorBufferHandle = bgfx::createVertexBuffer(colorBufferMem, ColorVertex::Layout);
	m_indexBufferHandle = bgfx::createIndexBuffer(indexBufferMem);
}

void Mesh::AddVertex(const Golem::Math::Vector3f& vertex)
{
	m_vertices.push_back(vertex);
}

void Mesh::AddVertices(const std::vector<Golem::Math::Vector3f>& vertices)
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		m_vertices.push_back(vertices[i]);
	}
}

void Mesh::AddColor(const Golem::Graphics::Color& color)
{
	m_colors.push_back(color);
}

void Mesh::AddColors(const std::vector<Golem::Graphics::Color>& colors)
{
	for (size_t i = 0; i < colors.size(); i++)
	{
		m_colors.push_back(colors[i]);
	}
}

void Mesh::AddIndex(const int index)
{
	m_indices.push_back(index);
}

void Mesh::AddIndices(const std::vector<uint16_t>& indices)
{
	for (size_t i = 0; i < indices.size(); i++)
	{
		m_indices.push_back(indices[i]);
	}
}

void Mesh::ClearMeshData()
{
	m_vertices.clear();
	m_colors.clear();
	m_indices.clear();
}

void Mesh::SetMaterial(const Material* material)
{
	m_material = material;
}
