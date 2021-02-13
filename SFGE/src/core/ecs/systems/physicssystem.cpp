#include "physicssystem.hpp"

#include "sfge/components/rigidbody.hpp"
#include "sfge/components/transformable.hpp"

#include <box2d/b2_body.h>

namespace sfge::ecs
{
    PhysicsSystem::PhysicsSystem()
        : m_world({0.0f, 10.0f})
    {
        // m_world.SetContactListener()
    }

    void PhysicsSystem::update(entt::registry &registry, float dt)
    {
        m_world.Step(dt, VELOCITY_ITERATIONS, POSITION_ITERATIONS);

        auto view = registry.view<RigidBody, Transformable>();
        for (const auto entity : view) {
            const auto [rigidBody, transform] = view.get<RigidBody, Transformable>(entity);

            assert(rigidBody.body() != nullptr);
            const b2Vec2 &b2Pos = rigidBody.body()->GetPosition();
            transform.setTransform({b2Pos.x, b2Pos.y}, rigidBody.body()->GetAngle());
        }
    }

    b2Body *PhysicsSystem::createBody(const b2BodyDef &def)
    {
        return m_world.CreateBody(&def);
    }

    void PhysicsSystem::destroyBody(b2Body *body)
    {
        m_world.DestroyBody(body);
    }
}// namespace sfge::ecs