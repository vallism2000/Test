/*
 * SharePage.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef SHAREPAGE_HPP_
#define SHAREPAGE_HPP_

#include <QObject>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/Container>
#include <bb/cascades/Page>
#include <string>
#include "events/ShareRecipeEvent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"

using namespace bb::cascades;

class SharePage: public QObject{

	Q_OBJECT

public:
	SharePage();
	virtual ~SharePage();

private:
	QmlDocument *m_qml;
	Page *m_root;
	Q_INVOKABLE void triggerShareEvent(std::string type);
	DrinkRecipe *m_recipe;

};


#endif /* SHAREPAGE_HPP_ */
