/*
 * IngredientListRequestEvent.hpp
 *
 */

#ifndef INGREDIENTLISTREQUESTEVENT_HPP_
#define INGREDIENTLISTREQUESTEVENT_HPP_

#include "IEvent.hpp"

class IngredientListRequestEvent: public IEvent {
public:
	IngredientListRequestEvent(bool isShoppingList);
	virtual ~IngredientListRequestEvent();

	bool IsShoppingList;
};

#endif /* INGREDIENTLISTREQUESTEVENT_HPP_ */
