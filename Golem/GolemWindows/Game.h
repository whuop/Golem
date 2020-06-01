#pragma once

#include "Application.h"

#include "Timer.h"

namespace Golem::Graphics
{
	class Mesh;
	class Material;
}


class Game : public Golem::Application
{
public:
	Game();

	void OnInitialize() override;
	void OnUpdate() override;
	void OnRender() override;

private:
	Golem::Graphics::Mesh* m_mesh;
	Golem::Graphics::Material* m_material;

	Golem::Core::Timer m_timer;
};

