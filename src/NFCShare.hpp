/*
 * NFCShare.hpp
 *
 */

#ifndef NFCSHARE_HPP_
#define NFCSHARE_HPP_

#include "ShareComponent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <string>
#include <QObject>
#include <bb/cascades/Invocation>

class NFCShare: public QObject, public ShareComponent{

	Q_OBJECT

public:
	NFCShare();
	virtual ~NFCShare();
	void share(std::string data);
	std::string recipeToString(DrinkRecipe *r);

private:
	bb::cascades::Invocation *m_Invocation;

public slots:
	void onArmed();

};


#endif /* NFCSHARE_HPP_ */
