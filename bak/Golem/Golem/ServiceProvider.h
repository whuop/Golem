#pragma once
#include "IService.h"
#include <map>
#include <typeinfo>

namespace Golem::Core
{
	class ServiceProvider
	{
	public:

		template <typename T>
		inline static void RegisterService(Golem::Core::IService* service)
		{
			size_t serviceHash = typeid(T).hash_code();
			if (m_services.find(serviceHash) == m_services.end())
			{
				m_services.insert({serviceHash, service});
			}
			else
			{
				printf("[ServiceProvider] Could not add service %s, service already added!", typeid(T).name());
			}
		}

		template <typename T>
		static void UnregisterService()
		{
			size_t serviceHash = typeid(T).hash_code();
			if (m_services.find(serviceHash) == m_services.end())
			{
				printf("[ServiceProvider] Could not unregister service %s, service hasn't been registered!", typeid(T).name());
			}
			else
			{
				m_services.erase(serviceHash);
			}
		}

		template <typename T>
		static bool HasService()
		{
			size_t serviceHash = typeid(T).hash_code();
			if (m_services.find(serviceHash) == m_services.end())
				return false;
			return true;
		}

		template <typename T>
		static T& GetService()
		{
			size_t serviceHash = typeid(T).hash_code();
			T* service = static_cast<T*>(m_services[serviceHash]);
			return *service;
		}

	private:
		static std::map<size_t, Golem::Core::IService*> m_services;
	};

	std::map<size_t, Golem::Core::IService*> ServiceProvider::m_services;
}


