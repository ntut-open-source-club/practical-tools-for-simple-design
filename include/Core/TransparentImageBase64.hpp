//
// Created by 黃漢軒 on 2023/12/25.
//

#ifndef PRACTICALTOOLSFORSIMPLEDESIGN_TRANSPARENTIMAGEBASE64_HPP
#define PRACTICALTOOLSFORSIMPLEDESIGN_TRANSPARENTIMAGEBASE64_HPP

#include <string>

// A transparent image base64 string.
// Since we want to hardcode the image, we have such a long string here.
// The original image should find in here: https://i.imgur.com/zS4sPCN.png
#define TRANSPARENT_IMAGE                                                      \
    "iVBORw0KGgoAAAANSUhEUgAABAAAAAQAAgMAAAACc8MQAAAAIGNIUk0AAHomAACAhAAA+"    \
    "gAAAIDoAAB1MAAA6mAAADqYAAAXcJy6UTwAAAAJUExURf8A3AAAAP///"                 \
    "6bxqqgAAAABYktHRAJmC3xkAAAAB3RJTUUH5wwZBjExvHoPtAAACkBJREFUeNrt0bEJwEAQB" \
    "DE36f5bcQkfPVrMXD4g9p7ncO/h/"                                             \
    "t5zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65wDdc4DuOUD3H" \
    "KB7DtA9B+"                                                                \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8B1/"             \
    "t5YB9ugAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogA" \
    "ZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogHWA7jlA9xygew" \
    "7QPQfongN0zwG65wDdc4DuOUD3HKB7DtA9B+"                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbpvoHWA7jlA9xygew7QPQfongN0zwG65wDdc4DuOUD3HKB7DtA9B+"             \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwHX+"  \
    "3lgH26ABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiAB" \
    "miABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiABmiAdYDuOUD3HKB7D" \
    "tA9B+"                                                                    \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8Bum+"            \
    "gdYDuOUD3HKB7DtA9B+"                                                      \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAdf7eWAfboAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaI" \
    "AGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIAGaIB1gO" \
    "45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65wDdc4DuOUD3HKB7Dt" \
    "A9B+"                                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG6b6" \
    "B1gO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65wDdc4DuOUD3HK" \
    "B7DtA9B+"                                                                 \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8B1/"             \
    "t5YB9ugAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogA" \
    "ZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogAZogHWA7jlA9xygew" \
    "7QPQfongN0zwG65wDdc4DuOUD3HKB7DtA9B+"                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+"                                                     \
    "ieA3TPAbrnAN1zgO45QPccoHsO0D0H6J4DdM8BuucA3XOA7jlA9xygew7QPQfongN0zwG65w" \
    "Ddc4DuOUD3HKB7DtA9B+ieA3TPAbr/"                                           \
    "ABxLCfesmysEAAAAJXRFWHRkYXRlOmNyZWF0ZQAyMDIzLTEyLTI1VDA2OjQ5OjQ4KzAwOjAw" \
    "0d583AAAACV0RVh0ZGF0ZTptb2RpZnkAMjAyMy0xMi0yNVQwNjo0OTo0OCswMDowMKCDxGAA" \
    "AAAodEVYdGRhdGU6dGltZXN0YW1wADIwMjMtMTItMjVUMDY6NDk6NDkrMDA6MDBR4e4LAAAA" \
    "AElFTkSuQmCC"

#endif // PRACTICALTOOLSFORSIMPLEDESIGN_TRANSPARENTIMAGEBASE64_HPP
