
#include <iostream>

#include "UIEventHandler.hpp"
#include "CoreEventBus.hpp"

#include "events/GetAllRecipesEvent.hpp"
#include "events/GetAllRecipesResultEvent.hpp"
#include "events/SearchRecipesEvent.hpp"
#include "events/SearchRecipesResultEvent.hpp"
#include "events/GetRecipeEvent.hpp"
#include "events/GetRecipeResultEvent.hpp"
#include "events/AddRecipeEvent.hpp"
#include "events/IngredientListRequestEvent.hpp"
#include "events/IngredientListResultEvent.hpp"
#include "events/ModifyRecipeEvent.hpp"

#include "drinkObjects/DrinkRecipe.hpp"
#include "drinkObjects/DrinkIngredient.hpp"

UIEventHandler::UIEventHandler(bb::cascades::ArrayDataModel * m1[], bb::cascades::ArrayDataModel * m2[], bb::cascades::NavigationPane * n) {
	//
	nav = n;

	// Attach data models
	model1 = m1[0];
	model2 = m2[0];
	model3 = m1[1];
	model4 = m2[1];
	model5 = m1[2];
	model6 = m2[2];

	// Register with CoreEventBus
	CoreEventBus::RegisterListener(this);

	//
}

void UIEventHandler::ActOnEvent(IEvent * e) {
	// Incoming RecipeList Data
	if (e->GetType() == IEvent::RECIPELISTRESULT) {
		GetAllRecipesResultEvent * event = (GetAllRecipesResultEvent*) e;
		const RecipeList * recipeList = event->AllRecipeList;
		//
		for (unsigned int i=0; i<recipeList->size(); i++) {
			model1->append(recipeList->at(i).RecipeId);
			std::string s = recipeList->at(i).Name;
			model2->append(s.c_str());
		}
	}
	// Incoming Searched RecipeList Data
	if (e->GetType() == IEvent::RECIPESEARCHRESULT) {
		SearchRecipesResultEvent * event = (SearchRecipesResultEvent*) e;
		const RecipeList * recipeList = event->Results;
		//
		for (unsigned int i=0; i<recipeList->size(); i++) {
			model1->append(recipeList->at(i).RecipeId);
			std::string s = recipeList->at(i).Name;
			model2->append(s.c_str());
		}
	}
	// Incoming RecipeItem Data
	if (e->GetType() == IEvent::RECIPERESULT) {
		GetRecipeResultEvent * event = (GetRecipeResultEvent*) e;
		DrinkRecipe * recipeItem = event->Recipe;
		m_name = recipeItem->GetName();
		m_description = recipeItem->GetDesc();
		m_instructions = recipeItem->GetInstructions();
        m_rating = recipeItem->GetRating();
		for(unsigned int i=0; i < recipeItem->GetNumIngredients(); i++){
			std::pair<DrinkIngredient, std::string> ing (recipeItem->GetIngredient(i), recipeItem->GetIngredientAmount(i));

			m_ingredients.push_back(ing);

		}
	}
	// Incoming IngredientList Data (Inventory or Shopping List)
	if (e->GetType() == IEvent::INGREDIENTLISTRESULT) {
		IngredientListResultEvent * event = (IngredientListResultEvent*) e;
		const std::vector<DrinkIngredient> * ingredientList = event->Ingredients;
		if (!event->IsShoppingList) {
			for (unsigned int i=0; i<ingredientList->size(); i++) {
				DrinkIngredient x = ingredientList->at(i);
				int y = x.GetID();
				model3->append(y);
				std::string s = ingredientList->at(i).GetName();
				model4->append(s.c_str());
			}
		} else {
			for (unsigned int i=0; i<ingredientList->size(); i++) {
				DrinkIngredient x = ingredientList->at(i);
				int y = x.GetID();
				model5->append(y);
				std::string s = ingredientList->at(i).GetName();
				model6->append(s.c_str());
			}
		}
	}
}

