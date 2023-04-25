#ifndef UTIL_EVENT_KEYBOARD_EVENT_HPP
#define UTIL_EVENT_KEYBOARD_EVENT_HPP

// warped enum from SDL_Scancode
enum class PTSD_Scancode {
    PTSD_SCANCODE_UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    PTSD_SCANCODE_A = 4,
    PTSD_SCANCODE_B = 5,
    PTSD_SCANCODE_C = 6,
    PTSD_SCANCODE_D = 7,
    PTSD_SCANCODE_E = 8,
    PTSD_SCANCODE_F = 9,
    PTSD_SCANCODE_G = 10,
    PTSD_SCANCODE_H = 11,
    PTSD_SCANCODE_I = 12,
    PTSD_SCANCODE_J = 13,
    PTSD_SCANCODE_K = 14,
    PTSD_SCANCODE_L = 15,
    PTSD_SCANCODE_M = 16,
    PTSD_SCANCODE_N = 17,
    PTSD_SCANCODE_O = 18,
    PTSD_SCANCODE_P = 19,
    PTSD_SCANCODE_Q = 20,
    PTSD_SCANCODE_R = 21,
    PTSD_SCANCODE_S = 22,
    PTSD_SCANCODE_T = 23,
    PTSD_SCANCODE_U = 24,
    PTSD_SCANCODE_V = 25,
    PTSD_SCANCODE_W = 26,
    PTSD_SCANCODE_X = 27,
    PTSD_SCANCODE_Y = 28,
    PTSD_SCANCODE_Z = 29,

    PTSD_SCANCODE_1 = 30,
    PTSD_SCANCODE_2 = 31,
    PTSD_SCANCODE_3 = 32,
    PTSD_SCANCODE_4 = 33,
    PTSD_SCANCODE_5 = 34,
    PTSD_SCANCODE_6 = 35,
    PTSD_SCANCODE_7 = 36,
    PTSD_SCANCODE_8 = 37,
    PTSD_SCANCODE_9 = 38,
    PTSD_SCANCODE_0 = 39,

    PTSD_SCANCODE_RETURN = 40,
    PTSD_SCANCODE_ESCAPE = 41,
    PTSD_SCANCODE_BACKSPACE = 42,
    PTSD_SCANCODE_TAB = 43,
    PTSD_SCANCODE_SPACE = 44,

    PTSD_SCANCODE_MINUS = 45,
    PTSD_SCANCODE_EQUALS = 46,
    PTSD_SCANCODE_LEFTBRACKET = 47,
    PTSD_SCANCODE_RIGHTBRACKET = 48,
    PTSD_SCANCODE_BACKSLASH = 49, /**< Located at the lower left of the return
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
    PTSD_SCANCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                   *   instead of 49 for the same key, but all
                                   *   OSes I've seen treat the two codes
                                   *   identically. So, as an implementor,
                                   * unless your keyboard generates both of
                                   * those codes and your OS treats them
                                   * differently, you should generate
                                   * PTSD_SCANCODE_BACKSLASH instead of this
                                   * code. As a user, you should not rely on
                                   * this code because SDL will never generate
                                   * it with most (all?) keyboards.
                                   */
    PTSD_SCANCODE_SEMICOLON = 51,
    PTSD_SCANCODE_APOSTROPHE = 52,
    PTSD_SCANCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
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
    PTSD_SCANCODE_COMMA = 54,
    PTSD_SCANCODE_PERIOD = 55,
    PTSD_SCANCODE_SLASH = 56,

    PTSD_SCANCODE_CAPSLOCK = 57,

    PTSD_SCANCODE_F1 = 58,
    PTSD_SCANCODE_F2 = 59,
    PTSD_SCANCODE_F3 = 60,
    PTSD_SCANCODE_F4 = 61,
    PTSD_SCANCODE_F5 = 62,
    PTSD_SCANCODE_F6 = 63,
    PTSD_SCANCODE_F7 = 64,
    PTSD_SCANCODE_F8 = 65,
    PTSD_SCANCODE_F9 = 66,
    PTSD_SCANCODE_F10 = 67,
    PTSD_SCANCODE_F11 = 68,
    PTSD_SCANCODE_F12 = 69,

