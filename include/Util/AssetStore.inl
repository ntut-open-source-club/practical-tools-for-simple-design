#include "Util/AssetStore.hpp"

namespace Util {
template <typename T>
void AssetStore<T>::Load(const std::string &filepath) {
    m_Map[filepath] = m_Loader(filepath);
}

template <typename T>
T AssetStore<T>::Get(const std::string &filepath) {
    auto result = m_Map.find(filepath);
    if (result != m_Map.end()) {
        return result->second;
    }

    Load(filepath);

    return m_Map[filepath];
}

template <typename T>
void AssetStore<T>::Remove(const std::string &filepath) {
    m_Map.erase(filepath);
}
} // namespace Util
