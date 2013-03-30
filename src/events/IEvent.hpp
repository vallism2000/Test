/*
 * IEvent.hpp
 *
 */

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

#include <string>

class IEvent {
public:

	enum EventType
	{
		INGREDIENTLIST,
		RECIPEADD,
		UIRECIPELISTREQUEST,
		UIRECIPEREQUEST,
		UISHAREREQUEST,
		NFCRECEIVEDRECIPE,
		SHARERESPONSESTATUS,
		BBMSHARE,
		NFCSHARE,
		FACEBOOKSHARE,
		TWITTERSHARE
	};


	IEvent(EventType type);
	virtual ~IEvent();

	EventType GetType();

private:
	EventType m_type;
};

#endif /* IEVENT_HPP_ */
