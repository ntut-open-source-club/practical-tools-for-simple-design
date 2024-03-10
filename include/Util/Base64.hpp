#ifndef UTIL_BASE64_HPP
#define UTIL_BASE64_HPP

/*
 * The code to decode the base64 in compilation time is powered by
 * https://stackoverflow.com/a/59604914 It's used to decode the base64 string in
 * compilation time and improve the efficiency. Actually it's dirty, but we just
 * treat as a utility and won't maintain it, so just make sure it can work.
 */
#include <string_view>

static constexpr size_t DecodeBase64Length(const char *s) {
    size_t len = std::char_traits<char>::length(s);
    if (s[len - 2] == '=')
        return (len / 4) * 3 - 2;
    else if (s[len - 1] == '=')
        return (len / 4) * 3 - 1;
    else
        return (len / 4) * 3;
}

static constexpr std::array<int, 256> PrepareBase64DecodeTable() {
    std::array<int, 256> T{0};
    // breaks constexpr: T.fill(-1) or missing initialization
    for (int i = 0; i < 256; i++)
        T[i] = -1;
    for (int i = 0; i < 64; i++)
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
              [i]] = i;
    return T;
}

template <int N>
static constexpr std::array<std::byte, N>
DecodeBase64(std::string_view b64Str) {
    constexpr auto T = PrepareBase64DecodeTable();
    std::array<std::byte, N> out = {std::byte(0)};
    int valb = -8;
    for (size_t i = 0, val = 0, posOut = 0;
         i < b64Str.length() && T[b64Str[i]] != -1; i++) {
        val = (val << 6) + T[b64Str[i]];
        valb += 6;
        if (valb >= 0) {
            out[posOut] = std::byte((val >> valb) & 0xFF);
            posOut += 1;
            valb -= 8;
        }
    }
    return out;
}

#endif
