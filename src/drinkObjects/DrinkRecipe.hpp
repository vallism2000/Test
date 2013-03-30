/*
 * DrinkRecipe.h
 *
 *
 *      This is to be created by the data manip layer and just interpretted elsewhere.
 *      This means that the size of the ingredient array is set on creation. Note that everything is read only to try and protect this.
 *
 */

#ifndef DRINKRECIPE_H_
#define DRINKRECIPE_H_

#include "DrinkIngredient.hpp"
#include <string>
#include <vector>
#include <utility>

class DrinkRecipe {
public:
	DrinkRecipe(int rating, std::string name, std::string desc);
	virtual ~DrinkRecipe();

	void AddIngredient(int ingredientID, const std::string & ingredientName, const std::string & amount);

	int GetRating() const;
	const std::string & GetName() const;
	const std::string & GetDesc() const;
	const DrinkIngredient GetIngredient(unsigned int index) const;
	const std::string GetIngredientAmount(unsigned int index) const;
	unsigned int GetNumIngredients() const;


private:
	int m_rating;
	std::string m_name;
	std::string m_desc;

	//DrinkRecipe takes ownership over this allocation.
	std::vector<std::pair<DrinkIngredient, std::string> > m_ingredients;
};

#endif /* DRINKRECIPE_H_ */
