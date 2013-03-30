/*
 * IngredientListResultEvent.cpp
 *
 */

#include "IngredientListResultEvent.hpp"

IngredientListResultEvent::IngredientListResultEvent(bool isShoppingList, const std::vector<DrinkIngredient> * ingredients)
 : IEvent(INGREDIENTLISTRESULT),
   IsShoppingList(isShoppingList),
   Ingredients(ingredients)
{
}

IngredientListResultEvent::~IngredientListResultEvent()
{
}

