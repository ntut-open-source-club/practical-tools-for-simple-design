#ifndef UTIL_KEYCODE_HPP
#define UTIL_KEYCODE_HPP

#include "pch.hpp" // IWYU pragma: export

#include <SDL_scancode.h>

namespace Util {
// Prevents from auto format checking fail
// clang-format off
enum class Keycode {
    UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,
    NUM_1 = SDL_SCANCODE_1,
    NUM_2 = SDL_SCANCODE_2,
    NUM_3 = SDL_SCANCODE_3,
    NUM_4 = SDL_SCANCODE_4,
    NUM_5 = SDL_SCANCODE_5,
    NUM_6 = SDL_SCANCODE_6,
    NUM_7 = SDL_SCANCODE_7,
    NUM_8 = SDL_SCANCODE_8,
    NUM_9 = SDL_SCANCODE_9,
    NUM_0 = SDL_SCANCODE_0,

    RETURN = SDL_SCANCODE_RETURN,
    ESCAPE = SDL_SCANCODE_ESCAPE,
    BACKSPACE = SDL_SCANCODE_BACKSPACE,
    TAB = SDL_SCANCODE_TAB,
    SPACE = SDL_SCANCODE_SPACE,

    MINUS = SDL_SCANCODE_MINUS,
    EQUALS = SDL_SCANCODE_EQUALS,
    LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
    RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
    BACKSLASH = SDL_SCANCODE_BACKSLASH, /**< Located at the lower left of the return
                                   *   key on ISO keyboards and at the right end
                                   *   of the QWERTY row on ANSI keyboards.
                                   *   Produces REVERSE SOLIDUS (backslash) and
                                   *   VERTICAL LINE in a US layout, REVERSE
                                   *   SOLIDUS and VERTICAL LINE in a UK Mac
                                   *   layout, NUMBER SIGN and TILDE in a UK
                                   *   Windows layout, DOLLAR SIGN and POUND
                                   * SIGN in a Swiss German layout, NUMBER SIGN
                                   * and APOSTROPHE in a German layout, GRAVE
                                   *   ACCENT and POUND SIGN in a French Mac
                                   *   layout, and ASTERISK and MICRO SIGN in a
                                   *   French Windows layout.
                                   */
    NONUSHASH = SDL_SCANCODE_NONUSHASH, /**< ISO USB keyboards actually use this code
                                   *   instead of 49 for the same key, but all
                                   *   OSes I've seen treat the two codes
                                   *   identically. So, as an implementor,
                                   * unless your keyboard generates both of
                                   * those codes and your OS treats them
                                   * differently, you should generate
                                   * BACKSLASH instead of this
                                   * code. As a user, you should not rely on
                                   * this code because SDL will never generate
                                   * it with most (all?) keyboards.
                                   */
    SEMICOLON = SDL_SCANCODE_SEMICOLON,
    APOSTROPHE = SDL_SCANCODE_APOSTROPHE,
    GRAVE = SDL_SCANCODE_GRAVE, /**< Located in the top left corner (on both ANSI
                               *   and ISO keyboards). Produces GRAVE ACCENT and
                               *   TILDE in a US Windows layout and in US and UK
                               *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                               *   and NOT SIGN in a UK Windows layout, SECTION
                               *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                               *   layouts on ISO keyboards, SECTION SIGN and
                               *   DEGREE SIGN in a Swiss German layout (Mac:
                               *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                               *   DEGREE SIGN in a German layout (Mac: only on
                               *   ISO keyboards), SUPERSCRIPT TWO and TILDE in
                               * a French Windows layout, COMMERCIAL AT and
                               *   NUMBER SIGN in a French Mac layout on ISO
                               *   keyboards, and LESS-THAN SIGN and
                               * GREATER-THAN SIGN in a Swiss German, German, or
                               * French Mac layout on ANSI keyboards.
                               */
    COMMA = SDL_SCANCODE_COMMA,
    PERIOD = SDL_SCANCODE_PERIOD,
    SLASH = SDL_SCANCODE_SLASH,

    CAPSLOCK = SDL_SCANCODE_CAPSLOCK,

