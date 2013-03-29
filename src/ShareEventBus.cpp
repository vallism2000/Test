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

void ShareEventBus::Initialize(){
	if(ShareEventBus::s_ShareInstance == NULL)
	{
		ShareEventBus::s_ShareInstance = new ShareEventBus();
	}
}

void ShareEventBus::RegisterListener(IEventListener * el){
	s_ShareInstance->m_shareEventListeners.push_back(el);
	std::cout << "size after register "<< s_ShareInstance->m_shareEventListeners.size() << std::endl;
}

void ShareEventBus::UnRegisterListener(IEventListener * el){
	for(unsigned int i = 0; i < s_ShareInstance->m_shareEventListeners.size(); i++){
		if(s_ShareInstance->m_shareEventListeners.at(i) == el){
			s_ShareInstance->m_shareEventListeners.erase(s_ShareInstance->m_shareEventListeners.begin() + i);
			break;
		}
	}
}

void ShareEventBus::FireEvent(IEvent * e){
	std::cout << "FireEvent" << std::endl;
	std::cout << s_ShareInstance->m_shareEventListeners.size() << std::endl;
	for(unsigned int i = 0; i < s_ShareInstance->m_shareEventListeners.size(); i++){
		s_ShareInstance->m_shareEventListeners.at(i)->ActOnEvent(e);
	}
}

void ShareEventBus::debugDump(){
	std::cout << s_ShareInstance->m_shareEventListeners.size() << std::endl;
}
