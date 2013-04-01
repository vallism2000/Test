/*
 * SearchRecipesEvent.cpp
 *
 */

#include "SearchRecipesEvent.hpp"

SearchRecipesEvent::SearchRecipesEvent(const std::string & name, const std::vector<std::string> & ingredients, bool useANDforSearch)
 : IEvent(RECIPESEARCHREQUEST),
   Name(name),
   IngredientNames(ingredients),
   UseANDForSearch(useANDforSearch)
{
}

SearchRecipesEvent::~SearchRecipesEvent()
{
}

