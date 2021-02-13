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
    // Orders of inserting component is crucial
    // 1. Renderable
    // 2. RigidBody
    m_logger->info("Init");
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Green);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<sfge::ecs::Renderable>(shape);
        obj->addComponent<sfge::ecs::RigidBody>();
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({2.2, -7});
        transformable.setAngle(0.700);

        obj->addComponent<sfge::ecs::Renderable>(shape);
        obj->addComponent<sfge::ecs::RigidBody>();

        obj->addComponent<TestScript>();

        auto &input = obj->addComponent<sfge::ecs::Input>();
        input.setKeyboardButton(true);
        input.setMouseButton(true);
        input.setMouseMove(true);
    }
    {
        sf::Shape *shape = new sf::RectangleShape({800, 25});
        shape->setFillColor(sf::Color::Red);
        auto obj = instantiate<sfge::AGameObject>();

        auto &transformable = obj->component<sfge::ecs::Transformable>();
        transformable.setPosition({-1, 3});

        obj->addComponent<sfge::ecs::Renderable>(shape);


        auto &rigidbody = obj->addComponent<sfge::ecs::RigidBody>();
        sfge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        rigidbody.setConfig(config);
    }
}
