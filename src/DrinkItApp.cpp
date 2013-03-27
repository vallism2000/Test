// Default empty project template
#include "DrinkItApp.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/Label>

#include <bb/data/JsonDataAccess>
#include <iostream>

#include "CoreEventBus.hpp"

#include "events/ShareRecipeEvent.hpp"
#include "ShareEventBus.hpp"

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
    createModules();
}

void DrinkItApp::getFullList()
{
	model1->clear(); model2->clear();
	model1->append(0); model2->append("White Russian");
	model1->append(1); model2->append("Rum and Coke");
	model1->append(2); model2->append("Irish Car Bomb");
	model1->append(3); model2->append("Long Island Iced Tea");
	if (recipeSubmitted) {
		model1->append(4); model2->append("Submitted Recipe Name");
	}
}

void DrinkItApp::getSearchedList()
{
	//Example call to the CoreEventBus
	CoreEventBus::GetInstance().FireEvent(NULL);

	model1->clear(); model2->clear();
	model1->append(0); model2->append("White Russian");
	model1->append(3); model2->append("Long Island Iced Tea");
}

void DrinkItApp::getRecipe(int index, int id)
{
	recipeID = id;
	recipeName = "";
	if (id == 0) {
		recipeName = "White Russian";
	}
	else if (id == 1) {
		recipeName = "Rum and Coke";
	}
	else if (id == 2) {
		recipeName = "Irish Car Bomb";
	}
	else if (id == 3) {
		recipeName = "Long Island Iced Tea";
	}
	else if (id == 4) {
		recipeName = "Submitted Recipe Name";
	}
	recipeInfo = "";
	if (id == 0) {
		recipeInfo = "Ingredients:\n2oz Vodka\n1oz Coffee Liqueur\nCream";
	}
	else if (id == 1) {
		recipeInfo = "Ingredients:\n4oz Rum\n8oz Coca Cola";
	}
	else if (id == 2) {
		recipeInfo = "Ingredients:\n1 Pint Guiness/Dry Irish Stout\n1oz Irish Cream Liqueur\n1oz Irish Whiskey";
	}
	else if (id == 3) {
		recipeInfo = "Ingredients:\n1oz Vodka\n1oz Tequila\n1oz Rum\n1oz Gin\n1oz Triple Sec\n1.5oz Sour Mix\n1 Splash Coca Cola";
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

	QVariantMap testObj;
	testObj.insert("text",text);

	QVariant testData = QVariant(testObj);

	QDir home = QDir::home();
	QFile file(home.absoluteFilePath("test.json"));

	if (file.open(QIODevice::WriteOnly))
	{
		bb::data::JsonDataAccess jda;
		jda.save(testData, &file);

		if(jda.hasError())
		{
			std::cout << "errors encountered saving" << std::endl;
		}
		file.close();
	}
	else
	{
		std::cout << "File would not open." << std::endl;
	}
}

QString DrinkItApp::loadJSON()
{
	std::cout << "Loading data from file." << std::endl;

	bb::data::JsonDataAccess jda;
	QDir home = QDir::home();
	QVariant list = jda.load(home.absoluteFilePath("test.json"));

	if(jda.hasError())
	{
		std::cout << "errors encountered loading" << std::endl;

		std::cout << jda.error().errorMessage().toStdString() << std::endl;
	}

	QVariantMap map = list.value<QVariantMap>();
	return map.value("text").toString();
}

void DrinkItApp::createModules(){
	_sharePage = new SharePage();
}

void DrinkItApp::triggerShareEvent(QString type){
	std::cout << "trigger share event" << std::endl;
	DrinkRecipe* m_recipe = new DrinkRecipe(1, "foo", "fooooooo", new DrinkIngredient(1, "bar", "1 part"), 1);
    // Assuming the share page somehow knows which recipe to share
    ShareRecipeEvent *e = new ShareRecipeEvent(type.toStdString()+"Share", m_recipe);
	ShareEventBus::GetInstance().FireEvent(e);

}




