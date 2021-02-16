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

#include "core/collisions/contactlistener.hpp"
#include "isystem.hpp"

#include <box2d/b2_world.h>

namespace sfge::ecs
{
    class PhysicsSystem : public ISystem
    {
    private:
        static const int32_t VELOCITY_ITERATIONS = 8;
        static const int32_t POSITION_ITERATIONS = 3;

    public:
        PhysicsSystem();

        void update(entt::registry &registry, float dt) override;

        b2Body *createBody(const b2BodyDef &def);
        void destroyBody(b2Body *body);

    private:
        b2World m_world;
        ContactListener m_contactListener;
    };
}// namespace sfge::ecs
