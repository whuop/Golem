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
}

void Mesh::ConstructMesh()
{

}

void Mesh::AddVertex(const Golem::Math::Vector3f& vertex)
{
	m_vertices.push_back(vertex);
}

void Mesh::AddColor(const Golem::Graphics::Color& color)
{
	m_colors.push_back(color);
}
