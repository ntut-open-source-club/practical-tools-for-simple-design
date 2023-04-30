#include "Util/LoadTextFile.hpp"

#include <fstream>
#include <sstream>

#include "Util/Logger.hpp"

namespace Util {
std::string LoadTextFile(const std::string &filepath) {
    std::string source;
    std::ifstream stream(filepath, std::ios::in);

    LOG_TRACE("Loading File: '{}'", filepath);

    if (stream.is_open()) {
        std::stringstream sstr;
        sstr << stream.rdbuf();
        source = sstr.str();
        stream.close();
    } else {
        LOG_ERROR("Failed to load '{}'", filepath);
    }

    return source;
}
} // namespace Util
