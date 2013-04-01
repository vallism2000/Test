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
#include "events/RemoveRecipeEvent.hpp"
#include "events/ModifyRecipeEvent.hpp"
#include "events/GetAllRecipesEvent.hpp"
#include "events/GetAllRecipesResultEvent.hpp"
#include "events/GetRecipeEvent.hpp"
#include "events/GetRecipeResultEvent.hpp"
#include "events/SearchRecipesEvent.hpp"
#include "events/SearchRecipesResultEvent.hpp"

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
			m_fileMgr.AddToIngredientList(parsedEvent->IngredientID, parsedEvent->IngredientName, parsedEvent->IsShoppingList);
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
	else if (e->GetType() == e->RECIPEREMOVE)
	{
		std::cout << "DataMgr: Remove Recipe event is being handled." << std::endl;
		RemoveRecipeEvent * parsedEvent = (RemoveRecipeEvent *) e;
		m_fileMgr.RemoveRecipe(parsedEvent->RecipeID);
	}
	else if (e->GetType() == e->RECIPEMODIFY)
	{
		std::cout << "DataMgr: Modify Recipe event is being handled." << std::endl;
		ModifyRecipeEvent * parsedEvent = (ModifyRecipeEvent *) e;
		m_fileMgr.ModifyRecipe(parsedEvent->RecipeID, parsedEvent->Rating, parsedEvent->Name,
						parsedEvent->Description, parsedEvent->Instructions,
						parsedEvent->GetIngredientsList());
	}
	else if (e->GetType() == e->RECIPELISTREQUEST)
	{
		std::cout << "DataMgr: Recipe List Request event is being handled." << std::endl;
		//GetAllRecipesEvent * parsedEvent = (GetAllRecipesEvent *) e;
		CoreEventBus::FireEvent(new GetAllRecipesResultEvent(m_fileMgr.GetAllRecipes()));
	}
	else if (e->GetType() == e->RECIPEREQUEST)
	{
		std::cout << "DataMgr: Specific Recipe Request event is being handled." << std::endl;
		GetRecipeEvent * parsedEvent = (GetRecipeEvent *) e;
		DrinkRecipe * foundRecipe = m_fileMgr.GetRecipe(parsedEvent->RecipeID);
		GetRecipeResultEvent * toSend = new GetRecipeResultEvent(foundRecipe);
		CoreEventBus::FireEvent(toSend);
	}
	else if (e->GetType() == e->RECIPESEARCHREQUEST)
	{
		std::cout << "DataMgr: Search Request event is being handled." << std::endl;
		SearchRecipesEvent * parsedEvent = (SearchRecipesEvent *) e;
		const RecipeList * results = m_fileMgr.GetSearchResults(parsedEvent->Name,
				parsedEvent->IngredientNames,
				parsedEvent->UseANDForSearch);
		SearchRecipesResultEvent * toSend = new SearchRecipesResultEvent(results);
		CoreEventBus::FireEvent(toSend);
	}
}
