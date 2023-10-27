#ifndef UTIL_GAME_OBJECT_HPP
#define UTIL_GAME_OBJECT_HPP

#include <memory>
#include <vector>

#include "Core/Drawable.hpp"
#include "Util/Transform.hpp"

namespace Util {
class GameObject {
public:
    GameObject(std::unique_ptr<Core::Drawable> drawable,
               std::vector<std::shared_ptr<GameObject>> children);

    virtual void Start() = 0;
    virtual void Update() = 0;

    void SetDrawable(std::unique_ptr<Core::Drawable> drawable) {
        m_Drawable = std::move(drawable);
    }

private:
    void EnQueue();

private:
    Util::Transform m_Transform;

    std::unique_ptr<Core::Drawable> m_Drawable = nullptr;
    std::vector<std::shared_ptr<GameObject>> m_Children;
};
} // namespace Util
#endif
