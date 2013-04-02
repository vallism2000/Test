/*
 * FileMgr.cpp
 *
 */

#include "FileMgr.hpp"
#include "drinkObjects/DrinkIngredient.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <iostream>
#include <bb/cascades/Application>

using namespace bb::cascades;

const QString IngredientTable = "Ingredients";
const QString RecipeTable = "Recipes";
const QString RecipeIngredientsTable = "RecipeIngredients";
const QString ShoppingTable = "Shopping";
const QString InventoryTable = "Inventory";

const QString IngredientID = "ingredientID";
const QString IngredientName = "ingredientName";
const QString RecipeID = "recipeID";
const QString RecipeRating = "recipeRating";
const QString RecipeName = "recipeName";
const QString RecipeDesc = "recipeDesc";
const QString RecipeInstructions = "recipeInstructions";
const QString IngredientQuantity = "ingredientQuantity";
QString getLastExecutedQuery(const QSqlQuery& query)
{
 QString str = query.lastQuery();
 QMapIterator<QString, QVariant> it(query.boundValues());
 while (it.hasNext())
 {
  it.next();
  str.replace(it.key(),it.value().toString());
 }
 return str;
}
FileMgr::FileMgr()
{
	m_lastSearchResults = new RecipeList();
	m_allRecipeList = new RecipeList();

	//Fill it with dummy data for now
	m_allRecipeList->push_back(RecipeTuple(0, "AllDrink0", true));
	m_allRecipeList->push_back(RecipeTuple(1, "AllDrink1", true));
	m_allRecipeList->push_back(RecipeTuple(2, "AllDrink2", false));
	m_allRecipeList->push_back(RecipeTuple(3, "AllDrink3", true));
	m_allRecipeList->push_back(RecipeTuple(4, "AllDrink4", true));
	m_allRecipeList->push_back(RecipeTuple(5, "AllDrink5", false));
	m_allRecipeList->push_back(RecipeTuple(6, "AllDrink6", true));
	m_allRecipeList->push_back(RecipeTuple(7, "AllDrink7", true));
	m_allRecipeList->push_back(RecipeTuple(8, "AllDrink8", false));
	m_allRecipeList->push_back(RecipeTuple(9, "AllDrink9", true));
	m_allRecipeList->push_back(RecipeTuple(10, "AllDrink10", false));
	m_allRecipeList->push_back(RecipeTuple(11, "AllDrink11", false));
	m_allRecipeList->push_back(RecipeTuple(12, "AllDrink12", true));
	m_allRecipeList->push_back(RecipeTuple(13, "AllDrink13", false));
	m_allRecipeList->push_back(RecipeTuple(14, "AllDrink14", true));
	m_allRecipeList->push_back(RecipeTuple(15, "AllDrink15", false));
	m_allRecipeList->push_back(RecipeTuple(16, "AllDrink16", true));

	const QString databasePath = "./data/recipes.db";
	QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
	database.setDatabaseName(databasePath);
	if(database.open())
	{
		std::cout << "FileMgr: DB created successfully " << std::endl;
	}
	else
	{
		std::cout << "FileMgr: Error opening DB. " << std::endl;
	}
	database.close();

	CreateTables();
}

