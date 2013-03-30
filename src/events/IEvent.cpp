/*
 * IEvent.cpp
 *
 */

#include "IEvent.hpp"

IEvent::IEvent(EventType type)
{
	m_type = type;
}

IEvent::~IEvent()
{
}

IEvent::EventType IEvent::GetType()
{
	return m_type;
}


