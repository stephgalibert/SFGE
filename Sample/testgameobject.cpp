#include "testgameobject.hpp"

#include "testscript.h"

void TestGameObject::onCreated()
{
    addComponent<TestScript>();
}

void TestGameObject::onDestroyed()
{
}