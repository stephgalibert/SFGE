#pragma once

#include "component.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

namespace ecge
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
            explicit RigidBody(AGameObject *gameObject, Config config = Config());
            RigidBody(const RigidBody &rhs);
            RigidBody(RigidBody &&rhs) noexcept;
            ~RigidBody() = default;

            RigidBody &operator=(const RigidBody &rhs);
            RigidBody &operator=(RigidBody &&rhs) noexcept;

            void setBody(b2Body *body);
            void setConfig(const Config &config);

            [[nodiscard]] b2Body *body() const;
            [[nodiscard]] Config config() const;

        private:
            b2Body *m_body = nullptr;
            Config m_config;
        };
    }// namespace ecs
}// namespace ecge