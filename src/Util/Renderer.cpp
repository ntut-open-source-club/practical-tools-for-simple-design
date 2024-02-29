#include "Util/Renderer.hpp"

#include <queue>

#include "Util/Logger.hpp"

namespace Util {
Renderer::Renderer(const std::vector<std::shared_ptr<GameObject>> &children)
    : m_Children(children) {}

void Renderer::AddChild(const std::shared_ptr<GameObject> &child) {
    m_Children.push_back(child);
}

void Renderer::RemoveChild(std::shared_ptr<GameObject> child) {
    m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), child),
                     m_Children.end());
}

void Renderer::AddChildren(
    const std::vector<std::shared_ptr<GameObject>> &children) {
    m_Children.reserve(m_Children.size() + children.size());
    m_Children.insert(m_Children.end(), children.begin(), children.end());
}

void Renderer::Update() {
    struct StackInfo {
        std::shared_ptr<GameObject> m_GameObject;
        Transform m_ParentTransform;
    };

    std::vector<StackInfo> stack;
    stack.reserve(m_Children.size());

    for (const auto &child : m_Children) {
        stack.push_back(StackInfo{child, Transform{}});
    }

    auto compareFunction = [](const StackInfo &a, const StackInfo &b) {
        return a.m_GameObject->GetZIndex() > b.m_GameObject->GetZIndex();
    };
    std::priority_queue<StackInfo, std::vector<StackInfo>,
                        decltype(compareFunction)>
        renderQueue(compareFunction);

    while (!stack.empty()) {
        auto curr = stack.back();
        stack.pop_back();
        renderQueue.push(curr);

        for (const auto &child : curr.m_GameObject->GetChildren()) {
            stack.push_back(
                StackInfo{child, curr.m_GameObject->GetTransform()});
        }
    }
    // draw all in render queue by order
    while (!renderQueue.empty()) {
        auto curr = renderQueue.top();
        renderQueue.pop();

        curr.m_GameObject->Draw();
    }
}
} // namespace Util
