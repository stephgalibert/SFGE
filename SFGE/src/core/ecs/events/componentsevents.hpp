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

#include "config/physicsconfig.hpp"
#include "sfge/components/rigidbody.hpp"
#include "sfge/components/transformable.hpp"

#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <functional>

namespace sfge::ecs
{
    class TransformableEvents
    {
    public:
        TransformableEvents();
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        float m_pixelsPerMeter;
    };

    class RenderableEvents
    {
    public:
        RenderableEvents();
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        float m_pixelsPerMeter;
    };

    struct RigidbodyEventsCallbacks;

    class RigidbodyEvents
    {
    public:
        void setCallbacks(RigidbodyEventsCallbacks *callbacks);

        void created(entt::registry &registry, entt::entity entity) const;
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        void createConfig(entt::registry &registry, entt::entity entity) const;
        b2Body *load(RigidBody::Config &config, const Transformable &transform) const;

    private:
        RigidbodyEventsCallbacks *m_callbacks = nullptr;
    };
}// namespace sfge::ecs
