// GolemWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#undef main
#include <iostream>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bx/bx.h>

#include "Window.h"
#include "Renderer.h"

using namespace Golem::Core;

int main()
{
	Window* window = new Window(100, 100, 640, 480);
	Renderer* renderer = new Renderer(window);

	window->Run();

	delete renderer;
	renderer = nullptr;
	delete window;
	window = nullptr;
	return 0;
}