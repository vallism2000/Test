/*
 * TwitterShare.cpp
 *
 */

#include "TwitterShare.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include <iostream>

TwitterShare::TwitterShare(){

}

TwitterShare::~TwitterShare(){

}

void TwitterShare::share(std::string data){
	std::cout << "Twitter Share called" << std::endl;
	// TODO: add invocation framework call to share the data
	// This relies on the Twitter app being on the phone. Should have some sort of check or find out if invocation framework checks

	// Getting the data into the right format for the invocation
	QByteArray dataArray = QByteArray();
    dataArray.insert(0, QString::fromStdString(data) );

	// Make the invocation
	  m_Invocation = bb::cascades::Invocation::create(bb::cascades::InvokeQuery::create()
		  .parent(this)
		  .mimeType("text/plain")
		  .uri("data://")
		  .invokeTargetId("Twitter")
		  .data(dataArray));
	  QObject::connect(m_Invocation, SIGNAL(armed()), this, SLOT(onArmed()));
	  QObject::connect(m_Invocation, SIGNAL(finished()), m_Invocation, SLOT(deleteLater()));
}

void TwitterShare::onArmed() {
	std::cout << "calling onArmed" << std::endl;
	m_Invocation->trigger("bb.action.SHARE");
}