FileMgr::~FileMgr()
{
}
bool FileMgr::PerformQuery(QString queryString) {
	QSqlDatabase database = QSqlDatabase::database();
	QSqlQuery q(database);
	if (!q.exec(queryString)) {
		const QSqlError error = q.lastError();
		std::cout << "SQL Error in query " << queryString.toStdString() << "\n" << error.text().toStdString() << "\n";
		return false;
	}
	std::cout << "Query successful: " << queryString.toStdString() << "\n";
	return true;
}
void FileMgr::DropTables() {

	const QString dropIngredients = "DROP TABLE " + IngredientTable;
	const QString dropRecipes = "DROP TABLE " + RecipeTable;
	const QString dropRecipeIngredients = "DROP TABLE " + RecipeIngredientsTable;
	const QString dropShoppingList = "DROP TABLE " + ShoppingTable;
	const QString dropInventory = "DROP TABLE " + InventoryTable;
	int length = 5;
	QString dropStrings[5] = {dropIngredients, dropRecipes, dropRecipeIngredients, dropShoppingList, dropInventory};

	for (int i = 0; i < length; i++) {
		PerformQuery(dropStrings[i]);
	}


}
void FileMgr::CreateTables()
{
	QSqlDatabase database = QSqlDatabase::database();

	//Create Ingredients table
	const QString ingredientTable = "CREATE TABLE IF NOT EXISTS " + IngredientTable + " ("
			" " + IngredientID + " INTEGER PRIMARY KEY AUTOINCREMENT,"
			" " + IngredientName + " VARCHAR);";
	QSqlQuery ingredientsQuery(database);
	if(ingredientsQuery.exec(ingredientTable))
	{
		std::cout << "Ingredient table created successfully." << std::endl;
	}
	else
	{
		std::cout << "Ingredient table errored on creation." << std::endl;
	}
	std::cout << getLastExecutedQuery(ingredientsQuery).toStdString() << "\n";
	//Create Recipe table
	const QString recipeTable = "CREATE TABLE IF NOT EXISTS " + RecipeTable + " ("
			" " + RecipeID + " INTEGER PRIMARY KEY AUTOINCREMENT,"
			" " + RecipeRating + " INTEGER,"
			" " + RecipeName + " VARCHAR,"
			" " + RecipeDesc + " VARCHAR,"
			" " + RecipeInstructions + " VARCHAR);";
	QSqlQuery recipesQuery(database);
	if(recipesQuery.exec(recipeTable))
	{
		std::cout << "Recipe table created successfully." << std::endl;
	}
	else
	{
		std::cout << "Recipe table errored on creation." << std::endl;
	}
	std::cout << getLastExecutedQuery(recipesQuery).toStdString() << "\n";
	//Create RecipeIngredients table
	const QString recipeIngredientsTable = "CREATE TABLE IF NOT EXISTS "
			+ RecipeIngredientsTable + " ("
					"" + RecipeID + " INTEGER,"
					" " + IngredientID + " INTEGER,"
					" " + IngredientQuantity + " VARCHAR);";
	QSqlQuery recipeIngredientsQuery(database);
	if(recipeIngredientsQuery.exec(recipeIngredientsTable))
	{
		std::cout << "RecipeIngredients table created successfully." << std::endl;
	}
	else
	{
		std::cout << "RecipeIngredients table errored on creation." << std::endl;
	}
	std::cout << getLastExecutedQuery(recipeIngredientsQuery).toStdString() << "\n";
	//Create ShoppingList table
	const QString shoppingTable = "CREATE TABLE IF NOT EXISTS " + ShoppingTable + " ("
			" " + IngredientID + " INTEGER PRIMARY KEY);";
	QSqlQuery shoppingQuery(database);
	if(shoppingQuery.exec(shoppingTable))
	{
		std::cout << "Shopping table created successfully." << std::endl;
	}
	else
	{
		std::cout << "Shopping table errored on creation." << std::endl;
	}

	//Create Inventory table
	const QString inventoryTable = "CREATE TABLE IF NOT EXISTS " + InventoryTable + " ("
			" " + IngredientID + " INTEGER PRIMARY KEY);";
	QSqlQuery inventoryQuery(database);
	if(inventoryQuery.exec(inventoryTable))
	{
		std::cout << "Inventory table created successfully." << std::endl;
	}
	else
	{
		std::cout << "Inventory table errored on creation." << std::endl;
	}

	database.close();
}

int FileMgr::DoesIngredientExist(const std::string & name, int id)
{
	QSqlDatabase database = QSqlDatabase::database();

	QString qName = QString::fromStdString(name);
	//Check for existance of ingredient
	QSqlQuery query(database);
	query.prepare("SELECT " + IngredientID + ", " + IngredientName
			 + " FROM " + IngredientTable
			 + " WHERE " + IngredientID + " = :id OR "
			 + " UPPER(" + IngredientName + ") = UPPER(:name);");
	query.bindValue(":id", id);
	query.bindValue(":name", qName);
	bool ok = true;;
	if(query.exec())
	{
		while(query.next())
		{
			database.close();
			return query.value(0).toInt(&ok);
		}
	}
	else
	{
		std::cout << "ExistenceCheck failed: " << query.lastError().text().toStdString() << std::endl;
	}

	database.close();
	return -1;
}

