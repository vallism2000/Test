/*
 * NFCShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef NFCSHARE_HPP_
#define NFCSHARE_HPP_

#include "ShareComponent.hpp"
#include "drinkObjects/DrinkRecipe.hpp"
#include <string>

class NFCShare: public ShareComponent{

public:
	NFCShare();
	virtual ~NFCShare();
	void share(std::string data);

private:
	std::string parseRecipe(Recipe r);

};


#endif /* NFCSHARE_HPP_ */
