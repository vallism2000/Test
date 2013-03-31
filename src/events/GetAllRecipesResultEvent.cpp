/*
 * GetAllRecipesResultEvent.cpp
 *
 */

#include "GetAllRecipesResultEvent.hpp"

GetAllRecipesResultEvent::GetAllRecipesResultEvent(const RecipeIdNameList * allRecipes)
 : IEvent(RECIPELISTRESULT),
   AllRecipeList(allRecipes)
{
}

GetAllRecipesResultEvent::~GetAllRecipesResultEvent()
{
}

