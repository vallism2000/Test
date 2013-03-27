/*
 * BBMShare.hpp
 *
 */

#ifndef BBMSHARE_HPP_
#define BBMSHARE_HPP_

#include <QObject>
#include <string>
#include <bb/cascades/Invocation>
#include <bb/cascades/InvokeQuery>
#include "ShareComponent.hpp"

namespace bb { namespace cascades { class Invocation; } }

class BBMShare: public QObject, public ShareComponent{

	Q_OBJECT

public:
	BBMShare();
	virtual ~BBMShare();
	void share(std::string data);


private:
	bb::cascades::Invocation *m_Invocation;

public slots:
    void onArmed();

};

#endif /* BBMSHARE_HPP_ */
