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

void Mesh::ConstructMesh()
{
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
	
	m_vbo = bgfx::createVertexBuffer(bgfx::makeRef(vertices.data(), vertices.size() * 3), m_vertexLayout);
	m_ibo = bgfx::createIndexBuffer(bgfx::makeRef(m_indices.data(), m_indices.size()));
}

void Mesh::AddVertex(const Golem::Math::Vector3f& vertex)
{
	m_vertices.push_back(vertex);
}

void Mesh::AddColor(const Golem::Graphics::Color& color)
{
	m_colors.push_back(color);
}

void Mesh::AddIndex(const int index)
{
	m_indices.push_back(index);
}
