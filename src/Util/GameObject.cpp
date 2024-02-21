#include "Util/GameObject.hpp"
#include "Util/Transform.hpp"

namespace Util {

void GameObject::Draw() {
    if (!m_Visible) {
        return;
    }

    m_Drawable->Draw(m_Transform, m_ZIndex, m_Pivot);
}

} // namespace Util
