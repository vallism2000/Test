/*
 * IngredientListResultEvent.hpp
 *
 */

#ifndef INGREDIENTLISTRESULTEVENT_HPP_
#define INGREDIENTLISTRESULTEVENT_HPP_

#include "IEvent.hpp"
#include "drinkObjects/DrinkIngredient.hpp"
#include <vector>

class IngredientListResultEvent: public IEvent {
public:
	IngredientListResultEvent(bool isShoppingList, const std::vector<DrinkIngredient> * ingredients);
	virtual ~IngredientListResultEvent();

	bool IsShoppingList;
	const std::vector<DrinkIngredient> * Ingredients;
};

#endif /* INGREDIENTLISTRESULTEVENT_HPP_ */
