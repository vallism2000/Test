/*
 * IngredientAddEvent.hpp
 *
 */

#ifndef INGREDIENTADDEVENT_HPP_
#define INGREDIENTADDEVENT_HPP_

#include "IEvent.hpp"

class IngredientAddEvent: public IEvent {
public:
	IngredientAddEvent(int ingredientId, bool isShoppingList);
	virtual ~IngredientAddEvent();
private:
	int m_ingredientID;
	bool m_isShoppingList;
};

#endif /* INGREDIENTADDEVENT_HPP_ */
