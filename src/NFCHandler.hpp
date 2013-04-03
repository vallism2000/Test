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
#include <bb/system/NfcShareManager>
#include <bb/system/NfcShareDataContent>
#include <bb/system/NfcShareMode>
#include "SharePage.hpp"

class NFCHandler : public QObject {

	Q_OBJECT
	Q_PROPERTY(bool sharingActive
	     READ sharingActive
	     WRITE setSharingActive
	     NOTIFY detectSharingActive)

	bool sharingActive() const;
	void setSharingActive(bool sharingState);
public:

	virtual ~NFCHandler();
	static NFCHandler* getInstance(SharePage * sp);
	static NFCHandler* getInstance();
	QString getText(const QByteArray &payload);
	Q_INVOKABLE void parseText(QString text);
	QString FormatTextForPage(const QByteArray &payload);

public slots:
    void dataShareContentChanged(QString message);
    void disableSharing();
    void enableDataSharing();
    void shareModeChanged(bb::system::NfcShareMode::Type mode);
    void finished(bb::system::NfcShareSuccess::Type result);
    void error(bb::system::NfcShareError::Type error);

signals:
    void setShareMode(bb::system::NfcShareMode::Type mode);
    void detectSharingActive();

private:
	// Private since we only want one instance of it
    NFCHandler(SharePage* sp);
	QStringList parseIngredient(QString ing);
	static NFCHandler* nfch_instance;
	bb::system::NfcShareDataContent share_data;
	bb::system::NfcShareManager * share_manager;
	bool sharing_active;
	SharePage* _sharePage;
};

#endif /* NFCHANDLER_HPP_ */
