/*
 * ShareEventBus.hpp
 *
 */

#ifndef SHAREEVENTBUS_HPP_
#define SHAREEVENTBUS_HPP_

#include "eventListeners/IEventListener.hpp"
#include "events/IEvent.hpp"
#include <vector>

class ShareEventBus{
public:
	virtual ~ShareEventBus();
	static void Initialize();

	static void RegisterListener(IEventListener * el);
	static void UnRegisterListener(IEventListener * el);
	static void FireEvent(IEvent *e);
	static void debugDump();

private:
	static ShareEventBus * s_ShareInstance;
	std::vector<IEventListener *> m_shareEventListeners;

	//Private constructor to enforce singleton
	ShareEventBus();

};



#endif /* SHAREEVENTBUS_HPP_ */
