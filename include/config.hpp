#ifndef CONFIG_H
#define CONFIG_H

#include "Util/Logger.hpp"
#include "pch.hpp" // IWYU pragma: export

namespace Core {
class Context;
}

struct PTSD_Config {
public:
    static std::string TITLE;

    static int WINDOW_POS_X;

    static int WINDOW_POS_Y;
    static unsigned int WINDOW_WIDTH;

    static unsigned int WINDOW_HEIGHT;
    static Util::Logger::Level DEFAULT_LOG_LEVEL;

    /**
     * @brief FPS limit
     *
     * Set value to 0 to turn off FPS cap
     */
    static unsigned int FPS_CAP;

private:
    friend class Core::Context;
    static void Init();
}; // namespace PTSD_Config

#endif
