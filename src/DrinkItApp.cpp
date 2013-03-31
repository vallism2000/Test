// Default empty project template
#include "DrinkItApp.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/Label>

#include <bb/data/JsonDataAccess>
#include <iostream>

#include "CoreEventBus.hpp"

//TEMP
#include "events/RemoveRecipeEvent.hpp"

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
    root = qml->createRootObject<TabbedPane>();
    // set created root object as a scene
    app->setScene(root);

    //Initialize the event bus
    CoreEventBus::Initialize();

    //Initialize the data manager.
    //It will live at the app layer. Nothing calls it directly.
    //Just through the event bus.
    m_dataManager = new DataMgr();

    // Find Cascades Objects
    list = root->findChild<ListView*>("recipeList");
    model1 = root->findChild<ArrayDataModel*>("recipeID");
    model2 = root->findChild<ArrayDataModel*>("recipeName");

    // Create Listener
    EH = new UIEventHandler(model1, model2);

    recipeSubmitted = false;

    getFullList();

    // Set up ShareObject
    createModules();
    qml->setContextProperty("_shareObject", _sharePage);

    // Initialize share event bus
    ShareEventBus::Initialize();
    _shareListener = new ShareEventListener();
    ShareEventBus::RegisterListener(_shareListener);
}

void DrinkItApp::getFullList()
{
	EH->getRecipeList("");
}

void DrinkItApp::getSearchedList()
{
	//Example call to the CoreEventBus
	CoreEventBus::FireEvent(new RemoveRecipeEvent(0));

	EH->getRecipeList("Search Info");
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






