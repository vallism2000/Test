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

class FileMgr {
public:
	FileMgr();
	virtual ~FileMgr();

	//TODO void GetIngredientList(bool isShoppingList);
	//TODO void AddToIngredientList(int recipeID, bool isShoppingList);
	//TODO void RemoveFromIngredientList(int recipeID, bool isShoppingList);

	//TODO void AddRecipe();
	//TODO void RemoveRecipe();
	//TODO void EditRecipe();
	//TODO void GetRecipe(int recipeID);
	//TODO void GetAllRecipes();
	//TODO void GetSearchResults();
};

#endif /* FILEMGR_HPP_ */
