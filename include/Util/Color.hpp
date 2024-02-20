#ifndef UTIL_COLOR_HPP
#define UTIL_COLOR_HPP

#include "pch.hpp" // IWYU pragma: export
#include <spdlog/fmt/bundled/format.h>
namespace Util {
/**
 * @enum Colors
 * @brief A enum class that includes common colors.
 */
enum class Colors : Uint32;
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
     * @brief Converts the color to a string representation.
     *
     * This method returns a string representation of the color in the format
     * "Color(r,g,b,a)". The values r, g, b, and a represent the red, green,
     * blue, and alpha components of the color, respectively.
     *
     * @return A string representation of the color.
     */
    std::string ToString() const {
        return fmt::v8::format("Color({},{},{},{})", r, g, b, a);
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
     * @param h Hue Value (0-1)
     * @param s Saturation Value (0-1)
     * @param l Lightness Value (0-1)
     * @param a Alpha Value (0-1), default is 1.0
     * @return Color
     */
    static Color FromHSL(float h, float s, float l, float a = 1.0F);

    /**
     * @brief Get Color From HSV Values
     * @param h Hue Value (0-1)
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
     * @brief Get Color From Hex RGB String, alpha value is necessary
     * @param hex Hex String ("00000000" - "FFFFFFFF")
     * @return Color
     */
    static Color FromHex(const std::string &hex);

    /**
     * @brief Get Color From name within Util::Colors
     * @param name Color Name in Util::Colors
     * @return Color
     * @see Util::Colors
     */
    static Color FromName(const Util::Colors &name);
};

enum class Colors : Uint32 {
    ALICE_BLUE = 0xF0F8FF,
    ANTIQUE_WHITE = 0xFAEBD7,
    AQUA = 0x00FFFF,
    AQUAMARINE = 0x7FFFD4,
    AZURE = 0xF0FFFF,
    BEIGE = 0xF5F5DC,
    BISQUE = 0xFFE4C4,
    BLACK = 0x000000,
    BLANCHED_ALMOND = 0xFFEBCD,
    BLUE = 0x0000FF,
    BLUE_VIOLET = 0x8A2BE2,
    BROWN = 0xA52A2A,
    BURLY_WOOD = 0xDEB887,
    CADET_BLUE = 0x5F9EA0,
    CHARTREUSE = 0x7FFF00,
    CHOCOLATE = 0xD2691E,
    CORAL = 0xFF7F50,
    CORNFLOWER_BLUE = 0x6495ED,
    CORNSILK = 0xFFF8DC,
    CRIMSON = 0xDC143C,
    CYAN = 0x00FFFF,
    DARK_BLUE = 0x00008B,
    DARK_CYAN = 0x008B8B,
    DARK_GOLDENROD = 0xB8860B,
    DARK_GRAY = 0xA9A9A9,
    DARK_GREEN = 0x006400,
    DARK_KHAKI = 0xBDB76B,
    DARK_MAGENTA = 0x8B008B,
    DARK_OLIVE_GREEN = 0x556B2F,
    DARK_ORANGE = 0xFF8C00,
    DARK_ORCHID = 0x9932CC,
    DARK_RED = 0x8B0000,
    DARK_SALMON = 0xE9967A,
    DARK_SEA_GREEN = 0x8FBC8F,
    DARK_SLATE_BLUE = 0x483D8B,
    DARK_SLATE_GRAY = 0x2F4F4F,
    DARK_TURQUOISE = 0x00CED1,
    DARK_VIOLET = 0x9400D3,
    DEEP_PINK = 0xFF1493,
    DEEP_SKY_BLUE = 0x00BFFF,
    DIM_GRAY = 0x696969,
    DODGER_BLUE = 0x1E90FF,
    FIREBRICK = 0xB22222,
    FLORAL_WHITE = 0xFFFAF0,
    FOREST_GREEN = 0x228B22,
    FUCHSIA = 0xFF00FF,
    GAINSBORO = 0xDCDCDC,
    GHOST_WHITE = 0xF8F8FF,
    GOLD = 0xFFD700,
    GOLDENROD = 0xDAA520,
    GRAY = 0x808080,
    GREEN = 0x008000,
    GREEN_YELLOW = 0xADFF2F,
    HONEYDEW = 0xF0FFF0,
    HOT_PINK = 0xFF69B4,
    INDIAN_RED = 0xCD5C5C,
    INDIGO = 0x4B0082,
    IVORY = 0xFFFFF0,
    KHAKI = 0xF0E68C,
    LAVENDER = 0xE6E6FA,
    LAVENDER_BLUSH = 0xFFF0F5,
    LAWN_GREEN = 0x7CFC00,
    LEMON_CHIFFON = 0xFFFACD,
    LIGHT_BLUE = 0xADD8E6,
    LIGHT_CORAL = 0xF08080,
    LIGHT_CYAN = 0xE0FFFF,
    LIGHT_GOLDENROD_YELLOW = 0xFAFAD2,
    LIGHT_GRAY = 0xD3D3D3,
    LIGHT_GREEN = 0x90EE90,
    LIGHT_PINK = 0xFFB6C1,
    LIGHT_SALMON = 0xFFA07A,
    LIGHT_SEA_GREEN = 0x20B2AA,
    LIGHT_SKY_BLUE = 0x87CEFA,
    LIGHT_SLATE_GRAY = 0x778899,
    LIGHT_STEEL_BLUE = 0xB0C4DE,
    LIGHT_YELLOW = 0xFFFFE0,
    LIME = 0x00FF00,
    LIME_GREEN = 0x32CD32,
    LINEN = 0xFAF0E6,
    MAGENTA = 0xFF00FF,
    MAROON = 0x800000,
    MEDIUM_AQUAMARINE = 0x66CDAA,
    MEDIUM_BLUE = 0x0000CD,
    MEDIUM_ORCHID = 0xBA55D3,
    MEDIUM_PURPLE = 0x9370DB,
    MEDIUM_SEA_GREEN = 0x3CB371,
    MEDIUM_SLATE_BLUE = 0x7B68EE,
    MEDIUM_SPRING_GREEN = 0x00FA9A,
    MEDIUM_TURQUOISE = 0x48D1CC,
    MEDIUM_VIOLET_RED = 0xC71585,
    MIDNIGHT_BLUE = 0x191970,
    MINT_CREAM = 0xF5FFFA,
    MISTY_ROSE = 0xFFE4E1,
    MOCCASIN = 0xFFE4B5,
    NAVAJO_WHITE = 0xFFDEAD,
    NAVY = 0x000080,
    OLD_LACE = 0xFDF5E6,
    OLIVE = 0x808000,
    OLIVE_DRAB = 0x6B8E23,
    ORANGE = 0xFFA500,
    ORANGE_RED = 0xFF4500,
    ORCHID = 0xDA70D6,
    PALE_GOLDENROD = 0xEEE8AA,
    PALE_GREEN = 0x98FB98,
    PALE_TURQUOISE = 0xAFEEEE,
    PALE_VIOLET_RED = 0xDB7093,
    PAPAYA_WHIP = 0xFFEFD5,
    PEACH_PUFF = 0xFFDAB9,
    PERU = 0xCD853F,
    PINK = 0xFFC0CB,
    PLUM = 0xDDA0DD,
    POWDER_BLUE = 0xB0E0E6,
    PURPLE = 0x800080,
    REBECCA_PURPLE = 0x663399,
    RED = 0xFF0000,
    ROSY_BROWN = 0xBC8F8F,
    ROYAL_BLUE = 0x4169E1,
    SADDLE_BROWN = 0x8B4513,
    SALMON = 0xFA8072,
    SANDY_BROWN = 0xF4A460,
    SEA_GREEN = 0x2E8B57,
    SEASHELL = 0xFFF5EE,
    SIENNA = 0xA0522D,
    SILVER = 0xC0C0C0,
    SKY_BLUE = 0x87CEEB,
    SLATE_BLUE = 0x6A5ACD,
    SLATE_GRAY = 0x708090,
    SNOW = 0xFFFAFA,
    SPRING_GREEN = 0x00FF7F,
    STEEL_BLUE = 0x4682B4,
    TAN = 0xD2B48C,
    TEAL = 0x008080,
    THISTLE = 0xD8BFD8,
    TOMATO = 0xFF6347,
    TURQUOISE = 0x40E0D0,
    VIOLET = 0xEE82EE,
    WHEAT = 0xF5DEB3,
    WHITE = 0xFFFFFF,
    WHITE_SMOKE = 0xF5F5F5,
    YELLOW = 0xFFFF00,
    YELLOW_GREEN = 0x9ACD32
};
} // namespace Util

#endif
