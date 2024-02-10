#include "Util/AssetStore.hpp"

namespace Util {
template <typename T>
void AssetStore<T>::Load(std::string_view filepath) {
    auto path = m_AssetPath / filepath;
    m_Map[filepath] = m_Loader(path);
}

template <typename T>
std::shared_ptr<T> AssetStore<T>::Get(std::string_view filepath) {
    auto path = m_AssetPath / filepath;
    if (m_Map.find(filepath) == m_Map.end()) {
    }
    if (!std::filesystem::exists(path)) {
    }
}

template <typename T>
void AssetStore<T>::Remove(std::string_view filepath) {}
} // namespace Util
