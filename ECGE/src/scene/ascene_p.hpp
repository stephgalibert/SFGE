#pragma once

#include "ecge/ascene.hpp"
#include "ecge/logger/logger.h"
#include "ecs/componentsevents.h"
#include "ecs/systems/physicssystem.hpp"
#include "ecs/systems/rendersystem.hpp"
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

        entt::registry m_registry;

        std::shared_ptr<ILogger> m_logger;
        std::unique_ptr<SceneGraph> m_graph;

        std::unique_ptr<ecs::RenderSystem> m_renderSystem;
        std::unique_ptr<ecs::PhysicsSystem> m_physicsSystem;
        std::unique_ptr<ecs::RigidbodyEvents> m_rigidbodyEvents;
    };
}// namespace ecge