/*
 * SharePage.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#include "SharePage.hpp"
#include "events/ShareRecipeEvent.hpp"
#include "ShareEventBus.hpp"
#include <iostream>


SharePage::SharePage(){
    m_recipe = NULL; //tmp

    m_qml = QmlDocument::create("asset:///share.qml");
    m_qml->setContextProperty("_share", this);
    m_root = m_qml->createRootObject<Page>();

}

SharePage::~SharePage(){

}

void SharePage::triggerShareEvent(std::string type){
	std::cout << "trigger share event" << std::endl;
	// Need to get drinkrecipe pointer from somewhere
	DrinkRecipe* m_recipe = new DrinkRecipe(1, "foo", "fooooooo", new DrinkIngredient(1, "bar", "1 part"), 1);
    // Assuming the share page somehow know which recipe to share
	ShareRecipeEvent *e = new ShareRecipeEvent(type, m_recipe);
	ShareEventBus::GetInstance().FireEvent(e);

}

