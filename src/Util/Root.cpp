#include "Util/Root.hpp"

#include <queue>

#include "Util/Logger.hpp"

namespace Util {
Root::Root(const std::vector<std::shared_ptr<GameObject>> &children)
    : m_Renderer(std::make_unique<Renderer>(children)) {
        LOG_WARN("Root is deprecated, use Renderer instead.");
    }

void Root::AddChild(const std::shared_ptr<GameObject> &child) {
    m_Renderer->AddChild(child);
}

void Root::RemoveChild(std::shared_ptr<GameObject> child) {
    m_Renderer->RemoveChild(child);
}

void Root::AddChildren(
    const std::vector<std::shared_ptr<GameObject>> &children) {
    m_Renderer->AddChildren(children);
}

void Root::Update() {
    m_Renderer->Update();
}
} // namespace Util
