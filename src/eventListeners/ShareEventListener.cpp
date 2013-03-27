/*
 * ShareEventListener.cpp
 *
 */

#include "ShareEventListener.hpp"
#include <string>

ShareEventListener::ShareEventListener(){

}

ShareEventListener::~ShareEventListener(){

}

void ShareEventListener::ActOnEvent(IEvent *e){
	std::string type = e->GetType();

	if( type == "NFCShare"){
		// TODO
	} else if( type == "BBMShare" ){
		// TODO
	} else if (type == "TwitterShare"){
		// TODO
	} else if (type == "FacebookShare"){
		// TODO
	} else if (type == "NFCReceivedRecipeEvent"){
		// TODO
	} else if (type == "ShareResponseStatus"){
		// TODO
	}
}

