#include "sfge/components/input.hpp"

namespace sfge::ecs
{
    void Input::setMouseMove(bool value)
    {
        m_mouseMove = value;
    }

    void Input::setMouseButton(bool value)
    {
        m_mouseButton = value;
    }

    void Input::setKeyboardButton(bool value)
    {
        m_keyboardButton = value;
    }

    bool Input::getMouseMove() const
    {
        return m_mouseMove;
    }

    bool Input::getMouseButton() const
    {
        return m_mouseButton;
    }

    bool Input::getKeyboardButton() const
    {
        return m_keyboardButton;
    }
}// namespace sfge::ecs