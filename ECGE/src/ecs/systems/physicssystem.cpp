#include "physicssystem.hpp"

#include "ecge/components.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

#include <iostream>

/**
 * RigidBody MUST have Transformable
 * Rigidbody retrieve Transformable after the pass and update them
 * RenderSystem MUST have Transformable
 * RenderSystem retrieve Transformable and apply
 */

namespace ecge
{
    PhysicsSystem::PhysicsSystem()
        : m_world({0.0f, 10.0f})
    {
    }

    void PhysicsSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ecs::RigidBody, ecs::Transformable>();

        for (const auto entity : view) {
            auto &r = view.get<ecs::RigidBody>(entity);
            auto &t = view.get<ecs::Transformable>(entity);
            if (!r.body) {
                r.def.position.x = t.position.x;
                r.def.position.y = t.position.y;
                r.body = createBody(r.def);

                r.shape.SetAsBox(t.scale.x / 2, t.scale.y / 2);

                r.fixtureDef.shape = &r.shape;
                r.fixtureDef.density = 1.0f;
                r.fixtureDef.friction = 0.3f;
                r.body->CreateFixture(&r.fixtureDef);
            }
        }

        m_world.Step(dt, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
        // m_world.SetContactListener()

        for (const auto entity : view) {
            const auto &r = view.get<ecs::RigidBody>(entity);
            auto &t = view.get<ecs::Transformable>(entity);

            assert(r.body != nullptr);
            // SFML refers to top-left, box2d center-center
            // SFML refers to pixel, bow2d to meters
            t.position.x = r.body->GetPosition().x;
            t.position.y = r.body->GetPosition().y;
//            if (t.position.y * 50 > 720)
//                r.body->SetTransform(r.def.position, r.def.angle);
            t.angle = r.body->GetAngle();
        }
    }

    b2Body *PhysicsSystem::createBody(const b2BodyDef &def)
    {
        return m_world.CreateBody(&def);
    }
}