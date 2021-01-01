#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components.hpp>

#include <iostream>

void TestScene::init()
{
    AScene::init();
    // Orders of inserting component is crucial
    // 1. Transformable
    // 2. Renderable
    // 3. RigidBody
    std::clog << "init test scene" << std::endl;
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Green);
        auto &obj = instantiate<TestGameObject>();

        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        // check registry.path<component>(entity, fn)
        // could be encapsulated in the agameobject
        // and encapsulate attributes to private
        transformable.position.x = 0;
        transformable.position.y = -7;

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());

        // if we reset transformable position here,
        // not changes in rigidbody...
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto &obj = instantiate<TestGameObject>();

        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        transformable.position.x = 2.2;
        transformable.position.y = -7;

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());
    }
    {
        sf::Shape *shape = new sf::RectangleShape({100, 25});
        shape->setFillColor(sf::Color::Red);
        auto &obj = instantiate<TestGameObject>();

        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        transformable.position.x = 1.1;
        transformable.position.y = 0;

        obj->addComponent<ecge::ecs::Renderable>(shape);

        ecge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        obj->addComponent<ecge::ecs::RigidBody>(obj.get(), config);
    }
}