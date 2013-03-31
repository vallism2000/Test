/*
 * FileMgr.cpp
 *
 */

#include "FileMgr.hpp"
#include "drinkObjects/DrinkIngredient.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <iostream>


FileMgr::FileMgr()
{
	m_allRecipeList = new RecipeIdNameList();

	//Fill it with dummy data for now
	m_allRecipeList->push_back(RecipeIdNamePair(0, "AllDrink0"));
	m_allRecipeList->push_back(RecipeIdNamePair(1, "AllDrink1"));
	m_allRecipeList->push_back(RecipeIdNamePair(2, "AllDrink2"));
	m_allRecipeList->push_back(RecipeIdNamePair(3, "AllDrink3"));
	m_allRecipeList->push_back(RecipeIdNamePair(4, "AllDrink4"));
	m_allRecipeList->push_back(RecipeIdNamePair(5, "AllDrink5"));
	m_allRecipeList->push_back(RecipeIdNamePair(6, "AllDrink6"));
	m_allRecipeList->push_back(RecipeIdNamePair(7, "AllDrink7"));
	m_allRecipeList->push_back(RecipeIdNamePair(8, "AllDrink8"));
	m_allRecipeList->push_back(RecipeIdNamePair(9, "AllDrink9"));
	m_allRecipeList->push_back(RecipeIdNamePair(10, "AllDrink10"));
	m_allRecipeList->push_back(RecipeIdNamePair(11, "AllDrink11"));
	m_allRecipeList->push_back(RecipeIdNamePair(12, "AllDrink12"));
	m_allRecipeList->push_back(RecipeIdNamePair(13, "AllDrink13"));
	m_allRecipeList->push_back(RecipeIdNamePair(14, "AllDrink14"));
	m_allRecipeList->push_back(RecipeIdNamePair(15, "AllDrink15"));
	m_allRecipeList->push_back(RecipeIdNamePair(16, "AllDrink16"));
}

FileMgr::~FileMgr()
{
}

void FileMgr::AddToIngredientList(int ingredientID, bool isShoppingList)
{
	std::cout << "FileMgr: Dummy handle for Add ingredient: " << ingredientID << " Shopping?: " << isShoppingList << std::endl;
}

void FileMgr::RemoveFromIngredientList(int ingredientID, bool isShoppingList)
{
	std::cout << "FileMgr: Dummy handle for Remove ingredient: " << ingredientID << " Shopping?: " << isShoppingList << std::endl;
}

std::vector<DrinkIngredient> * FileMgr::GetIngredientList(bool isShoppingList)
{
	std::cout << "FileMgr: Dummy handle for GetIngredientList: Shopping?: " << isShoppingList << std::endl;
	std::vector<DrinkIngredient> * tempIngredients = new std::vector<DrinkIngredient>();
	if(isShoppingList)
	{
		tempIngredients->push_back(DrinkIngredient(0, "TestBoozeNeed0"));
		tempIngredients->push_back(DrinkIngredient(1, "TestBoozeNeed1"));
		tempIngredients->push_back(DrinkIngredient(2, "TestBoozeNeed2"));
		tempIngredients->push_back(DrinkIngredient(3, "TestBoozeNeed3"));
		tempIngredients->push_back(DrinkIngredient(4, "TestBoozeNeed4"));
	}
	else
	{
		tempIngredients->push_back(DrinkIngredient(0, "TestBoozeHave0"));
		tempIngredients->push_back(DrinkIngredient(1, "TestBoozeHave1"));
		tempIngredients->push_back(DrinkIngredient(2, "TestBoozeHave2"));
		tempIngredients->push_back(DrinkIngredient(3, "TestBoozeHave3"));
		tempIngredients->push_back(DrinkIngredient(4, "TestBoozeHave4"));
	}
	return tempIngredients;
}

void FileMgr::AddRecipe(int rating, const std::string & name,
			const std::string & description, const std::string & instructions,
			const std::vector<std::pair<std::string, std::string> > & ingredients)
{
	std::cout << "FileMgr: Dummy handle for Add Recipe:" << rating << name << description << instructions << std::endl;
	(void)ingredients;
}

void FileMgr::ModifyRecipe(int recipeID, int rating, const std::string & name,
			const std::string & description, const std::string & instructions,
			const std::vector<std::pair<std::string, std::string> > & ingredients)
{
	std::cout << "FileMgr: Dummy handle for Modify Recipe:"  << recipeID << rating << name << description << instructions << std::endl;
	(void)ingredients;
}

void FileMgr::RemoveRecipe(int recipeID)
{
	std::cout << "FileMgr: Dummy handle for Delete Recipe:" << recipeID << std::endl;
}

//The file manager will keep an active pointer to the full list and only blow it away when things change.
const RecipeIdNameList * FileMgr::GetAllRecipes()
{
	std::cout << "FileMgr: Dummy handle for GetAllRecipes." << std::endl;
	return m_allRecipeList;

}


