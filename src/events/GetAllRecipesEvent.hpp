/*
 * GetAllRecipesEvent.hpp
 *
 */

#ifndef GETALLRECIPESEVENT_HPP_
#define GETALLRECIPESEVENT_HPP_

#include "IEvent.hpp"

class GetAllRecipesEvent: public IEvent {
public:
	GetAllRecipesEvent();
	virtual ~GetAllRecipesEvent();
};

#endif /* GETALLRECIPESEVENT_HPP_ */
