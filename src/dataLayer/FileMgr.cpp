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

void FileMgr::RemoveRecipe(int recipeID)
{
	std::cout << "FileMgr: Dummy handle for Delete Recipe:" << recipeID << std::endl;
}


