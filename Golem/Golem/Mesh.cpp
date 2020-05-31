#include "Mesh.h"

using namespace Golem;
using namespace Golem::Graphics;

Mesh::Mesh()
{
	m_vertexLayout.begin()
		.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float, true)
		.end();
}

Mesh::~Mesh()
{
	bgfx::destroy(m_vbo);
	bgfx::destroy(m_ibo);
}

void Mesh::Render(uint64_t state, float mtx[16])
{
	//	Set rendering model matrix
	bgfx::setTransform(mtx);

	//	Set vertex and index buffer
	bgfx::setVertexBuffer(0, m_vbo);
	bgfx::setIndexBuffer(m_ibo);

	//	Set render states
	bgfx::setState(state);

}

void Mesh::ConstructMesh()
{
	printf("Constructing mesh");
	std::vector<float> vertices;
	for (size_t i = 0; i < m_vertices.size(); i++)
	{
		vertices.push_back(m_vertices[i].X);
		vertices.push_back(m_vertices[i].Y);
		vertices.push_back(m_vertices[i].Z);

		vertices.push_back(m_colors[i].R);
		vertices.push_back(m_colors[i].G);
		vertices.push_back(m_colors[i].B);
		vertices.push_back(m_colors[i].A);
	}
	
	const bgfx::Memory* vboMem = bgfx::copy(vertices.data(), vertices.size() * sizeof(float));
	const bgfx::Memory* iboMem = bgfx::copy(m_indices.data(), m_indices.size() * sizeof(int));

	m_vbo = bgfx::createVertexBuffer(vboMem, m_vertexLayout);
	m_ibo = bgfx::createIndexBuffer(iboMem);
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
