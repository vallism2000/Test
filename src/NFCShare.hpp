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
#include <nfc/nfc_ndef.h>
#include <bb/system/NfcShareManager>
#include <bb/system/NfcShareDataContent>

class NFCShare: public QObject, public ShareComponent{

	Q_OBJECT

public:
	NFCShare();
	virtual ~NFCShare();
	void share(std::string data);
	std::string recipeToString(DrinkRecipe *r);
	Q_INVOKABLE void clearShare();

private:
	bb::cascades::Invocation *m_Invocation;
	bb::system::NfcShareDataContent share_data;
	bb::system::NfcShareManager * share_manager;

public slots:
	void onArmed();

};


#endif /* NFCSHARE_HPP_ */
