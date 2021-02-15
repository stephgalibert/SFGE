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

#include "sfge/components/component.hpp"

namespace sfge::ecs
{
    Component::Component(const Component &rhs)
    {
        *this = rhs;
    }

    Component::Component(Component &&rhs) noexcept
    {
        *this = std::move(rhs);
    }

    Component &Component::operator=(const Component &rhs)
    {
        if (this != &rhs) {
            m_registry = rhs.m_registry;
            m_entity = rhs.m_entity;
        }
        return *this;
    }

    Component &Component::operator=(Component &&rhs) noexcept
    {
        m_registry = rhs.m_registry;
        m_entity = rhs.m_entity;
        rhs.m_registry = nullptr;
        rhs.m_entity = entt::null;
        return *this;
    }

    void Component::attachGameObject(AGameObject *gameObject)
    {
        m_gameObject = gameObject;
    }

    AGameObject *Component::getGameObject() const
    {
        return m_gameObject;
    }

    void Component::setRegistry(entt::registry *registry)
    {
        m_registry = registry;
    }

    void Component::setEntity(entt::entity entity)
    {
        m_entity = entity;
    }
}// namespace sfge::ecs