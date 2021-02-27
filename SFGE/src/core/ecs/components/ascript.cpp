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

#include "sfge/components/base/ascript.hpp"
#include "sfge/common.hpp"

namespace sfge::ecs
{
    void AScript::attachGameObject(AGameObject *gameObject)
    {
        m_gameObject = gameObject;
    }

    AGameObject *AScript::getGameObject() const
    {
        return m_gameObject;
    }

    void AScript::onCollisionEnter(AGameObject *collided)
    {
        SFGE_UNUSED(collided);
    }

    void AScript::onCollisionExit(AGameObject *collided)
    {
        SFGE_UNUSED(collided);
    }

    void AScript::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        SFGE_UNUSED(event);
    }

    void AScript::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        SFGE_UNUSED(event);
    }
}// namespace sfge::ecs