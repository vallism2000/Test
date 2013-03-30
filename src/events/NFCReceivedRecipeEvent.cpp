/*
 * NFCReceivedRecipeEvent.cpp
 *
 */

#include "NFCReceivedRecipeEvent.hpp"

NFCReceivedRecipeEvent::NFCReceivedRecipeEvent(DrinkRecipe* recipe) : IEvent(NFCRECEIVEDRECIPE){
	m_recipe = recipe;
}

NFCReceivedRecipeEvent::~NFCReceivedRecipeEvent(){

}

DrinkRecipe* NFCReceivedRecipeEvent::GetRecipe(){
	return m_recipe;
}


