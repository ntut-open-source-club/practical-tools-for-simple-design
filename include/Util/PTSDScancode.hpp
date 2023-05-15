#ifndef UTIL_EVENT_STUFF_PTSD_SCANCODE_HPP
#define UTIL_EVENT_STUFF_PTSD_SCANCODE_HPP

// stolen enum from SDL_Scancode
#include "SDL_scancode.h"
enum class PTSDScancode {
    PTSD_SCANCODE_UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    PTSD_SCANCODE_A = SDL_SCANCODE_A,
    PTSD_SCANCODE_B = SDL_SCANCODE_B,
    PTSD_SCANCODE_C = SDL_SCANCODE_C,
    PTSD_SCANCODE_D = SDL_SCANCODE_D,
    PTSD_SCANCODE_E = SDL_SCANCODE_E,
    PTSD_SCANCODE_F = SDL_SCANCODE_F,
    PTSD_SCANCODE_G = SDL_SCANCODE_G,
    PTSD_SCANCODE_H = SDL_SCANCODE_H,
    PTSD_SCANCODE_I = SDL_SCANCODE_I,
    PTSD_SCANCODE_J = SDL_SCANCODE_J,
    PTSD_SCANCODE_K = SDL_SCANCODE_K,
    PTSD_SCANCODE_L = SDL_SCANCODE_L,
    PTSD_SCANCODE_M = SDL_SCANCODE_M,
    PTSD_SCANCODE_N = SDL_SCANCODE_N,
    PTSD_SCANCODE_O = SDL_SCANCODE_O,
    PTSD_SCANCODE_P = SDL_SCANCODE_P,
    PTSD_SCANCODE_Q = SDL_SCANCODE_Q,
    PTSD_SCANCODE_R = SDL_SCANCODE_R,
    PTSD_SCANCODE_S = SDL_SCANCODE_S,
    PTSD_SCANCODE_T = SDL_SCANCODE_T,
    PTSD_SCANCODE_U = SDL_SCANCODE_U,
    PTSD_SCANCODE_V = SDL_SCANCODE_V,
    PTSD_SCANCODE_W = SDL_SCANCODE_W,
    PTSD_SCANCODE_X = SDL_SCANCODE_X,
    PTSD_SCANCODE_Y = SDL_SCANCODE_Y,
    PTSD_SCANCODE_Z = SDL_SCANCODE_Z,
    PTSD_SCANCODE_1 = SDL_SCANCODE_1,
    PTSD_SCANCODE_2 = SDL_SCANCODE_2,
    PTSD_SCANCODE_3 = SDL_SCANCODE_3,
    PTSD_SCANCODE_4 = SDL_SCANCODE_4,
    PTSD_SCANCODE_5 = SDL_SCANCODE_5,
    PTSD_SCANCODE_6 = SDL_SCANCODE_6,
    PTSD_SCANCODE_7 = SDL_SCANCODE_7,
    PTSD_SCANCODE_8 = SDL_SCANCODE_8,
    PTSD_SCANCODE_9 = SDL_SCANCODE_9,
    PTSD_SCANCODE_0 = SDL_SCANCODE_0,

    PTSD_SCANCODE_RETURN = SDL_SCANCODE_RETURN,
    PTSD_SCANCODE_ESCAPE = SDL_SCANCODE_ESCAPE,
    PTSD_SCANCODE_BACKSPACE = SDL_SCANCODE_BACKSPACE,
    PTSD_SCANCODE_TAB = SDL_SCANCODE_TAB,
    PTSD_SCANCODE_SPACE = SDL_SCANCODE_SPACE,

