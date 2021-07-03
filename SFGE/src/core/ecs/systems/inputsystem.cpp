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

#include "inputsystem.hpp"

namespace sfge::ecs
{
    InputSystem::InputSystem()
        : m_eventCallbacks({
                  {sf::Event::KeyPressed, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onKeyboardEvent(event, input, scriptable); }},
                  {sf::Event::KeyReleased, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onKeyboardEvent(event, input, scriptable); }},
                  {sf::Event::Closed, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onWindowClosing(event, input, scriptable); }},
                  {sf::Event::MouseButtonPressed, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onMouseButtonEvent(event, input, scriptable); }},
                  {sf::Event::MouseButtonReleased, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onMouseButtonEvent(event, input, scriptable); }},
                  {sf::Event::MouseMoved, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onMouseMoveEvent(event, input, scriptable); }},
                  {sf::Event::Resized, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onWindowResized(event, input, scriptable); }},
                  {sf::Event::GainedFocus, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onFocusChanged(true); }},
                  {sf::Event::LostFocus, [](const sf::Event &event, const Input &input, Scriptable &scriptable) { onFocusChanged(false); }},
          })
    {
    }

    void InputSystem::update(entt::registry &registry, float dt)
    {
        while (!m_events.empty()) {
            const sf::Event event = m_events.front();
            m_events.pop();

            auto view = registry.view<Input, Scriptable>();
            for (const auto entity : view) {
                const auto [input, scriptable] = view.get<Input, Scriptable>(entity);

                const auto found = m_eventCallbacks.find(event.type);
                if (found != m_eventCallbacks.end())
                    found->second(event, input, scriptable);
            }
        }
    }

    void InputSystem::push(const sf::Event &event)
    {
        m_events.push(event);
    }

    void InputSystem::onWindowClosing(const sf::Event &event, const Input &input, Scriptable &scriptable)
    {
        //        (void) event;
        //        m_listener->onWindowClosing();
    }

    void InputSystem::onKeyboardEvent(const sf::Event &event, const Input &input, Scriptable &scriptable)
    {
        if (input.getKeyboardButton())
            scriptable.onKeyboardEvent({event.key.code, event.type == sf::Event::KeyPressed});
        // m_listener->onKeyboardEvent({event.key.code, event.type == sf::Event::KeyPressed});
    }

    void InputSystem::onMouseButtonEvent(const sf::Event &event, const Input &input, Scriptable &scriptable)
    {
        if (input.getMouseButton())
            scriptable.onMouseButtonEvent({event.mouseButton.button,
                                           {event.mouseButton.x, event.mouseButton.y},
                                           event.type == sf::Event::MouseButtonPressed});
    }

    void InputSystem::onMouseMoveEvent(const sf::Event &event, const Input &input, Scriptable &scriptable)
    {
        //        if (input.getMouseMove())
        //            scriptable.onMouseMoveEvent({event.mouseMove.x, event.mouseMove.y});
    }

    void InputSystem::onWindowResized(const sf::Event &event, const Input &input, Scriptable &scriptable)
    {
        //        m_listener->onWindowResized({event.size.width, event.size.height});
    }

    void InputSystem::onFocusChanged(bool value)
    {
        //        m_listener->onFocusChanged({value});
    }
}// namespace sfge::ecs

//            while (input.getKeyboardButton() && !m_keyboardEvents.empty()) {
//                const input::KeyboardEvent &event = m_keyboardEvents.front();
//                scriptable.onKeyboardEvent(event);
//                m_keyboardEvents.pop();
//            }
