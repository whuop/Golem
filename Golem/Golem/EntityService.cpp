#include "EntityService.h"
#include "Entity.h"

using namespace Golem::ECS;

Entity* Golem::ECS::EntityService::CreateEntity(const char* name)
{
	Entity* entity = new Entity();
	m_entities.push_back(entity);
	return entity;
}

void Golem::ECS::EntityService::DestroyEntity(Entity* entity)
{
	for (size_t i = 0; i < m_entities.size(); i++)
	{
		if (m_entities[i] == entity)
		{
			m_entities.erase(m_entities.begin() + i);
			break;
		}
	}
	delete entity;
}
