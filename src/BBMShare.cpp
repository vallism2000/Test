/*
 * BBMShare.cpp
 *
 */

#include "BBMShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>

BBMShare::BBMShare(){

}

BBMShare::~BBMShare(){

}

void BBMShare::share(std::string data){
	// TODO trigger ShareResponseStatusEvent when done,
	// make sure it goes back to the recipe page? or at least the share page.
	QByteArray dataArray = QByteArray();
	dataArray.insert(0, QString::fromStdString(data) );
	m_Invocation = bb::cascades::Invocation::create(
		  bb::cascades::InvokeQuery::create()
		   .parent(this)
		   .mimeType("text/plain")
		   .data(dataArray)
		   .invokeTargetId("sys.bbm.sharehandler")
	);
	QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));


}

void BBMShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}
