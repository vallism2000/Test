/*
 * DrinkIngredient.hpp
 *
 *
 *      This is set up much like the DrinkRecipe by the file manager.
 *      It is meant to only be created by the file manager and just be read by the rest of the program.
 */

#ifndef DRINKINGREDIENT_HPP_
#define DRINKINGREDIENT_HPP_

#include <string>

class DrinkIngredient
{

public:
	DrinkIngredient(int id, const std::string & name);
	virtual ~DrinkIngredient();

	const std::string & GetName() const;
	int GetID();


private:
	std::string m_name;
	int m_ingredientID;

};

#endif /* DRINKINGREDIENT_HPP_ */
