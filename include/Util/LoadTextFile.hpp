#ifndef UTIL_LOAD_TEXT_FILE_HPP
#define UTIL_LOAD_TEXT_FILE_HPP

#include <string>

namespace Util {
/**
 * @brief Generic helper function that loads a text file into a `std::string`.
 */
std::string LoadTextFile(const std::string &filepath);
} // namespace Util

#endif