    PTSD_SCANCODE_PRINTSCREEN = 70,
    PTSD_SCANCODE_SCROLLLOCK = 71,
    PTSD_SCANCODE_PAUSE = 72,
    PTSD_SCANCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards
                                  (but does send code 73, not 117) */
    PTSD_SCANCODE_HOME = 74,
    PTSD_SCANCODE_PAGEUP = 75,
    PTSD_SCANCODE_DELETE = 76,
    PTSD_SCANCODE_END = 77,
    PTSD_SCANCODE_PAGEDOWN = 78,
    PTSD_SCANCODE_RIGHT = 79,
    PTSD_SCANCODE_LEFT = 80,
    PTSD_SCANCODE_DOWN = 81,
    PTSD_SCANCODE_UP = 82,

    PTSD_SCANCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                      */
    PTSD_SCANCODE_KP_DIVIDE = 84,
    PTSD_SCANCODE_KP_MULTIPLY = 85,
    PTSD_SCANCODE_KP_MINUS = 86,
    PTSD_SCANCODE_KP_PLUS = 87,
    PTSD_SCANCODE_KP_ENTER = 88,
    PTSD_SCANCODE_KP_1 = 89,
    PTSD_SCANCODE_KP_2 = 90,
    PTSD_SCANCODE_KP_3 = 91,
    PTSD_SCANCODE_KP_4 = 92,
    PTSD_SCANCODE_KP_5 = 93,
    PTSD_SCANCODE_KP_6 = 94,
    PTSD_SCANCODE_KP_7 = 95,
    PTSD_SCANCODE_KP_8 = 96,
    PTSD_SCANCODE_KP_9 = 97,
    PTSD_SCANCODE_KP_0 = 98,
    PTSD_SCANCODE_KP_PERIOD = 99,

    PTSD_SCANCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                         *   keyboards have over ANSI ones,
                                         *   located between left shift and Y.
                                         *   Produces GRAVE ACCENT and TILDE in
                                         * a US or UK Mac layout, REVERSE
                                         * SOLIDUS (backslash) and VERTICAL LINE
                                         * in a US or UK Windows layout, and
                                         *   LESS-THAN SIGN and GREATER-THAN
                                         * SIGN in a Swiss German, German, or
                                         * French layout. */
    PTSD_SCANCODE_APPLICATION = 101,    /**< windows contextual menu, compose */
    PTSD_SCANCODE_POWER = 102, /**< The USB document says this is a status flag,
                                *   not a physical key - but some Mac keyboards
                                *   do have a power key. */
    PTSD_SCANCODE_KP_EQUALS = 103,
    PTSD_SCANCODE_F13 = 104,
    PTSD_SCANCODE_F14 = 105,
    PTSD_SCANCODE_F15 = 106,
    PTSD_SCANCODE_F16 = 107,
    PTSD_SCANCODE_F17 = 108,
    PTSD_SCANCODE_F18 = 109,
    PTSD_SCANCODE_F19 = 110,
    PTSD_SCANCODE_F20 = 111,
    PTSD_SCANCODE_F21 = 112,
    PTSD_SCANCODE_F22 = 113,
    PTSD_SCANCODE_F23 = 114,
    PTSD_SCANCODE_F24 = 115,
    PTSD_SCANCODE_EXECUTE = 116,
    PTSD_SCANCODE_HELP = 117, /**< AL Integrated Help Center */
    PTSD_SCANCODE_MENU = 118, /**< Menu (show menu) */
    PTSD_SCANCODE_SELECT = 119,
    PTSD_SCANCODE_STOP = 120,  /**< AC Stop */
    PTSD_SCANCODE_AGAIN = 121, /**< AC Redo/Repeat */
    PTSD_SCANCODE_UNDO = 122,  /**< AC Undo */
    PTSD_SCANCODE_CUT = 123,   /**< AC Cut */
    PTSD_SCANCODE_COPY = 124,  /**< AC Copy */
    PTSD_SCANCODE_PASTE = 125, /**< AC Paste */
    PTSD_SCANCODE_FIND = 126,  /**< AC Find */
    PTSD_SCANCODE_MUTE = 127,
    PTSD_SCANCODE_VOLUMEUP = 128,
    PTSD_SCANCODE_VOLUMEDOWN = 129,
    /* not sure whether there's a reason to enable these */
    /*     PTSD_SCANCODE_LOCKINGCAPSLOCK = 130,  */
    /*     PTSD_SCANCODE_LOCKINGNUMLOCK = 131, */
    /*     PTSD_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    PTSD_SCANCODE_KP_COMMA = 133,
    PTSD_SCANCODE_KP_EQUALSAS400 = 134,

    PTSD_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    PTSD_SCANCODE_INTERNATIONAL2 = 136,
    PTSD_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
    PTSD_SCANCODE_INTERNATIONAL4 = 138,
    PTSD_SCANCODE_INTERNATIONAL5 = 139,
    PTSD_SCANCODE_INTERNATIONAL6 = 140,
    PTSD_SCANCODE_INTERNATIONAL7 = 141,
    PTSD_SCANCODE_INTERNATIONAL8 = 142,
    PTSD_SCANCODE_INTERNATIONAL9 = 143,
    PTSD_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
    PTSD_SCANCODE_LANG2 = 145, /**< Hanja conversion */
    PTSD_SCANCODE_LANG3 = 146, /**< Katakana */
    PTSD_SCANCODE_LANG4 = 147, /**< Hiragana */
    PTSD_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    PTSD_SCANCODE_LANG6 = 149, /**< reserved */
    PTSD_SCANCODE_LANG7 = 150, /**< reserved */
    PTSD_SCANCODE_LANG8 = 151, /**< reserved */
    PTSD_SCANCODE_LANG9 = 152, /**< reserved */

