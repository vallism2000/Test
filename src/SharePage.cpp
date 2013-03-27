/*
 * SharePage.cpp
 *
 */

#include "SharePage.hpp"
#include "events/ShareRecipeEvent.hpp"
#include "ShareEventBus.hpp"
#include "eventListeners/ShareEventListener.hpp"
#include <iostream>

SharePage::SharePage(){
	// For now the recipe is being mocked in the triggerShareEvent() function, fix this later
    m_recipe = NULL;
    m_qml = QmlDocument::create("asset:///share.qml");
    m_qml->setContextProperty("_shareObject", this);
    m_root = m_qml->createRootObject<Page>();

    std::cout << "SharePage created" << std::endl;
}

SharePage::~SharePage(){

}

void SharePage::triggerShareEvent(QString type){
	std::cout << "trigger share event" << std::endl;
	// Will need to get drinkrecipe pointer from somewhere
	DrinkRecipe* m_recipe = new DrinkRecipe(1, "foo", "fooooooo", new DrinkIngredient(1, "bar", "1 part"), 1);

	ShareRecipeEvent *e = new ShareRecipeEvent(type.toStdString()+"Share", m_recipe);
	ShareEventBus::GetInstance().FireEvent(e);

}

