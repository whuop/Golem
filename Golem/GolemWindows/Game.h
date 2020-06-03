#pragma once

#include "Application.h"

#include "Timer.h"

namespace Golem::Graphics
{
	class Mesh;
	class Material;
}

namespace Golem::Math
{
	struct Vector2i;
}

class Game : public Golem::Application
{
public:
	Game();

	void OnInitialize() override;
	void OnUpdate() override;
	void OnRender() override;

protected:
	void OnWindowResized(const Golem::Math::Vector2i& size) override;
	void OnWindowMoved(const Golem::Math::Vector2i& position) override;

private:

	Golem::Graphics::Mesh* m_rabbitMesh;
	Golem::Graphics::Material* m_rabbitMaterial;

	Golem::Graphics::Mesh* m_cubeMesh;
	Golem::Graphics::Material* m_cubeMaterial;

	Golem::Core::Timer m_timer;
};

