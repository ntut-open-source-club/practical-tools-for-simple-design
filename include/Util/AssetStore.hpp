#ifndef UTIL_ASSET_STORE_HPP
#define UTIL_ASSET_STORE_HPP

#include "pch.hpp"

#include <filesystem>
#include <functional>
#include <unordered_map>

// TODO: figure out a better way to abstract API

namespace Util {
/**
 * @class AssetStore
 * @brief Generic asset manager for avoiding reloading expensive resources
 */
template <typename T>
class AssetStore {
public:
    AssetStore(std::string_view directory,
               std::function<std::shared_ptr<T>(std::string_view)> loader)
        : m_AssetPath(directory),
          m_Loader(loader) {}

    void Load(std::string_view filepath);
    std::shared_ptr<T> Get(std::string_view filepath);
    void Remove(std::string_view filepath);

private:
    std::filesystem::path m_AssetPath;
    std::function<std::shared_ptr<T>(std::string_view)> m_Loader;

    std::unordered_map<std::string, std::shared_ptr<T>> m_Map;
};
} // namespace Util

// #include "Util/AssetStore.inl"

#endif
