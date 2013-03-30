
/*
 * 	UIShareEvent
 * 	Sent by the UI when the user wants to share a recipe
 */

#ifndef UISHAREEVENT_HPP_
#define UISHAREEVENT_HPP_

#include "IEvent.hpp"

class UIShareEvent : public IEvent {

public:
	UIShareEvent(int id);
	int GetID();
private:
	int m_id;
};

#endif /* UISHAREEVENT_HPP_ */
