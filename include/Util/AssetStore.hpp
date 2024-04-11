#ifndef UTIL_ASSET_STORE_HPP
#define UTIL_ASSET_STORE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <functional>

namespace Util {
/**
 * @brief A class template for managing assets.
 *
 * The AssetStore class template provides functionality for loading, storing,
 * and accessing potentially expensive resources. It uses a loader function to
 * load assets from filepaths and stores them in an unordered map for efficient
 * retrieval.
 *
 * @tparam T The type of assets managed by the store.
 */
template <typename T>
class AssetStore {
public:
    /**
     * @brief Constructs an AssetStore object with the specified loader
     * function.
     *
     * @param loader The function used to load assets of type T from filepaths.
     * Missing files should be handled inside loader.
     */
    AssetStore(std::function<T(const std::string &)> loader)
        : m_Loader(loader) {}

    /**
     * @brief Preload resources for future use.
     *
     * Calling this function before using the resource is optional and is
     * reserved as an optimization technique.
     *
     * @param filepath The filepath of the asset to load.
     */
    void Load(const std::string &filepath);

    /**
     * @brief Retrieves the asset associated with the specified filepath.
     *
     * If the requested resource in not already in the store, this function will
     * load the resource using `loader` and cache it. This should be the default
     * way of loading resources.
     *
     * @param filepath The filepath of the asset to retrieve.
     * @return A shared pointer to the asset, or nullptr if not found.
     */
    T Get(const std::string &filepath);

    /**
     * @brief Removes the asset associated with the specified filepath from the
     * store.
     *
     * It is generally not required to manually manage resources in the store
     * unless the program hits a memory limit. This operation does nothing if
     * the filepath is not in the store.
     *
     * @param filepath The filepath of the asset to remove.
     */
    void Remove(const std::string &filepath);

private:
    std::function<T(const std::string &)> m_Loader;

    std::unordered_map<std::string, T> m_Map;
};
} // namespace Util

#include "Util/AssetStore.inl"

#endif
