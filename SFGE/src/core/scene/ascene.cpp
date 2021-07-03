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

#include "sfge/scene/ascene.hpp"
#include "ascene_p.hpp"
#include "scenegraph.hpp"

#include "sfge/gameobject/agameobject.hpp"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

#include "sfge/components/input.hpp"
#include "sfge/components/renderable.hpp"
#include "sfge/components/rigidbody.hpp"
#include "sfge/components/scriptable.hpp"
#include "sfge/components/transformable.hpp"

#include "core/ecs/events/componentsevents.hpp"

namespace sfge
{
    /** Private implementation **/

    AScenePrivate::AScenePrivate(AScene *qq)
        : q_ptr(qq)
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();

        m_logger = loggerService->getOrCreateLogger("AScene");
        m_logger->addLoggingFile("logs/log.txt");

        m_graph = std::make_unique<SceneGraph>();
        m_renderSystem = std::make_unique<ecs::CameraSystem>();
        m_physicsSystem = std::make_unique<ecs::PhysicsSystem>();
        m_scriptSystem = std::make_unique<ecs::ScriptSystem>();
        m_inputSystem = std::make_unique<ecs::InputSystem>();

        m_transformableEvents = std::make_unique<ecs::TransformableEvents>();
        m_renderableEvents = std::make_unique<ecs::RenderableEvents>();
        m_rigidbodyEvents = std::make_unique<ecs::RigidbodyEvents>();
        m_rigidbodyEvents->setCallbacks(this);

        // Setup components dependencies
        m_registry.on_construct<ecs::Input>().connect<&entt::registry::get_or_emplace<ecs::Scriptable>>();

        // Setup construct listeners
        m_registry.on_construct<ecs::RigidBody>().connect<&ecs::RigidbodyEvents::created>(m_rigidbodyEvents);

        // Setup change listeners
        m_registry.on_update<ecs::Transformable>().connect<&ecs::TransformableEvents::changed>(m_transformableEvents);
        m_registry.on_update<ecs::Renderable>().connect<&ecs::RenderableEvents::changed>(m_renderableEvents);
        m_registry.on_update<ecs::RigidBody>().connect<&ecs::RigidbodyEvents::changed>(m_rigidbodyEvents);
        // entt::observer observer(m_registry, entt::collector.update<ecs::Transformable>());
    }

    b2Body *AScenePrivate::addBody(const ecs::RigidBody::Config &config)
    {
        return m_physicsSystem->createBody(config.bodyDef);
    }

    void AScenePrivate::deleteBody(b2Body *body)
    {
        m_physicsSystem->destroyBody(body);
    }

    /** Public API **/

    AScene::AScene()
        : AScene(new AScenePrivate(this))
    {
    }

    AScene::AScene(AScenePrivate *dd)
        : d_ptr(dd)
    {
    }

    AScene::~AScene()
    {
    }

    void AScene::init()
    {
        PIMPL_D(AScene);
        d->m_logger->info("Init");
    }

    //    void AScene::onWindowClosing()
    //    {
    //        PIMPL_D(AScene);
    //        d->m_logger->info("Destroy");
    //
    //        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
    //        loggerService->removeLogger(d->m_logger);
    //    }
    //
    //    void AScene::onKeyboardEvent(const input::KeyboardEvent &events)
    //    {
    //        PIMPL_D(AScene);
    //        d->m_inputSystem->push(events);
    //    }

    void AScene::onEvent(const sf::Event &event)
    {
        PIMPL_D(AScene);
        d->m_inputSystem->push(event);
    }

    void AScene::update(float dt)
    {
        PIMPL_D(AScene);
        d->m_inputSystem->update(d->m_registry, 0);
        d->m_physicsSystem->update(d->m_registry, dt);
        d->m_scriptSystem->update(d->m_registry, dt);
    }

    void AScene::draw()
    {
        PIMPL_D(AScene);
        d->m_renderSystem->update(d->m_registry, 0);
    }

    void AScene::addGameObject(const std::shared_ptr<AGameObject> &obj)
    {
        PIMPL_D(AScene);
        obj->setScene(this);
        obj->setComponentRegistry(&d->m_registry);

        // Create default components
        obj->addComponent<ecs::Transformable>();
        obj->addComponent<ecs::Scriptable>();

        d->m_graph->insert(obj);
        obj->onCreated();
    }
}// namespace sfge