#include "testscene.hpp"

#include "testgameobject.hpp"

#include <ecge/components.hpp>

#include <iostream>

void TestScene::init()
{
    AScene::init();

    std::clog << "init test scene" << std::endl;

    // Size should always be 1.
    sf::Shape *shape = new sf::RectangleShape({1,1});
    shape->setFillColor(sf::Color::Green);
    auto &obj = instantiate<TestGameObject>();

    obj->addComponent<ecge::ecs::Renderable>(shape);
    obj->addComponent<ecge::ecs::RigidBody>(obj.get());

    auto &transformable = obj->component<ecge::ecs::Transformable>();
    transformable.position.x = 0;
    transformable.position.y = -7;
    transformable.scale.x = 1;
    transformable.scale.y = 1;
}