    F1 = SDL_SCANCODE_F1,
    F2 = SDL_SCANCODE_F2,
    F3 = SDL_SCANCODE_F3,
    F4 = SDL_SCANCODE_F4,
    F5 = SDL_SCANCODE_F5,
    F6 = SDL_SCANCODE_F6,
    F7 = SDL_SCANCODE_F7,
    F8 = SDL_SCANCODE_F8,
    F9 = SDL_SCANCODE_F9,
    F10 = SDL_SCANCODE_F10,
    F11 = SDL_SCANCODE_F11,
    F12 = SDL_SCANCODE_F12,

    PRINTSCREEN = SDL_SCANCODE_PRINTSCREEN,
    SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
    PAUSE = SDL_SCANCODE_PAUSE,
    INSERT = SDL_SCANCODE_INSERT, /**< insert on PC, help on some Mac keyboards
                                  (but does send code 73, not 117) */
    HOME = SDL_SCANCODE_HOME,
    PAGEUP = SDL_SCANCODE_PAGEUP,
    DELETE = SDL_SCANCODE_DELETE,
    END = SDL_SCANCODE_END,
    PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
    RIGHT = SDL_SCANCODE_RIGHT,
    LEFT = SDL_SCANCODE_LEFT,
    DOWN = SDL_SCANCODE_DOWN,
    UP = SDL_SCANCODE_UP,

    NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR, /**< num lock on PC, clear on Mac keyboards
                                      */
    KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
    KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
    KP_MINUS = SDL_SCANCODE_KP_MINUS,
    KP_PLUS = SDL_SCANCODE_KP_PLUS,
    KP_ENTER = SDL_SCANCODE_KP_ENTER,
    KP_1 = SDL_SCANCODE_KP_1,
    KP_2 = SDL_SCANCODE_KP_2,
    KP_3 = SDL_SCANCODE_KP_3,
    KP_4 = SDL_SCANCODE_KP_4,
    KP_5 = SDL_SCANCODE_KP_5,
    KP_6 = SDL_SCANCODE_KP_6,
    KP_7 = SDL_SCANCODE_KP_7,
    KP_8 = SDL_SCANCODE_KP_8,
    KP_9 = SDL_SCANCODE_KP_9,
    KP_0 = SDL_SCANCODE_KP_0,
    KP_PERIOD = SDL_SCANCODE_KP_PERIOD,

    NONUSBACKSLASH = SDL_SCANCODE_NONUSBACKSLASH, /**< This is the additional key that ISO
                                         *   keyboards have over ANSI ones,
                                         *   located between left shift and Y.
                                         *   Produces GRAVE ACCENT and TILDE in
                                         * a US or UK Mac layout, REVERSE
                                         * SOLIDUS (backslash) and VERTICAL LINE
                                         * in a US or UK Windows layout, and
                                         *   LESS-THAN SIGN and GREATER-THAN
                                         * SIGN in a Swiss German, German, or
                                         * French layout. */
    APPLICATION = SDL_SCANCODE_APPLICATION,    /**< windows contextual menu, compose */
    POWER = SDL_SCANCODE_POWER, /**< The USB document says this is a status flag,
                                *   not a physical key - but some Mac keyboards
                                *   do have a power key. */
    KP_EQUALS = SDL_SCANCODE_KP_EQUALS,
    F13 = SDL_SCANCODE_F13,
    F14 = SDL_SCANCODE_F14,
    F15 = SDL_SCANCODE_F15,
    F16 = SDL_SCANCODE_F16,
    F17 = SDL_SCANCODE_F17,
    F18 = SDL_SCANCODE_F18,
    F19 = SDL_SCANCODE_F19,
    F20 = SDL_SCANCODE_F20,
    F21 = SDL_SCANCODE_F21,
    F22 = SDL_SCANCODE_F22,
    F23 = SDL_SCANCODE_F23,
    F24 = SDL_SCANCODE_F24,
    EXECUTE = SDL_SCANCODE_EXECUTE,
    HELP = SDL_SCANCODE_HELP, /**< AL Integrated Help Center */
    MENU = SDL_SCANCODE_MENU, /**< Menu (show menu) */
    SELECT = SDL_SCANCODE_SELECT,
    STOP = SDL_SCANCODE_STOP,  /**< AC Stop */
    AGAIN = SDL_SCANCODE_AGAIN, /**< AC Redo/Repeat */
    UNDO = SDL_SCANCODE_UNDO,  /**< AC Undo */
    CUT = SDL_SCANCODE_CUT,   /**< AC Cut */
    COPY = SDL_SCANCODE_COPY,  /**< AC Copy */
    PASTE = SDL_SCANCODE_PASTE, /**< AC Paste */
    FIND = SDL_SCANCODE_FIND,  /**< AC Find */
    MUTE = SDL_SCANCODE_MUTE,
    VOLUMEUP = SDL_SCANCODE_VOLUMEUP,
    VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN,
    /* not sure whether there's a reason to enable these */
    /*     LOCKINGCAPSLOCK = 130,  */
    /*     LOCKINGNUMLOCK = 131, */
    /*     LOCKINGSCROLLLOCK = 132, */
    KP_COMMA = SDL_SCANCODE_KP_COMMA,
    KP_EQUALSAS400 = SDL_SCANCODE_KP_EQUALSAS400,

