#pragma once

#include "isystem.hpp"

#include <box2d/b2_world.h>

namespace sfge
{
    class PhysicsSystem : public ISystem
    {
    private:
        static const int32_t VELOCITY_ITERATIONS = 6;
        static const int32_t POSITION_ITERATIONS = 2;

    public:
        PhysicsSystem();
        void update(entt::registry &registry, float dt) override;

    private:
        b2World m_world;
    };
}
