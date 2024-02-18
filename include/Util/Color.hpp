#ifndef UTIL_COLOR_HPP
#define UTIL_COLOR_HPP

#include "pch.hpp" // IWYU pragma: export

namespace Util {
/**
 * @class Color
 * @brief A class representing a color.
 *
 * This class is an extend of glm::vec4. It provides functionalities to
 * convert from and to SDL_Color format.
 */
class Color : public glm::vec4 {
public:
    using glm::vec4::vec;

    /*
     * @brief Parameterized constructor.
     *
     * @param vec The color in glm::vec4 format.
     */
    Color(const glm::vec4 &vec)
        : glm::vec4(vec) {}

    /*
     * @brief Parameterized constructor.
     *
     * @param r The red component of the color.
     * @param g The green component of the color.
     * @param b The blue component of the color.
     * @param a The alpha component of the color.
     */
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255)
        : glm::vec4(r, g, b, a) {}

    /*
     * @brief Parameterized constructor.
     */
    Color(glm::vec4 &&vec)
        : glm::vec4(std::move(vec)) {}

    /*
     * @brief Parameterized constructor.
     *
     * @param color The color in SDL_Color format.
     */
    Color(const SDL_Color &color)
        : glm::vec4({
              color.r,
              color.g,
              color.b,
              color.a,
          }) {}

    /**
     * @brief Converts the color to SDL_Color format.
     *
     * @return The color in SDL_Color format.
     */
    SDL_Color ToSdlColor() const {
        return SDL_Color{
            static_cast<Uint8>(r),
            static_cast<Uint8>(g),
            static_cast<Uint8>(b),
            static_cast<Uint8>(a),
        };
    }

    /**
     * @brief Get Color From RGB Values
     * @param r Red Value (0-255)
     * @param g Green Value (0-255)
     * @param b Blue Value (0-255)
     * @param a Alpha Value (0-255), default is 255
     * @return Color
     */
    static Color FromRGB(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

    /**
     * @brief Get Color From HSL Values
     * @param h Hue Value (0-360)
     * @param s Saturation Value (0-1)
     * @param l Lightness Value (0-1)
     * @param a Alpha Value (0-1), default is 1.0
     * @return Color
     */
    static Color FromHSL(float h, float s, float l, float a = 1.0F);

    /**
     * @brief Get Color From HSV Values
     * @param h Hue Value (0-360)
     * @param s Saturation Value (0-1)
     * @param v Value (0-1)
     * @param a Alpha Value (0-1), default is 1.0
     * @return Color
     */
    static Color FromHSV(float h, float s, float v, float a = 1.0F);

    /**
     * @brief Get Color From Hex RGB Value, alpha value is necessary
     * @param hex Hex Value (0x00000000 - 0xFFFFFFFF)
     * @return Color
     */
    static Color FromHex(Uint32 hex);

    /**
     * @brief Get Color From Hex RGB String
     * @param hex Hex String ("00000000" - "FFFFFFFF")
     * @return Color
     */
    static Color FromHex(const std::string &hex);

    /**
     * @brief Get Color From Name
     * @param name Color Name, case insensitive, see Util/Color.cpp for
     * available names
     * @return Color
     */
    static Color FromName(const std::string &name);

private:
    static std::unordered_map<std::string, Uint32> s_ColorNames;
};
} // namespace Util

#endif
