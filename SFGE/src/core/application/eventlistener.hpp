//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include <SFML/Graphics.hpp>

#include <functional>

namespace sfge::input
{
    struct KeyboardEvent;
    struct MouseButtonEvent;
    struct MouseMoveEvent;
    struct WindowResizedEvent;
    struct FocusChangedEvent;

    struct EventHandler {
        virtual ~EventHandler() = default;

        virtual void onWindowClosing() = 0;
        virtual void onKeyboardEvent(const KeyboardEvent &event) = 0;
        virtual void onMouseButtonEvent(const MouseButtonEvent &event) = 0;
        virtual void onMouseMoveEvent(const MouseMoveEvent &event) = 0;
        virtual void onWindowResized(const WindowResizedEvent &event) = 0;
        virtual void onFocusChanged(const FocusChangedEvent &event) = 0;
    };
}// namespace sfge::input