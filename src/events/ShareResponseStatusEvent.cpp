/*
 * ShareResponseStatusEvent.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#include "ShareResponseStatusEvent.hpp"

ShareResponseStatusEvent::ShareResponseStatusEvent(Status status) : IEvent(SHARERESPONSESTATUS){
	m_status = status;
}

ShareResponseStatusEvent::~ShareResponseStatusEvent(){

}

ShareResponseStatusEvent::Status ShareResponseStatusEvent::GetStatus(){

	return m_status;
}

