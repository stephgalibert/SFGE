#include "ecge/ascene.hpp"
#include "scene/ascene_p.hpp"
#include "scene/scenegraph.hpp"

#include "ecge/agameobject.hpp"

#include "ecge/components/renderable.hpp"
#include "ecge/components/rigidbody.hpp"
#include "ecge/components/transformable.hpp"

#include "ecs/componentsevents.h"
#include "ecs/systems/physicssystem.hpp"
#include "ecs/systems/rendersystem.hpp"

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

        m_rigidbodyEvents = std::make_unique<ecs::RigidbodyEvents>();
        m_rigidbodyEvents->setCreatorFn([this](const ecs::RigidBody::Config &config) {
            return m_physicsSystem->createBody(config.bodyDef);
        });

        // Setup components dependencies
        // m_registry.on_construct<ecs::Renderable>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();
        // m_registry.on_construct<ecs::RigidBody>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();

        // Setup construct listeners
        // m_registry.on_construct<ecs::Renderable>().connect<&AScenePrivate::renderableCreated>(this);
        m_registry.on_construct<ecs::Renderable>().connect<&ecs::RenderableEvents::created>();
        m_registry.on_construct<ecs::RigidBody>().connect<&ecs::RigidbodyEvents::created>(m_rigidbodyEvents);

        // Setup change listeners
        m_registry.on_update<ecs::Transformable>().connect<&ecs::TransformableEvents::changed>();
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

    void AScene::stop()
    {
        PIMPL_D(AScene);
        d->m_logger->info("Stop");
    }

    void AScene::onKeyboardEvent(sf::Keyboard::Key key, bool pressed)
    {
        PIMPL_D(AScene);
        // TODO: input system
        d->m_logger->info("onKeyboardEvent");
    }

    void AScene::onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed)
    {
        PIMPL_D(AScene);
        // TODO: input system
        d->m_logger->info("onMouseButtonEvent");
    }

    void AScene::update(float dt)
    {
        PIMPL_D(AScene);
        d->m_physicsSystem->update(d->m_registry, dt);
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
    }
}// namespace ecge