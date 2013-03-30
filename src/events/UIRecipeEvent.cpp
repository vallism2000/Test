
#include "UIRecipeEvent.hpp"

UIRecipeEvent::UIRecipeEvent(int id) : IEvent(UIRECIPEREQUEST) {
	m_id = id;
}

int UIRecipeEvent::GetID() {
	return m_id;
}
