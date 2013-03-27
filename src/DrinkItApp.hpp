// Default empty project template
#ifndef DrinkItApp_HPP_
#define DrinkItApp_HPP_

#include <QObject>

#include <bb/cascades/NavigationPane>
#include <bb/cascades/ListView>
#include <bb/cascades/ArrayDataModel>
#include <QString>

#include <string>
#include "drinkObjects/DrinkRecipe.hpp"
#include "SharePage.hpp"

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
    Q_INVOKABLE void getSearchedList();
    Q_INVOKABLE void getRecipe(int index, int id);

    Q_INVOKABLE QString getRecipeName();
    Q_INVOKABLE QString getRecipeInfo();

    Q_INVOKABLE void saveJSON(QString text);
    Q_INVOKABLE void submitRecipe();
    Q_INVOKABLE QString loadJSON();
    Q_INVOKABLE void triggerShareEvent(QString type);

private:
    bb::cascades::NavigationPane *root;
    bb::cascades::ListView *list;
    bb::cascades::ArrayDataModel *model1;
    bb::cascades::ArrayDataModel *model2;

    int recipeID;
    std::string recipeName;
    std::string recipeInfo;

    bool recipeSubmitted;

    void createModules();
    SharePage* _sharePage;
};


#endif /* DrinkItApp_HPP_ */




