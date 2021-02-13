#include "testscript.h"
#include <ecge/agameobject.hpp>

TestScript::TestScript()
{
    m_logger = ecge::Logger::CreateLogger("TestScript");
    m_logger->addLoggingFile("logs/sample.txt");
}

TestScript::~TestScript()
{
    ecge::Logger::RemoveLogger(m_logger);
}

void TestScript::onAwake()
{
    m_logger->info("onAwake");
}

void TestScript::onUpdate(float dt)
{
}

void TestScript::onDestroy()
{
    m_logger->info("onDestroy");
}

void TestScript::onKeyboardEvent(const ecge::input::KeyboardEvent &event)
{
    assert(m_gameObject);
    auto &rigidbody = m_gameObject->component<ecge::ecs::RigidBody>();

    if (event.key == sf::Keyboard::Right) {
        rigidbody.body()->ApplyLinearImpulseToCenter({1, 0}, true);
    } else if (event.key == sf::Keyboard::Left) {
        rigidbody.body()->ApplyLinearImpulseToCenter({-1, 0}, true);
    } else if (event.key == sf::Keyboard::Up) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, -5}, true);
    } else if (event.key == sf::Keyboard::Down) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, 5}, true);
    }
}
