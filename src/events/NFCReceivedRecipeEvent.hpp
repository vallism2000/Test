/*
 * NFCReceivedRecipeEvent.hpp
 *
 */

#ifndef NFCRECEIVEDRECIPEEVENT_HPP_
#define NFCRECEIVEDRECIPEEVENT_HPP_

#include "IEvent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <string>

class NFCReceivedRecipeEvent: public IEvent{

public:
	NFCReceivedRecipeEvent(DrinkRecipe* recipe);
	virtual ~NFCReceivedRecipeEvent();
	DrinkRecipe* GetRecipe();

private:
	DrinkRecipe *m_recipe;

};


#endif /* NFCRECEIVEDRECIPEEVENT_HPP_ */
