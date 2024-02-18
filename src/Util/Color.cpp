#include "Util/Color.hpp"
#include "Util/Logger.hpp"
namespace Util {

Color Color::FromRGB(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    if (r > 255 || g > 255 || b > 255 || a > 255) {
        LOG_ERROR("Invalid color: ({}, {}, {}, {})", r, g, b, a);
        throw std::invalid_argument("Invalid color");
    }
    return Color(r, g, b, a);
}

Color Color::FromHex(Uint32 hex) {
    return FromRGB((hex >> 24) & 0xFF, (hex >> 16) & 0xFF, (hex >> 8) & 0xFF,
                 hex & 0xFF);
}

Color Color::FromHex(const std::string &hex) {
    try {
        Uint32 hexValue = std::stoul(hex, nullptr, 16);
        return FromHex(hexValue);
    } catch (const std::invalid_argument &e) {
        LOG_ERROR("Invalid color hex: '{}'", hex);
        throw std::invalid_argument("Invalid hex string");
    }
}

Color Color::FromName(const Util::Colors &name) {
    return FromHex(static_cast<Uint32>(name) << 8 | 0xFF);
}

Color Color::FromHSL(float h, float s, float l, float a) {

    float chroma = (1 - std::abs(2 * l - 1)) * s;
    float huePrime = h * 6;
    float x = chroma * (1 - std::abs(std::fmod(huePrime, 2) - 1));
    float m = l - chroma / 2;

    std::array<float, 3> rgb1 = {0, 0, 0};
    int hueSegment = static_cast<int>(huePrime);
    rgb1[hueSegment % 3] = chroma;
    rgb1[(hueSegment + 1) % 3] = x;

    Uint8 r = static_cast<Uint8>((rgb1[0] + m) * 255);
    Uint8 g = static_cast<Uint8>((rgb1[1] + m) * 255);
    Uint8 b = static_cast<Uint8>((rgb1[2] + m) * 255);

    return FromRGB(r, g, b, a);
}

Color Color::FromHSV(float h, float s, float v, float a) {
    float chroma = v * s;
    float huePrime = h * 6;
    float x = chroma * (1 - std::abs(std::fmod(huePrime, 2) - 1));
    float m = v - chroma;

    std::array<float, 3> rgb1 = {0, 0, 0};
    int hueSegment = static_cast<int>(huePrime);
    rgb1[hueSegment % 3] = chroma;
    rgb1[(hueSegment + 1) % 3] = x;

    Uint8 r = static_cast<Uint8>((rgb1[0] + m) * 255);
    Uint8 g = static_cast<Uint8>((rgb1[1] + m) * 255);
    Uint8 b = static_cast<Uint8>((rgb1[2] + m) * 255);

    return FromRGB(r, g, b, a);
}

} // namespace Util
