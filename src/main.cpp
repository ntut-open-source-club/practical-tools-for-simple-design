#include <spdlog/spdlog.h>

int main(int argc, char **argv) {
    spdlog::set_pattern("%n [%^%l%$] %v");
    spdlog::set_level(spdlog::level::debug);

    spdlog::debug("[{}]", "Sample Text");
}
