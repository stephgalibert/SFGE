#include "testscene.hpp"

#include "testgameobject.hpp"

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
        auto obj = Instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto obj = Instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({2.2, -7});

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());
    }
    {
        sf::Shape *shape = new sf::RectangleShape({100, 25});
        shape->setFillColor(sf::Color::Red);
        auto obj = Instantiate<TestGameObject>();

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.setPosition({1.1, 0});

        obj->addComponent<ecge::ecs::Renderable>(shape);

        ecge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        obj->addComponent<ecge::ecs::RigidBody>(obj.get(), config);
    }
}
