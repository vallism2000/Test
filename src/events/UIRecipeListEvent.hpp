
/*
 * 	UIRecipeListEvent
 * 	Sent by the UI when it needs the Name and ID of recipes for the list
 * 	Contains search information entered by user
 */

#ifndef UIRECIPELISTEVENT_HPP_
#define UIRECIPELISTEVENT_HPP_

#include "IEvent.hpp"

#include <vector>

class UIRecipeListEvent : public IEvent {

public:
	UIRecipeListEvent(std::vector<std::string> * ingredients, bool andSearch);
	std::vector<std::string> * GetIngredients();
	bool IsAndSearch();
private:
	std::vector<std::string> * m_ingredients;
	bool m_andSearch;
};

#endif /* UIRECIPELISTEVENT_HPP_ */
