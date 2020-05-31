#pragma once

#include "Application.h"

class Game : public Golem::Application
{
public:
	Game(int windowPosX, int windowPosY, int windowWidth, int windowHeight);

	void OnInitialize() override;
	void OnUpdate() override;
	void OnRender() override;

private:
};

