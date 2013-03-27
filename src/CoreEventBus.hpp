/*
 * CoreEventBus.h
 *
 */

#ifndef COREEVENTBUS_H_
#define COREEVENTBUS_H_

#include "eventListeners/IEventListener.hpp"
#include "events/IEvent.hpp"
#include <vector>

class CoreEventBus {
public:
	virtual ~CoreEventBus();
	static void Initialize();

	static void RegisterListener(IEventListener * el);
	static void UnRegisterListener(IEventListener * el);
	static void FireEvent(IEvent * e);

private:
	static CoreEventBus * s_Instance;

	//Private constructor to enforce singleton
	CoreEventBus();
	std::vector<IEventListener *> m_eventListeners;

};

#endif /* COREEVENTBUS_H_ */
