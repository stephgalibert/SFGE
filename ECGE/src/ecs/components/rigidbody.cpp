#include "ecge/components/rigidbody.hpp"

#include <iostream>

namespace ecge::ecs
{
    RigidBody::Config::Config()
    {
        bodyDef.type = b2_dynamicBody;
    }

    RigidBody::RigidBody(AGameObject *gameObject, Config config)
        : m_config(std::move(config))
    {
        m_config.bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(gameObject);
    }

    RigidBody::RigidBody(const RigidBody &rhs)
        : Component(rhs)
    {
        std::clog << "rigidbody copy ctor" << std::endl;
        *this = rhs;
    }

    RigidBody::RigidBody(RigidBody &&rhs) noexcept
        : Component(std::move(rhs))
    {
        std::clog << "rigidbody move ctor" << std::endl;
        *this = std::move(rhs);
    }

    RigidBody &RigidBody::operator=(const RigidBody &rhs)
    {
        std::clog << "rigidbody assign" << std::endl;
        if (this != &rhs) {
            Component::operator=(rhs);
            m_body = rhs.m_body;
            m_config = rhs.m_config;
        }
        return *this;
    }

    RigidBody &RigidBody::operator=(RigidBody &&rhs) noexcept
    {
        std::clog << "rigidbody move assign" << std::endl;
        m_body = rhs.m_body;
        m_config = rhs.m_config;
        return *this;
    }

    void RigidBody::setBody(b2Body *body)
    {
        m_body = body;
    }

    void RigidBody::setConfig(const Config &config)
    {
        m_config = config;
    }

    b2Body *RigidBody::body() const
    {
        return m_body;
    }

    RigidBody::Config RigidBody::config() const
    {
        return m_config;
    }
}// namespace ecge::ecs