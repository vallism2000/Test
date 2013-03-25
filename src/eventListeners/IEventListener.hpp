/*
 * IEventListener.hpp
 *
 */

#ifndef IEVENTLISTENER_HPP_
#define IEVENTLISTENER_HPP_

#include "events/IEvent.hpp"

class IEventListener {
public:
	IEventListener();
	virtual ~IEventListener();

	//Will determine if the event is one that it cares about,
	// and act on it if it is.
	virtual void ActOnEvent(IEvent * e) = 0;

};

#endif /* IEVENTLISTENER_HPP_ */
