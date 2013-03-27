/*
 * TwitterShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef TWITTERSHARE_HPP_
#define TWITTERSHARE_HPP_

#include "ShareComponent.hpp"
#include <string>
#include <QObject>
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>

class TwitterShare: public QObject, public ShareComponent{

	Q_OBJECT

public:
	TwitterShare();
	virtual ~TwitterShare();
	void share(std::string data);

public slots:
    void onArmed();

private:
	bb::cascades::Invocation *m_Invocation;
};

#endif /* TWITTERSHARE_HPP_ */
