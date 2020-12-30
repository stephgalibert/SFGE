#include "physicssystem.hpp"

#include <box2d/b2_body.h>

/**
 * RigidBody MUST have Transformable
 * Rigidbody retrieve Transformable after the pass and update them
 * RenderSystem MUST have Transformable
 * RenderSystem retrieve Transformable and apply
 */

namespace sfge
{
    PhysicsSystem::PhysicsSystem()
        : m_world({0.0f, -10.0f})
    {
    }

    /*
     * Retrieve RigidBody, Transformable components
     */
    void PhysicsSystem::update(entt::registry &registry, float dt)
    {
        m_world.Step(dt, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
        // m_world.SetContactListener()

        b2BodyDef def;
        // def.position.Set(x, y);
        // def.linearDamping = 0.00f;
        // def.angularDamping = 0.01f;
        // def.fixedRotation = true;
        // def.userData.pointer = reinterpret_cast<uintptr_t>(agameobject);

        // b2Body *dynBody = m_world.CreateBody(&def);
    }
}