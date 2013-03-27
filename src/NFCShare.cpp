/*
 * NFCShare.cpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */
#include "NFCShare.hpp"

NFCShare::NFCShare(){

}

NFCShare::~NFCShare(){

}

void NFCShare::share(std::string data){
	// TODO: add the NFC calls to send the data to the other phone, send a ShareResponseEvent


}

// We've specified that sharing sends a string,
// but need to parse that data from the recipe sent in the ShareRecipeEvent.
// Maybe add a general parseRecipe function somewhere?
std::string NFCShare::parseRecipes(Recipe r){

	return "Foo";
}
