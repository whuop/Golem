#pragma once
#include "IEntityService.h"
#include <vector>

namespace Golem::ECS
{
	class Entity;
	class EntityService : public IEntityService
	{
	public:
		Entity* CreateEntity(const char* name);
		void DestroyEntity(Entity* entity);
	private:
		std::vector<Entity*> m_entities;
	};
}



