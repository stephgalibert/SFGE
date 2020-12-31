#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components.hpp>

#include <iostream>

void TestScene::init()
{
    AScene::init();

    std::clog << "init test scene" << std::endl;

    sf::Shape *shape = new sf::RectangleShape({1,1});
    shape->setFillColor(sf::Color::Green);
    auto &obj = instantiate<TestGameObject>();

    obj->addComponent<ecge::ecs::Renderable>(shape);
    obj->addComponent<ecge::ecs::RigidBody>(obj.get());

    auto &transformable = obj->component<ecge::ecs::Transformable>();
    transformable.position.x = 50;
    transformable.position.y = 50;
    transformable.scale.x = 10;
    transformable.scale.y = 10;
}