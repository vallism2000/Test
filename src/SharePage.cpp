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

}

SharePage::~SharePage(){

}

void SharePage::triggerShareEvent(QString type){
	std::cout << "type: " << type.toStdString() << std::endl;

	// Will need to get drinkrecipe pointer from somewhere, mocking it for now
	DrinkRecipe* m_recipe = new DrinkRecipe(5, 1, "foo", "fooooooo", "How to foo");
	m_recipe->AddIngredient(1, "vodka", "a lot");
	m_recipe->AddIngredient(2, "orange juice", "a splash");

	IEvent::EventType event_type;
	if (type == "BBM"){
		event_type = IEvent::BBMSHARE;
	} else if (type == "Facebook"){
		event_type = IEvent::FACEBOOKSHARE;
	} else if (type == "NFC"){
		event_type = IEvent::NFCSHARE;
	} else if (type == "Twitter"){
		event_type = IEvent::TWITTERSHARE;

	}
	ShareRecipeEvent *e = new ShareRecipeEvent(event_type, m_recipe);
	ShareEventBus::FireEvent(e);

}

