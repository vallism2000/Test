
#ifndef UIEVENTHANDLER_HPP_
#define UIEVENTHANDLER_HPP_

#include <string>

#include <bb/cascades/ArrayDataModel>

#include "events/IEvent.hpp"
#include "eventListeners/IEventListener.hpp"

class UIEventHandler : public IEventListener
{

public:
	UIEventHandler(bb::cascades::ArrayDataModel * m1, bb::cascades::ArrayDataModel * m2);

	// Handles all incoming events
	void ActOnEvent(IEvent * e);

	// Functions related to Recipes
	void getRecipeList(std::string s="");
	void getRecipe(int index, int id);
	void addRecipe();
	void shareRecipe(int id);
private:
	bb::cascades::ArrayDataModel * model1;
	bb::cascades::ArrayDataModel * model2;
};


#endif /* UIEVENTHANDLER_HPP_ */
