#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components.hpp>

#include <iostream>

void TestScene::init()
{
    AScene::init();

    std::clog << "init test scene" << std::endl;

    sf::Shape *shape = new sf::RectangleShape(sf::Vector2f(20, 10));
    shape->setFillColor(sf::Color::Green);
    shape->setPosition(10, 10);
    auto &obj = instantiate<TestGameObject>();

    obj->addComponent<ecge::ecs::Renderable>(shape);
    obj->addComponent<ecge::ecs::RigidBody>(obj.get());
}