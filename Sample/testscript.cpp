//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#include "testscript.hpp"
#include <sfge/components/renderable.hpp>
#include <sfge/gameobject/agameobject.hpp>
#include <sfge/services/iloggerservice.hpp>
#include <sfge/services/servicelocator.hpp>

#include <sfge/services/itextureloaderservice.h>
#include <sfge/services/servicelocator.hpp>

TestScript::TestScript()
{
    auto loggerService = sfge::services::ServiceLocator::Get<sfge::services::ILoggerService>();
    m_logger = loggerService->createLogger("TestScript");
    m_logger->addLoggingFile("logs/sample.txt");
}

TestScript::~TestScript()
{
    auto loggerService = sfge::services::ServiceLocator::Get<sfge::services::ILoggerService>();
    loggerService->removeLogger(m_logger);
}

void TestScript::onCollisionEnter(sfge::AGameObject *collided)
{
    auto &renderable = m_gameObject->component<sfge::ecs::Renderable>();
    renderable.setColor(sf::Color::Red);
}

void TestScript::onCollisionExit(sfge::AGameObject *collided)
{
    auto &renderable = m_gameObject->component<sfge::ecs::Renderable>();
    renderable.setColor(sf::Color::White);
}

void TestScript::onAwake()
{
    m_logger->info("onAwake");
}

void TestScript::onUpdate(float dt)
{
    // TODO: we should be able to call instanciate<AGameObject>()
}

void TestScript::onDestroy()
{
    m_logger->info("onDestroy");
}

void TestScript::onKeyboardEvent(const sfge::input::KeyboardEvent &event)
{
    assert(m_gameObject);
    auto &rigidbody = m_gameObject->component<sfge::ecs::RigidBody>();
    auto &transformable = m_gameObject->component<sfge::ecs::Transformable>();

    if (event.key == sf::Keyboard::Right) {
        rigidbody.body()->ApplyLinearImpulseToCenter({3, 0}, true);
    } else if (event.key == sf::Keyboard::Left) {
        rigidbody.body()->ApplyLinearImpulseToCenter({-3, 0}, true);
    } else if (event.key == sf::Keyboard::Up) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, -3}, true);
    } else if (event.key == sf::Keyboard::Down) {
        rigidbody.body()->ApplyLinearImpulseToCenter({0, 3}, true);
    } else if (event.key == sf::Keyboard::D) {
        rigidbody.body()->ApplyAngularImpulse(0.75, true);
    } else if (event.key == sf::Keyboard::Q) {
        rigidbody.body()->ApplyAngularImpulse(-0.75, true);
    } else if (event.key == sf::Keyboard::S) {
        sfge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        rigidbody.setConfig(config);
    } else if (event.key == sf::Keyboard::N) {
        static int i = 0;
        if (i > 2) return;
        ++i;

        auto textureService = sfge::services::ServiceLocator::Get<sfge::services::ITextureLoaderService>();
        sf::Texture *texture = textureService->getTexture("test");

        sf::Shape *shape = new sf::RectangleShape({1, 1});
        shape->setTexture(texture);

        auto obj = m_gameObject->instantiate<sfge::AGameObject>();

        auto &t = obj->component<sfge::ecs::Transformable>();
        t.setPosition(transformable.getPosition());
        t.setAngle(transformable.getAngleRadians());
        t.setScale(transformable.getScale());

        obj->addComponent<sfge::ecs::Renderable>(shape);
    } else {
        auto &transform = m_gameObject->component<sfge::ecs::Transformable>();
        if (transform.getPosition().y > 6) {
            transform.setPosition({0, -5});
        }
    }
}
