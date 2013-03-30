/*
 * IngredientListEvent.hpp
 *
 */

#ifndef INGREDIENTLISTEVENT_HPP_
#define INGREDIENTLISTEVENT_HPP_

#include "IEvent.hpp"

class IngredientListEvent: public IEvent {
public:
	IngredientListEvent(int ingredientId, bool isShoppingList, bool isAddEvent);
	virtual ~IngredientListEvent();
	int IngredientID;
	bool IsShoppingList; //Alternative is inventory
	bool IsAddEvent; //Alternative is remove
};

#endif /* INGREDIENTLISTEVENT_HPP_ */
