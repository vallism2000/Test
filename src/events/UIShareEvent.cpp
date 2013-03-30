
#include "UIShareEvent.hpp"

UIShareEvent::UIShareEvent(int id) : IEvent(UISHAREREQUEST) {
	m_id = id;
}

int UIShareEvent::GetID() {
	return m_id;
}
