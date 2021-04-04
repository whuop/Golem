#pragma once
#include "IService.h"

namespace Golem::ECS
{
	class Entity;
	class IEntityService : public Golem::Core::IService
	{
	public:
		virtual Entity* CreateEntity(const char* name) = 0;
		virtual void DestroyEntity(Entity* entity) = 0;
	};
}



