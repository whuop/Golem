// GolemWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#undef main

#include "Game.h"

int main()
{
	Game* app = new Game(200, 200, 640, 480);
	app->Run();
	delete app;
	return 0;
}