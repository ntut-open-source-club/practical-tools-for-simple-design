#include "Util/GameObject.hpp"

namespace Util {

    void GameObject::Draw() {
        m_Drawable->Draw(m_Transform, m_ZIndex);
    }

    bool GameObject::Comparator::operator()(const std::shared_ptr<GameObject> &lhs,
                                            const std::shared_ptr<GameObject> &rhs) const {
        return lhs->Get_ZIndex() < rhs->Get_ZIndex();
    }

} // namespace Util
