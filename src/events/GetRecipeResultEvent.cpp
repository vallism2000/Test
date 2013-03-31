/*
 * GetRecipeResultEvent.cpp
 *
 */

#include "GetRecipeResultEvent.hpp"

GetRecipeResultEvent::GetRecipeResultEvent(DrinkRecipe * recipe)
 : IEvent(RECIPERESULT),
   Recipe(recipe)
{
}

GetRecipeResultEvent::~GetRecipeResultEvent()
{
}

