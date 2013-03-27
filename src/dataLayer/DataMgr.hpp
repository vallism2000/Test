/*
 * DataMgr.hpp
 *
 */

#ifndef DATAMGR_HPP_
#define DATAMGR_HPP_

#include "eventListeners/IEventListener.hpp"

class DataMgr : IEventListener
{
public:
	DataMgr();
	virtual ~DataMgr();

	virtual void ActOnEvent(IEvent * e);
};

#endif /* DATAMGR_HPP_ */
