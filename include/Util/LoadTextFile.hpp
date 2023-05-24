#ifndef UTIL_LOAD_TEXT_FILE_HPP
#define UTIL_LOAD_TEXT_FILE_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Util {
/**
 * @brief Generic helper function that loads a text file into a `std::string`.
 */
std::string LoadTextFile(const std::string &filepath);
} // namespace Util

#endif
