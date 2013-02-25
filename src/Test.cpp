// Default empty project template
#include "Test.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/Label>

#include <iostream>

using namespace bb::cascades;

Test::Test(bb::cascades::Application *app)
: QObject(app)
{
    // create scene document from main.qml asset
    // set parent to created document to ensure it exists for the whole application lifetime
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    //
    qml->setContextProperty("TestObject", this);

    // create root object for the UI
    root = qml->createRootObject<NavigationPane>();
    // set created root object as a scene
    app->setScene(root);

    // Test Stuff
    list = root->findChild<ListView*>("recipeList");
    model1 = root->findChild<ArrayDataModel*>("recipeID");
    model2 = root->findChild<ArrayDataModel*>("recipeName");

    getFullList();
}

void Test::getFullList()
{
	model1->clear(); model2->clear();
	model1->append(0); model2->append("Drink with Vodka");
	model1->append(1); model2->append("Drink with Rum");
	model1->append(2); model2->append("Drink with Whisky");
	model1->append(3); model2->append("Drink with Vodka and Rum");
}

void Test::getSearchedList()
{
	model1->clear(); model2->clear();
	model1->append(0); model2->append("Drink with Vodka");
	model1->append(3); model2->append("Drink with Vodka and Rum");
}

void Test::getRecipe(int index, int id)
{
	recipeID = id;
	recipeName = "";
	if (id == 0) {
		recipeName = "Drink with Vodka";
	}
	else if (id == 1) {
		recipeName = "Drink with Rum";
	}
	else if (id == 2) {
		recipeName = "Drink with Whisky";
	}
	else if (id == 3) {
		recipeName = "Drink with Vodka and Rum";
	}
	recipeInfo = "";
	if (id == 0) {
		recipeInfo = "This drink recipe uses Vodka";
	}
	else if (id == 1) {
		recipeInfo = "This drink recipe uses Rum";
	}
	else if (id == 2) {
		recipeInfo = "This drink recipe uses Whisky";
	}
	else if (id == 3) {
		recipeInfo = "This drink recipe uses Vodka and Rum";
	}
	std::cout << "index: '" << index << "', id: '" << id << "'" << std::endl;
}

QString Test::getRecipeName()
{
	std::cout << "recipe name: '" << recipeName << "'" << std::endl;
	return (QString(recipeName.c_str()));
}

QString Test::getRecipeInfo()
{
	return (QString(recipeInfo.c_str()));
}




