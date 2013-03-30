
#include <iostream>

#include "UIEventHandler.hpp"
#include "CoreEventBus.hpp"

UIEventHandler::UIEventHandler(bb::cascades::ArrayDataModel * m1, bb::cascades::ArrayDataModel * m2) {
	// Attach data models
	model1 = m1;
	model2 = m2;

	// Register with CoreEventBus
	//
}

void UIEventHandler::ActOnEvent(IEvent * e) {
	//
}

void UIEventHandler::getRecipeList(std::string s) {
	model1->clear(); model2->clear();
	// Test
	//std::cout << s << std::endl;
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
}
void UIEventHandler::getRecipe(int index, int id) {
	//
}
void UIEventHandler::addRecipe() {
	//
}
void UIEventHandler::shareRecipe(int id) {
	//
}
