/*
 * ShareResponseStatusEvent.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#include "ShareResponseStatusEvent.hpp"

ShareResponseStatusEvent::ShareResponseStatusEvent(std::string type, std::string status) : IEvent(type){
	m_type = type;
	m_status = status;
}

ShareResponseStatusEvent::~ShareResponseStatusEvent(){

}

std::string ShareResponseStatusEvent::GetStatus(){

	return m_status;
}