    PTSD_SCANCODE_MINUS = SDL_SCANCODE_MINUS,
    PTSD_SCANCODE_EQUALS = SDL_SCANCODE_EQUALS,
    PTSD_SCANCODE_LEFTBRACKET = SDL_SCANCODE_LEFTBRACKET,
    PTSD_SCANCODE_RIGHTBRACKET = SDL_SCANCODE_RIGHTBRACKET,
    PTSD_SCANCODE_BACKSLASH = SDL_SCANCODE_BACKSLASH, /**< Located at the lower left of the return
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
    PTSD_SCANCODE_NONUSHASH = SDL_SCANCODE_NONUSHASH, /**< ISO USB keyboards actually use this code
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
    PTSD_SCANCODE_SEMICOLON = SDL_SCANCODE_SEMICOLON,
    PTSD_SCANCODE_APOSTROPHE = SDL_SCANCODE_APOSTROPHE,
    PTSD_SCANCODE_GRAVE = SDL_SCANCODE_GRAVE, /**< Located in the top left corner (on both ANSI
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
    PTSD_SCANCODE_COMMA = SDL_SCANCODE_COMMA,
    PTSD_SCANCODE_PERIOD = SDL_SCANCODE_PERIOD,
    PTSD_SCANCODE_SLASH = SDL_SCANCODE_SLASH,

    PTSD_SCANCODE_CAPSLOCK = SDL_SCANCODE_CAPSLOCK,

    PTSD_SCANCODE_F1 = SDL_SCANCODE_F1,
    PTSD_SCANCODE_F2 = SDL_SCANCODE_F2,
    PTSD_SCANCODE_F3 = SDL_SCANCODE_F3,
    PTSD_SCANCODE_F4 = SDL_SCANCODE_F4,
    PTSD_SCANCODE_F5 = SDL_SCANCODE_F5,
    PTSD_SCANCODE_F6 = SDL_SCANCODE_F6,
    PTSD_SCANCODE_F7 = SDL_SCANCODE_F7,
    PTSD_SCANCODE_F8 = SDL_SCANCODE_F8,
    PTSD_SCANCODE_F9 = SDL_SCANCODE_F9,
    PTSD_SCANCODE_F10 = SDL_SCANCODE_F10,
    PTSD_SCANCODE_F11 = SDL_SCANCODE_F11,
    PTSD_SCANCODE_F12 = SDL_SCANCODE_F12,

    PTSD_SCANCODE_PRINTSCREEN = SDL_SCANCODE_PRINTSCREEN,
    PTSD_SCANCODE_SCROLLLOCK = SDL_SCANCODE_SCROLLLOCK,
    PTSD_SCANCODE_PAUSE = SDL_SCANCODE_PAUSE,
    PTSD_SCANCODE_INSERT = SDL_SCANCODE_INSERT, /**< insert on PC, help on some Mac keyboards
                                  (but does send code 73, not 117) */
    PTSD_SCANCODE_HOME = SDL_SCANCODE_HOME,
    PTSD_SCANCODE_PAGEUP = SDL_SCANCODE_PAGEUP,
    PTSD_SCANCODE_DELETE = SDL_SCANCODE_DELETE,
    PTSD_SCANCODE_END = SDL_SCANCODE_END,
    PTSD_SCANCODE_PAGEDOWN = SDL_SCANCODE_PAGEDOWN,
    PTSD_SCANCODE_RIGHT = SDL_SCANCODE_RIGHT,
    PTSD_SCANCODE_LEFT = SDL_SCANCODE_LEFT,
    PTSD_SCANCODE_DOWN = SDL_SCANCODE_DOWN,
    PTSD_SCANCODE_UP = SDL_SCANCODE_UP,

