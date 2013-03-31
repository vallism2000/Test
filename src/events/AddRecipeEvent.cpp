/*
 * AddRecipeEvent.cpp
 *
 */

#include "AddRecipeEvent.hpp"

AddRecipeEvent::AddRecipeEvent(int rating, const std::string & name, const std::string & desc, const std::string & instructions)
 : IEvent(RECIPEADD),
   Rating(rating),
   Name(name),
   Description(desc),
   Instructions(instructions)
{
}

AddRecipeEvent::~AddRecipeEvent()
{
	m_ingredients.clear();
}

void AddRecipeEvent::AddIngredient(const std::string & name, const std::string & amount)
{
	m_ingredients.push_back(std::pair<std::string, std::string>(name, amount));
}

const std::vector<std::pair<std::string,std::string> > & AddRecipeEvent::GetIngredientsList()
{
	return m_ingredients;
}
