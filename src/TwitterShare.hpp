/*
 * TwitterShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef TWITTERSHARE_HPP_
#define TWITTERSHARE_HPP_

#include "ShareComponent.hpp"
#include <string>

class TwitterShare: public ShareComponent{

public:
	TwitterShare();
	virtual ~TwitterShare();
	void share(std::string data);


};

#endif /* TWITTERSHARE_HPP_ */
