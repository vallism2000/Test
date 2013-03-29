/*
 * DataMgr.hpp
 *
 */

#ifndef DATAMGR_HPP_
#define DATAMGR_HPP_

#include "eventListeners/IEventListener.hpp"
#include "dataLayer/FileMgr.hpp"

class DataMgr : IEventListener
{
public:
	DataMgr();
	virtual ~DataMgr();

	virtual void ActOnEvent(IEvent * e);

private:
	FileMgr m_fileMgr;
};

#endif /* DATAMGR_HPP_ */
