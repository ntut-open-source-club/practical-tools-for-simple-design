constexpr size_t DecodeBase64Length(const char *s)
{
    size_t len = std::char_traits<char>::length(s);
    if (s[len - 2] == '=')
        return (len / 4) * 3 - 2;
    else if(s[len -1] == '=')
        return (len / 4) * 3 - 1;
    else
        return (len / 4) * 3 ;
}

constexpr std::array<int, 256> PrepareBase64DecodeTable() {
    std::array<int, 256> T{ 0 }; // breaks constexpr: T.fill(-1) or missing initialization
    for (int i = 0; i < 256; i++)
        T[i] = -1;
    for (int i = 0; i < 64; i++)
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    return T;
}

template<int N>
constexpr std::array<std::byte, N> DecodeBase64(const char *b64Str)
{
    constexpr auto T = PrepareBase64DecodeTable();
    std::array<std::byte, N> out = { std::byte(0) };
    int valb = -8;
    for (size_t i = 0, val = 0, posOut = 0; i < std::char_traits<char>::length(b64Str) && T[b64Str[i]] != -1; i++) {
        val = (val << 6) + T[b64Str[i]];
        valb += 6;
        if (valb >= 0) {
            out[posOut++] = std::byte((val >> valb) & 0xFF);
            valb -= 8;
        }
    }
    return out;
}