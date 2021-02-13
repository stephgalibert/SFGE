#include "sfge/components/rigidbody.hpp"

#include <iostream>

namespace sfge::ecs
{
    RigidBody::Config::Config()
    {
        bodyDef.type = b2_dynamicBody;
    }

    RigidBody::RigidBody(AGameObject *gameObject, Config config)
    {
        config.bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(gameObject);
    }

    void RigidBody::setBody(b2Body *body)
    {
        m_body = body;
    }

    void RigidBody::setConfig(const Config &config)
    {
        m_registry->patch<RigidBody>(m_entity, [&config](RigidBody &rigidBody) {
            rigidBody.m_config = config;
        });
    }

    b2Body *RigidBody::body() const
    {
        return m_body;
    }

    RigidBody::Config RigidBody::config() const
    {
        return m_config;
    }
}// namespace sfge::ecs