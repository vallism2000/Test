/*
 * DrinkIngredient.cpp
 *
 */

#include "DrinkIngredient.hpp"


DrinkIngredient::DrinkIngredient(int id, const std::string & name)
{
	m_name = name;
	m_ingredientID = id;
}

DrinkIngredient::~DrinkIngredient()
{
}

const std::string & DrinkIngredient::GetName() const
{
	return m_name;
}

int DrinkIngredient::GetID()
{
	return m_ingredientID;
}
