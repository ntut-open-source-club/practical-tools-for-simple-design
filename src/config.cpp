#include "config.hpp"
#include "SDL_image.h"

#include <fstream>

std::string PTSD_Config::TITLE = "Practice-Tools-for-Simple-Design";

int PTSD_Config::WINDOW_POS_X = SDL_WINDOWPOS_UNDEFINED;
int PTSD_Config::WINDOW_POS_Y = SDL_WINDOWPOS_UNDEFINED;

unsigned int PTSD_Config::WINDOW_WIDTH = 1280;
unsigned int PTSD_Config::WINDOW_HEIGHT = 720;

Util::Logger::Level PTSD_Config::DEFAULT_LOG_LEVEL = Util::Logger::Level::INFO;

unsigned int PTSD_Config::FPS_CAP = 60;

template <typename T>
inline static void AssignValueFromConfigFile(const nlohmann::json &j,
                                             const std::string_view key,
                                             T &value) {
    if (j.contains(key.data())) {
        value = j[key.data()].get<T>();
    }
}

void PTSD_Config::Init() {
    nlohmann::json j;
    std::ifstream file;
    if (std::filesystem::exists("config.json")) {
        file = std::ifstream("config.json");
    } else if (std::filesystem::exists("../config.json")) {
        file = std::ifstream("../config.json");
    } else {
        LOG_WARN("config.json not found, using default configurations.");
        return;
    }
    file >> j;
    file.close();
    AssignValueFromConfigFile(j, "title", TITLE);
    AssignValueFromConfigFile(j, "window_pos_x", WINDOW_POS_X);
    AssignValueFromConfigFile(j, "window_pos_y", WINDOW_POS_Y);
    AssignValueFromConfigFile(j, "window_width", WINDOW_WIDTH);
    AssignValueFromConfigFile(j, "window_height", WINDOW_HEIGHT);
    AssignValueFromConfigFile(j, "default_log_level", DEFAULT_LOG_LEVEL);
    AssignValueFromConfigFile(j, "fps_cap", FPS_CAP);
}
