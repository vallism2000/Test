/*
 * DrinkIngredient.cpp
 *
 */

#include "DrinkIngredient.hpp"


DrinkIngredient::DrinkIngredient(int id, const std::string & name, const std::string & amount)
{
	m_name = name;
	m_ingredientID = id;
	m_amount = amount;
}

DrinkIngredient::~DrinkIngredient()
{
}

const std::string & DrinkIngredient::GetName()
{
	return m_name;
}

int DrinkIngredient::GetID()
{
	return m_ingredientID;
}

const std::string & DrinkIngredient::GetAmount()
{
	return m_amount;
}
