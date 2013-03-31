/*
 * RemoveRecipeEvent.cpp
 *
 */

#include "RemoveRecipeEvent.hpp"

RemoveRecipeEvent::RemoveRecipeEvent(int recipeID)
 : IEvent(RECIPEREMOVE),
   RecipeID(recipeID)
{
}

RemoveRecipeEvent::~RemoveRecipeEvent()
{
}

