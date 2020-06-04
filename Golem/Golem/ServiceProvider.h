#pragma once
#include "IService.h"
#include <map>
#include <typeinfo>

namespace Golem::Core
{
	class ServiceProvider
	{
	public:

		void RegisterService(Golem::Core::IService* service);
		void UnregisterService(Golem::Core::IService* service);

		Golem::Core::IService& GetService() const;

	private:
		std::map<size_t, Golem::Core::IService*> m_services;
	};
}


