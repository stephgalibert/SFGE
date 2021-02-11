#include "scriptsystem.h"

#include "ecge/components/ascript.h"
#include "ecge/components/scriptable.h"

namespace ecge::ecs
{
    void ScriptSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<ecs::Scriptable>();
        for (const auto entity : view) {
            auto &scriptable = view.get<ecs::Scriptable>(entity);
            scriptable.update(dt);
        }
    }
}// namespace ecge::ecs
