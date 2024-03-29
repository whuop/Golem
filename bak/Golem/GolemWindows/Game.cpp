#include "Game.h"
#include <stdio.h>

#include "Mesh.h"
#include "Material.h"
#include "Math/Vector3f.h"
#include "Math/Vector2i.h"
#include "VertexLayouts.h"

#include <AssImpImporter.h>
#include <SDL_events.h>


#include "ServiceProvider.h"
#include "IEntityService.h"
#include "EntityService.h"
#include "Window.h"

#include "imgui/imgui.h"

using namespace Golem::Graphics;
using namespace Golem::Math;
using namespace Golem::Core;
using namespace Golem::ECS;


Game::Game():
	Application("Golem Windows", Vector2i(500, 500), Vector2i(1024, 768))
{
}

Game::~Game()
{
	imguiDestroy();
}

void Game::OnInitialize()
{
	ServiceProvider::RegisterService<IEntityService>(new Golem::ECS::EntityService());

	printf("Has EntityService: %s\n", ServiceProvider::HasService<IEntityService>() ? "true" : "false");

	IEntityService& entityService = ServiceProvider::GetService<IEntityService>();
	printf("EntityService: %zu\n", typeid(entityService).hash_code());

	ServiceProvider::UnregisterService<IEntityService>();
	printf("Has EntityService: %s\n", ServiceProvider::HasService<IEntityService>() ? "true" : "false");

	PositionVertex::Init();
	ColorVertex::Init();

	m_cubeMesh = new Mesh();
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

	/*std::vector<PositionColorVertex> cubeVertices[] =
	{
		{-1.0f,  1.0f,  1.0f, 0xff000000 },
		{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
		{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
		{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
		{-1.0f,  1.0f, -1.0f, 0xffff0000 },
		{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
		{-1.0f, -1.0f, -1.0f, 0xffffff00 },
		{ 1.0f, -1.0f, -1.0f, 0xffffffff },
	};*/

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

	m_cubeMesh->AddVertices(vertices);
	m_cubeMesh->AddColors(colors);
	m_cubeMesh->AddIndices(indices);

	m_cubeMesh->ConstructMesh();

	m_cubeMaterial = new Material("../assets/shaders/v_simple.bin", "../assets/shaders/f_simple.bin");
	m_cubeMesh->SetMaterial(m_cubeMaterial);

	m_rabbitMaterial = new Material("../assets/shaders/simple_lit.vert.bin", "../assets/shaders/simple_lit.frag.bin");
	
	Golem::Graphics::Importers::AssImpImporter importer;
	m_rabbitMesh = importer.LoadMesh("../assets/meshes/fruit-juice.fbx");
	m_rabbitMesh->ConstructMesh();
	m_rabbitMesh->SetMaterial(m_rabbitMaterial);

	//	Set up rendering transforms
	Vector3f eyePos(0.0f, 0.0f, -35.0f);
	Vector3f lookAtPos(0.0f, 0.0f, 0.0f);
	//bx::Vec3 at = bx::Vec3(0.0f, 0.0f, 0.0f);
	//bx::Vec3 eye = bx::Vec3(0.0f, 0.0f, -35.0f);

	m_view.LookAt(eyePos, lookAtPos);
	//float view[16];
	//bx::mtxLookAt(view, eye, at);

	m_projection.Projection(60.0f, float(640) / float(480), 0.1f, 100.0f);
	//float proj[16];
	//bx::mtxProj(proj, 60.0f, float(640) / float(480), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);
	bgfx::setViewTransform(0, m_view.Data, m_projection.Data);

	imguiCreate();
}

void Game::OnUpdate()
{
}

void Game::OnRender()
{
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
	uint8_t button = m_mouse.LeftButton ? 1 : m_mouse.RightButton ? 2 : 0;
	imguiBeginFrame(m_mouse.Position.X, m_mouse.Position.Y, button, 0, m_window->GetWindowSize().X, m_window->GetWindowSize().Y);

	bool open = true;
	if (!ImGui::Begin("About Dear Imgui", &open, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::End();
	}
	else
	{
		ImGui::Text("Dear ImGUI %s", ImGui::GetVersion());
		ImGui::End();
	}
	
	imguiEndFrame();

	printf("Time: %f\n", time);
	
	//	Submit cubes
	for (uint32_t yy = 0; yy < 11; ++yy)
	{
		for (uint32_t xx = 0; xx < 11; ++xx)
		{
			m_modelTransform.SetToIdentity();
			m_modelTransform.RotateY(/*time + float(xx) * 0.21f, */time + float(yy) * 0.37f);
			m_modelTransform.Translate(-15.0f + float(xx) * 3.0f,
				-15.0f + float(yy) * 3.0f,
				0.0f);
			
			/*float mtx[16];
			bx::mtxRotateXY(mtx, time + xx * 0.21f, time + yy * 0.37f);
			mtx[12] = -15.0f + float(xx) * 3.0f;
			mtx[13] = -15.0f + float(yy) * 3.0f;
			mtx[14] = 0.0f;*/

			m_cubeMesh->Render(state, m_modelTransform);
			m_cubeMaterial->Submit();
		}
	}

	//float mtx[16];
	//bx::mtxRotateXY(mtx, time + 0.21f, time + 0.37f);
	//mtx[12] = 0.0f;
	//mtx[13] = 0.0f;
	//mtx[14] = 0.0f;
	
	//m_rabbitMesh->Render(state, mtx);
	//m_rabbitMaterial->Submit();
}

void Game::OnWindowResized(const Golem::Math::Vector2i& size)
{
	printf("Window Resized: %i/%i", size.X, size.Y);
}

void Game::OnWindowMoved(const Golem::Math::Vector2i& position)
{
	printf("Window Moved: %i/%i", position.X, position.Y);
}
