
#ifndef UIEVENTHANDLER_HPP_
#define UIEVENTHANDLER_HPP_

#include <string>

#include <bb/cascades/QmlDocument>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/ArrayDataModel>

#include "events/IEvent.hpp"
#include "eventListeners/IEventListener.hpp"
#include "drinkObjects/DrinkIngredient.hpp"

class UIEventHandler : public IEventListener
{

public:
	UIEventHandler(bb::cascades::ArrayDataModel * m1[], bb::cascades::ArrayDataModel * m2[], bb::cascades::NavigationPane * n);

	// Handles all incoming events
	void ActOnEvent(IEvent * e);

	// Functions related to Recipes
	void getRecipeList(std::string s="");
	void getRecipe(int index, int id);
	void addRecipe(int rate, std::string text[], std::string ingred[], std::string amount[], int size);
	void shareRecipe(int id);
	std::string getRecipeName();
	std::string getRecipeDescription();
	std::string getRecipeInstructions();
	std::vector<std::pair<DrinkIngredient, std::string> > getRecipeIngredients();
	int getRecipeID();
	int getRecipeRating();


	// Functions related to Inventory List
	void getInvList();

	// Functions related to Shoping List
	void getShopList();

	// Functions related to both
	void moveListItem(int id, std::string name, bool isShopList);
	void removeListItem(int id, std::string name, bool isShopList);
	void addListItem(std::string name, bool isShopList);

	void updateRecipeRating(int rating);

private:
	bb::cascades::NavigationPane * nav;
	// Data for the Recipe List
	bb::cascades::ArrayDataModel * model1;
	bb::cascades::ArrayDataModel * model2;
	// Data for the queried Recipe
	int m_id;
	std::string m_name;
	std::string m_description;
	std::string m_instructions;
	int m_rating;
	std::vector<std::pair<DrinkIngredient, std::string> > m_ingredients;

	//
	bb::cascades::ArrayDataModel * model3;
	bb::cascades::ArrayDataModel * model4;

	//
	bb::cascades::ArrayDataModel * model5;
	bb::cascades::ArrayDataModel * model6;
};


#endif /* UIEVENTHANDLER_HPP_ */
