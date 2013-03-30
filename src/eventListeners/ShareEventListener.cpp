/*
 * ShareEventListener.cpp
 *
 */

#include "events/IEvent.hpp"
#include "events/ShareRecipeEvent.hpp"
#include "ShareEventListener.hpp"
#include <bb/cascades/InvokeQuery>
#include <string>
#include <iostream>
#include <QByteArray>
#include "BBMShare.hpp"
#include "TwitterShare.hpp"
#include "FacebookShare.hpp"
#include "NFCShare.hpp"

ShareEventListener::ShareEventListener(){

}

ShareEventListener::~ShareEventListener(){

}

void ShareEventListener::ActOnEvent(IEvent *e){
    std::string data;
	IEvent::EventType type = e->GetType();
	ShareRecipeEvent *se = (ShareRecipeEvent*)e;

	// For helping debug, remove later
    std::cout << "ActOnEvent "<< type << std::endl;

	if( type == IEvent::NFCSHARE){
		// TODO
		std::cout << "Got NFCShare event" << std::endl;




	} else if( type == IEvent::BBMSHARE ){
		// Prepare the data that will be shared
		data = "I just made a " + se->GetRecipe()->GetName() + "with DrinkItApp!";
		// Call the share function
		BBMShare* bbm = new BBMShare();
		bbm->share(data);

		std::cout << "Got BBMShare event" << std::endl;


	} else if (type == IEvent::TWITTERSHARE){
		// Prepare the data that will be shared
	    data = "I just made a " + se->GetRecipe()->GetName() + "with DrinkItApp!";

	    TwitterShare* tw = new TwitterShare();
	    tw->share(data);

		// TODO: Should figure out the status, send the ShareResponseStatusEvent

		std::cout << "Got TwitterShare event" << std::endl;

	} else if (type == IEvent::FACEBOOKSHARE){

		// Prepare the data that will be shared
		data = "I just made a " + se->GetRecipe()->GetName() + " with DrinkItApp!";

		FacebookShare* fbs = new FacebookShare();
        fbs->share(data);

		std::cout << "Got FacebookShare event" << std::endl;

	} else if (type == IEvent::NFCRECEIVEDRECIPE){
		// TODO
		std::cout << "Got NFCReceivedRecipe event" << std::endl;
	} else if (type == IEvent::SHARERESPONSESTATUS){
		// TODO
		std::cout << "Got ShareResponseStatus event" << std::endl;
	}
}