    PTSD_SCANCODE_NUMLOCKCLEAR = SDL_SCANCODE_NUMLOCKCLEAR, /**< num lock on PC, clear on Mac keyboards
                                      */
    PTSD_SCANCODE_KP_DIVIDE = SDL_SCANCODE_KP_DIVIDE,
    PTSD_SCANCODE_KP_MULTIPLY = SDL_SCANCODE_KP_MULTIPLY,
    PTSD_SCANCODE_KP_MINUS = SDL_SCANCODE_KP_MINUS,
    PTSD_SCANCODE_KP_PLUS = SDL_SCANCODE_KP_PLUS,
    PTSD_SCANCODE_KP_ENTER = SDL_SCANCODE_KP_ENTER,
    PTSD_SCANCODE_KP_1 = SDL_SCANCODE_KP_1,
    PTSD_SCANCODE_KP_2 = SDL_SCANCODE_KP_2,
    PTSD_SCANCODE_KP_3 = SDL_SCANCODE_KP_3,
    PTSD_SCANCODE_KP_4 = SDL_SCANCODE_KP_4,
    PTSD_SCANCODE_KP_5 = SDL_SCANCODE_KP_5,
    PTSD_SCANCODE_KP_6 = SDL_SCANCODE_KP_6,
    PTSD_SCANCODE_KP_7 = SDL_SCANCODE_KP_7,
    PTSD_SCANCODE_KP_8 = SDL_SCANCODE_KP_8,
    PTSD_SCANCODE_KP_9 = SDL_SCANCODE_KP_9,
    PTSD_SCANCODE_KP_0 = SDL_SCANCODE_KP_0,
    PTSD_SCANCODE_KP_PERIOD = SDL_SCANCODE_KP_PERIOD,

