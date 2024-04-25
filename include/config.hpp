#ifndef CONFIG_H
#define CONFIG_H

#include "Util/Logger.hpp"
#include "pch.hpp" // IWYU pragma: export

namespace PTSD_Config {

void Init();
extern std::string TITLE;

extern int WINDOW_POS_X;
extern int WINDOW_POS_Y;

extern unsigned int WINDOW_WIDTH;
extern unsigned int WINDOW_HEIGHT;

extern Util::Logger::Level DEFAULT_LOG_LEVEL;

/**
 * @brief FPS limit
 *
 * Set value to 0 to turn off FPS cap
 */
extern unsigned int FPS_CAP;
}; // namespace PTSD_Config

#endif
