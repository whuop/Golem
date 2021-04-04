#pragma once

namespace Golem::ECS
{
	class Entity
	{
	public:
		Entity(const char* name);
		~Entity();
	private:
		const char* m_name;
	};
}



