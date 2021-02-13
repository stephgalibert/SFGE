#include "testscript.h"
#include <sfge/agameobject.hpp>

TestScript::TestScript()
{
    m_logger = sfge::Logger::CreateLogger("TestScript");
    m_logger->addLoggingFile("logs/sample.txt");
}

TestScript::~TestScript()
{
    sfge::Logger::RemoveLogger(m_logger);
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

void TestScript::onKeyboardEvent(const sfge::input::KeyboardEvent &event)
{
    assert(m_gameObject);
    auto &rigidbody = m_gameObject->component<sfge::ecs::RigidBody>();

    if (event.key == sf::Keyboard::Right) {
        rigidbody.body()->ApplyLinearImpulseToCenter({1, 0}, true);
    } else if (event.key == sf::Keyboard::Left) {
        rigidbody.body()->ApplyLinearImpulseToCenter({-1, 0}, true);
    } else if (event.key == sf::Keyboard::Up) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, -5}, true);
    } else if (event.key == sf::Keyboard::Down) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, 5}, true);
    } else if (event.key == sf::Keyboard::D) {
        rigidbody.body()->ApplyAngularImpulse(0.5, true);
    } else if (event.key == sf::Keyboard::Q) {
        rigidbody.body()->ApplyAngularImpulse(-0.5, true);
    } else {
        auto &transform = m_gameObject->component<sfge::ecs::Transformable>();
        if (transform.position().y > 6) {
            transform.setPosition({0, -5});
        }
    }
}