    PTSD_SCANCODE_ALTERASE = 153, /**< Erase-Eaze */
    PTSD_SCANCODE_SYSREQ = 154,
    PTSD_SCANCODE_CANCEL = 155, /**< AC Cancel */
    PTSD_SCANCODE_CLEAR = 156,
    PTSD_SCANCODE_PRIOR = 157,
    PTSD_SCANCODE_RETURN2 = 158,
    PTSD_SCANCODE_SEPARATOR = 159,
    PTSD_SCANCODE_OUT = 160,
    PTSD_SCANCODE_OPER = 161,
    PTSD_SCANCODE_CLEARAGAIN = 162,
    PTSD_SCANCODE_CRSEL = 163,
    PTSD_SCANCODE_EXSEL = 164,

    PTSD_SCANCODE_KP_00 = 176,
    PTSD_SCANCODE_KP_000 = 177,
    PTSD_SCANCODE_THOUSANDSSEPARATOR = 178,
    PTSD_SCANCODE_DECIMALSEPARATOR = 179,
    PTSD_SCANCODE_CURRENCYUNIT = 180,
    PTSD_SCANCODE_CURRENCYSUBUNIT = 181,
    PTSD_SCANCODE_KP_LEFTPAREN = 182,
    PTSD_SCANCODE_KP_RIGHTPAREN = 183,
    PTSD_SCANCODE_KP_LEFTBRACE = 184,
    PTSD_SCANCODE_KP_RIGHTBRACE = 185,
    PTSD_SCANCODE_KP_TAB = 186,
    PTSD_SCANCODE_KP_BACKSPACE = 187,
    PTSD_SCANCODE_KP_A = 188,
    PTSD_SCANCODE_KP_B = 189,
    PTSD_SCANCODE_KP_C = 190,
    PTSD_SCANCODE_KP_D = 191,
    PTSD_SCANCODE_KP_E = 192,
    PTSD_SCANCODE_KP_F = 193,
    PTSD_SCANCODE_KP_XOR = 194,
    PTSD_SCANCODE_KP_POWER = 195,
    PTSD_SCANCODE_KP_PERCENT = 196,
    PTSD_SCANCODE_KP_LESS = 197,
    PTSD_SCANCODE_KP_GREATER = 198,
    PTSD_SCANCODE_KP_AMPERSAND = 199,
    PTSD_SCANCODE_KP_DBLAMPERSAND = 200,
    PTSD_SCANCODE_KP_VERTICALBAR = 201,
    PTSD_SCANCODE_KP_DBLVERTICALBAR = 202,
    PTSD_SCANCODE_KP_COLON = 203,
    PTSD_SCANCODE_KP_HASH = 204,
    PTSD_SCANCODE_KP_SPACE = 205,
    PTSD_SCANCODE_KP_AT = 206,
    PTSD_SCANCODE_KP_EXCLAM = 207,
    PTSD_SCANCODE_KP_MEMSTORE = 208,
    PTSD_SCANCODE_KP_MEMRECALL = 209,
    PTSD_SCANCODE_KP_MEMCLEAR = 210,
    PTSD_SCANCODE_KP_MEMADD = 211,
    PTSD_SCANCODE_KP_MEMSUBTRACT = 212,
    PTSD_SCANCODE_KP_MEMMULTIPLY = 213,
    PTSD_SCANCODE_KP_MEMDIVIDE = 214,
    PTSD_SCANCODE_KP_PLUSMINUS = 215,
    PTSD_SCANCODE_KP_CLEAR = 216,
    PTSD_SCANCODE_KP_CLEARENTRY = 217,
    PTSD_SCANCODE_KP_BINARY = 218,
    PTSD_SCANCODE_KP_OCTAL = 219,
    PTSD_SCANCODE_KP_DECIMAL = 220,
    PTSD_SCANCODE_KP_HEXADECIMAL = 221,

