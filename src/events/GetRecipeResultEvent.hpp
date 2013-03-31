/*
 * GetRecipeResultEvent.hpp
 *
 */

#ifndef GETRECIPERESULTEVENT_HPP_
#define GETRECIPERESULTEVENT_HPP_

#include "IEvent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"

class GetRecipeResultEvent: public IEvent {
public:
	GetRecipeResultEvent(DrinkRecipe * recipe);
	virtual ~GetRecipeResultEvent();

	DrinkRecipe * Recipe;
};

#endif /* GETRECIPERESULTEVENT_HPP_ */
