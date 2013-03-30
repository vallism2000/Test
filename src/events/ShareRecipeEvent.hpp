/*
 * ShareRecipeEvent.hpp
 *
 */

#ifndef SHARERECIPEEVENT_HPP_
#define SHARERECIPEEVENT_HPP_

#include "IEvent.hpp"
#include <string>
#include <iostream>
#include "drinkObjects/DrinkRecipe.hpp"

class ShareRecipeEvent: public IEvent{

public:
	ShareRecipeEvent(EventType type, DrinkRecipe *recipe);
	virtual ~ShareRecipeEvent();
	DrinkRecipe* GetRecipe();


private:
	DrinkRecipe *m_recipe;

};

#endif /* SHARERECIPEEVENT_HPP_ */
