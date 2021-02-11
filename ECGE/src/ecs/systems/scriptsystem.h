#pragma once

#include "isystem.hpp"

namespace ecge::ecs
{
    class ScriptSystem : public ISystem
    {
    public:
        void update(entt::registry &registry, float dt) override;
    };
}// namespace ecge::ecs