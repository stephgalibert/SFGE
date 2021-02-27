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

#include "sfge/components/base/component.hpp"
#include "sfge/gameobject/agameobject.hpp"

namespace sfge::ecs
{
    void Component::attachGameObject(AGameObject *gameObject)
    {
        m_gameObject = gameObject;
    }

    void Component::setRegistry(entt::registry *registry)
    {
        m_registry = registry;
    }

    void Component::setEntity(entt::entity entity)
    {
        m_entity = entity;
    }

    AGameObject *Component::getGameObject() const
    {
        return m_gameObject;
    }

    entt::registry *Component::getRegistry() const
    {
        return m_registry;
    }

    entt::entity Component::getEntity() const
    {
        return m_entity;
    }
}// namespace sfge::ecs