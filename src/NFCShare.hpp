/*
 * NFCShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
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
	std::string parseRecipe(DrinkRecipe *r);

private:
	bb::cascades::Invocation *m_Invocation;

public slots:
	void onArmed();

};


#endif /* NFCSHARE_HPP_ */
