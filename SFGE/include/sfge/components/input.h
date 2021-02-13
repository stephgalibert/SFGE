#pragma once

#include "component.hpp"

namespace sfge::ecs
{
    class Input : public Component
    {
    public:
        void setMouseMove(bool value);
        void setMouseButton(bool value);
        void setKeyboardButton(bool value);

        [[nodiscard]] bool getMouseMove() const;
        [[nodiscard]] bool getMouseButton() const;
        [[nodiscard]] bool getKeyboardButton() const;

    private:
        bool m_mouseMove;
        bool m_mouseButton;
        bool m_keyboardButton;
    };

}// namespace sfge::ecs
