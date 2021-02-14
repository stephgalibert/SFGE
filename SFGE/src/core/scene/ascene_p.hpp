//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

#include "core/ecs/componentsevents.hpp"
#include "core/ecs/rigidbodyeventscallbacks.hpp"
#include "core/ecs/systems/inputsystem.hpp"
#include "core/ecs/systems/physicssystem.hpp"
#include "core/ecs/systems/rendersystem.hpp"
#include "core/ecs/systems/scriptsystem.hpp"
#include "scenegraph.hpp"
#include "sfge/logger/logger.hpp"
#include "sfge/scene/ascene.hpp"

#include <memory>

namespace sfge
{
    class AScenePrivate : public ecs::RigidbodyEventsCallbacks
    {
    public:
        b2Body *addBody(const ecs::RigidBody::Config &config) override;
        void deleteBody(b2Body *body) override;

    private:
        explicit AScenePrivate(AScene *qq);
        PIMPL_DECLARE_PUBLIC(AScene);

        entt::registry m_registry;

        std::shared_ptr<ILogger> m_logger;
        std::unique_ptr<SceneGraph> m_graph;

        // TODO: encapsulate systems
        std::unique_ptr<ecs::RenderSystem> m_renderSystem;
        std::unique_ptr<ecs::PhysicsSystem> m_physicsSystem;
        std::unique_ptr<ecs::ScriptSystem> m_scriptSystem;
        std::unique_ptr<ecs::InputSystem> m_inputSystem;

        // TODO: encapsulate components events
        std::unique_ptr<ecs::TransformableEvents> m_transformableEvents;
        std::unique_ptr<ecs::RenderableEvents> m_renderableEvents;
        std::unique_ptr<ecs::RigidbodyEvents> m_rigidbodyEvents;
    };
}// namespace sfge