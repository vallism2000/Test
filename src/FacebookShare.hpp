/*
 * FacebookShare.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef FACEBOOKSHARE_HPP_
#define FACEBOOKSHARE_HPP_

#include "ShareComponent.hpp"
#include <string>

class FacebookShare: public ShareComponent{

public:
	FacebookShare();
	virtual ~FacebookShare();
	void share(std::string data);

};

#endif /* FACEBOOKSHARE_HPP_ */
