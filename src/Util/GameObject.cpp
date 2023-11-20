#include "Util/GameObject.hpp"

namespace Util {

void GameObject::Draw() {
    m_Drawable->Draw(m_Transform, m_ZIndex);
}

} // namespace Util
