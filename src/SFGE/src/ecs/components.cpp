#include "sfge/components.hpp"

namespace sfge::ecs
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