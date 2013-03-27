/*
 * ShareRecipeEvent.cpp
 *
 */

#include "ShareRecipeEvent.hpp"
#include <iostream>

ShareRecipeEvent::ShareRecipeEvent(std::string type, DrinkRecipe *recipe) : IEvent(type){
	m_type = type;
	m_recipe = recipe;

	std::cout << "ShareRecipeEvent created" << std::endl;
}

ShareRecipeEvent::~ShareRecipeEvent(){

}

DrinkRecipe *ShareRecipeEvent::GetRecipe(){
	return m_recipe;
}
