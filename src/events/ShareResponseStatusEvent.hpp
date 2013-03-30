/*
 * ShareResponseStatusEvent.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef SHARERESPONSESTATUSEVENT_HPP_
#define SHARERESPONSESTATUSEVENT_HPP_

#include "IEvent.hpp"

class ShareResponseStatusEvent: public IEvent{

public:
	ShareResponseStatusEvent(std::string status);
	virtual ~ShareResponseStatusEvent();
	std::string GetStatus();

private:
	std::string m_status;

};


#endif /* SHARERESPONSESTATUSEVENT_HPP_ */
