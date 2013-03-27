/*
 * ShareEventBus.cpp
 *
 */

#include "ShareEventBus.hpp"
#include <iostream>

ShareEventBus::ShareEventBus(){
	std::cout << "Create ShareEventBus" << std::endl;
	m_shareEventListeners = std::vector<IEventListener *>();
}

ShareEventBus::~ShareEventBus(){
	m_shareEventListeners.clear();
}

ShareEventBus * ShareEventBus::s_ShareInstance;

ShareEventBus ShareEventBus::GetInstance(){
	if(ShareEventBus::s_ShareInstance == NULL)
	{
		ShareEventBus::s_ShareInstance = new ShareEventBus();
	}
	return *ShareEventBus::s_ShareInstance;
}

void ShareEventBus::RegisterListener(IEventListener * el){
	m_shareEventListeners.push_back(el);
	std::cout << "registered listener" << std::endl;
	std::cout << "size after register "<< m_shareEventListeners.size() << std::endl;
}

void ShareEventBus::UnRegisterListener(IEventListener * el){
	for(unsigned int i = 0; i < m_shareEventListeners.size(); i++){
		if(m_shareEventListeners.at(i) == el){
			m_shareEventListeners.erase(m_shareEventListeners.begin() + i);
			break;
		}
	}
}

void ShareEventBus::FireEvent(IEvent * e){
	std::cout << "FireEvent" << std::endl;
	std::cout << m_shareEventListeners.size() << std::endl;
	for(unsigned int i = 0; i < m_shareEventListeners.size(); i++){
		m_shareEventListeners.at(i)->ActOnEvent(e);
	}
}

void ShareEventBus::debugDump(){
	std::cout << m_shareEventListeners.size() << std::endl;
}
