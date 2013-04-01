/*
 * NFCShare.cpp
 *
 */
#include "NFCShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include <nfc/nfc_ndef.h>
#include <bb/system/NfcShareManager>
#include <bb/system/NfcShareDataContent>


NFCShare::NFCShare(){

}

NFCShare::~NFCShare(){

}

void NFCShare::share(std::string data){
	// TODO: add the NFC calls to send the data to the other phone, send a ShareResponseEvent

	/*bb::system::NfcShareDataContent share_data = bb::system::NfcShareDataContent();
	bb::system::NfcShareManager *share_manager = new bb::system::NfcShareManager();

	QString text = QString::fromStdString(data);
	QByteArray array_data = QByteArray();
	array_data.insert(0, text);

	share_data.setMimeType("text/plain");
	share_data.setData(array_data);

	share_manager->setShareMode(bb::system::NfcShareMode::Data);
	share_manager->setShareContent(share_data);
*/
// Can't test invoke NFC on the simulator
 QByteArray data_array = QByteArray();
 data_array.insert(0, QString::fromStdString(data) );
	m_Invocation = bb::cascades::Invocation::create(
			  bb::cascades::InvokeQuery::create()
			   .parent(this)
			   .mimeType("text/plain")
			   //.mimeType("application/drinkitapp")
			   .data(data_array)
			   //.invokeTargetId("sys.NFCViewer")
		);
	QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));




}

// We've specified that sharing sends a string,
// but need to parse that data from the recipe sent in the ShareRecipeEvent.
// Maybe add a general parseRecipe function somewhere?
std::string NFCShare::parseRecipe(DrinkRecipe *r){

	return "Foo";
}

void NFCShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}
