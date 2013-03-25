/*
 * IEvent.cpp
 *
 */

#include "IEvent.hpp"

IEvent::IEvent(std::string type)
{
	m_type = type;
}

IEvent::~IEvent()
{
}

const std::string & IEvent::GetType()
{
	return m_type;
}