int FileMgr::AddIngredient(const std::string & name)
{
	bool ok = true;
	QString qName = QString::fromStdString(name);
	QSqlDatabase database = QSqlDatabase::database();
	QSqlQuery query(database);
	query.prepare("INSERT INTO " + IngredientTable
			 + " (" + IngredientName + ")"
			 + " VALUES (:name)");
	query.bindValue(":name", qName);
	if(!query.exec())
	{
		std::cout << "Create Ingredient failed: " << query.lastError().text().toStdString() << std::endl;
	}

	query.prepare("SELECT " + IngredientID
					 + " FROM " + IngredientTable
					 + " WHERE "
					 + " UPPER(" + IngredientName + ") = UPPER(:name);");
	query.bindValue(":name", qName);
	if(query.exec())
	{
		query.next();
		int toRet = query.value(0).toInt(&ok);
		database.close();
		return toRet;
	}
	else
	{
		std::cout << "Retrieve ID failed: " << query.lastError().text().toStdString() << std::endl;
	}

	database.close();
	return -1;
}

void FileMgr::AddToIngredientList(int ingredientID,const std::string & name, bool isShoppingList)
{
	//Check for existence
	int existsID = DoesIngredientExist(name, ingredientID);

	if(existsID < 0)
	{
		existsID = AddIngredient(name);
	}

	QString table = (isShoppingList) ? ShoppingTable : InventoryTable;
	QSqlDatabase database = QSqlDatabase::database();

	//Is it already in the list?
	QString qName = QString::fromStdString(name);
	QSqlQuery query(database);
	query.prepare("SELECT " + IngredientID + " FROM " + table
			 + " WHERE " + IngredientID + " = :id ;");
	query.bindValue(":id", existsID);
	if(query.exec())
	{
		while(query.next())
		{
			//Yep. it's there. Do nothing
			database.close();
			return;
		}
	}
	else
	{
		std::cout << "ExistenceCheck failed: " << query.lastError().text().toStdString() << std::endl;
	}

	//Add it to the list
	query.prepare("INSERT INTO " + table + " (" + IngredientID + ") "
				 + " VALUES( :id ) ;");
	query.bindValue(":id", existsID);
	if(!query.exec())
	{
		std::cout << "Adding ingredient to inv/shop failed: " << query.lastError().text().toStdString() << std::endl;
	}
	database.close();
}

void FileMgr::RemoveFromIngredientList(int ingredientID, bool isShoppingList)
{
	QSqlDatabase database = QSqlDatabase::database();
	QString table = (isShoppingList) ? ShoppingTable : InventoryTable;
	QSqlQuery query(database);

	//Remove it from the list
	query.prepare("DELETE FROM " + table +
			" WHERE " + IngredientID + " = :id ;");
	query.bindValue(":id", ingredientID);
	if(!query.exec())
	{
		std::cout << "Removing ingredient to inv/shop failed: " << query.lastError().text().toStdString() << std::endl;
	}
	database.close();
}

std::vector<DrinkIngredient> * FileMgr::GetIngredientList(bool isShoppingList)
{
	std::vector<DrinkIngredient> * tempIngredients = new std::vector<DrinkIngredient>();

	QSqlDatabase database = QSqlDatabase::database();
	QSqlQuery query(database);

	QString table = (isShoppingList) ? ShoppingTable : InventoryTable;

	QString ingredientListQuery = "SELECT list." + IngredientID + ", " + IngredientName
			 + " FROM " + table + " AS list, " + IngredientTable + " AS main"
			 + " WHERE list." + IngredientID + " = main." + IngredientID + ";";
	if(query.exec(ingredientListQuery))
	{
		while(query.next())
		{
			bool ok = false;
			tempIngredients->push_back(DrinkIngredient(
					query.value(0).toInt(&ok),
					query.value(1).toString().toStdString()));
		}
	}
	else
	{
		std::cout << "Read failed: " << query.lastError().text().toStdString() << std::endl;
	}

	database.close();
	return tempIngredients;
}

