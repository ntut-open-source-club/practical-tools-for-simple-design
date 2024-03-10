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
    // from https://gist.github.com/ciembor/1494530
    auto hueToRgb = [](float p, float q, float t) {
        if (t < 0)
            t += 1;
        if (t > 1)
            t -= 1;
        if (t < 1.0f / 6.0f)
            return p + (q - p) * 6 * t;
        if (t < 1.0f / 2.0f)
            return q;
        if (t < 2.0f / 3.0f)
            return p + (q - p) * (2.0f / 3.0f - t) * 6;
        return p;
    };
    float r, g, b;
    if (s == 0) {
        r = g = b = l * 255.0; // Achromatic
    } else {
        float q = l < 0.5f ? l * (1 + s) : l + s - l * s;
        float p = 2 * l - q;
        r = hueToRgb(p, q, h + 1.0f / 3.0f) * 255;
        g = hueToRgb(p, q, h) * 255;
        b = hueToRgb(p, q, h - 1.0f / 3.0f) * 255;
    }
    a *= 255;
    return FromRGB(r, g, b, a);
}

Color Color::FromHSV(float h, float s, float v, float a) {
    // from https://stackoverflow.com/a/6930407
    float p, q, t, ff, r, g, b;
    long i;
    v *= 255;
    if (s <= 0.0) {
        r = v;
        g = v;
        b = v;
        return FromRGB(r, g, b, a);
    }
    h *= 360.0F;
    if (h >= 360.0)
        h = 0.0;
    h /= 60.0;
    i = (long)h;
    ff = h - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch (i) {
    case 0:
        r = v;
        g = t;
        b = p;
        break;
    case 1:
        r = q;
        g = v;
        b = p;
        break;
    case 2:
        r = p;
        g = v;
        b = t;
        break;

    case 3:
        r = p;
        g = q;
        b = v;
        break;
    case 4:
        r = t;
        g = p;
        b = v;
        break;
    case 5:
    default:
        r = v;
        g = p;
        b = q;
        break;
    }
    a *= 255;
    return FromRGB(static_cast<Uint8>(r), static_cast<Uint8>(g),
                   static_cast<Uint8>(b), static_cast<Uint8>(a));
}
} // namespace Util
