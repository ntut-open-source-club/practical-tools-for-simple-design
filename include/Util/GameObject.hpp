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
               std::vector<std::shared_ptr<GameObject>> &children)
        : m_Drawable(std::move(drawable)),
          m_Children(children) {}

    virtual void Start() = 0;
    virtual void Update() = 0;

    unsigned int Get_ZIndex() const { return m_ZIndex; }
    void SetMZIndex(unsigned int index) { m_ZIndex = index; }

    void SetDrawable(std::unique_ptr<Core::Drawable> drawable) {
        m_Drawable = std::move(drawable);
    }

    class Comparior {
    public:
        bool operator()(GameObject &lhs, GameObject &rhs) { return lhs.Get_ZIndex() > rhs.Get_ZIndex();}
    };

private:
    void EnQueue();

private:
    Util::Transform m_Transform;

    std::unique_ptr<Core::Drawable> m_Drawable = nullptr;
    std::vector<std::shared_ptr<GameObject>> m_Children;

    unsigned int m_ZIndex;
};
} // namespace Util
#endif
