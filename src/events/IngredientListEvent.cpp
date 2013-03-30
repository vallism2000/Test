/*
 * IngredientAddEvent.cpp
 *
 */

#include "IngredientListEvent.hpp"

IngredientListEvent::IngredientListEvent(int ingredientId, bool isShoppingList, bool isAddEvent)
: IEvent( INGREDIENTLIST),
  IngredientID(ingredientId),
  IsShoppingList(isShoppingList),
  IsAddEvent(isAddEvent)
{
}

IngredientListEvent::~IngredientListEvent()
{
}

