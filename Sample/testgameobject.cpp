#include "testgameobject.hpp"

#include <iostream>

TestGameObject::TestGameObject()
{
    std::clog << "testgameobject ctor" << std::endl;
}

TestGameObject::~TestGameObject()
{
    std::clog << "testgameobject dtor" << std::endl;
}