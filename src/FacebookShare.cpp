/*
 * FacebookShare.cpp
 *
 */

#include "FacebookShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>

FacebookShare::FacebookShare(){

}

FacebookShare::~FacebookShare(){

}

void FacebookShare::share(std::string data){

	// Getting the data into the right format for the invocation
	QByteArray dataArray = QByteArray();
	dataArray.insert(0, QString::fromStdString(data) );

	// Using invocation for now, if we want to interact with the DrinkIt facebook app we'll have to change this
	m_Invocation = bb::cascades::Invocation::create(bb::cascades::InvokeQuery::create()
	    .parent(this)
		.mimeType("text/plain")
	    .invokeTargetId("Facebook")
		.data(dataArray));
   QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));

}

void FacebookShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}
// TODO not sure what the RequestRecipes function returns, leaving it out for now