    INTERNATIONAL1 = SDL_SCANCODE_INTERNATIONAL1, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    INTERNATIONAL2 = SDL_SCANCODE_INTERNATIONAL2,
    INTERNATIONAL3 = SDL_SCANCODE_INTERNATIONAL3, /**< Yen */
    INTERNATIONAL4 = SDL_SCANCODE_INTERNATIONAL4,
    INTERNATIONAL5 = SDL_SCANCODE_INTERNATIONAL5,
    INTERNATIONAL6 = SDL_SCANCODE_INTERNATIONAL6,
    INTERNATIONAL7 = SDL_SCANCODE_INTERNATIONAL7,
    INTERNATIONAL8 = SDL_SCANCODE_INTERNATIONAL8,
    INTERNATIONAL9 = SDL_SCANCODE_INTERNATIONAL9,
    LANG1 = SDL_SCANCODE_LANG1, /**< Hangul/English toggle */
    LANG2 = SDL_SCANCODE_LANG2, /**< Hanja conversion */
    LANG3 = SDL_SCANCODE_LANG3, /**< Katakana */
    LANG4 = SDL_SCANCODE_LANG4, /**< Hiragana */
    LANG5 = SDL_SCANCODE_LANG5, /**< Zenkaku/Hankaku */
    LANG6 = SDL_SCANCODE_LANG6, /**< reserved */
    LANG7 = SDL_SCANCODE_LANG7, /**< reserved */
    LANG8 = SDL_SCANCODE_LANG8, /**< reserved */
    LANG9 = SDL_SCANCODE_LANG9, /**< reserved */

    ALTERASE = SDL_SCANCODE_ALTERASE, /**< Erase-Eaze */
    SYSREQ = SDL_SCANCODE_SYSREQ,
    CANCEL = SDL_SCANCODE_CANCEL, /**< AC Cancel */
    CLEAR = SDL_SCANCODE_CLEAR,
    PRIOR = SDL_SCANCODE_PRIOR,
    RETURN2 = SDL_SCANCODE_RETURN2,
    SEPARATOR = SDL_SCANCODE_SEPARATOR,
    OUT = SDL_SCANCODE_OUT,
    OPER = SDL_SCANCODE_OPER,
    CLEARAGAIN = SDL_SCANCODE_CLEARAGAIN,
    CRSEL = SDL_SCANCODE_CRSEL,
    EXSEL = SDL_SCANCODE_EXSEL,