    PTSD_SCANCODE_LCTRL = 224,
    PTSD_SCANCODE_LSHIFT = 225,
    PTSD_SCANCODE_LALT = 226, /**< alt, option */
    PTSD_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
    PTSD_SCANCODE_RCTRL = 228,
    PTSD_SCANCODE_RSHIFT = 229,
    PTSD_SCANCODE_RALT = 230, /**< alt gr, option */
    PTSD_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

    PTSD_SCANCODE_MODE = 257, /**< I'm not sure if this is really not covered
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

    PTSD_SCANCODE_AUDIONEXT = 258,
    PTSD_SCANCODE_AUDIOPREV = 259,
    PTSD_SCANCODE_AUDIOSTOP = 260,
    PTSD_SCANCODE_AUDIOPLAY = 261,
    PTSD_SCANCODE_AUDIOMUTE = 262,
    PTSD_SCANCODE_MEDIASELECT = 263,
    PTSD_SCANCODE_WWW = 264, /**< AL Internet Browser */
    PTSD_SCANCODE_MAIL = 265,
    PTSD_SCANCODE_CALCULATOR = 266, /**< AL Calculator */
    PTSD_SCANCODE_COMPUTER = 267,
    PTSD_SCANCODE_AC_SEARCH = 268,    /**< AC Search */
    PTSD_SCANCODE_AC_HOME = 269,      /**< AC Home */
    PTSD_SCANCODE_AC_BACK = 270,      /**< AC Back */
    PTSD_SCANCODE_AC_FORWARD = 271,   /**< AC Forward */
    PTSD_SCANCODE_AC_STOP = 272,      /**< AC Stop */
    PTSD_SCANCODE_AC_REFRESH = 273,   /**< AC Refresh */
    PTSD_SCANCODE_AC_BOOKMARKS = 274, /**< AC Bookmarks */

    /* @} */ /* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    PTSD_SCANCODE_BRIGHTNESSDOWN = 275,
    PTSD_SCANCODE_BRIGHTNESSUP = 276,
    PTSD_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    PTSD_SCANCODE_KBDILLUMTOGGLE = 278,
    PTSD_SCANCODE_KBDILLUMDOWN = 279,
    PTSD_SCANCODE_KBDILLUMUP = 280,
    PTSD_SCANCODE_EJECT = 281,
    PTSD_SCANCODE_SLEEP = 282, /**< SC System Sleep */

    PTSD_SCANCODE_APP1 = 283,
    PTSD_SCANCODE_APP2 = 284,

    /* @} */ /* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    PTSD_SCANCODE_AUDIOREWIND = 285,
    PTSD_SCANCODE_AUDIOFASTFORWARD = 286,

    /* @} */ /* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
    /* @{ */

    PTSD_SCANCODE_SOFTLEFT =
        287, /**< Usually situated below the display on phones and
                  used as a multi-function feature key for selecting
                  a software defined function shown on the bottom left
                  of the display. */
    PTSD_SCANCODE_SOFTRIGHT =
        288, /**< Usually situated below the display on phones and
                 used as a multi-function feature key for selecting
                 a software defined function shown on the bottom right
                 of the display. */
    PTSD_SCANCODE_CALL = 289,    /**< Used for accepting phone calls. */
    PTSD_SCANCODE_ENDCALL = 290, /**< Used for rejecting phone calls. */

    /* @} */ /* Mobile keys */

    /* Add any other keys here. */

    PTSD_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
};

class KeyBoardEvent {
public:
    bool IfKeyPressed(const PTSD_Scancode &keyCode) const;

private:
    int *m_KeyArr;
    int m_KeyArrLen;
};

#endif // UTIL_EVENT_KEYBOARD_EVENT_HPP