void UIEventHandler::getRecipeList(std::string s) {
	model1->clear(); model2->clear();
	// Test START
	/*
	std::cout << s << std::endl;
	if (s=="") {
		model1->append(0); model2->append("White Russian");
		model1->append(1); model2->append("Rum and Coke");
		model1->append(2); model2->append("Irish Car Bomb");
		model1->append(3); model2->append("Long Island Iced Tea");
	}
	else {
		model1->append(0); model2->append("White Russian");
		model1->append(3); model2->append("Long Island Iced Tea");
	}
	*/
	// Test END

	// Fire Request
	IEvent * event;
	if (s == "") {
		event = new GetAllRecipesEvent();
	} else {
		std::vector<std::string> * ing = new std::vector<std::string>();
		std::string str = s;
		unsigned int x;

		x = str.find(" ");
		while(x != std::string::npos) {
			if (str.substr(0, x) != "") {
				ing->push_back(str.substr(0, x));
			}
			str = str.substr(x+1);
			x = str.find(" ");
		}
		if (str != "") {
			ing->push_back(str);
		}

		event = new SearchRecipesEvent("", ing, true);
		// Test START
		std::cout << "Search String: '" << s << "'" << std::endl;
		std::cout << "Parsed String:";
		for (unsigned int i=0; i<ing->size(); i++) {
			std::cout << " '" << ing->at(i) << "'";
		}
		std::cout << std::endl;
		// Test END
	}
	CoreEventBus::FireEvent(event);
}
void UIEventHandler::getRecipe(int index, int id) {
	m_id = id;
	m_name = "";
	m_description = "";

	// Test START
	/*
	if (id == 0) {
		m_name = "White Russian";
	}
	else if (id == 1) {
		m_name = "Rum and Coke";
	}
	else if (id == 2) {
		m_name = "Irish Car Bomb";
	}
	else if (id == 3) {
		m_name = "Long Island Iced Tea";
	}
	else if (id == 4) {
		m_name = "Submitted Recipe Name";
	}
	*/
	/*
	if (id == 0) {
		m_description = "Ingredients:\n2oz Vodka\n1oz Coffee Liqueur\nCream";
	}
	else if (id == 1) {
		m_description = "Ingredients:\n4oz Rum\n8oz Coca Cola";
	}
	else if (id == 2) {
		m_description = "Ingredients:\n1 Pint Guiness/Dry Irish Stout\n1oz Irish Cream Liqueur\n1oz Irish Whiskey";
	}
	else if (id == 3) {
		m_description = "Ingredients:\n1oz Vodka\n1oz Tequila\n1oz Rum\n1oz Gin\n1oz Triple Sec\n1.5oz Sour Mix\n1 Splash Coca Cola";
	}
	else if (id == 4) {
		m_description = "Submitted Recipe Info";
	}
	*/
	//std::cout << "index: '" << index << "', id: '" << id << "'" << std::endl;
	// Test END

	// Fire Request
	GetRecipeEvent * event = new GetRecipeEvent(m_id);
	CoreEventBus::FireEvent(event);
}
void UIEventHandler::addRecipe(int rate, std::string text[], std::string ingred[], std::string amount[], int size) {
	// Test START
	std::cout << text[0] << ", " << text[1] << ", " << text[2] << std::endl;
	for (int i=0; i<size; i++) {
		std::cout << ingred[i] << ", " << amount[i] << std::endl;
	}
	// Test END

	// Fire Submission
	AddRecipeEvent * event = new AddRecipeEvent(rate, text[0], text[1], text[2]);
	for (int i=0; i<size; i++) {
		event->AddIngredient(ingred[i], amount[i]);
	}
	CoreEventBus::FireEvent(event);
}
void UIEventHandler::shareRecipe(int id) {
	//
}

std::string UIEventHandler::getRecipeName() {
	return m_name;
}
std::string UIEventHandler::getRecipeDescription() {
	return m_description;
}
std::string UIEventHandler::getRecipeInstructions() {
	return m_instructions;
}

int UIEventHandler::getRecipeID(){
	return m_id;
}

int UIEventHandler::getRecipeRating(){
	return m_rating;
}

std::vector<std::pair<DrinkIngredient, std::string> > UIEventHandler::getRecipeIngredients(){
	return m_ingredients;
}

void UIEventHandler::getInvList() {
	model3->clear(); model4->clear();
	// Test START
	//model3->append(0); model4->append("Booze(tm)");
	//model3->append(1); model4->append("Vodka");
	// Test END

	// Fire Request
	IngredientListRequestEvent * event = new IngredientListRequestEvent(false);
	CoreEventBus::FireEvent(event);
}


void UIEventHandler::getShopList() {
	model5->clear(); model6->clear();
	// Test START
	//model5->append(0); model6->append("Salt");
	//model5->append(1); model6->append("Pepper");
	// Test END

	// Fire Request
	IngredientListRequestEvent * event = new IngredientListRequestEvent(true);
	CoreEventBus::FireEvent(event);
}


void UIEventHandler::moveListItem(int id, bool isShopList) {
	std::cout << "Item Moved:: ID: '" << id << "', ShopList Origin?: '" << isShopList << "'" << std::endl;
}

void UIEventHandler::updateRecipeRating(int rating){

	ModifyRecipeEvent* event = new ModifyRecipeEvent(m_id, rating, m_name, m_description, m_instructions);
	CoreEventBus::FireEvent(event);
}




