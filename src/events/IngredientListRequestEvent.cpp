/*
 * IngredientListRequestEvent.cpp
 *
 */

#include "IngredientListRequestEvent.hpp"

IngredientListRequestEvent::IngredientListRequestEvent(bool isShoppingList)
 : IEvent(INGREDIENTLISTREQUEST),
   IsShoppingList(isShoppingList)
{
}

IngredientListRequestEvent::~IngredientListRequestEvent()
{
}

