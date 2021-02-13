#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

namespace ecge::input
{
    struct KeyboardEvent {
        sf::Keyboard::Key key;
        bool pressed;
    };

    struct MouseButtonEvent {
        sf::Mouse::Button button;
        sf::Vector2i pos;
        bool pressed;
    };

    struct MouseMoveEvent {
    };

    struct WindowResizedEvent {
        sf::Vector2i size;
    };

    struct FocusChangedEvent {
        bool focused;
    };
}// namespace ecge::input