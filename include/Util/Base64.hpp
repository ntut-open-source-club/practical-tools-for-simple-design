//
// Created by 黃漢軒 on 2023/12/25.
//

#ifndef PRACTICALTOOLSFORSIMPLEDESIGN_BASE64_HPP
#define PRACTICALTOOLSFORSIMPLEDESIGN_BASE64_HPP

#include <vector>
#include <string>
typedef unsigned char BYTE;

std::string base64_encode(BYTE const* buf, unsigned int bufLen);
std::vector<BYTE> base64_decode(std::string const&);

#endif // PRACTICALTOOLSFORSIMPLEDESIGN_BASE64_HPP
