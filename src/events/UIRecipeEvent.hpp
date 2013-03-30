
/*
 * 	UIRecipeEvent
 * 	Sent by the UI when it requires information on a specific recipe
 * 	Contains the recipe ID integer
 */

#ifndef UIRECIPEEVENT_HPP_
#define UIRECIPEEVENT_HPP_

#include "IEvent.hpp"

class UIRecipeEvent : public IEvent {

public:
	UIRecipeEvent(int id);
	int GetID();
private:
	int m_id;
};

#endif /* UIRECIPEEVENT_HPP_ */
