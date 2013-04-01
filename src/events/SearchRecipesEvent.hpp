/*
 * SearchRecipesEvent.hpp
 *
 */

#ifndef SEARCHRECIPESEVENT_HPP_
#define SEARCHRECIPESEVENT_HPP_

#include "IEvent.hpp"
#include <vector>
#include <string>

class SearchRecipesEvent: public IEvent {
public:
	//Alternative to AND is OR
	SearchRecipesEvent(const std::string & name, const std::vector<std::string> & ingredients, bool useANDforSearch);
	virtual ~SearchRecipesEvent();

	//Name of recipe will take precedence over ingredients
	std::string Name;

	//Ingredients will either be AND-ed or OR-ed based on the bool
	const std::vector<std::string> & IngredientNames;
	bool UseANDForSearch;
};

#endif /* SEARCHRECIPESEVENT_HPP_ */
