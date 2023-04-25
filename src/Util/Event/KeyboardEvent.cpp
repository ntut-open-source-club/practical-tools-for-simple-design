#include "Util/Event/KeyboardEvent.hpp"

bool KeyBoardEvent::IfKeyPressed(const PTSD_Scancode &keyCode) const{
    return *(m_KeyArr+static_cast<int>(keyCode)) == 1;
}
