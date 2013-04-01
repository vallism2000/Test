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
	m_lastSearchResults = new RecipeList();
	m_allRecipeList = new RecipeList();

	//Fill it with dummy data for now
	m_allRecipeList->push_back(RecipeTuple(0, "AllDrink0", true));
	m_allRecipeList->push_back(RecipeTuple(1, "AllDrink1", true));
	m_allRecipeList->push_back(RecipeTuple(2, "AllDrink2", false));
	m_allRecipeList->push_back(RecipeTuple(3, "AllDrink3", true));
	m_allRecipeList->push_back(RecipeTuple(4, "AllDrink4", true));
	m_allRecipeList->push_back(RecipeTuple(5, "AllDrink5", false));
	m_allRecipeList->push_back(RecipeTuple(6, "AllDrink6", true));
	m_allRecipeList->push_back(RecipeTuple(7, "AllDrink7", true));
	m_allRecipeList->push_back(RecipeTuple(8, "AllDrink8", false));
	m_allRecipeList->push_back(RecipeTuple(9, "AllDrink9", true));
	m_allRecipeList->push_back(RecipeTuple(10, "AllDrink10", false));
	m_allRecipeList->push_back(RecipeTuple(11, "AllDrink11", false));
	m_allRecipeList->push_back(RecipeTuple(12, "AllDrink12", true));
	m_allRecipeList->push_back(RecipeTuple(13, "AllDrink13", false));
	m_allRecipeList->push_back(RecipeTuple(14, "AllDrink14", true));
	m_allRecipeList->push_back(RecipeTuple(15, "AllDrink15", false));
	m_allRecipeList->push_back(RecipeTuple(16, "AllDrink16", true));
}

FileMgr::~FileMgr()
{
}

void FileMgr::AddToIngredientList(int ingredientID,const std::string & name, bool isShoppingList)
{
	std::cout << "FileMgr: Dummy handle for Add ingredient: " << ingredientID << name <<  " Shopping?: " << isShoppingList << std::endl;
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
const RecipeList * FileMgr::GetAllRecipes()
{
	std::cout << "FileMgr: Dummy handle for GetAllRecipes." << std::endl;
	return m_allRecipeList;

}

DrinkRecipe * FileMgr::GetRecipe(int recipeId)
{
	std::cout << "FileMgr: Dummy handle for GetRecipe." << std::endl;
	DrinkRecipe * toRet = new DrinkRecipe(recipeId, 5, "Specific Drink", "Tasty.", "Mix!");
	toRet->AddIngredient(3, "Wodka", "Tons");
	return toRet;
}

const RecipeList * FileMgr::GetSearchResults(const std::string & recipeName, const std::vector<std::string> & ingredientList, bool useAND)
{
	(void)recipeName;
	(void)ingredientList;
	(void)useAND;
	std::cout << "FileMgr: Dummy handle for GetSearchResults." << std::endl;

	m_lastSearchResults->clear();
	m_lastSearchResults->push_back(RecipeTuple(5, "Result 1", true));
	m_lastSearchResults->push_back(RecipeTuple(6, "Result 2", true));
	m_lastSearchResults->push_back(RecipeTuple(7, "Result 3", true));
	m_lastSearchResults->push_back(RecipeTuple(8, "Result 4", true));

	std::cout << "FileMgr searched correctly." << std::endl;

	return m_lastSearchResults;
}


