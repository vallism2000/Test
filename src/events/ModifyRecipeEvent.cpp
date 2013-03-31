/*
 * ModifyRecipeEvent.cpp
 *
 */

#include "ModifyRecipeEvent.hpp"

ModifyRecipeEvent::ModifyRecipeEvent(int recipeID, int rating, const std::string & name, const std::string & desc, const std::string & instructions)
 : IEvent(RECIPEMODIFY),
   RecipeID(recipeID),
   Rating(rating),
   Name(name),
   Description(desc),
   Instructions(instructions)
{
}

ModifyRecipeEvent::~ModifyRecipeEvent()
{
	m_ingredients.clear();
}

void ModifyRecipeEvent::AddIngredient(const std::string & name, const std::string & amount)
{
	m_ingredients.push_back(std::pair<std::string, std::string>(name, amount));
}

const std::vector<std::pair<std::string,std::string> > & ModifyRecipeEvent::GetIngredientsList()
{
	return m_ingredients;
}
