#pragma once

#include "Application.h"

namespace Golem::Graphics
{
	class Mesh;
	class Material;
}


class Game : public Golem::Application
{
public:
	Game(int windowPosX, int windowPosY, int windowWidth, int windowHeight);

	void OnInitialize() override;
	void OnUpdate() override;
	void OnRender() override;

private:

	Golem::Graphics::Mesh* m_mesh;
	Golem::Graphics::Material* m_material;
};

