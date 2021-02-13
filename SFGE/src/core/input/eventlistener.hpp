#pragma once

#include <SFML/Graphics.hpp>

#include <functional>

namespace sfge::input
{
    struct KeyboardEvent;
    struct MouseButtonEvent;

    struct EventListener {
        virtual ~EventListener() = default;
        virtual void onWindowClosing() = 0;
        virtual void onKeyboardEvent(const KeyboardEvent &event) = 0;
        virtual void onMouseButtonEvent(const MouseButtonEvent &event) = 0;

        // virtual void onWindowResized(int newWidth, int newHeight) = 0;
        // virtual void onFocusChanged(bool isFocused) = 0;
    };
}// namespace sfge::input