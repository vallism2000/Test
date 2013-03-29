/*
 * DataMgr.cpp
 *
 */

#include "DataMgr.hpp"
#include "CoreEventBus.hpp"

#include <iostream>

DataMgr::DataMgr()
{
	m_fileMgr = FileMgr();
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
	if(e->GetType() == e->INGREDIENTLIST)
	{
		std::cout << "Ingredient List event is being handled." << std::endl;
	}
}
