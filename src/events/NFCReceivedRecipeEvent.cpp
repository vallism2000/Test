/*
 * NFCReceivedRecipeEvent.cpp
 *
 */

#include "NFCReceivedRecipeEvent.hpp"

NFCReceivedRecipeEvent::NFCReceivedRecipeEvent(std::string type, DrinkRecipe* recipe) : IEvent(type){
	m_type = type;
	m_recipe = recipe;
}

NFCReceivedRecipeEvent::~NFCReceivedRecipeEvent(){

}

DrinkRecipe* NFCReceivedRecipeEvent::GetRecipe(){
	return m_recipe;
}