    PTSD_SCANCODE_NONUSBACKSLASH = SDL_SCANCODE_NONUSBACKSLASH, /**< This is the additional key that ISO
                                         *   keyboards have over ANSI ones,
                                         *   located between left shift and Y.
                                         *   Produces GRAVE ACCENT and TILDE in
                                         * a US or UK Mac layout, REVERSE
                                         * SOLIDUS (backslash) and VERTICAL LINE
                                         * in a US or UK Windows layout, and
                                         *   LESS-THAN SIGN and GREATER-THAN
                                         * SIGN in a Swiss German, German, or
                                         * French layout. */
    PTSD_SCANCODE_APPLICATION = SDL_SCANCODE_APPLICATION,    /**< windows contextual menu, compose */
    PTSD_SCANCODE_POWER = SDL_SCANCODE_POWER, /**< The USB document says this is a status flag,
                                *   not a physical key - but some Mac keyboards
                                *   do have a power key. */
    PTSD_SCANCODE_KP_EQUALS = SDL_SCANCODE_KP_EQUALS,
    PTSD_SCANCODE_F13 = SDL_SCANCODE_F13,
    PTSD_SCANCODE_F14 = SDL_SCANCODE_F14,
    PTSD_SCANCODE_F15 = SDL_SCANCODE_F15,
    PTSD_SCANCODE_F16 = SDL_SCANCODE_F16,
    PTSD_SCANCODE_F17 = SDL_SCANCODE_F17,
    PTSD_SCANCODE_F18 = SDL_SCANCODE_F18,
    PTSD_SCANCODE_F19 = SDL_SCANCODE_F19,
    PTSD_SCANCODE_F20 = SDL_SCANCODE_F20,
    PTSD_SCANCODE_F21 = SDL_SCANCODE_F21,
    PTSD_SCANCODE_F22 = SDL_SCANCODE_F22,
    PTSD_SCANCODE_F23 = SDL_SCANCODE_F23,
    PTSD_SCANCODE_F24 = SDL_SCANCODE_F24,
    PTSD_SCANCODE_EXECUTE = SDL_SCANCODE_EXECUTE,
    PTSD_SCANCODE_HELP = SDL_SCANCODE_HELP, /**< AL Integrated Help Center */
    PTSD_SCANCODE_MENU = SDL_SCANCODE_MENU, /**< Menu (show menu) */
    PTSD_SCANCODE_SELECT = SDL_SCANCODE_SELECT,
    PTSD_SCANCODE_STOP = SDL_SCANCODE_STOP,  /**< AC Stop */
    PTSD_SCANCODE_AGAIN = SDL_SCANCODE_AGAIN, /**< AC Redo/Repeat */
    PTSD_SCANCODE_UNDO = SDL_SCANCODE_UNDO,  /**< AC Undo */
    PTSD_SCANCODE_CUT = SDL_SCANCODE_CUT,   /**< AC Cut */
    PTSD_SCANCODE_COPY = SDL_SCANCODE_COPY,  /**< AC Copy */
    PTSD_SCANCODE_PASTE = SDL_SCANCODE_PASTE, /**< AC Paste */
    PTSD_SCANCODE_FIND = SDL_SCANCODE_FIND,  /**< AC Find */
    PTSD_SCANCODE_MUTE = SDL_SCANCODE_MUTE,
    PTSD_SCANCODE_VOLUMEUP = SDL_SCANCODE_VOLUMEUP,
    PTSD_SCANCODE_VOLUMEDOWN = SDL_SCANCODE_VOLUMEDOWN,
    /* not sure whether there's a reason to enable these */
    /*     PTSD_SCANCODE_LOCKINGCAPSLOCK = 130,  */
    /*     PTSD_SCANCODE_LOCKINGNUMLOCK = 131, */
    /*     PTSD_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    PTSD_SCANCODE_KP_COMMA = SDL_SCANCODE_KP_COMMA,
    PTSD_SCANCODE_KP_EQUALSAS400 = SDL_SCANCODE_KP_EQUALSAS400,

    PTSD_SCANCODE_INTERNATIONAL1 = SDL_SCANCODE_INTERNATIONAL1, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    PTSD_SCANCODE_INTERNATIONAL2 = SDL_SCANCODE_INTERNATIONAL2,
    PTSD_SCANCODE_INTERNATIONAL3 = SDL_SCANCODE_INTERNATIONAL3, /**< Yen */
    PTSD_SCANCODE_INTERNATIONAL4 = SDL_SCANCODE_INTERNATIONAL4,
    PTSD_SCANCODE_INTERNATIONAL5 = SDL_SCANCODE_INTERNATIONAL5,
    PTSD_SCANCODE_INTERNATIONAL6 = SDL_SCANCODE_INTERNATIONAL6,
    PTSD_SCANCODE_INTERNATIONAL7 = SDL_SCANCODE_INTERNATIONAL7,
    PTSD_SCANCODE_INTERNATIONAL8 = SDL_SCANCODE_INTERNATIONAL8,
    PTSD_SCANCODE_INTERNATIONAL9 = SDL_SCANCODE_INTERNATIONAL9,
    PTSD_SCANCODE_LANG1 = SDL_SCANCODE_LANG1, /**< Hangul/English toggle */
    PTSD_SCANCODE_LANG2 = SDL_SCANCODE_LANG2, /**< Hanja conversion */
    PTSD_SCANCODE_LANG3 = SDL_SCANCODE_LANG3, /**< Katakana */
    PTSD_SCANCODE_LANG4 = SDL_SCANCODE_LANG4, /**< Hiragana */
    PTSD_SCANCODE_LANG5 = SDL_SCANCODE_LANG5, /**< Zenkaku/Hankaku */
    PTSD_SCANCODE_LANG6 = SDL_SCANCODE_LANG6, /**< reserved */
    PTSD_SCANCODE_LANG7 = SDL_SCANCODE_LANG7, /**< reserved */
    PTSD_SCANCODE_LANG8 = SDL_SCANCODE_LANG8, /**< reserved */
    PTSD_SCANCODE_LANG9 = SDL_SCANCODE_LANG9, /**< reserved */

