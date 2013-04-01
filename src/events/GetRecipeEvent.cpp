/*
 * GetRecipeEvent.cpp
 *
 */

#include "GetRecipeEvent.hpp"

GetRecipeEvent::GetRecipeEvent(int recipeId)
 : IEvent(RECIPEREQUEST),
   RecipeID(recipeId)
{
}

GetRecipeEvent::~GetRecipeEvent()
{
}

