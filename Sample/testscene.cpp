#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components/transformable.hpp>
#include <ecge/components/renderable.hpp>
#include <ecge/components/rigidbody.hpp>

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

        // transformable should be mandatory
        // agameobject without transform is nonsense??
        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        transformable.setPosition({0, -7});

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto &obj = instantiate<TestGameObject>();

        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        transformable.setPosition({2.2, -7});

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());
    }
    {
        sf::Shape *shape = new sf::RectangleShape({100, 25});
        shape->setFillColor(sf::Color::Red);
        auto &obj = instantiate<TestGameObject>();

        auto &transformable = obj->addComponent<ecge::ecs::Transformable>();
        transformable.setPosition({1.1, 0});

        obj->addComponent<ecge::ecs::Renderable>(shape);

        ecge::ecs::RigidBody::Config config;
        config.bodyDef.type = b2_staticBody;
        obj->addComponent<ecge::ecs::RigidBody>(obj.get(), config);
    }
}