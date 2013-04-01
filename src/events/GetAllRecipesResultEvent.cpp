/*
 * GetAllRecipesResultEvent.cpp
 *
 */

#include "GetAllRecipesResultEvent.hpp"

GetAllRecipesResultEvent::GetAllRecipesResultEvent(const RecipeList * allRecipes)
 : IEvent(RECIPELISTRESULT),
   AllRecipeList(allRecipes)
{
}

GetAllRecipesResultEvent::~GetAllRecipesResultEvent()
{
}

