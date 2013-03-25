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

class DrinkRecipe {
public:
	DrinkRecipe(int rating, std::string name, std::string desc, DrinkIngredient* ingredients, int numIngredients);
	virtual ~DrinkRecipe();

	int GetRating();
	const std::string & GetName();
	const std::string & GetDesc();
	const DrinkIngredient & GetDrinkIngredient(int index);
	int GetNumIngredients();


private:
	int m_rating;
	std::string m_name;
	std::string m_desc;
	DrinkIngredient* m_ingredients;
	int m_numIngredients;
};

#endif /* DRINKRECIPE_H_ */
