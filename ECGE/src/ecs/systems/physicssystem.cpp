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
        : m_world({0.0f, 981.0f})
    {
    }

    // quand on crée un component RigidBody
    // 1. on l'assigne à un gameobject (done by addComponent<>())
    // 2. faire une procédure d'initialisation
    //      => créer le body
    // agameobject / ascene => physicssystem

    void PhysicsSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ecs::RigidBody, ecs::Transformable>();

        for (const auto entity : view) {
            auto &r = view.get<ecs::RigidBody>(entity);
            auto &t = view.get<ecs::Transformable>(entity);
            if (!r.body) {
                r.def.position.Set(t.position.x, t.position.y);
                // r.def.gravityScale = 0;
                r.body = createBody(r.def);

                r.shape.SetAsBox(t.scale.x / 2, t.scale.y / 2);

                r.fixtureDef.shape = &r.shape;
                r.fixtureDef.density = 1.0f;
                r.fixtureDef.friction = 0.3f;
                r.body->CreateFixture(&r.fixtureDef);

                r.body->ApplyAngularImpulse(100, true);
            }
        }

        m_world.Step(dt, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
        // m_world.SetContactListener()

        for (const auto entity : view) {
            const auto &r = view.get<ecs::RigidBody>(entity);
            auto &t = view.get<ecs::Transformable>(entity);

            assert(r.body != nullptr);
            t.position.x = r.body->GetPosition().x;
            t.position.y = r.body->GetPosition().y;
            t.angle = r.body->GetAngle() * 180 / b2_pi;
            // std::clog << t.angle << std::endl;
            // rotations... in RenderSystem too
        }
    }

    b2Body *PhysicsSystem::createBody(const b2BodyDef &def)
    {
        return m_world.CreateBody(&def);
    }
}