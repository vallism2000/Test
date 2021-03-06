// Default empty project template
#ifndef DrinkItApp_HPP_
#define DrinkItApp_HPP_

#include <QObject>

#include <bb/cascades/TabbedPane>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ArrayDataModel>
#include <QString>

#include <string>
#include "dataLayer/DataMgr.hpp"
#include "eventListeners/ShareEventListener.hpp"
#include "SharePage.hpp"

#include "UIEventHandler.hpp"


#include <bb/system/InvokeManager>
#include <bb/system/InvokeRequest>
#include <nfc/nfc.h>
#include <nfc/nfc_ndef.h>
#include <QtNfcSubset/qndefmessage.h>
#include "NFCHandler.hpp"

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class DrinkItApp : public QObject
{
    Q_OBJECT
public:
    DrinkItApp(bb::cascades::Application *app);
    virtual ~DrinkItApp() {}
    Q_INVOKABLE void getFullList();
    Q_INVOKABLE void getSearchedList(QString s);
    Q_INVOKABLE void getRecipe(int index, int id);

    Q_INVOKABLE QString getRecipeName();
    Q_INVOKABLE QString getRecipeInfo();
    Q_INVOKABLE int getRecipeRating();
    Q_INVOKABLE std::vector<std::pair<DrinkIngredient, std::string> > getIngredients();
    Q_INVOKABLE QString getInstructions();
    Q_INVOKABLE int getRecipeID();
    Q_INVOKABLE QString getIngredientsText();

    Q_INVOKABLE void saveJSON(QString text);
    Q_INVOKABLE void submitRecipe();
    Q_INVOKABLE void removeRecipe();
    Q_INVOKABLE QString loadJSON();

    Q_INVOKABLE void getInvList();
    Q_INVOKABLE void getShopList();
    Q_INVOKABLE void moveListItems(bool isShopList);
    Q_INVOKABLE void removeListItems(bool isShopList);

    Q_INVOKABLE void addListItem(QString name, bool isShopList);
    Q_INVOKABLE void addIngredientsToShoppingList();

    Q_INVOKABLE void updateRecipeRating(int rating);
    Q_INVOKABLE QString getIngredientTextAt(int i);
    Q_INVOKABLE QString getIngredientQuantityTextAt(int i);
    Q_INVOKABLE void modRecipe();

private:
    bb::cascades::TabbedPane *root;
    bb::cascades::NavigationPane *nav;
    bb::cascades::ListView *list;
    bb::cascades::ListView *list2;
    bb::cascades::ListView *list3;
    bb::cascades::ArrayDataModel *model1;
    bb::cascades::ArrayDataModel *model2;
    bb::cascades::ArrayDataModel *model3;
    bb::cascades::ArrayDataModel *model4;
    bb::cascades::ArrayDataModel *model5;
    bb::cascades::ArrayDataModel *model6;

    int recipeID;
    std::string recipeName;
    std::string recipeInfo;
    std::string recipeInstr;
    std::vector<std::pair<DrinkIngredient, std::string> > recipeIngredients;
    int recipeRating;

    bool recipeSubmitted;
    DataMgr * m_dataManager;

    UIEventHandler * EH;

    void createModules();
    SharePage* _sharePage;
    ShareEventListener* _shareListener;
    bb::system::InvokeManager* _invokeManager;
    NFCHandler* _nfcHandler;
    bb::cascades::AbstractPane *test;

signals:
    void message(const QVariant &text, const QVariant &formatted);
    void launchReader(const QVariant &text);

public slots:
    void receivedInvokeRequest(const bb::system::InvokeRequest& request);


};


#endif /* DrinkItApp_HPP_ */




