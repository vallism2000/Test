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
	static CoreEventBus GetInstance();

	void RegisterListener(IEventListener * el);
	void UnRegisterListener(IEventListener * el);
	void FireEvent(IEvent * e);

private:
	static CoreEventBus * s_Instance;
	std::vector<IEventListener *> m_eventListeners;

	//Private constructor to enforce singleton
	CoreEventBus();

};

#endif /* COREEVENTBUS_H_ */
