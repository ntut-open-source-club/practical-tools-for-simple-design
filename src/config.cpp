#include "config.hpp"

#include <fstream>

namespace PTSD_Config {
std::string TITLE = "Practice-Tools-for-Simple-Design";

int WINDOW_POS_X = 0;
int WINDOW_POS_Y = 0;

unsigned int WINDOW_WIDTH = 1280;
unsigned int WINDOW_HEIGHT = 720;

Util::Logger::Level DEFAULT_LOG_LEVEL = Util::Logger::Level::INFO;

/**
 * @brief FPS limit
 *
 * Set value to 0 to turn off FPS cap
 */
unsigned int FPS_CAP = 60;

void Init() {
    nlohmann::json j;
    if (std::filesystem::exists("config.json")) {
        std::ifstream file("config.json");
        if (std::filesystem::exists("../config.json")) {
            std::ifstream file("../config.json");
            file >> j;
            file.close();
        } else {
            LOG_WARN("config.json not found, using default configurations.");
            return;
        }
        TITLE = j["title"].get<std::string>();
        WINDOW_POS_X = j["window_pos_x"].get<int>();
        WINDOW_POS_Y = j["window_pos_y"].get<int>();
        WINDOW_WIDTH = j["window_width"].get<int>();
        WINDOW_HEIGHT = j["window_height"].get<int>();
        DEFAULT_LOG_LEVEL =
            static_cast<Util::Logger::Level>(j["default_log_level"].get<int>());
        FPS_CAP = j["fps_cap"].get<int>();
    }
}

} // namespace PTSD_Config
