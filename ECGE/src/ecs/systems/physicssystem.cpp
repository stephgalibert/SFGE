#include "physicssystem.hpp"

#include "ecge/components.hpp"

#include <box2d/b2_body.h>

#include <iostream>

namespace ecge
{
    PhysicsSystem::PhysicsSystem()
        : m_world({0.0f, 10.0f})
    {
    }

    void PhysicsSystem::update(entt::registry &registry, float dt)
    {
        m_world.Step(dt, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
        // m_world.SetContactListener()

        auto view = registry.view<ecs::RigidBody, ecs::Transformable>();
        for (const auto entity : view) {
            const auto &r = view.get<ecs::RigidBody>(entity);
            auto &t = view.get<ecs::Transformable>(entity);

            assert(r.body != nullptr);
            t.position.x = r.body->GetPosition().x;
            t.position.y = r.body->GetPosition().y;
            t.angle = r.body->GetAngle();
        }
    }

    b2Body *PhysicsSystem::createBody(const b2BodyDef &def)
    {
        return m_world.CreateBody(&def);
    }
}