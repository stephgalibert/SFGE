#pragma once

#include "component.hpp"

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
            explicit RigidBody(AGameObject *gameObject, Config config = Config());

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