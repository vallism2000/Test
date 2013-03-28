/*
 * DataMgr.cpp
 *
 */

#include "DataMgr.hpp"
#include "CoreEventBus.hpp"

#include <iostream>

DataMgr::DataMgr()
{
	std::cout << "About to register the DataMgr" << std::endl;
	CoreEventBus::RegisterListener(this);
}

DataMgr::~DataMgr()
{
	std::cout << "About to unregister the DataMgr" << std::endl;
	CoreEventBus::UnRegisterListener(this);
}

void DataMgr::ActOnEvent(IEvent * e)
{
	std::cout << "Data mgr is acting on an event." << std::endl;
}
