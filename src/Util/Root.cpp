#include "Util/Root.hpp"

#include "Util/Logger.hpp"

namespace Util {
Root::Root(const std::vector<std::shared_ptr<GameObject>> &children)
    : m_Children(children) {}

void Root::AddChild(const std::shared_ptr<GameObject>& child) {
    m_Children.push_back(child);
}

void Root::RemoveChild(std::shared_ptr<GameObject> child) {
    m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), child),
                     m_Children.end());
}

void Root::AddChildren(
    const std::vector<std::shared_ptr<GameObject>> &children) {
    m_Children.reserve(m_Children.size() + children.size());
    m_Children.insert(m_Children.end(), children.begin(), children.end());
}

void Root::Update() {
    struct StackInfo {
        std::shared_ptr<GameObject> m_GameObject;
        Transform m_ParentTransform;
    };

    std::vector<StackInfo> stack;
    stack.reserve(m_Children.size());

    for (const auto &child : m_Children) {
        stack.push_back(StackInfo{child, Transform{}});
    }

    while (!stack.empty()) {
        auto curr = stack.back();
        stack.pop_back();

        curr.m_GameObject->Draw();

        for (const auto &child : curr.m_GameObject->GetChildren()) {
            stack.push_back(
                StackInfo{child, curr.m_GameObject->GetTransform()});
        }
    }
}
} // namespace Util
