#ifndef UTIL_ROOT_HPP
#define UTIL_ROOT_HPP

#include <memory>
#include <vector>

#include "Util/GameObject.hpp"

class App;

namespace Util {
class Root final {
public:
    Root(const std::vector<std::shared_ptr<GameObject>> &children = {});

    void AddChild(std::shared_ptr<GameObject> child);
    void AddChildren(const std::vector<std::shared_ptr<GameObject>> &children);

    void Update();

private:
    std::vector<std::shared_ptr<GameObject>> m_Children;
};
} // namespace Util

#endif
