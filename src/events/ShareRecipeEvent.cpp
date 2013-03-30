/*
 * ShareRecipeEvent.cpp
 *
 */

#include "ShareRecipeEvent.hpp"
#include <iostream>

ShareRecipeEvent::ShareRecipeEvent(EventType type, DrinkRecipe *recipe) : IEvent(type){
	m_recipe = recipe;

	std::cout << "ShareRecipeEvent created" << std::endl;
}

ShareRecipeEvent::~ShareRecipeEvent(){

}

DrinkRecipe *ShareRecipeEvent::GetRecipe(){
	return m_recipe;
}
