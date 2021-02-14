#include "testscene.hpp"

#include "testscript.hpp"

#include <sfge/components/input.hpp>
#include <sfge/components/renderable.hpp>
#include <sfge/components/rigidbody.hpp>
#include <sfge/components/transformable.hpp>
#include <sfge/gameobject/agameobject.hpp>

#include <iostream>

TestScene::TestScene()
{
    m_logger = sfge::Logger::CreateLogger("TestScene");
    m_logger->addLoggingFile("logs/sample.txt");
}

void TestScene::init()
{
    AScene::init();

    // TODO: test purpose, remove it
    static sf::Texture tex;
    tex.loadFromFile("texture.jpg");

    m_logger->info("Init");
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});// 50, 50
        shape->setFillColor(sf::Color::Green);
        auto obj = instantiate<sfge::AGameObject>();

        obj->addComponent<sfge::ecs::Renderable>(shape);

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<sfge::ecs::RigidBody>();
    }
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});
        shape->setTexture(&tex);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, 0});
        transformable.setAngle(0.700);
        transformable.setScale({1, 0.5f});

        obj->addComponent<sfge::ecs::RigidBody>();
        obj->addComponent<TestScript>();

        auto &input = obj->addComponent<sfge::ecs::Input>();
        input.setKeyboardButton(true);
        input.setMouseButton(true);
        input.setMouseMove(true);

        obj->addComponent<sfge::ecs::Renderable>(shape);
    }
    {
        sf::Shape *shape = new sf::RectangleShape({1, 1});// 800, 25
        shape->setFillColor(sf::Color::Red);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({-1, 3});
        transformable.setScale({10, 0.2f});

        obj->addComponent<sfge::ecs::Renderable>(shape);

        auto &rigidbody = obj->addComponent<sfge::ecs::RigidBody>();
        sfge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        rigidbody.setConfig(config);
    }
}
