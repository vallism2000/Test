/*
 * ModifyRecipeEvent.hpp
 *
 */

#ifndef MODIFYRECIPEEVENT_HPP_
#define MODIFYRECIPEEVENT_HPP_

#include "IEvent.hpp"
#include <string>
#include <vector>
#include <utility>


class ModifyRecipeEvent: public IEvent {
public:
	ModifyRecipeEvent(int recipeID, int rating, const std::string & name, const std::string & desc, const std::string & instructions);
	virtual ~ModifyRecipeEvent();

	int RecipeID;
	int Rating;
	std::string Name;
	std::string Description;
	std::string Instructions;

	void AddIngredient(const std::string & name, const std::string & amount);
	const std::vector<std::pair<std::string,std::string> > & GetIngredientsList();

private:
	std::vector< std::pair<std::string, std::string> > m_ingredients;

};

#endif /* MODIFYRECIPEEVENT_HPP_ */
