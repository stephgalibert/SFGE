#include "ecge/components.hpp"

namespace ecge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : shape(shape)
    {
    }

    RigidBody::Config::Config()
    {
        bodyDef.type = b2_dynamicBody;
    }

    RigidBody::RigidBody(AGameObject *gameObject, Config config)
        : config(std::move(config))
    {
        this->config.bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(gameObject);
    }
}