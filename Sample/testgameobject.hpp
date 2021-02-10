#pragma once

#include <ecge/agameobject.hpp>

class TestGameObject : public ecge::AGameObject
{
public:
    void onCreated() override;
    void onDestroyed() override;

private:
};
