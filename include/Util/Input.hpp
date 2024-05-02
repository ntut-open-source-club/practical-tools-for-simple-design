#ifndef UTIL_EVENT_HPP
#define UTIL_EVENT_HPP

#include "pch.hpp" // IWYU pragma: export

#include <SDL_events.h> // for SDL_Event
#include <SDL_stdinc.h> // for Uint8

#include "Util/Keycode.hpp" // for Keycode

#include "Util/Position.hpp" // Util::PTSDPosition

namespace Util {

/**
* @class Input
* @brief The Input class provides access to keyboard and mouse input.
* @note This class is a singleton and constructable. Use is as follows: \n
            `Util::Input::IsKeyPressed(Keycode::A)`,
            `Util::Input::IsLButtonDown()`, etc.
*/
class Input {
public:
    Input() = delete;
    Input(const Input &) = delete;
    Input(Input &&) = delete;
    ~Input() = delete;
    Input &operator=(const Input &) = delete;

    /**
     * @brief Retrieves the scroll distance of an element.\n
     *
     * @details The scroll distance is the distance that the mouse wheel has
     * been scrolled. The distance is expressed in multiples or fractions of
     * lines; for example, if the mouse wheel is rotated three lines downward,
     * the scroll distance is {-1.0F, 0.0F}. If the mouse wheel is rotated three
     * lines upward, the scroll distance is {1.0F, 0.0F}. If the mouse wheel is
     * rotated three lines right, the scroll distance is {0.0F, 1.0F}. If the
     * mouse wheel is rotated three lines left, the scroll distance is {0.0F,
     * -1.0F}.
     *
     * @return The scroll distance as vec2(x,y).
     */
    static glm::vec2 GetScrollDistance();

    /**
     * @brief Retrieves the current position of the cursor.
     * @note The cursor position is relative to the upper-left corner of the
     * client area of the window.
     *
     * @return The cursor position as vec2(x, y).
     *
     * @see Util::Input::SetCursorPosition()
     */
    static Util::PTSDPosition GetCursorPosition();

    /**
     * @brief Check if a specific key is currently pressed.
     *
     * This function checks whether the given key is currently pressed.
     *
     * @param key The keycode of the key to check.
     *
     * @return true if `key` is currently pressed, false otherwise.
     *
     * @see Util::Keycode
     */
    static bool IsKeyPressed(const Keycode &key);

    /**
     * @brief Check if a specific key is being pressed.
     *
     * This function checks whether the given key is currently being pressed.
     *
     * @param key The keycode of the key to check.
     *
     * @return true if `key` is currently pressed, false otherwise.
     *
     * @see Util::Keycode
     */
    static bool IsKeyDown(const Keycode &key);

    /**
     * @brief Check if a specific key is being un-pressed.
     *
     * This function checks whether the given key is currently being un-pressed.
     *
     * @param key The keycode of the key to check.
     *
     * @return true if `key` is currently pressed, false otherwise.
     *
     * @see Util::Keycode
     */
    static bool IsKeyUp(const Keycode &key);

    /**
     * @brief Checks if the mouse wheel is currently being scrolled.
     * @return  A bool value representing the current state of the mouse
     * wheel.
     */
    static bool IfScroll();

    /**
     * @brief Checks if the mouse is currently moving.
     * @return  true if the mouse is currently moving, false otherwise.
     */
    static bool IsMouseMoving();

    /**
     * @brief Checks if the window is closed
     * @return  true if the window is closed, false otherwise.
     */
    static bool IfExit();

    /**
     * @brief Sets the position of the cursor.
     * @param pos The position to set the cursor to.
     * @note The cursor position is relative to the upper-left corner of the
     * client area of the window.
     * @note It also generates a mouse motion event, which leads
     * Util::Input::IsMouseMoving() to return true in this update-cycle.
     * @see Util::Input::GetCursorPosition()
     */
    static void SetCursorPosition(const Util::PTSDPosition &pos);

    /**
     * @brief Updates the state of the input.
     * @warning DO NOT CALL THIS METHOD. It is called by context::Update()
     * already.
     */
    static void Update();

private:
    static void UpdateKeyState(const SDL_Event *event);

    static SDL_Event s_Event;

    static Util::PTSDPosition s_CursorPosition;
    static glm::vec2 s_ScrollDistance;

    static std::unordered_map<Keycode, std::pair<bool, bool>> s_KeyState;

    static bool s_Scroll;
    static bool s_MouseMoving;
    static bool s_Exit;

    static ImGuiIO s_Io;
};

} // namespace Util

#endif // UTIL_EVENT_HPP
