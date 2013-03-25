/*
 * CoreEventBus.cpp
 *
 */

#include "CoreEventBus.hpp"

CoreEventBus::CoreEventBus()
{
	m_eventListeners = std::vector<IEventListener *>();

}

CoreEventBus::~CoreEventBus()
{
	m_eventListeners.clear();
}

CoreEventBus * CoreEventBus::s_Instance;

CoreEventBus CoreEventBus::GetInstance()
{
	if(CoreEventBus::s_Instance == NULL)
	{
		CoreEventBus::s_Instance = new CoreEventBus();
	}
	return *CoreEventBus::s_Instance;
}


//Note that the core event bus does not take ownership over registered listeners
void CoreEventBus::RegisterListener(IEventListener * el)
{
	m_eventListeners.push_back(el);
}

void CoreEventBus::UnRegisterListener(IEventListener * el)
{
	for(unsigned int i = 0; i < m_eventListeners.size(); i++)
	{
		if(m_eventListeners.at(i) == el)
		{
			m_eventListeners.erase(m_eventListeners.begin() + i);
			break;
		}
	}
}

void CoreEventBus::FireEvent(IEvent * e)
{
	for(unsigned int i = 0; i < m_eventListeners.size(); i++)
	{
		m_eventListeners.at(i)->ActOnEvent(e);
	}
}
