/*
 * CoreEventBus.cpp
 *
 */

#include "CoreEventBus.hpp"
#include <iostream>

CoreEventBus::CoreEventBus()
{
	m_eventListeners = std::vector<IEventListener *>();

}

CoreEventBus::~CoreEventBus()
{
	m_eventListeners.clear();
}

CoreEventBus * CoreEventBus::s_Instance;

void CoreEventBus::Initialize()
{
	if(CoreEventBus::s_Instance == NULL)
	{
		CoreEventBus::s_Instance = new CoreEventBus();
	}
}


//Note that the core event bus does not take ownership over registered listeners
void CoreEventBus::RegisterListener(IEventListener * el)
{
	s_Instance->m_eventListeners.push_back(el);
	std::cout << "Registered a listener" << std::endl;
}

void CoreEventBus::UnRegisterListener(IEventListener * el)
{
	for(unsigned int i = 0; i < s_Instance->m_eventListeners.size(); i++)
	{
		if(s_Instance->m_eventListeners.at(i) == el)
		{
			s_Instance->m_eventListeners.erase(s_Instance->m_eventListeners.begin() + i);
			break;
			std::cout << "Removed a listener" << std::endl;
		}
	}
}

void CoreEventBus::FireEvent(IEvent * e)
{
	if(e == NULL)
	{
		std::cout << "Null event ignored." << std::endl;
		return;
	}

	std::cout << "Firing event  on " << s_Instance->m_eventListeners.size() << " listeners." << std::endl;
	for(unsigned int i = 0; i < s_Instance->m_eventListeners.size(); i++)
	{
		s_Instance->m_eventListeners.at(i)->ActOnEvent(e);
	}
}
