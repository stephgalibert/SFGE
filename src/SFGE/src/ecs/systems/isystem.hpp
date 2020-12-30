#pragma once

#include <entt/entt.hpp>

namespace sfge
{
    struct ISystem
    {
        virtual ~ISystem() = default;
        virtual void update(entt::registry &registry, float dt) = 0;
    };
}
