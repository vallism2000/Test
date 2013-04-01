/*
 * SearchRecipesResultEvent.hpp
 *
 */

#ifndef SEARCHRECIPESRESULTEVENT_HPP_
#define SEARCHRECIPESRESULTEVENT_HPP_

#include "IEvent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"

class SearchRecipesResultEvent: public IEvent {
public:
	SearchRecipesResultEvent(const RecipeList * results);
	virtual ~SearchRecipesResultEvent();

	const RecipeList * Results;
};

#endif /* SEARCHRECIPESRESULTEVENT_HPP_ */
