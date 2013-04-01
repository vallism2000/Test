/*
 * GetAllRecipesResultEvent.hpp
 *
 */

#ifndef GETALLRECIPESRESULTEVENT_HPP_
#define GETALLRECIPESRESULTEVENT_HPP_

#include "IEvent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"

class GetAllRecipesResultEvent: public IEvent {
public:
	GetAllRecipesResultEvent(const RecipeList * allRecipes);
	virtual ~GetAllRecipesResultEvent();

	//Event doesn't take control of this. It should NOT delete the contents. Just the pointer.
	const RecipeList * AllRecipeList;
};

#endif /* GETALLRECIPESRESULTEVENT_HPP_ */
