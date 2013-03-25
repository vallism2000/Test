/*
 * IEvent.hpp
 *
 */

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

#include <string>

class IEvent {
public:
	IEvent(std::string type);
	virtual ~IEvent();

	const std::string & GetType();

private:
	std::string m_type;
};

#endif /* IEVENT_HPP_ */
