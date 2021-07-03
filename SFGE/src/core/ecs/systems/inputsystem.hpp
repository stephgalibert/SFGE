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

#include "isystem.hpp"

#include "sfge/components/input.hpp"
#include "sfge/components/scriptable.hpp"
#include "sfge/event.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <functional>
#include <queue>
#include <unordered_map>

namespace sfge::ecs
{
    class InputSystem : public ISystem
    {
    public:
        InputSystem();

        void update(entt::registry &registry, float dt) override;

        void push(const sf::Event &event);

    private:
        static void onWindowClosing(const sf::Event &event, const Input &input, Scriptable &scriptable);
        static void onKeyboardEvent(const sf::Event &event, const Input &input, Scriptable &scriptable);
        static void onMouseButtonEvent(const sf::Event &event, const Input &input, Scriptable &scriptable);
        static void onMouseMoveEvent(const sf::Event &event, const Input &input, Scriptable &scriptable);
        static void onWindowResized(const sf::Event &event, const Input &input, Scriptable &scriptable);
        static void onFocusChanged(bool value);

    private:
        const std::unordered_map<sf::Event::EventType, std::function<void(const sf::Event &, const Input &, Scriptable &)>> m_eventCallbacks;
        std::queue<sf::Event> m_events;
    };
}// namespace sfge::ecs
