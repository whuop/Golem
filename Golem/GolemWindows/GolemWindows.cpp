// GolemWindows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#undef main

#include "Game.h"

int main()
{
	Game* app = new Game();
	app->Run();
	delete app;
	return 0;
}