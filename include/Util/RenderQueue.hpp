#ifndef UTIL_RENDER_QUEUE_HPP
#define UTIL_RENDER_QUEUE_HPP

#include <queue>

#include "Util/GameObject.hpp"

namespace Util {

    class RenderQueue {
    public:
        void EnQueue(std::shared_ptr<GameObject> gameObject);

        void Render();

    private:
        std::multiset<std::shared_ptr<Util::GameObject>,
                Util::GameObject::Comparator> m_Queue;
    };

} // namespace Util

#endif // UTIL_RENDER_QUEUE_HPP
