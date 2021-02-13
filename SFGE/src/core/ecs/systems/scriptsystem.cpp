#include "scriptsystem.hpp"

#include "sfge/components/ascript.hpp"
#include "sfge/components/scriptable.hpp"

namespace sfge::ecs
{
    void ScriptSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ecs::Scriptable>();
        for (const auto entity : view) {
            auto &scriptable = view.get<ecs::Scriptable>(entity);
            scriptable.update(dt);
        }
    }
}// namespace sfge::ecs
