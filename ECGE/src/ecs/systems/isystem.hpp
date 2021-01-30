#pragma once

#include <entt/entt.hpp>

namespace ecge
{
    struct ISystem {
        virtual ~ISystem() = default;
        virtual void update(entt::registry &registry, float dt) = 0;
    };
}// namespace ecge
