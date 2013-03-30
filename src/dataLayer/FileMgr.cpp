/*
 * FileMgr.cpp
 *
 */

#include "FileMgr.hpp"
#include "CoreEventBus.hpp"
#include "events/IngredientListResultEvent.hpp"
#include "drinkObjects/DrinkIngredient.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <iostream>
#include <vector>

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

void FileMgr::GetIngredientList(bool isShoppingList)
{
	std::cout << "FileMgr: Dummy handle for GetIngredientList: Shopping?: " << isShoppingList << std::endl;
	std::vector<DrinkIngredient> * tempIngredients = new std::vector<DrinkIngredient>();
	if(isShoppingList)
	{
		tempIngredients->push_back(DrinkIngredient(0, "TestBoozeNeed0", "2 oz."));
		tempIngredients->push_back(DrinkIngredient(1, "TestBoozeNeed1", "A splash."));
		tempIngredients->push_back(DrinkIngredient(2, "TestBoozeNeed2", "3 cups."));
		tempIngredients->push_back(DrinkIngredient(3, "TestBoozeNeed3", "1 part."));
		tempIngredients->push_back(DrinkIngredient(4, "TestBoozeNeed4", "A bottle."));
	}
	else
	{
		tempIngredients->push_back(DrinkIngredient(0, "TestBoozeHave0", "2 oz."));
		tempIngredients->push_back(DrinkIngredient(1, "TestBoozeHave1", "A splash."));
		tempIngredients->push_back(DrinkIngredient(2, "TestBoozeHave2", "3 cups."));
		tempIngredients->push_back(DrinkIngredient(3, "TestBoozeHave3", "1 part."));
		tempIngredients->push_back(DrinkIngredient(4, "TestBoozeHave4", "A bottle."));
	}
	CoreEventBus::FireEvent(new IngredientListResultEvent(isShoppingList, tempIngredients));
}
