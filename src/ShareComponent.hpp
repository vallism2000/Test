/*
 * ShareComponent.hpp
 *
 *  Created on: Mar 25, 2013
 *      Author: kirstensolomon
 */

#ifndef SHARECOMPONENT_HPP_
#define SHARECOMPONENT_HPP_

#include <string>

class ShareComponent {

public:
	ShareComponent();
	virtual ~ShareComponent();
	virtual void share(std::string data) = 0;

};


#endif /* SHARECOMPONENT_HPP_ */
