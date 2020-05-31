#include "Game.h"
#include <stdio.h>


Game::Game(int windowPosX, int windowPosY, int windowWidth, int windowHeight):
	Application(windowPosX, windowPosY, windowWidth, windowHeight)
{
}

void Game::OnInitialize()
{
	printf("Hello Initialize");
}

void Game::OnUpdate()
{
	printf("Hello Update");
}

void Game::OnRender()
{
	printf("Hello Render");
}
