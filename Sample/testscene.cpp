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

#include "testscene.hpp"

#include "testscript.hpp"

#include <sfge/components/camera.hpp>
#include <sfge/components/input.hpp>
#include <sfge/components/renderable.hpp>
#include <sfge/components/rigidbody.hpp>
#include <sfge/components/transformable.hpp>
#include <sfge/gameobject/agameobject.hpp>
#include <sfge/gameobject/camera.hpp>

#include <sfge/services/iloggerservice.hpp>
#include <sfge/services/imainrendererservice.hpp>
#include <sfge/services/isoundloaderservice.hpp>
#include <sfge/services/itextureloaderservice.hpp>
#include <sfge/services/servicelocator.hpp>

#include <iostream>

TestScene::TestScene()
{
    auto loggerService = sfge::services::ServiceLocator::Get<sfge::services::ILoggerService>();

    m_logger = loggerService->getOrCreateLogger("TestScene");
    m_logger->addLoggingFile("logs/sample.txt");
}

void TestScene::init()
{
    AScene::init();

    // TODO: test purpose, remove it
    auto textureService = sfge::services::ServiceLocator::Get<sfge::services::ITextureLoaderService>();
    textureService->loadFromFile("test", "texture.jpg");
    sf::Texture *texture = textureService->getTexture("test");

    // auto soundService = sfge::services::ServiceLocator::Get<sfge::services::ISoundLoaderService>();
    //    soundService->loadFromFile("splash", "sound.wav");
    //    m_splashSound = soundService->getSound("splash");
    //    m_splashSound->play();

    m_logger->info("Init");
    {
        auto mainRenderer = sfge::services::ServiceLocator::Get<sfge::services::IMainRendererService>();
        auto obj = instantiate<sfge::gameobjects::Camera>();

        obj->setRenderTarget(mainRenderer->renderer().get());
        obj->setSize(1280, 720);
        obj->setCenter(0, 0);
        obj->setActive(true);
    }
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});
        shape->setFillColor(sf::Color::Green);
        auto obj = instantiate<sfge::AGameObject>();

        auto &renderable = obj->addComponent<sfge::ecs::Renderable>();
        renderable.setShape(shape);

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<sfge::ecs::RigidBody>();
    }
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, 0});
        transformable.setAngle_DEGREES(0.00);
        transformable.setScale({1.50f, 1.50f});

        obj->addComponent<sfge::ecs::RigidBody>();
        obj->addComponent<TestScript>();

        auto &input = obj->addComponent<sfge::ecs::Input>();
        input.setKeyboardButton(true);
        input.setMouseButton(true);
        input.setMouseMove(true);

        auto &renderable = obj->addComponent<sfge::ecs::Renderable>();
        renderable.setShape(shape);
        if (texture) {
            renderable.setTexture(texture);
        }
    }
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});
        shape->setFillColor(sf::Color::Red);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, 3});
        transformable.setScale({20, 0.2f});

        auto &renderable = obj->addComponent<sfge::ecs::Renderable>();
        renderable.setShape(shape);

        auto &rigidbody = obj->addComponent<sfge::ecs::RigidBody>();
        sfge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        rigidbody.setConfig(config);
    }
}
