// GolemWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#undef main
#include <iostream>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/bx.h>

#include "Application.h"

using namespace Golem;

int main()
{
	Application* app = new Application(640, 480);
	app->Run();
	delete app;
	return 0;
}