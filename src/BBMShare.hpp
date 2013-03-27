/*
 * BBMShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef BBMSHARE_HPP_
#define BBMSHARE_HPP_

#include <QObject>
#include <string>
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include "ShareComponent.hpp"

class BBMShare: public QObject, public ShareComponent{

	Q_OBJECT

public:
	BBMShare();
	virtual ~BBMShare();
	void share(std::string data);


private:
	bb::cascades::Invocation *m_pInvocation;

public slots:
    void onArmed();

};

#endif /* BBMSHARE_HPP_ */
