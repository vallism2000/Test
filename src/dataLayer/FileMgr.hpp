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

	//Return the entirety of the designated list. Hope this isn't too big.
	void GetIngredientList(bool isShoppingList);

	//Add an ingredient to the list (if it isn't there already)
	//This will not remove it from the other list if it is present there)
	void AddToIngredientList(int ingredientID, bool isShoppingList);

	//Remove from the designated list only.
	void RemoveFromIngredientList(int ingredientID, bool isShoppingList);

	//TODO void AddRecipe();
	//TODO void RemoveRecipe();
	//TODO void EditRecipe();
	//TODO void GetRecipe(int recipeID);
	//TODO void GetAllRecipes();
	//TODO void GetSearchResults();
};

#endif /* FILEMGR_HPP_ */
