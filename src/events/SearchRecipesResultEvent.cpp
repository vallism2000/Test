/*
 * SearchRecipesResultEvent.cpp
 *
 */

#include "SearchRecipesResultEvent.hpp"

SearchRecipesResultEvent::SearchRecipesResultEvent(const RecipeList * results)
 : IEvent(RECIPESEARCHRESULT),
   Results(results)
{
}

SearchRecipesResultEvent::~SearchRecipesResultEvent()
{
}

