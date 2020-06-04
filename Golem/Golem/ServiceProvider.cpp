#include "ServiceProvider.h"

using namespace Golem::Core;

void ServiceProvider::RegisterService(IService* service)
{
	auto hash = typeid(service).hash_code();
	if (m_services.contains(hash))
	{
		printf("Service of type %s has already been added to the service provider.", typeid(service).name());
		return;
	}

	m_services.insert(std::pair<size_t, IService*>(hash, service));
}
