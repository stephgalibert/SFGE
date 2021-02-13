#include "testscene.hpp"

#include "testgameobject.hpp"
#include "testscript.h"

#include <ecge/components/input.h>
#include <ecge/components/renderable.hpp>
#include <ecge/components/rigidbody.hpp>
#include <ecge/components/transformable.hpp>

#include <iostream>

TestScene::TestScene()
{
    m_logger = ecge::Logger::CreateLogger("TestScene");
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
        auto obj = instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>();
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto obj = instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({2.2, -7});
        transformable.setAngle(0.700);

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>();

        obj->addComponent<TestScript>();

        auto &input = obj->addComponent<ecge::ecs::Input>();
        input.setKeyboardButton(true);
        input.setMouseButton(true);
        input.setMouseMove(true);
    }
    {
        sf::Shape *shape = new sf::RectangleShape({800, 25});
        shape->setFillColor(sf::Color::Red);
        auto obj = instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({-1, 3});

        obj->addComponent<ecge::ecs::Renderable>(shape);


        auto &rigidbody = obj->addComponent<ecge::ecs::RigidBody>();
        ecge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        rigidbody.setConfig(config);
    }
}
