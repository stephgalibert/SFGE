#include "ecge/components.hpp"

namespace ecge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : shape(shape)
    {
    }

    RigidBody::RigidBody(AGameObject *gameObject)
//        : gameObject(gameObject)
    {
        def.type = b2_dynamicBody;
//         def.position.Set(x, y);
        def.linearDamping = 0.00f;
        def.angularDamping = 0.01f;
        // def.fixedRotation = true;
        def.userData.pointer = reinterpret_cast<uintptr_t>(gameObject);
//         b2Body *dynBody = m_world.CreateBody(&def);
    }
}