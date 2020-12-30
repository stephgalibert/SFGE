#include "ecge/components.hpp"

namespace ecge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : shape(shape)
    {
    }

    RigidBody::RigidBody(AGameObject *gameObject)
        : gameObject(gameObject)
    {
    }
}