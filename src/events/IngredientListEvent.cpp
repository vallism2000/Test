/*
 * IngredientAddEvent.cpp
 *
 */

#include "IngredientListEvent.hpp"

IngredientListEvent::IngredientListEvent(int ingredientId, bool isShoppingList, bool isAddEvent)
: IEvent( INGREDIENTLIST),
  m_ingredientID(ingredientId),
  m_isShoppingList(isShoppingList),
  m_isAddEvent(isAddEvent)
{
}

IngredientListEvent::~IngredientListEvent()
{
}

