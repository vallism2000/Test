
#include "UIRecipeListEvent.hpp"

UIRecipeListEvent::UIRecipeListEvent(std::vector<std::string> * ingredients, bool andSearch) : IEvent(UIRECIPELISTREQUEST) {
	m_ingredients = ingredients;
	m_andSearch = andSearch;
}

std::vector<std::string> * UIRecipeListEvent::GetIngredients() {
	return m_ingredients;
}
bool UIRecipeListEvent::IsAndSearch() {
	return m_andSearch;
}
