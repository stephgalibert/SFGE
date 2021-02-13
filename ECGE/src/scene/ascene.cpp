#include "ecge/ascene.hpp"
#include "scene/ascene_p.hpp"
#include "scene/scenegraph.hpp"

#include "ecge/agameobject.hpp"

#include "ecge/components/input.h"
#include "ecge/components/renderable.hpp"
#include "ecge/components/rigidbody.hpp"
#include "ecge/components/scriptable.h"
#include "ecge/components/transformable.hpp"

#include "ecs/componentsevents.h"
//#include "ecs/systems/physicssystem.hpp"
//#include "ecs/systems/rendersystem.hpp"

#include <iostream>

namespace ecge
{
    AScenePrivate::AScenePrivate(AScene *qq)
        : q_ptr(qq)
    {
        m_logger = Logger::CreateLogger("AScene");
        m_logger->addLoggingFile("logs/log.txt");

        m_graph = std::make_unique<SceneGraph>();
        m_renderSystem = std::make_unique<ecs::RenderSystem>();
        m_physicsSystem = std::make_unique<ecs::PhysicsSystem>();
        m_scriptSystem = std::make_unique<ecs::ScriptSystem>();
        m_inputSystem = std::make_unique<ecs::InputSystem>();

        m_transformableEvents = std::make_unique<ecs::TransformableEvents>();
        m_renderableEvents = std::make_unique<ecs::RenderableEvents>();
        m_rigidbodyEvents = std::make_unique<ecs::RigidbodyEvents>();
        m_rigidbodyEvents->setCreatorFn([this](const ecs::RigidBody::Config &config) {
            return m_physicsSystem->createBody(config.bodyDef);
        });

        // Setup components dependencies
        m_registry.on_construct<ecs::Input>().connect<&entt::registry::get_or_emplace<ecs::Scriptable>>();

        // Setup construct listeners
        m_registry.on_construct<ecs::Renderable>().connect<&ecs::RenderableEvents::created>(m_renderableEvents);
        m_registry.on_construct<ecs::RigidBody>().connect<&ecs::RigidbodyEvents::created>(m_rigidbodyEvents);

        // Setup change listeners
        m_registry.on_update<ecs::Transformable>().connect<&ecs::TransformableEvents::changed>(m_transformableEvents);
        m_registry.on_update<ecs::RigidBody>().connect<&ecs::RigidbodyEvents::changed>(m_rigidbodyEvents);
        // entt::observer observer(m_registry, entt::collector.update<ecs::Transformable>());
    }

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
        PIMPL_D(AScene);
        Logger::RemoveLogger(d->m_logger);
    }

    void AScene::init()
    {
        PIMPL_D(AScene);
        d->m_logger->info("Init");
    }

    void AScene::setRenderTarget(sf::RenderTarget *target)
    {
        PIMPL_D(AScene);
        d->m_renderSystem->setRenderTarget(target);
    }

    void AScene::destroy()
    {
        PIMPL_D(AScene);
        d->m_logger->info("Destroy");
    }

    void AScene::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        PIMPL_D(AScene);
        // TODO: input system
        d->m_logger->info("onKeyboardEvent");
        d->m_inputSystem->push(event);
        // d->m_inputSystem->push(key, pressed);
    }

    void AScene::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        PIMPL_D(AScene);
        // TODO: input system
        d->m_logger->info("onMouseButtonEvent");
        // d->m_inputSystem->push(btn, x, y, pressed);
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
        obj->addComponent<ecs::Transformable>();
        d->m_graph->insert(obj);
        obj->onCreated();
    }
}// namespace ecge