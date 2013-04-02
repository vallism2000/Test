/*
 * SharePage.cpp
 *
 */

#include "SharePage.hpp"
#include "events/ShareRecipeEvent.hpp"
#include "ShareEventBus.hpp"
#include "eventListeners/ShareEventListener.hpp"
#include "events/GetRecipeEvent.hpp"
#include <iostream>

SharePage::SharePage(){
	// For now the recipe is being mocked in the triggerShareEvent() function, fix this later
    m_qml = QmlDocument::create("asset:///share.qml");
    m_qml->setContextProperty("_shareObject", this);
    m_root = m_qml->createRootObject<Page>();

}

SharePage::~SharePage(){

}

void SharePage::triggerShareEvent(QString type){
	std::cout << "type: " << type.toStdString() << std::endl;

	// Will need to get drinkrecipe pointer from somewhere, mocking it for now
	DrinkRecipe* m_recipe = new DrinkRecipe(recipeID, recipeRating, recipeName, recipeDesc, recipeInstr);

	for(int i=0; i<recipeIngredients.size(); i++){
		std::pair<DrinkIngredient, std::string> addIng = recipeIngredients[i];
		int tmp_id = addIng.first.GetID();
		std::string tmp_name = addIng.first.GetName();
		std::string tmp_amount = addIng.second;

		m_recipe->AddIngredient(tmp_id, tmp_name, tmp_amount);
	}

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

// Want to get all this info from the recipe that was displayed on the recipe page before share was clicked
void SharePage::setRecipeID(int id){
	recipeID = id;
}

void SharePage::setRecipeName(QString name){
	recipeName = name.toStdString();;
}

void SharePage::setRecipeDesc(QString desc){
	recipeDesc = desc.toStdString();
}

void SharePage::setRecipeIngredients(std::vector<std::pair<DrinkIngredient, std::string> > ingredients){
	 recipeIngredients = ingredients;
	 /*for(int i=0; i< ingredients.size(); i++){

		 std::pair<DrinkIngredient, std::string> addIng = ingredients[i];
		 recipeI

	 }*/
}

void SharePage::setRecipeInstructions(QString instructions){
	recipeInstr = instructions.toStdString();
}

void SharePage::setRating(int rating){
	recipeRating = rating;
}
