#pragma once

namespace Golem::ECS
{
	class Component
	{
	public:
		virtual void Create() = 0;
		virtual void Update() = 0;
		virtual void Destroy() = 0;
	private:

	};
}

