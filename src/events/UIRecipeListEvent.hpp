
/*
 * 	UIRecipeListEvent
 * 	Sent by the UI when it needs the Name and ID of recipes for the list
 * 	Contains search information entered by user
 */

#ifndef UIRECIPELISTEVENT_HPP_
#define UIRECIPELISTEVENT_HPP_

#include "IEvent.hpp"

class UIRecipeListEvent : public IEvent {

public:
	UIRecipeListEvent();
private:
	//
};

#endif /* UIRECIPELISTEVENT_HPP_ */
