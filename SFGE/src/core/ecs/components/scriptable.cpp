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

#include "sfge/components/scriptable.hpp"

namespace sfge::ecs
{
    Scriptable::~Scriptable()
    {
        destroy();
    }

    void Scriptable::onCollisionEnter(AGameObject *collided)
    {
        for (const auto &script : m_scripts) {
            script->onCollisionEnter(collided);
        }
    }

    void Scriptable::onCollisionExit(AGameObject *collided)
    {
        for (const auto &script : m_scripts) {
            script->onCollisionExit(collided);
        }
    }

    void Scriptable::update(float dt)
    {
        for (const auto &script : m_scripts) {
            script->onUpdate(dt);
        }
    }

    void Scriptable::destroy()
    {
        for (const auto &script : m_scripts) {
            script->onDestroy();
        }
    }

    void Scriptable::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        for (auto &script : m_scripts) {
            script->onKeyboardEvent(event);
        }
    }

    void Scriptable::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        for (auto &script : m_scripts) {
            script->onMouseButtonEvent(event);
        }
    }
}// namespace sfge::ecs
