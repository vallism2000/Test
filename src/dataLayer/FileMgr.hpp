/*
 * FileMgr.hpp
 *
 * Manages two main files.
 *
 * Ingredient Collection/Shopping List
 * Can add items to each list
 * Can remove items from each list.
 * Can Request either list
 *
 * Recipe Collection
 * Can add recipes
 * Can remove recipes
 * Can edit recipes
 * Can request specific
 * Can request all (perhaps in chunks?)
 * Can request by search terms
 */

#ifndef FILEMGR_HPP_
#define FILEMGR_HPP_

#include <vector>
#include <string>
#include <utility>
#include "drinkObjects/DrinkIngredient.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <bb/data/SqlConnection>
#include <QtSql/QtSql>

class FileMgr {
public:
	FileMgr();
	virtual ~FileMgr();

	//Return the entirety of the designated list. Hope this isn't too big.
	std::vector<DrinkIngredient> * GetIngredientList(bool isShoppingList);

	//Add an ingredient to the list (if it isn't there already)
	//This will not remove it from the other list if it is present there)
	void AddToIngredientList(int ingredientID, const std::string & name, bool isShoppingList);

	//Remove from the designated list only.
	void RemoveFromIngredientList(int ingredientID, bool isShoppingList);

	void AddRecipe(int rating, const std::string & name,
			const std::string & description, const std::string & instructions,
			const std::vector<std::pair<std::string, std::string> > & ingredients);

	void RemoveRecipe(int recipeID);

	void ModifyRecipe(int recipeId, int rating, const std::string & name,
				const std::string & description, const std::string & instructions,
				const std::vector<std::pair<std::string, std::string> > & ingredients);

	const RecipeList * GetAllRecipes();

	//Returns a new object. It does not take ownership over the new object
	DrinkRecipe * GetRecipe(int recipeId);

	const RecipeList * GetSearchResults(const std::string & recipeName, const std::vector<std::string> & ingredientList, bool useAND);

private:

	//Maintained by the file manager as the full list of all names and ids.
	RecipeList * m_allRecipeList;

	//Maintained by the file manager
	RecipeList * m_lastSearchResults;

	//Initialize the DB if it hasn't already been done
	void CreateTables();

	//Drop all the tables in the DB
	void DropTables();

	//Perform a query
	bool PerformQuery(QString queryString);

	// return if the user has all the ingredients for a particular recipe
	bool HasAllIngredientsForRecipe(int recipeID);

	//Checks for the existence. Returns the ID if it exists, otherwise -1;
	int DoesIngredientExist(const std::string & name, int id = -1);

	//Adds the Ingredient and returns its new index.
	int AddIngredient(const std::string & name);
};

#endif /* FILEMGR_HPP_ */
