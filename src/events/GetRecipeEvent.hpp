/*
 * GetRecipeEvent.hpp
 *
 */

#ifndef GETRECIPEEVENT_HPP_
#define GETRECIPEEVENT_HPP_

#include "IEvent.hpp"

class GetRecipeEvent: public IEvent {
public:
	GetRecipeEvent(int recipeId);
	virtual ~GetRecipeEvent();

	int RecipeID;
};

#endif /* GETRECIPEEVENT_HPP_ */
