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

#include "sfge/components/input.hpp"
#include "sfge/components/scriptable.hpp"

namespace sfge::ecs
{
    void InputSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<Input, Scriptable>();
        for (const auto entity : view) {
            const auto [input, scriptable] = view.get<Input, Scriptable>(entity);

            if (input.getMouseMove()) {
            }
            if (input.getMouseButton()) {
            }

            while (input.getKeyboardButton() && !m_keyboardEvents.empty()) {
                const input::KeyboardEvent &event = m_keyboardEvents.front();
                scriptable.onKeyboardEvent(event);
                m_keyboardEvents.pop();
            }
        }
    }

    void InputSystem::push(const input::KeyboardEvent &event)
    {
        m_keyboardEvents.push(event);
    }

    void InputSystem::push(const input::MouseButtonEvent &event)
    {
    }
}// namespace sfge::ecs