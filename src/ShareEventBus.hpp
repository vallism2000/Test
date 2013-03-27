/*
 * ShareEventBus.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef SHAREEVENTBUS_HPP_
#define SHAREEVENTBUS_HPP_

#include "eventListeners/IEventListener.hpp"
#include "events/IEvent.hpp"
#include <vector>

class ShareEventBus{
public:
	virtual ~ShareEventBus();
	static ShareEventBus GetInstance();

	void RegisterListener(IEventListener * el);
	void UnRegisterListener(IEventListener * el);
	void FireEvent(IEvent *e);
	void debugDump();

private:
	static ShareEventBus * s_ShareInstance;
	std::vector<IEventListener *> m_shareEventListeners;

	//Private constructor to enforce singleton
	ShareEventBus();

};



#endif /* SHAREEVENTBUS_HPP_ */
