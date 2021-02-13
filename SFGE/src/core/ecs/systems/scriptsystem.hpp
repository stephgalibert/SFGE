#pragma once

#include "isystem.hpp"

namespace sfge::ecs
{
    class ScriptSystem : public ISystem
    {
    public:
        void update(entt::registry &registry, float dt) override;
    };
}// namespace sfge::ecs