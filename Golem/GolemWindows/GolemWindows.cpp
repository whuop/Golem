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
	app->Run();
	delete app;
	return 0;
}