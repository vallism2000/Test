/*
 * RemoveRecipeEvent.hpp
 *
 */

#ifndef REMOVERECIPEEVENT_HPP_
#define REMOVERECIPEEVENT_HPP_

#include "IEvent.hpp"

class RemoveRecipeEvent: public IEvent {
public:
	RemoveRecipeEvent(int recipeID);
	virtual ~RemoveRecipeEvent();

	int RecipeID;
};

#endif /* REMOVERECIPEEVENT_HPP_ */
