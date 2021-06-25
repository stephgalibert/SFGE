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

#include "eventprocessor.hpp"

#include "core/application/eventlistener.hpp"
#include "sfge/event.hpp"

namespace sfge::input
{
    EventProcessor::EventProcessor(EventHandler *listener)
        : m_events({
                  {sf::Event::KeyPressed, [this](const sf::Event &event) { onKeyboardEvent(event); }},
                  {sf::Event::KeyReleased, [this](const sf::Event &event) { onKeyboardEvent(event); }},
                  {sf::Event::Closed, [this](const sf::Event &event) { onWindowClosing(event); }},
                  {sf::Event::MouseButtonPressed, [this](const sf::Event &event) { onMouseButtonEvent(event); }},
                  {sf::Event::MouseButtonReleased, [this](const sf::Event &event) { onMouseButtonEvent(event); }},
                  {sf::Event::MouseMoved, [this](const sf::Event &event) { onMouseMoveEvent(event); }},
                  {sf::Event::Resized, [this](const sf::Event &event) { onWindowResized(event); }},
                  {sf::Event::GainedFocus, [this](const sf::Event &event) { onFocusChanged(true); }},
                  {sf::Event::LostFocus, [this](const sf::Event &event) { onFocusChanged(false); }},
          }),
          m_listener(listener)
    {
    }

    void EventProcessor::process(const sf::Event &event)
    {
        auto found = m_events.find(event.type);
        if (found != m_events.end())
            found->second(event);
    }

    void EventProcessor::onWindowClosing(const sf::Event &event)
    {
        (void) event;
        m_listener->onWindowClosing();
    }

    void EventProcessor::onKeyboardEvent(const sf::Event &event)
    {
        m_listener->onKeyboardEvent({event.key.code, event.type == sf::Event::KeyPressed});
    }

    void EventProcessor::onMouseButtonEvent(const sf::Event &event)
    {
        m_listener->onMouseButtonEvent({event.mouseButton.button,
                                        {event.mouseButton.x, event.mouseButton.y},
                                        event.type == sf::Event::MouseButtonPressed});
    }

    void EventProcessor::onMouseMoveEvent(const sf::Event &event)
    {
        m_listener->onMouseMoveEvent({event.mouseMove.x, event.mouseMove.y});
    }

    void EventProcessor::onWindowResized(const sf::Event &event)
    {
        m_listener->onWindowResized({event.size.width, event.size.height});
    }

    void EventProcessor::onFocusChanged(bool value)
    {
        m_listener->onFocusChanged({value});
    }
}// namespace sfge::input