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

#include <entt/entt.hpp>

namespace sfge::ecs
{
    struct Component {
    public:
        Component() = default;
        Component(const Component &rhs);
        Component(Component &&rhs) noexcept;
        ~Component() = default;

        Component &operator=(const Component &o);
        Component &operator=(Component &&o) noexcept;

        void setRegistry(entt::registry *registry);
        void setEntity(entt::entity entity);

    protected:
        entt::registry *m_registry = nullptr;
        entt::entity m_entity = entt::null;
    };
}// namespace sfge::ecs