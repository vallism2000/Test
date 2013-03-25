/*
 * DrinkRecipe.cpp
 *
 *  Created on: Mar 17, 2013
 *      Author: Nathan
 */

#include "DrinkRecipe.hpp"

DrinkRecipe::DrinkRecipe(int rating, std::string name, std::string desc, DrinkIngredient* ingredients, int numIngredients)
{
	 m_rating = rating;
	 m_name = name;
	 m_desc = desc;
	 m_ingredients = ingredients; //This class takes ownership over the ingredients
	 m_numIngredients = numIngredients;
}

DrinkRecipe::~DrinkRecipe()
{
	delete m_ingredients;
}

int DrinkRecipe::GetRating()
{
	return m_rating;
}

const std::string & DrinkRecipe::GetName()
{
	return m_name;
}

const std::string & DrinkRecipe::GetDesc()
{
	return m_desc;
}

const DrinkIngredient & DrinkRecipe::GetDrinkIngredient(int index)
{
	return m_ingredients[index];
}

int DrinkRecipe::GetNumIngredients()
{
	return m_numIngredients;
}

