#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components.hpp>

#include <iostream>

void TestScene::init()
{
    AScene::init();

    std::clog << "init test scene" << std::endl;

    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Green);
        auto &obj = instantiate<TestGameObject>();

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.position.x = 0;
        transformable.position.y = -7;
        transformable.scale.x = shape->getLocalBounds().width * 0.02f;
        transformable.scale.y = shape->getLocalBounds().height * 0.02f;
    }
    {
        sf::Shape *shape = new sf::RectangleShape({50, 50});
        shape->setFillColor(sf::Color::Yellow);
        auto &obj = instantiate<TestGameObject>();

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get());

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.position.x = 2.2;
        transformable.position.y = -7;
        transformable.scale.x = shape->getLocalBounds().width * 0.02f;
        transformable.scale.y = shape->getLocalBounds().height * 0.02f;
    }
    {
        sf::Shape *shape = new sf::RectangleShape({100, 25});
        shape->setFillColor(sf::Color::Red);
        auto &obj = instantiate<TestGameObject>();

        obj->addComponent<ecge::ecs::Renderable>(shape);
        obj->addComponent<ecge::ecs::RigidBody>(obj.get()).def.type = b2_staticBody;

        auto &transformable = obj->component<ecge::ecs::Transformable>();
        transformable.position.x = 1.1;
        transformable.position.y = 0;
        transformable.scale.x = shape->getLocalBounds().width * 0.02f;
        transformable.scale.y = shape->getLocalBounds().height * 0.02f;
    }
}