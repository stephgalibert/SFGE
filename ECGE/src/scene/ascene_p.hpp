#pragma once

#include "ecge/ascene.hpp"
#include "ecs/systems/physicssystem.hpp"
#include "ecs/systems/rendersystem.hpp"
#include "logger/logger.h"
#include "scenegraph.hpp"

#include <memory>

namespace ecge
{
    class AScenePrivate
    {
    public:
    private:
        explicit AScenePrivate(AScene *qq);
        PIMPL_DECLARE_PUBLIC(AScene);

        void rigidBodyCreated(entt::registry &registry, entt::entity entity);
        void renderableCreated(entt::registry &registry, entt::entity entity);

        void transformableChanged(entt::registry &registry, entt::entity entity);

        entt::registry m_registry;
        SceneGraph m_graph;
        RenderSystem m_renderSystem;
        PhysicsSystem m_physicsSystem;

        std::shared_ptr<ILogger> m_logger;
    };
}// namespace ecge