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
	ShareRecipeEvent(std::string type, DrinkRecipe *recipe);
	virtual ~ShareRecipeEvent();
	DrinkRecipe* GetRecipe();


private:
	std::string m_type;
	DrinkRecipe *m_recipe;

};

#endif /* SHARERECIPEEVENT_HPP_ */
