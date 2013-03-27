/*
 * ShareEventListener.hpp
 *
 */

#ifndef SHAREEVENTLISTENER_HPP_
#define SHAREEVENTLISTENER_HPP_

#include "eventListeners/IEventListener.hpp"
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include <QObject>

namespace bb { namespace cascades { class Invocation; } }

class ShareEventListener: public QObject, public IEventListener{

	Q_OBJECT

public:
	ShareEventListener();
	virtual ~ShareEventListener();
	void ActOnEvent(IEvent *e);
	void debugTest();

public slots:
	void onArmed();


private:
	bb::cascades::Invocation* m_invocation;

};


#endif /* SHAREEVENTLISTENER_HPP_ */
