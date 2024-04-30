#include "config.hpp"
#include "SDL_image.h"

#include <fstream>

std::string_view PTSD_Config::TITLE = "Practice-Tools-for-Simple-Design";

int PTSD_Config::WINDOW_POS_X = SDL_WINDOWPOS_UNDEFINED;
int PTSD_Config::WINDOW_POS_Y = SDL_WINDOWPOS_UNDEFINED;

unsigned int PTSD_Config::WINDOW_WIDTH = 1280;
unsigned int PTSD_Config::WINDOW_HEIGHT = 720;

Util::Logger::Level PTSD_Config::DEFAULT_LOG_LEVEL = Util::Logger::Level::INFO;

unsigned int PTSD_Config::FPS_CAP = 60;

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
    TITLE = j["title"].get<std::string_view>();
    WINDOW_POS_X = j["window_pos_x"].get<int>();
    WINDOW_POS_Y = j["window_pos_y"].get<int>();
    WINDOW_WIDTH = j["window_width"].get<int>();
    WINDOW_HEIGHT = j["window_height"].get<int>();
    DEFAULT_LOG_LEVEL =
        static_cast<Util::Logger::Level>(j["default_log_level"].get<int>());
    FPS_CAP = j["fps_cap"].get<int>();
}