    PTSD_SCANCODE_ALTERASE = SDL_SCANCODE_ALTERASE, /**< Erase-Eaze */
    PTSD_SCANCODE_SYSREQ = SDL_SCANCODE_SYSREQ,
    PTSD_SCANCODE_CANCEL = SDL_SCANCODE_CANCEL, /**< AC Cancel */
    PTSD_SCANCODE_CLEAR = SDL_SCANCODE_CLEAR,
    PTSD_SCANCODE_PRIOR = SDL_SCANCODE_PRIOR,
    PTSD_SCANCODE_RETURN2 = SDL_SCANCODE_RETURN2,
    PTSD_SCANCODE_SEPARATOR = SDL_SCANCODE_SEPARATOR,
    PTSD_SCANCODE_OUT = SDL_SCANCODE_OUT,
    PTSD_SCANCODE_OPER = SDL_SCANCODE_OPER,
    PTSD_SCANCODE_CLEARAGAIN = SDL_SCANCODE_CLEARAGAIN,
    PTSD_SCANCODE_CRSEL = SDL_SCANCODE_CRSEL,
    PTSD_SCANCODE_EXSEL = SDL_SCANCODE_EXSEL,

    PTSD_SCANCODE_KP_00 = SDL_SCANCODE_KP_00,
    PTSD_SCANCODE_KP_000 = SDL_SCANCODE_KP_000,
    PTSD_SCANCODE_THOUSANDSSEPARATOR = SDL_SCANCODE_THOUSANDSSEPARATOR,
    PTSD_SCANCODE_DECIMALSEPARATOR = SDL_SCANCODE_DECIMALSEPARATOR,
    PTSD_SCANCODE_CURRENCYUNIT = SDL_SCANCODE_CURRENCYUNIT,
    PTSD_SCANCODE_CURRENCYSUBUNIT = SDL_SCANCODE_CURRENCYSUBUNIT,
    PTSD_SCANCODE_KP_LEFTPAREN = SDL_SCANCODE_KP_LEFTPAREN,
    PTSD_SCANCODE_KP_RIGHTPAREN = SDL_SCANCODE_KP_RIGHTPAREN,
    PTSD_SCANCODE_KP_LEFTBRACE = SDL_SCANCODE_KP_LEFTBRACE,
    PTSD_SCANCODE_KP_RIGHTBRACE = SDL_SCANCODE_KP_RIGHTBRACE,
    PTSD_SCANCODE_KP_TAB = SDL_SCANCODE_KP_TAB,
    PTSD_SCANCODE_KP_BACKSPACE = SDL_SCANCODE_KP_BACKSPACE,
    PTSD_SCANCODE_KP_A = SDL_SCANCODE_KP_A,
    PTSD_SCANCODE_KP_B = SDL_SCANCODE_KP_B,
    PTSD_SCANCODE_KP_C = SDL_SCANCODE_KP_C,
    PTSD_SCANCODE_KP_D = SDL_SCANCODE_KP_D,
    PTSD_SCANCODE_KP_E = SDL_SCANCODE_KP_E,
    PTSD_SCANCODE_KP_F = SDL_SCANCODE_KP_F,
    PTSD_SCANCODE_KP_XOR = SDL_SCANCODE_KP_XOR,
    PTSD_SCANCODE_KP_POWER = SDL_SCANCODE_KP_POWER,
    PTSD_SCANCODE_KP_PERCENT = SDL_SCANCODE_KP_PERCENT,
    PTSD_SCANCODE_KP_LESS = SDL_SCANCODE_KP_LESS,
    PTSD_SCANCODE_KP_GREATER = SDL_SCANCODE_KP_GREATER,
    PTSD_SCANCODE_KP_AMPERSAND = SDL_SCANCODE_KP_AMPERSAND,
    PTSD_SCANCODE_KP_DBLAMPERSAND = SDL_SCANCODE_KP_DBLAMPERSAND,
    PTSD_SCANCODE_KP_VERTICALBAR = SDL_SCANCODE_KP_VERTICALBAR,
    PTSD_SCANCODE_KP_DBLVERTICALBAR = SDL_SCANCODE_KP_DBLVERTICALBAR,
    PTSD_SCANCODE_KP_COLON = SDL_SCANCODE_KP_COLON,
    PTSD_SCANCODE_KP_HASH = SDL_SCANCODE_KP_HASH,
    PTSD_SCANCODE_KP_SPACE = SDL_SCANCODE_KP_SPACE,
    PTSD_SCANCODE_KP_AT = SDL_SCANCODE_KP_AT,
    PTSD_SCANCODE_KP_EXCLAM = SDL_SCANCODE_KP_EXCLAM,
    PTSD_SCANCODE_KP_MEMSTORE = SDL_SCANCODE_KP_MEMSTORE,
    PTSD_SCANCODE_KP_MEMRECALL = SDL_SCANCODE_KP_MEMRECALL,
    PTSD_SCANCODE_KP_MEMCLEAR = SDL_SCANCODE_KP_MEMCLEAR,
    PTSD_SCANCODE_KP_MEMADD = SDL_SCANCODE_KP_MEMADD,
    PTSD_SCANCODE_KP_MEMSUBTRACT = SDL_SCANCODE_KP_MEMSUBTRACT,
    PTSD_SCANCODE_KP_MEMMULTIPLY = SDL_SCANCODE_KP_MEMMULTIPLY,
    PTSD_SCANCODE_KP_MEMDIVIDE = SDL_SCANCODE_KP_MEMDIVIDE,
    PTSD_SCANCODE_KP_PLUSMINUS = SDL_SCANCODE_KP_PLUSMINUS,
    PTSD_SCANCODE_KP_CLEAR = SDL_SCANCODE_KP_CLEAR,
    PTSD_SCANCODE_KP_CLEARENTRY = SDL_SCANCODE_KP_CLEARENTRY,
    PTSD_SCANCODE_KP_BINARY = SDL_SCANCODE_KP_BINARY,
    PTSD_SCANCODE_KP_OCTAL = SDL_SCANCODE_KP_OCTAL,
    PTSD_SCANCODE_KP_DECIMAL = SDL_SCANCODE_KP_DECIMAL,
    PTSD_SCANCODE_KP_HEXADECIMAL = SDL_SCANCODE_KP_HEXADECIMAL,

