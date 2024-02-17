#include "Util/GameObject.hpp"
#include "Util/Transform.hpp"

namespace Util {

void GameObject::Draw() {
    if (!m_Visible) {
        return;
    }

    Util::Transform offsetTransform {
        m_Transform.translation - m_Pivot,
        m_Transform.rotation,
        m_Transform.scale,
    };

    m_Drawable->Draw(offsetTransform, m_ZIndex);
}

} // namespace Util
