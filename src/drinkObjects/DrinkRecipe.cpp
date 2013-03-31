/*
 * DrinkRecipe.cpp
 *
 */

#include "DrinkRecipe.hpp"

DrinkRecipe::DrinkRecipe(int recipeID, int rating, std::string name, std::string desc, std::string instructions)
{
	m_recipeID = recipeID;
	 m_rating = rating;
	 m_name = name;
	 m_desc = desc;
	 m_instructions = instructions;
	 m_ingredients = std::vector<std::pair<DrinkIngredient, std::string> >();
}

DrinkRecipe::~DrinkRecipe()
{
	//Ingredients are local, so they clean themselves
}

void DrinkRecipe::AddIngredient(int ingredientID, const std::string & ingredientName, const std::string & amount)
{
	m_ingredients.push_back(std::pair<DrinkIngredient, std::string>(DrinkIngredient(ingredientID, ingredientName), amount));
}

int DrinkRecipe::GetRating() const
{
	return m_rating;
}

int DrinkRecipe::GetID() const
{
	return m_recipeID;
}

const std::string & DrinkRecipe::GetName() const
{
	return m_name;
}

const std::string & DrinkRecipe::GetDesc() const
{
	return m_desc;
}

const std::string & DrinkRecipe::GetInstructions() const
{
	return m_instructions;
}

const DrinkIngredient DrinkRecipe::GetIngredient(unsigned int index) const
{
	std::pair<DrinkIngredient, std::string> desiredPair = m_ingredients.at(index);
	return (desiredPair.first);
}

const std::string DrinkRecipe::GetIngredientAmount(unsigned int index) const
{
	std::pair<DrinkIngredient, std::string> desiredPair = m_ingredients.at(index);
	return (desiredPair.second);
}

unsigned int DrinkRecipe::GetNumIngredients() const
{
	return m_ingredients.size();
}

