// GolemWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#undef main
#include <iostream>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/bx.h>

#include "Application.h"

#include "Mesh.h"
#include "Material.h"

#include "Game.h"

using namespace Golem;
using namespace Golem::Graphics;
using namespace Golem::Math;


int main()
{
	Game* app = new Game(200, 200, 640, 480);
	
	/*Mesh* mesh = new Mesh();
	mesh->AddVertex(Vector3f(-1.0f, 1.0f, 1.0f));
	mesh->AddVertex(Vector3f(1.0f, 1.0f, 1.0f));
	mesh->AddVertex(Vector3f(-1.0f, -1.0f, 1.0f));
	mesh->AddVertex(Vector3f(1.0f, -1.0f, 1.0f));
	mesh->AddVertex(Vector3f(-1.0f, 1.0f, -1.0f));
	mesh->AddVertex(Vector3f(1.0f, 1.0f, -1.0f));
	mesh->AddVertex(Vector3f(-1.0f, -1.0f, -1.0f));
	mesh->AddVertex(Vector3f(1.0f, -1.0f, -1.0f));

	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));
	mesh->AddColor(Color(1, 0, 0, 1));

	mesh->AddIndex(0);
	mesh->AddIndex(1);
	mesh->AddIndex(2);

	mesh->AddIndex(1);
	mesh->AddIndex(3);
	mesh->AddIndex(2);

	mesh->AddIndex(4);
	mesh->AddIndex(6);
	mesh->AddIndex(5);

	mesh->AddIndex(5);
	mesh->AddIndex(6);
	mesh->AddIndex(7);

	mesh->AddIndex(0);
	mesh->AddIndex(2);
	mesh->AddIndex(4);

	mesh->AddIndex(4);
	mesh->AddIndex(2);
	mesh->AddIndex(6);

	mesh->AddIndex(1);
	mesh->AddIndex(5);
	mesh->AddIndex(3);

	mesh->AddIndex(5);
	mesh->AddIndex(7);
	mesh->AddIndex(3);

	mesh->AddIndex(0);
	mesh->AddIndex(4);
	mesh->AddIndex(1);

	mesh->AddIndex(4);
	mesh->AddIndex(5);
	mesh->AddIndex(1);

	mesh->AddIndex(2);
	mesh->AddIndex(3);
	mesh->AddIndex(6);

	mesh->AddIndex(6);
	mesh->AddIndex(3);
	mesh->AddIndex(7);

	mesh->ConstructMesh();

	Material* material = new Material("../assets/shaders/v_simple.bin", "../assets/shaders/f_simple.bin");
	mesh->SetMaterial(material);*/
	
	app->Run();
	delete app;
	return 0;
}