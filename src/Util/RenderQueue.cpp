#include "Util/RenderQueue.hpp"

namespace Util {


    void RenderQueue::EnQueue(std::shared_ptr<GameObject> gameObject) {
        m_Queue.insert(gameObject);
        for (const std::shared_ptr<GameObject> &i: gameObject->GetChildren()) {
            EnQueue(i);
        }
    }

    void RenderQueue::Render() {
        for (const std::shared_ptr<GameObject> &i: m_Queue) {
            i->Draw();
        }
    }

}
