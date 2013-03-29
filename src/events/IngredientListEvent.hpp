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
private:
	int m_ingredientID;
	bool m_isShoppingList; //Alternative is inventory
	bool m_isAddEvent; //Alternative is remove
};

#endif /* INGREDIENTLISTEVENT_HPP_ */
