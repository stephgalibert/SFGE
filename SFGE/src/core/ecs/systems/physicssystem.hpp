#pragma once

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
    };
}// namespace sfge::ecs
