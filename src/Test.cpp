// Default empty project template
#include "Test.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

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
    NavigationPane *root = qml->createRootObject<NavigationPane>();
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
	model1->append(1); model2->append("Drink with Vodka");
	model1->append(2); model2->append("Drink with Rum");
	model1->append(3); model2->append("Drink with Whisky");
	model1->append(4); model2->append("Drink with Vodka and Rum");
}

void Test::getSearchedList()
{
	model1->clear(); model2->clear();
	model1->append(1); model2->append("Drink with Vodka");
	model1->append(4); model2->append("Drink with Vodka and Rum");
}
