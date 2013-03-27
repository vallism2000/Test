/*
 * TwitterShare.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#include "TwitterShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>

TwitterShare::TwitterShare(){

}

TwitterShare::~TwitterShare(){

}

void TwitterShare::share(std::string data){
	// TODO: add invocation framework call to share the data
	// This relies on the Twitter app being on the phone. Should have some sort of check or find out if invocation framework checks

	// Getting the data into the right format for the invocation
	QByteArray dataArray = QByteArray();
    dataArray.insert(0, QString::fromStdString(data) );

	// Make the invocation
	  m_Invocation = bb::cascades::Invocation::create(bb::cascades::InvokeQuery::create()
		  .parent(this)
		  .mimeType("text/plain")
		  .invokeTargetId("Twitter")
		  .data(dataArray));
	  QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	  QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));
}

void TwitterShare::onArmed() {
	m_Invocation->trigger("bb.action.SHARE");
}
