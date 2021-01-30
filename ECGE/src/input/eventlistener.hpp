#pragma once

#include <SFML/Graphics.hpp>

#include <functional>

namespace ecge
{
    struct EventListener {
        virtual ~EventListener() = default;
        virtual void onWindowClosing() = 0;
        virtual void onKeyboardEvent(sf::Keyboard::Key key, bool pressed) = 0;
        virtual void onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed) = 0;

        //		virtual void onWindowResized(int newWidth, int newHeight) = 0;
        //		virtual void onFocusChanged(bool isFocused) = 0;
    };
}// namespace ecge