/*
 * IngredientAddEvent.cpp
 *
 */

#include "IngredientListEvent.hpp"

IngredientListEvent::IngredientListEvent(int ingredientId, const std::string & ingredientName, bool isShoppingList, bool isAddEvent)
: IEvent( INGREDIENTLIST),
  IngredientID(ingredientId),
  IngredientName(ingredientName),
  IsShoppingList(isShoppingList),
  IsAddEvent(isAddEvent)
{
}

IngredientListEvent::~IngredientListEvent()
{
}

