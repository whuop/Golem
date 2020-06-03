#include "Game.h"
#include <stdio.h>

#include "Mesh.h"
#include "Material.h"
#include "Vector3f.h"
#include "Vector2i.h"
#include "VertexLayouts.h"

#include <bx/math.h>
#include <bx/bx.h>

using namespace Golem::Graphics;
using namespace Golem::Math;
using namespace Golem::Core;

Game::Game():
	Application("Golem Windows", Vector2i(500, 500), Vector2i(1024, 768))
{
}

void Game::OnInitialize()
{
	PositionVertex::Init();
	ColorVertex::Init();

	m_mesh = new Mesh();
	std::vector<Vector3f> vertices = {
		{-1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{-1.0f, -1.0f,  1.0f},
		{ 1.0f, -1.0f,  1.0f},
		{-1.0f,  1.0f, -1.0f},
		{ 1.0f,  1.0f, -1.0f},
		{-1.0f, -1.0f, -1.0f},
		{ 1.0f, -1.0f, -1.0f}
	};

	std::vector<Color> colors = {
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1}
	};

	std::vector<uint16_t> indices = { 
		0, 1, 2, // 0
		1, 3, 2,
		4, 6, 5, // 2
		5, 6, 7,
		0, 2, 4, // 4
		4, 2, 6,
		1, 5, 3, // 6
		5, 7, 3,
		0, 4, 1, // 8
		4, 5, 1,
		2, 3, 6, // 10
		6, 3, 7
	};

	m_mesh->AddVertices(vertices);
	m_mesh->AddColors(colors);
	m_mesh->AddIndices(indices);

	m_mesh->ConstructMesh();

	m_material = new Material("../assets/shaders/v_simple.bin", "../assets/shaders/f_simple.bin");
	m_mesh->SetMaterial(m_material);
}

void Game::OnUpdate()
{
}

void Game::OnRender()
{
	bx::Vec3 at = bx::Vec3(0.0f, 0.0f, 0.0f);
	bx::Vec3 eye = bx::Vec3(0.0f, 0.0f, -35.0f);

	//	Set view and projection matrix for view 0
	{
		float view[16];
		bx::mtxLookAt(view, eye, at);
		

		float proj[16];
		bx::mtxProj(proj, 60.0f, float(640) / float(480), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
		bgfx::setViewTransform(0, view, proj);

		// Set view 0 default viewport
		//bgfx::setViewRect(0, 0, 0, uint16_t(640), uint16_t(480));
	}

	uint64_t state = 0
		| BGFX_STATE_WRITE_R
		| BGFX_STATE_WRITE_G 
		| BGFX_STATE_WRITE_B
		| BGFX_STATE_WRITE_A
		| BGFX_STATE_WRITE_Z
		| BGFX_STATE_DEPTH_TEST_LESS
		| BGFX_STATE_CULL_CW
		| BGFX_STATE_MSAA
		| UINT64_C(0)
		;

	float time = m_timer.elapsed();

	//	Submit cubes
	for (uint32_t yy = 0; yy < 11; ++yy)
	{
		for (uint32_t xx = 0; xx < 11; ++xx)
		{
			float mtx[16];
			bx::mtxRotateXY(mtx, time + xx * 0.21f, time + yy * 0.37f);
			mtx[12] = -15.0f + float(xx) * 3.0f;
			mtx[13] = -15.0f + float(yy) * 3.0f;
			mtx[14] = 0.0f;

			m_mesh->Render(state, mtx);
			m_material->Submit();
		}
	}
}

void Game::OnWindowResized(const Golem::Math::Vector2i& size)
{
	printf("Window Resized: %i/%i", size.X, size.Y);
}

void Game::OnWindowMoved(const Golem::Math::Vector2i& position)
{
	printf("Window Moved: %i/%i", position.X, position.Y);
}