    PTSD_SCANCODE_LCTRL = SDL_SCANCODE_LCTRL,
    PTSD_SCANCODE_LSHIFT = SDL_SCANCODE_LSHIFT,
    PTSD_SCANCODE_LALT = SDL_SCANCODE_LALT, /**< alt, option */
    PTSD_SCANCODE_LGUI = SDL_SCANCODE_LGUI, /**< windows, command (apple), meta */
    PTSD_SCANCODE_RCTRL = SDL_SCANCODE_RCTRL,
    PTSD_SCANCODE_RSHIFT = SDL_SCANCODE_RSHIFT,
    PTSD_SCANCODE_RALT = SDL_SCANCODE_RALT, /**< alt gr, option */
    PTSD_SCANCODE_RGUI = SDL_SCANCODE_RGUI, /**< windows, command (apple), meta */

    PTSD_SCANCODE_MODE = SDL_SCANCODE_MODE, /**< I'm not sure if this is really not covered
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

    PTSD_SCANCODE_AUDIONEXT = SDL_SCANCODE_AUDIONEXT,
    PTSD_SCANCODE_AUDIOPREV = SDL_SCANCODE_AUDIOPREV,
    PTSD_SCANCODE_AUDIOSTOP = SDL_SCANCODE_AUDIOSTOP,
    PTSD_SCANCODE_AUDIOPLAY = SDL_SCANCODE_AUDIOPLAY,
    PTSD_SCANCODE_AUDIOMUTE = SDL_SCANCODE_AUDIOMUTE,
    PTSD_SCANCODE_MEDIASELECT = SDL_SCANCODE_MEDIASELECT,
    PTSD_SCANCODE_WWW = SDL_SCANCODE_WWW, /**< AL Internet Browser */
    PTSD_SCANCODE_MAIL = SDL_SCANCODE_MAIL,
    PTSD_SCANCODE_CALCULATOR = SDL_SCANCODE_CALCULATOR, /**< AL Calculator */
    PTSD_SCANCODE_COMPUTER = SDL_SCANCODE_COMPUTER,
    PTSD_SCANCODE_AC_SEARCH = SDL_SCANCODE_AC_SEARCH,    /**< AC Search */
    PTSD_SCANCODE_AC_HOME = SDL_SCANCODE_AC_HOME,      /**< AC Home */
    PTSD_SCANCODE_AC_BACK = SDL_SCANCODE_AC_BACK,      /**< AC Back */
    PTSD_SCANCODE_AC_FORWARD = SDL_SCANCODE_AC_FORWARD,   /**< AC Forward */
    PTSD_SCANCODE_AC_STOP = SDL_SCANCODE_AC_STOP,      /**< AC Stop */
    PTSD_SCANCODE_AC_REFRESH = SDL_SCANCODE_AC_REFRESH,   /**< AC Refresh */
    PTSD_SCANCODE_AC_BOOKMARKS = SDL_SCANCODE_AC_BOOKMARKS, /**< AC Bookmarks */

