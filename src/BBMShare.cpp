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
	// TODO add invocation framework calls, trigger ShareResponseStatusEvent when done,
	// make sure it goes back to the recipe page? or at least the share page.

	m_pInvocation = Invocation::create(
		  InvokeQuery::create()
		   .parent(this)
		   .mimeType("text/plain")
		   .data(data)
		   .targetID(sys.bbm.sharehandler)
	);
	QObject::connect(m_pInvocation, SIGNAL(armed()), this, SLOT(onArmed()));
	QObject::connect(m_pInvocation, SIGNAL(finished()), m_pInvocation, SLOT(deleteLater()));


}

void BBMShare::onArmed() {
	m_pInvocation->trigger("bb.action.SHARE");
}
