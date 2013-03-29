/*
 * IngredientAddEvent.cpp
 *
 */

#include "IngredientAddEvent.hpp"

IngredientAddEvent::IngredientAddEvent(int ingredientId, bool isShoppingList)
: IEvent( INGREDIENTADD),
  m_ingredientID(ingredientId),
  m_isShoppingList(isShoppingList)
{
}

IngredientAddEvent::~IngredientAddEvent()
{
}