    KP_00 = SDL_SCANCODE_KP_00,
    KP_000 = SDL_SCANCODE_KP_000,
    THOUSANDSSEPARATOR = SDL_SCANCODE_THOUSANDSSEPARATOR,
    DECIMALSEPARATOR = SDL_SCANCODE_DECIMALSEPARATOR,
    CURRENCYUNIT = SDL_SCANCODE_CURRENCYUNIT,
    CURRENCYSUBUNIT = SDL_SCANCODE_CURRENCYSUBUNIT,
    KP_LEFTPAREN = SDL_SCANCODE_KP_LEFTPAREN,
    KP_RIGHTPAREN = SDL_SCANCODE_KP_RIGHTPAREN,
    KP_LEFTBRACE = SDL_SCANCODE_KP_LEFTBRACE,
    KP_RIGHTBRACE = SDL_SCANCODE_KP_RIGHTBRACE,
    KP_TAB = SDL_SCANCODE_KP_TAB,
    KP_BACKSPACE = SDL_SCANCODE_KP_BACKSPACE,
    KP_A = SDL_SCANCODE_KP_A,
    KP_B = SDL_SCANCODE_KP_B,
    KP_C = SDL_SCANCODE_KP_C,
    KP_D = SDL_SCANCODE_KP_D,
    KP_E = SDL_SCANCODE_KP_E,
    KP_F = SDL_SCANCODE_KP_F,
    KP_XOR = SDL_SCANCODE_KP_XOR,
    KP_POWER = SDL_SCANCODE_KP_POWER,
    KP_PERCENT = SDL_SCANCODE_KP_PERCENT,
    KP_LESS = SDL_SCANCODE_KP_LESS,
    KP_GREATER = SDL_SCANCODE_KP_GREATER,
    KP_AMPERSAND = SDL_SCANCODE_KP_AMPERSAND,
    KP_DBLAMPERSAND = SDL_SCANCODE_KP_DBLAMPERSAND,
    KP_VERTICALBAR = SDL_SCANCODE_KP_VERTICALBAR,
    KP_DBLVERTICALBAR = SDL_SCANCODE_KP_DBLVERTICALBAR,
    KP_COLON = SDL_SCANCODE_KP_COLON,
    KP_HASH = SDL_SCANCODE_KP_HASH,
    KP_SPACE = SDL_SCANCODE_KP_SPACE,
    KP_AT = SDL_SCANCODE_KP_AT,
    KP_EXCLAM = SDL_SCANCODE_KP_EXCLAM,
    KP_MEMSTORE = SDL_SCANCODE_KP_MEMSTORE,
    KP_MEMRECALL = SDL_SCANCODE_KP_MEMRECALL,
    KP_MEMCLEAR = SDL_SCANCODE_KP_MEMCLEAR,
    KP_MEMADD = SDL_SCANCODE_KP_MEMADD,
    KP_MEMSUBTRACT = SDL_SCANCODE_KP_MEMSUBTRACT,
    KP_MEMMULTIPLY = SDL_SCANCODE_KP_MEMMULTIPLY,
    KP_MEMDIVIDE = SDL_SCANCODE_KP_MEMDIVIDE,
    KP_PLUSMINUS = SDL_SCANCODE_KP_PLUSMINUS,
    KP_CLEAR = SDL_SCANCODE_KP_CLEAR,
    KP_CLEARENTRY = SDL_SCANCODE_KP_CLEARENTRY,
    KP_BINARY = SDL_SCANCODE_KP_BINARY,
    KP_OCTAL = SDL_SCANCODE_KP_OCTAL,
    KP_DECIMAL = SDL_SCANCODE_KP_DECIMAL,
    KP_HEXADECIMAL = SDL_SCANCODE_KP_HEXADECIMAL,

    LCTRL = SDL_SCANCODE_LCTRL,
    LSHIFT = SDL_SCANCODE_LSHIFT,
    LALT = SDL_SCANCODE_LALT, /**< alt, option */
    LGUI = SDL_SCANCODE_LGUI, /**< windows, command (apple), meta */
    RCTRL = SDL_SCANCODE_RCTRL,
    RSHIFT = SDL_SCANCODE_RSHIFT,
    RALT = SDL_SCANCODE_RALT, /**< alt gr, option */
    RGUI = SDL_SCANCODE_RGUI, /**< windows, command (apple), meta */

    MODE = SDL_SCANCODE_MODE, /**< I'm not sure if this is really not covered
                               *   by any of the above, but since there's a
                               *   special KMOD_MODE for it I'm adding it here
                               */

