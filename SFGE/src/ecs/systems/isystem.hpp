#pragma once

#include <entt/entt.hpp>

namespace sfge::ecs
{
    struct ISystem {
        virtual ~ISystem() = default;
        virtual void update(entt::registry &registry, float dt) = 0;
    };
}// namespace sfge::ecs
