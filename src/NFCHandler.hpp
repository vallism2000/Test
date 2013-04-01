/*
 * NFCHandler.hpp
 *
 */

#ifndef NFCHANDLER_HPP_
#define NFCHANDLER_HPP_

#include <QObject>

#include <bb/system/InvokeManager.hpp>
#include <bb/system/InvokeRequest.hpp>
#include <QtNfcSubset/qndefmessage.h>

#include <bps/bps.h>
#include <nfc/nfc.h>
#include <nfc/nfc_ndef.h>

class NFCHandler : public QObject {

	Q_OBJECT
public:

	virtual ~NFCHandler();
	static NFCHandler* getInstance();
	QString getText(const QByteArray &payload);
	Q_INVOKABLE void parseText(QString text);
	QString FormatTextForPage(const QByteArray &payload);


private:
	// Private since we only want one instance of it
	NFCHandler();
	QStringList parseIngredient(QString ing);
	static NFCHandler* nfch_instance;
};

#endif /* NFCHANDLER_HPP_ */
