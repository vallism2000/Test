/*
 * FacebookShare.hpp
 *
 */

#ifndef FACEBOOKSHARE_HPP_
#define FACEBOOKSHARE_HPP_

#include <QObject>
#include <string>
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include "ShareComponent.hpp"

class FacebookShare: public QObject, public ShareComponent{
	Q_OBJECT

public:
	FacebookShare();
	virtual ~FacebookShare();
	void share(std::string data);
	void getRecipes();

private:
	bb::cascades::Invocation *m_Invocation;

public slots:
    void onArmed();

};

#endif /* FACEBOOKSHARE_HPP_ */