    /* @} */ /* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    PTSD_SCANCODE_BRIGHTNESSDOWN = SDL_SCANCODE_BRIGHTNESSDOWN,
    PTSD_SCANCODE_BRIGHTNESSUP = SDL_SCANCODE_BRIGHTNESSUP,
    PTSD_SCANCODE_DISPLAYSWITCH = SDL_SCANCODE_DISPLAYSWITCH, /**< display mirroring/dual display
                                           switch, video mode switch */
    PTSD_SCANCODE_KBDILLUMTOGGLE = SDL_SCANCODE_KBDILLUMTOGGLE,
    PTSD_SCANCODE_KBDILLUMDOWN = SDL_SCANCODE_KBDILLUMDOWN,
    PTSD_SCANCODE_KBDILLUMUP = SDL_SCANCODE_KBDILLUMUP,
    PTSD_SCANCODE_EJECT = SDL_SCANCODE_EJECT,
    PTSD_SCANCODE_SLEEP = SDL_SCANCODE_SLEEP, /**< SC System Sleep */

    PTSD_SCANCODE_APP1 = SDL_SCANCODE_APP1,
    PTSD_SCANCODE_APP2 = SDL_SCANCODE_APP2,

    /* @} */ /* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    PTSD_SCANCODE_AUDIOREWIND = SDL_SCANCODE_AUDIOREWIND,
    PTSD_SCANCODE_AUDIOFASTFORWARD = SDL_SCANCODE_AUDIOFASTFORWARD,

    /* @} */ /* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
    /* @{ */

    PTSD_SCANCODE_SOFTLEFT =
        SDL_SCANCODE_SOFTLEFT, /**< Usually situated below the display on phones and
                  used as a multi-function feature key for selecting
                  a software defined function shown on the bottom left
                  of the display. */
    PTSD_SCANCODE_SOFTRIGHT =
        SDL_SCANCODE_SOFTRIGHT, /**< Usually situated below the display on phones and
                 used as a multi-function feature key for selecting
                 a software defined function shown on the bottom right
                 of the display. */
    PTSD_SCANCODE_CALL = SDL_SCANCODE_CALL,    /**< Used for accepting phone calls. */
    PTSD_SCANCODE_ENDCALL = SDL_SCANCODE_ENDCALL, /**< Used for rejecting phone calls. */

    /* @} */ /* Mobile keys */

    /* Add any other keys here. */

    PTSD_NUM_SCANCODES = SDL_NUM_SCANCODES /**< not a key, just marks the number of scancodes
                                 for array bounds */
};

#endif // UTIL_EVENT_STUFF_PTSD_SCANCODE_HPP