void FileMgr::AddRecipe(int rating, const std::string & name,
		const std::string & description, const std::string & instructions,
		const std::vector<std::pair<std::string, std::string> > & ingredients) {
	QSqlDatabase database = QSqlDatabase::database();
	QString qName = QString::fromStdString(name);
	QString qDescription = QString::fromStdString(description);
	QString qInstructions = QString::fromStdString(instructions);

	QSqlQuery insertQuery(database);
	QSqlQuery getInsertedIdQuery(database);
	insertQuery.prepare(
			"INSERT INTO " + RecipeTable
					+ " (" + RecipeRating + ", " + RecipeName + ", " + RecipeDesc + ", " +  RecipeInstructions+ ") VALUES(:rating, :name, :description, :instructions);");
	insertQuery.bindValue(":rating", rating);
	insertQuery.bindValue(":name", qName);
	insertQuery.bindValue(":description", qDescription);
	insertQuery.bindValue(":instructions", qInstructions);

	if (!insertQuery.exec()) {
		const QSqlError error = insertQuery.lastError();
		std::cout << "SQL Error in insertRecipe" << error.text().toStdString() << "\n";
		//return;
	}

	std::cout << getLastExecutedQuery(insertQuery).toStdString() << "\n";

	bool * ok;
	int test = insertQuery.lastInsertId().toInt(ok);
	std::cout << test << "\n";
	int recipeId = test;

	std::cout << "Inserted recipe id: " << recipeId << "\n";
	unsigned int i = 0;
	for (i = 0; i < ingredients.size(); i++) {
		std::pair<std::string, std::string> p = ingredients.at(i);
		std::string iName = p.first;
		std::string iQuantity = p.second;
		QString qiQuantity = QString::fromStdString(iQuantity);


		int ingredientId = DoesIngredientExist(iName, -1);
		if (ingredientId == -1) {
			ingredientId = AddIngredient(iName);
		}
		database = QSqlDatabase::database();
		QSqlQuery insertRecipeIngredientQuery(database);
		insertRecipeIngredientQuery.prepare("INSERT INTO " +  RecipeIngredientsTable + " (" + RecipeID + ", " + IngredientID + ", " +  IngredientQuantity +") VALUES(:rId, :iId, :iq);");
		insertRecipeIngredientQuery.bindValue(":rId", recipeId);
		insertRecipeIngredientQuery.bindValue(":iId", ingredientId);
		insertRecipeIngredientQuery.bindValue(":iq", qiQuantity);
		if (!insertRecipeIngredientQuery.exec()) {
			const QSqlError error2 = insertRecipeIngredientQuery.lastError();
			std::cout << "SQL Error in insertRecipeIngredientQuery " << error2.text().toStdString() << "\n";
		}
		std::cout << getLastExecutedQuery(insertRecipeIngredientQuery).toStdString() << "\n";
		}
	}

void FileMgr::ModifyRecipe(int recipeID, int rating, const std::string & name,
			const std::string & description, const std::string & instructions,
			const std::vector<std::pair<std::string, std::string> > & ingredients)
{
	std::cout << "FileMgr: Dummy handle for Modify Recipe:"  << recipeID << rating << name << description << instructions << std::endl;
	(void)ingredients;
}

void FileMgr::RemoveRecipe(int recipeID)
{
	std::cout << "FileMgr: Dummy handle for Delete Recipe:" << recipeID << std::endl;
}

