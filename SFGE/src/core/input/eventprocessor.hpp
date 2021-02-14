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
#include <unordered_map>

namespace sfge::input
{
    struct EventListener;

    class EventProcessor
    {
    public:
        explicit EventProcessor(EventListener *listener);
        ~EventProcessor() = default;

        void process(const sf::Event &event);

    private:
        void onWindowClosing(const sf::Event &event);
        void onKeyboardEvent(const sf::Event &event);
        void onMouseButtonEvent(const sf::Event &event);
        void onMouseMoveEvent(const sf::Event &event);
        void onWindowResized(const sf::Event &event);
        void onFocusChanged(const sf::Event &event);

    private:
        std::unordered_map<sf::Event::EventType, std::function<void(const sf::Event &)>> m_events;
        EventListener *m_listener;
    };
}// namespace sfge::input