/*
 * DataMgr.cpp
 *
 */

#include "DataMgr.hpp"
#include "CoreEventBus.hpp"
#include "events/IngredientListEvent.hpp"
#include "events/IngredientListRequestEvent.hpp"
#include "events/IngredientListResultEvent.hpp"
#include "events/AddRecipeEvent.hpp"

#include <iostream>

DataMgr::DataMgr()
{
	m_fileMgr = FileMgr();
	std::cout << "DataMgr: About to register the DataMgr" << std::endl;
	CoreEventBus::RegisterListener(this);
}

DataMgr::~DataMgr()
{
	std::cout << "DataMgr: About to unregister the DataMgr" << std::endl;
	CoreEventBus::UnRegisterListener(this);
}

void DataMgr::ActOnEvent(IEvent * e)
{
	if(e->GetType() == e->INGREDIENTLIST)
	{
		std::cout << "DataMgr: Ingredient List modify event is being handled." << std::endl;
		IngredientListEvent * parsedEvent = (IngredientListEvent *) e;
		if(parsedEvent->IsAddEvent)
		{
			m_fileMgr.AddToIngredientList(parsedEvent->IngredientID, parsedEvent->IsShoppingList);
		}
		else //Alternative is Remove
		{
			m_fileMgr.RemoveFromIngredientList(parsedEvent->IngredientID, parsedEvent->IsShoppingList);
		}
	}
	else if (e->GetType() == e->INGREDIENTLISTREQUEST)
	{
		std::cout << "DataMgr: Ingredient List request event is being handled." << std::endl;
		IngredientListRequestEvent * parsedEvent = (IngredientListRequestEvent *) e;

		std::vector<DrinkIngredient> * tempIngredients = m_fileMgr.GetIngredientList(parsedEvent->IsShoppingList);
		CoreEventBus::FireEvent(new IngredientListResultEvent(parsedEvent->IsShoppingList, tempIngredients));
	}
	else if (e->GetType() == e->RECIPEADD)
	{
		std::cout << "DataMgr: Add Recipe event is being handled." << std::endl;
		AddRecipeEvent * parsedEvent = (AddRecipeEvent *) e;
		m_fileMgr.AddRecipe(parsedEvent->Rating, parsedEvent->Name,
				parsedEvent->Description, parsedEvent->Instructions,
				parsedEvent->GetIngredientsList());
	}
}
