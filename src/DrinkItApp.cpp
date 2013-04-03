// Default empty project template
#include "DrinkItApp.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <bb/cascades/Label>
#include <bb/cascades/TextArea>

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
    list2 = root->findChild<ListView*>("invList");
    list3 = root->findChild<ListView*>("shopList");
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
    QObject::connect(this, SIGNAL(message(QVariant, QVariant)), root, SLOT(message(QVariant, QVariant)));
    QObject::connect(this, SIGNAL(launchReader(QVariant)), root, SLOT(launchReader(QVariant)));
}

void DrinkItApp::getFullList()
{
	EH->getRecipeList("");
}

void DrinkItApp::getSearchedList(QString s)
{
	//Example call to the CoreEventBus
	CoreEventBus::FireEvent(new RemoveRecipeEvent(0));

	EH->getRecipeList(s.toStdString());
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

int DrinkItApp::getRecipeRating(){

	recipeRating = EH->getRecipeRating();

	return recipeRating;
}

int DrinkItApp::getRecipeID(){

	recipeID = EH->getRecipeID();

	return recipeID;
}

std::vector<std::pair<DrinkIngredient, std::string> > DrinkItApp::getIngredients(){
	recipeIngredients = EH->getRecipeIngredients();

	return recipeIngredients;
}

QString DrinkItApp::getInstructions(){

	recipeInstr = EH->getRecipeInstructions();

	return (QString(recipeInstr.c_str()));
}

QString DrinkItApp::getIngredientsText(){
	QString ings;

    recipeIngredients = EH->getRecipeIngredients();

	for(unsigned int i=0; i < recipeIngredients.size(); i++){
		std::pair<DrinkIngredient, std::string>  tmp = recipeIngredients.at(i);
		std::string name = tmp.first.GetName();
		std::string amount = tmp.second;

		ings.append( QString::fromStdString(amount) + " \t" + QString::fromStdString(name) + "\n");
	}

	return ings;
}

void DrinkItApp::submitRecipe()
{
	//recipeSubmitted = true;
	std::string text[3];
	std::string ingred[5];
	std::string amount[5];
	int size = 5;

	text[0] = root->findChild<TextArea*>("addName")->text().toStdString();
	text[1] = root->findChild<TextArea*>("addInfo")->text().toStdString();
	text[2] = root->findChild<TextArea*>("addInst")->text().toStdString();

	ingred[0] = root->findChild<TextArea*>("ing11")->text().toStdString();
	ingred[1] = root->findChild<TextArea*>("ing21")->text().toStdString();
	ingred[2] = root->findChild<TextArea*>("ing31")->text().toStdString();
	ingred[3] = root->findChild<TextArea*>("ing41")->text().toStdString();
	ingred[4] = root->findChild<TextArea*>("ing51")->text().toStdString();

	amount[0] = root->findChild<TextArea*>("ing12")->text().toStdString();
	amount[1] = root->findChild<TextArea*>("ing22")->text().toStdString();
	amount[2] = root->findChild<TextArea*>("ing32")->text().toStdString();
	amount[3] = root->findChild<TextArea*>("ing42")->text().toStdString();
	amount[4] = root->findChild<TextArea*>("ing52")->text().toStdString();

	for (int i=5; i>0; i--) {
		if (ingred[i-1] == "") {
			size = i-1;
		}
	}

	EH->addRecipe(0, text, ingred, amount, size);
}
void DrinkItApp::removeRecipe() {
	EH->removeRecipe();
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

void DrinkItApp::moveListItems(bool isShopList) {
	int x;
	int y;
	std::string z;
	if (!isShopList) {
		for (int i=0; i<list2->selectionList().size(); i++) {
			x = list2->selectionList().at(i).toList().at(0).toInt();
			y = model3->value(x).toInt();
			z = model4->value(x).toString().toStdString();
			//std::cout << "'" << x << "', '" << y << "'" << std::endl;
			EH->moveListItem(y, z, false);
		}
	} else {
		for (int i=0; i<list3->selectionList().size(); i++) {
			x = list3->selectionList().at(i).toList().at(0).toInt();
			y = model5->value(x).toInt();
			z = model6->value(x).toString().toStdString();
			//std::cout << "'" << x << "', '" << y << "'" << std::endl;
			EH->moveListItem(y, z, true);
		}
	}
	if (!isShopList) {
		getInvList();
	} else {
		getShopList();
	}
}

void DrinkItApp::removeListItems(bool isShopList) {
	int x;
	int y;
	std::string z;
	if (!isShopList) {
		for (int i=0; i<list2->selectionList().size(); i++) {
			x = list2->selectionList().at(i).toList().at(0).toInt();
			y = model3->value(x).toInt();
			z = model4->value(x).toString().toStdString();
			//std::cout << "'" << x << "', '" << y << "'" << std::endl;
			EH->removeListItem(y, z, false);
		}
	} else {
		for (int i=0; i<list3->selectionList().size(); i++) {
			x = list3->selectionList().at(i).toList().at(0).toInt();
			y = model5->value(x).toInt();
			z = model6->value(x).toString().toStdString();
			//std::cout << "'" << x << "', '" << y << "'" << std::endl;
			EH->removeListItem(y, z, true);
		}
	}
	if (!isShopList) {
		getInvList();
	} else {
		getShopList();
	}
}

void DrinkItApp::addListItem(QString name, bool isShopList) {
	EH->addListItem(name.toStdString(), isShopList);
	if (!isShopList) {
		getInvList();
	} else {
		getShopList();
	}
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
	 			emit message(QString("%1").arg(_nfcHandler->getText(ndefRecord->payload())),
	 					QString("%1").arg(_nfcHandler->FormatTextForPage(ndefRecord->payload())));
	 		}
	 	}

	 }
}

void DrinkItApp::updateRecipeRating(int rating){
    EH->updateRecipeRating(rating);
}