    /* @} */ /* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     *  See https://usb.org/sites/default/files/hut1_2.pdf
     *
     *  There are way more keys in the spec than we can represent in the
     *  current scancode range, so pick the ones that commonly come up in
     *  real world usage.
     */
    /* @{ */

    AUDIONEXT = SDL_SCANCODE_AUDIONEXT,
    AUDIOPREV = SDL_SCANCODE_AUDIOPREV,
    AUDIOSTOP = SDL_SCANCODE_AUDIOSTOP,
    AUDIOPLAY = SDL_SCANCODE_AUDIOPLAY,
    AUDIOMUTE = SDL_SCANCODE_AUDIOMUTE,
    MEDIASELECT = SDL_SCANCODE_MEDIASELECT,
    WWW = SDL_SCANCODE_WWW, /**< AL Internet Browser */
    MAIL = SDL_SCANCODE_MAIL,
    CALCULATOR = SDL_SCANCODE_CALCULATOR, /**< AL Calculator */
    COMPUTER = SDL_SCANCODE_COMPUTER,
    AC_SEARCH = SDL_SCANCODE_AC_SEARCH,    /**< AC Search */
    AC_HOME = SDL_SCANCODE_AC_HOME,      /**< AC Home */
    AC_BACK = SDL_SCANCODE_AC_BACK,      /**< AC Back */
    AC_FORWARD = SDL_SCANCODE_AC_FORWARD,   /**< AC Forward */
    AC_STOP = SDL_SCANCODE_AC_STOP,      /**< AC Stop */
    AC_REFRESH = SDL_SCANCODE_AC_REFRESH,   /**< AC Refresh */
    AC_BOOKMARKS = SDL_SCANCODE_AC_BOOKMARKS, /**< AC Bookmarks */

    /* @} */ /* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    BRIGHTNESSDOWN = SDL_SCANCODE_BRIGHTNESSDOWN,
    BRIGHTNESSUP = SDL_SCANCODE_BRIGHTNESSUP,
    DISPLAYSWITCH = SDL_SCANCODE_DISPLAYSWITCH, /**< display mirroring/dual display
                                           switch, video mode switch */
    KBDILLUMTOGGLE = SDL_SCANCODE_KBDILLUMTOGGLE,
    KBDILLUMDOWN = SDL_SCANCODE_KBDILLUMDOWN,
    KBDILLUMUP = SDL_SCANCODE_KBDILLUMUP,
    EJECT = SDL_SCANCODE_EJECT,
    SLEEP = SDL_SCANCODE_SLEEP, /**< SC System Sleep */

    APP1 = SDL_SCANCODE_APP1,
    APP2 = SDL_SCANCODE_APP2,

    /* @} */ /* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    AUDIOREWIND = SDL_SCANCODE_AUDIOREWIND,
    AUDIOFASTFORWARD = SDL_SCANCODE_AUDIOFASTFORWARD,

    /* @} */ /* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
    /* @{ */

    SOFTLEFT =
        SDL_SCANCODE_SOFTLEFT, /**< Usually situated below the display on phones and
                  used as a multi-function feature key for selecting
                  a software defined function shown on the bottom left
                  of the display. */
    SOFTRIGHT =
        SDL_SCANCODE_SOFTRIGHT, /**< Usually situated below the display on phones and
                 used as a multi-function feature key for selecting
                 a software defined function shown on the bottom right
                 of the display. */
    CALL = SDL_SCANCODE_CALL,    /**< Used for accepting phone calls. */
    ENDCALL = SDL_SCANCODE_ENDCALL, /**< Used for rejecting phone calls. */

    /* @} */ /* Mobile keys */

    /* Add any other keys here. */

    NUM_SCANCODES = SDL_NUM_SCANCODES, /**< not a key, just marks the number of scancodes
                                 for array bounds */


    // Below are the keycodes handling mouse buttons.

    MOUSE_LB = 513,
    MOUSE_MB = 514,
    MOUSE_RB = 515,
};
// clang-format on
} // namespace Util

#endif // UTIL_EVENT_STUFF_HPP
