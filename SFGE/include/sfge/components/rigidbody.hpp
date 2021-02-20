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

#include "sfge/components/base/component.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

namespace sfge
{
    class AGameObject;

    namespace ecs
    {
        class RigidBody : public Component
        {
        public:
            struct Config {
                Config();
                b2BodyDef bodyDef;
                b2PolygonShape shape;
                b2FixtureDef fixtureDef;
            };

        public:
            RigidBody() = default;

            void setBody(b2Body *body);
            void setConfig(const Config &config);

            [[nodiscard]] b2Body *body() const;
            [[nodiscard]] Config config() const;

        private:
            b2Body *m_body = nullptr;
            Config m_config;

            friend class RigidbodyEvents;
        };
    }// namespace ecs
}// namespace sfge