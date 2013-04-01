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
	enum Status
		{
			SUCCESS,
			FAILURE
		};
	ShareResponseStatusEvent(Status status);
	virtual ~ShareResponseStatusEvent();
	Status GetStatus();

private:
	Status m_status;

};


#endif /* SHARERESPONSESTATUSEVENT_HPP_ */