//The file manager will keep an active pointer to the full list and only blow it away when things change.
const RecipeList * FileMgr::GetAllRecipes()
{
	QSqlDatabase database = QSqlDatabase::database();
	RecipeList * allRecipes = new RecipeList();
	QString getRecipeIds = "SELECT " + RecipeID + ", " + RecipeName + " FROM " + RecipeTable + " ORDER BY " + RecipeID + " ASC";
	QSqlQuery getRecipeIdsQuery(database);
	if (!getRecipeIdsQuery.exec(getRecipeIds)) {
		const QSqlError error = getRecipeIdsQuery.lastError();
		std::cout << "SQL Error in getRecipeIdsQuery " << error.text().toStdString() << "\n";
		return NULL;
	}
	while(getRecipeIdsQuery.next()) {

		bool ok = false;
		int recipeId = getRecipeIdsQuery.value(0).toInt(&ok);
		std::string recipeName = getRecipeIdsQuery.value(1).toString().toStdString();
		// TODO: Add in logic for finding out if we have the ingredient
		allRecipes->push_back(RecipeTuple(recipeId, recipeName, false));
	}
	return allRecipes;

}

DrinkRecipe * FileMgr::GetRecipe(int recipeId)
{
	QSqlDatabase database = QSqlDatabase::database();
	QString getRecipe = "SELECT " + RecipeRating + ", " + RecipeName + ", " + RecipeDesc + ", " +  RecipeInstructions + " FROM " + RecipeTable + " WHERE " + RecipeID + " = :rId";
	QSqlQuery getRecipeQuery(database);
	getRecipeQuery.prepare(getRecipe);
	getRecipeQuery.bindValue(":rId", recipeId);
	DrinkRecipe * toRet;
	if (!getRecipeQuery.exec()) {
		const QSqlError error = getRecipeQuery.lastError();
		std::cout << "SQL Error in getRecipeQuery " << error.text().toStdString() << "\n";
		return NULL;
	}
	if (getRecipeQuery.next()) {
		bool * ok;
		int recipeRating = getRecipeQuery.value(0).toInt(ok);
		std::string recipeName = getRecipeQuery.value(1).toString().toStdString();
		std::string recipeDesc = getRecipeQuery.value(2).toString().toStdString();
		std::string recipeInstructions = getRecipeQuery.value(3).toString().toStdString();
		toRet = new DrinkRecipe(recipeId, recipeRating, recipeName, recipeDesc, recipeInstructions);
	}
	else {
		return NULL;
	}
	QSqlQuery getIngredientsQuery(database);
	QString getIngredients = "SELECT I." + IngredientID + ", I." + IngredientName + ", RI." + IngredientQuantity + " FROM " + RecipeIngredientsTable + " RI INNER JOIN " + IngredientTable + " I ON I." + IngredientID + " = RI." + IngredientID + " WHERE RI." + RecipeID + " = :rId";
	std::cout << getIngredients.toStdString() << "\n";
	getIngredientsQuery.prepare(getIngredients);
	getIngredientsQuery.bindValue(":rId", recipeId);
	if (!getIngredientsQuery.exec()) {
		const QSqlError error = getIngredientsQuery.lastError();
		std::cout << "SQL Error in getIngredientsQuery " << error.text().toStdString() << "\n";
		return NULL;
	}
	while (getIngredientsQuery.next()) {
		bool * ok;
		int ingredientId = getIngredientsQuery.value(0).toInt(ok);
		std::string ingredientName = getIngredientsQuery.value(1).toString().toStdString();
		std::string ingredientQuantity = getIngredientsQuery.value(2).toString().toStdString();
		toRet->AddIngredient(ingredientId, ingredientName, ingredientQuantity);
	}


	return toRet;
}

const RecipeList * FileMgr::GetSearchResults(const std::string & recipeName, const std::vector<std::string> & ingredientList, bool useAND)
{
	(void)recipeName;
	(void)ingredientList;
	(void)useAND;
	std::cout << "FileMgr: Dummy handle for GetSearchResults." << std::endl;

	m_lastSearchResults->clear();
	m_lastSearchResults->push_back(RecipeTuple(5, "Result 1", true));
	m_lastSearchResults->push_back(RecipeTuple(6, "Result 2", true));
	m_lastSearchResults->push_back(RecipeTuple(7, "Result 3", true));
	m_lastSearchResults->push_back(RecipeTuple(8, "Result 4", true));

	std::cout << "FileMgr searched correctly." << std::endl;

	return m_lastSearchResults;
}


