#ifndef UTIL_ROOT_HPP
#define UTIL_ROOT_HPP

#include <memory>
#include <vector>

#include "Util/GameObject.hpp"
#include "Util/Renderer.hpp"

class App;

namespace Util {
/**
 * @class Renderer
 * @brief A class handling GameObjects' Draw()
 * @see Util::GameObject
 */
class Root final {
public:
    /**
     * @brief Parameterized constructor.
     *`
     *
     * @param children The GameObject needing to be managed by Renderer.
     */
    Root(const std::vector<std::shared_ptr<GameObject>> &children = {});

    /**
     * @brief Add a child to Renderer.
     *
     * @param child The GameObject needing to be managed by Renderer.
     */
    void AddChild(const std::shared_ptr<GameObject> &child);

    /**
     * @brief Add children to Renderer.
     *
     * @param children The GameObjects needing to be managed by Renderer.
     */
    void AddChildren(const std::vector<std::shared_ptr<GameObject>> &children);

    /**
     * @brief Remove the child.
     *
     * @param child The GameObject being removed.
     */
    void RemoveChild(std::shared_ptr<GameObject> child);

    /**
     * @brief Draw children according to their z-index.
     *
     * @note The user is not recommended to modify this function.
     */
    void Update();

private:
    std::unique_ptr<Renderer> m_Renderer;
};
} // namespace Util

#endif
