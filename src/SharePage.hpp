/*
 * SharePage.hpp
 *
 */

#ifndef SHAREPAGE_HPP_
#define SHAREPAGE_HPP_

#include <QObject>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Container>
#include <bb/cascades/Page>
#include <string>
#include "events/ShareRecipeEvent.hpp"
#include "eventListeners/ShareEventListener.hpp"
#include "drinkObjects/DrinkRecipe.hpp"

using namespace bb::cascades;

class SharePage: public QObject{

	Q_OBJECT

public:
	SharePage();
	virtual ~SharePage();
	Q_INVOKABLE void triggerShareEvent(QString type);
	Q_INVOKABLE void setRecipeID(int id);
	Q_INVOKABLE void setRecipeName(QString name);
	Q_INVOKABLE void setRecipeDesc(QString desc);
	Q_INVOKABLE void setRecipeIngredients(std::vector<std::pair<DrinkIngredient, std::string> > ingredients);
	Q_INVOKABLE void setRecipeInstructions(QString instructions);
	Q_INVOKABLE void setRating(int rating);

private:
	QmlDocument *m_qml;
	Page *m_root;
	DrinkRecipe *m_recipe;
    std::string recipeName;
	std::string recipeDesc;
	std::string recipeInstr;
	std::vector<std::pair<DrinkIngredient, std::string> > recipeIngredients;
	int recipeRating;
	int recipeID;

};


#endif /* SHAREPAGE_HPP_ */
