/*
 * ShareEventBus.cpp
 *
 */

#include "ShareEventBus.hpp"

ShareEventBus::ShareEventBus(){
	m_eventListeners = std::vector<IEventListener *>();
}

ShareEventBus::~ShareEventBus()
{
	m_eventListeners.clear();
}

ShareEventBus * ShareEventBus::s_ShareInstance;

ShareEventBus ShareEventBus::GetInstance()
{
	if(ShareEventBus::s_ShareInstance == NULL)
	{
		ShareEventBus::s_ShareInstance = new ShareEventBus();
	}
	return *ShareEventBus::s_ShareInstance;
}

void ShareEventBus::RegisterListener(IEventListener * el)
{
	m_eventListeners.push_back(el);
}

void ShareEventBus::UnRegisterListener(IEventListener * el)
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

void ShareEventBus::FireEvent(IEvent * e)
{
	for(unsigned int i = 0; i < m_eventListeners.size(); i++)
	{
		m_eventListeners.at(i)->ActOnEvent(e);
	}
}
