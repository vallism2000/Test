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
    nav = root->findChild<NavigationPane*>("nav");
    list = root->findChild<ListView*>("recipeList");
    model1 = root->findChild<ArrayDataModel*>("recipeID");
    model2 = root->findChild<ArrayDataModel*>("recipeName");
    model3 = root->findChild<ArrayDataModel*>("invID");
    model4 = root->findChild<ArrayDataModel*>("invName");
    model5 = root->findChild<ArrayDataModel*>("shopID");
    model6 = root->findChild<ArrayDataModel*>("shopName");

    ArrayDataModel* IDs[] = {model1, model3, model5};
    ArrayDataModel* Names[] = {model2, model4, model6};

    // Create Listener
    EH = new UIEventHandler(IDs, Names, nav);

    recipeSubmitted = false;

    getFullList();
    getInvList();
    getShopList();

    // Set up ShareObject
    createModules();
    qml->setContextProperty("_shareObject", _sharePage);

    // Initialize share event bus
    ShareEventBus::Initialize();
    _shareListener = new ShareEventListener();
    ShareEventBus::RegisterListener(_shareListener);

    _invokeManager = new bb::system::InvokeManager();
    _nfcHandler = NFCHandler::getInstance();
    qml->setContextProperty("_nfcHandlerObject", _nfcHandler);

    // Connections for receving nfc
    QObject::connect(_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)), this,
    		SLOT(receivedInvokeRequest(const bb::system::InvokeRequest&)));
    QObject::connect(this, SIGNAL(message(QVariant)), root, SLOT(message(QVariant)));
    QObject::connect(this, SIGNAL(launchReader(QVariant)), root, SLOT(launchReader(QVariant)));
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
	recipeName = "BAD DATA";
	recipeInfo = "MORE BAD DATA";

	EH->getRecipe(index, id);
}

QString DrinkItApp::getRecipeName()
{
	recipeName = EH->getRecipeName();

	std::cout << "recipe name: '" << recipeName << "'" << std::endl;
	return (QString(recipeName.c_str()));
}

QString DrinkItApp::getRecipeInfo()
{
	recipeInfo = EH->getRecipeDescription();

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

void DrinkItApp::getInvList()
{
	EH->getInvList();
}

void DrinkItApp::getShopList()
{
	EH->getShopList();
}

void DrinkItApp::receivedInvokeRequest(const bb::system::InvokeRequest& request) {

	 QByteArray data = request.data();
	 QtMobilitySubset::QNdefMessage ndefMessage = QtMobilitySubset::QNdefMessage::fromByteArray(data);


	 QList<QtMobilitySubset::QNdefRecord>::const_iterator ndefRecord;

	 for ( ndefRecord = ndefMessage.begin(); ndefRecord != ndefMessage.end(); ndefRecord++) {


	 	if (ndefRecord->typeNameFormat() == QtMobilitySubset::QNdefRecord::NfcRtd) {
	 		if (ndefRecord->type() == "T") {
	 			std::cout << "Detected a Text Tag" << std::endl;
	 			emit launchReader(QString("Tag read event detected"));
	 			emit message(QString("%1").arg(_nfcHandler->getText(ndefRecord->payload())));
	 		}
	 	}

	 }
}



