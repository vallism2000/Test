/*
 * ShareEventListener.hpp
 *
 */

#ifndef SHAREEVENTLISTENER_HPP_
#define SHAREEVENTLISTENER_HPP_

#include "eventListeners/IEventListener.hpp"

class ShareEventListener: public IEventListener{
public:
	ShareEventListener();
	virtual ~ShareEventListener();
	void ActOnEvent(IEvent *e);
};


#endif /* SHAREEVENTLISTENER_HPP_ */
