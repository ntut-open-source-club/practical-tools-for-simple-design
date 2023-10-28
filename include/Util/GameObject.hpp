#ifndef UTIL_GAME_OBJECT_HPP
#define UTIL_GAME_OBJECT_HPP

#include <memory>
#include <vector>

#include "Core/Drawable.hpp"
#include "Util/Transform.hpp"

namespace Util {
    class GameObject { // TODO: Refactor this hard-coded class
    public:

        GameObject() = default;

        GameObject(std::unique_ptr<Core::Drawable> drawable,
                   std::vector<std::shared_ptr<GameObject>> &children, const int zIndex)
                : m_Drawable(std::move(drawable)),
                  m_Children(children),
                  m_ZIndex(zIndex) {}


        GameObject(std::unique_ptr<Core::Drawable> drawable, const int zIndex)
                : m_Drawable(std::move(drawable)),
                  m_ZIndex(zIndex) {}

        virtual ~GameObject() = default;

        virtual void Start() = 0;

        virtual void Update() = 0;

        unsigned int Get_ZIndex() const { return m_ZIndex; }

        std::vector<std::shared_ptr<GameObject>> &GetChildren() { return m_Children; }

        void SetZIndex(unsigned int index) { m_ZIndex = index; }

        void SetDrawable(std::unique_ptr<Core::Drawable> drawable) {
            m_Drawable = std::move(drawable);
        }

        void AppendChild(std::shared_ptr<GameObject> child) {
            m_Children.push_back(std::move(child));
        }

        void Draw();

        class Comparior {
        public:
            bool
            operator()(const std::shared_ptr<GameObject> &lhs, const std::shared_ptr<GameObject> &rhs) const;
        };

    private:
        void EnQueue();

    protected:
        Util::Transform m_Transform;

        std::unique_ptr<Core::Drawable> m_Drawable = nullptr;
        std::vector<std::shared_ptr<GameObject>> m_Children;

        unsigned int m_ZIndex;
    };
} // namespace Util`
#endif
