/*
 * AddRecipeEvent.hpp
 *
 */

#ifndef ADDRECIPEEVENT_HPP_
#define ADDRECIPEEVENT_HPP_

#include "IEvent.hpp"
#include <string>
#include <vector>
#include <utility>


class AddRecipeEvent: public IEvent {
public:
	AddRecipeEvent(int rating, const std::string & name, const std::string & desc, const std::string & instructions);
	virtual ~AddRecipeEvent();

	int Rating;
	std::string Name;
	std::string Description;
	std::string Instructions;

	void AddIngredient(const std::string & name, const std::string & amount);
	const std::vector<std::pair<std::string,std::string> > & GetIngredientsList();

private:
	std::vector< std::pair<std::string, std::string> > m_ingredients;

};

#endif /* ADDRECIPEEVENT_HPP_ */
