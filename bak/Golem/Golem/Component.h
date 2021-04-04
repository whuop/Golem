#pragma once

namespace Golem::ECS
{
	class Component
	{
	public:
		virtual void Create() {};
		virtual void Update() {};
		virtual void Destroy() {};
	private:

	};
}

