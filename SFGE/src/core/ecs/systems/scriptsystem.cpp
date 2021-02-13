#include "scriptsystem.h"

#include "sfge/components/ascript.h"
#include "sfge/components/scriptable.h"

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
