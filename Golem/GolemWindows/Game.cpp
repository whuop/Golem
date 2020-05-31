#include "Game.h"
#include <stdio.h>

#include "Mesh.h"
#include "Material.h"
#include "Vector3f.h"

using namespace Golem::Graphics;
using namespace Golem::Math;

Game::Game(int windowPosX, int windowPosY, int windowWidth, int windowHeight):
	Application(windowPosX, windowPosY, windowWidth, windowHeight)
{
}

void Game::OnInitialize()
{
	printf("Hello Initialize");

	m_mesh = new Mesh();
	m_mesh->AddVertex(Vector3f(-1.0f, 1.0f, 1.0f));
	m_mesh->AddVertex(Vector3f(1.0f, 1.0f, 1.0f));
	m_mesh->AddVertex(Vector3f(-1.0f, -1.0f, 1.0f));
	m_mesh->AddVertex(Vector3f(1.0f, -1.0f, 1.0f));
	m_mesh->AddVertex(Vector3f(-1.0f, 1.0f, -1.0f));
	m_mesh->AddVertex(Vector3f(1.0f, 1.0f, -1.0f));
	m_mesh->AddVertex(Vector3f(-1.0f, -1.0f, -1.0f));
	m_mesh->AddVertex(Vector3f(1.0f, -1.0f, -1.0f));

	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));
	m_mesh->AddColor(Color(1, 0, 0, 1));

	m_mesh->AddIndex(0);
	m_mesh->AddIndex(1);
	m_mesh->AddIndex(2);

	m_mesh->AddIndex(1);
	m_mesh->AddIndex(3);
	m_mesh->AddIndex(2);

	m_mesh->AddIndex(4);
	m_mesh->AddIndex(6);
	m_mesh->AddIndex(5);

	m_mesh->AddIndex(5);
	m_mesh->AddIndex(6);
	m_mesh->AddIndex(7);

	m_mesh->AddIndex(0);
	m_mesh->AddIndex(2);
	m_mesh->AddIndex(4);

	m_mesh->AddIndex(4);
	m_mesh->AddIndex(2);
	m_mesh->AddIndex(6);

	m_mesh->AddIndex(1);
	m_mesh->AddIndex(5);
	m_mesh->AddIndex(3);

	m_mesh->AddIndex(5);
	m_mesh->AddIndex(7);
	m_mesh->AddIndex(3);

	m_mesh->AddIndex(0);
	m_mesh->AddIndex(4);
	m_mesh->AddIndex(1);

	m_mesh->AddIndex(4);
	m_mesh->AddIndex(5);
	m_mesh->AddIndex(1);

	m_mesh->AddIndex(2);
	m_mesh->AddIndex(3);
	m_mesh->AddIndex(6);

	m_mesh->AddIndex(6);
	m_mesh->AddIndex(3);
	m_mesh->AddIndex(7);

	m_mesh->ConstructMesh();

	m_material = new Material("../assets/shaders/v_simple.bin", "../assets/shaders/f_simple.bin");
	m_mesh->SetMaterial(m_material);
}

void Game::OnUpdate()
{
	//printf("Hello Update");
}

void Game::OnRender()
{
	//printf("Hello Render");
}
