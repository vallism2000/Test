// Default empty project template
#include "DrinkItApp.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/Label>

#include <iostream>

using namespace bb::cascades;

DrinkItApp::DrinkItApp(bb::cascades::Application *app)
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

    recipeSubmitted = false;

    getFullList();
}

void DrinkItApp::getFullList()
{
	model1->clear(); model2->clear();
	model1->append(0); model2->append("Drink with Vodka");
	model1->append(1); model2->append("Drink with Rum");
	model1->append(2); model2->append("Drink with Whisky");
	model1->append(3); model2->append("Drink with Vodka and Rum");
	if (recipeSubmitted) {
		model1->append(4); model2->append("Submitted Recipe Name");
	}
}

void DrinkItApp::getSearchedList()
{
	model1->clear(); model2->clear();
	model1->append(0); model2->append("Drink with Vodka");
	model1->append(3); model2->append("Drink with Vodka and Rum");
}

void DrinkItApp::getRecipe(int index, int id)
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
	else if (id == 4) {
		recipeName = "Submitted Recipe Name";
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
	else if (id == 4) {
		recipeInfo = "Submitted Recipe Info";
	}
	std::cout << "index: '" << index << "', id: '" << id << "'" << std::endl;
}

QString DrinkItApp::getRecipeName()
{
	std::cout << "recipe name: '" << recipeName << "'" << std::endl;
	return (QString(recipeName.c_str()));
}

QString DrinkItApp::getRecipeInfo()
{
	return (QString(recipeInfo.c_str()));
}

void DrinkItApp::submitRecipe()
{
	recipeSubmitted = true;
}

//The following are file save/load methods and should not be located here according to our architecture.

void DrinkItApp::saveJSON(QString text)
{
	std::cout << "Saving " << text.toStdString() << " to file." << std::endl;
}

QString DrinkItApp::loadJSON()
{
	std::cout << "Loading data from file." << std::endl;

	return "NOTWORKINGYET";
}




