#include "ecge/ascene.hpp"
#include "scene/ascene_p.hpp"

#include "ecge/agameobject.hpp"

#include "ecge/components/renderable.hpp"
#include "ecge/components/rigidbody.hpp"
#include "ecge/components/transformable.hpp"

#include "logger/Logger.h"

#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

#include <iostream>

namespace ecge
{
    static auto Logger = Logger::CreateLogger(CLASSNAME(AScene));

    AScenePrivate::AScenePrivate(AScene *qq)
        : q_ptr(qq)
    {
        // Setup components dependencies
        // m_registry.on_construct<ecs::Renderable>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();
        // m_registry.on_construct<ecs::RigidBody>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();

        // Setup construct listeners
        m_registry.on_construct<ecs::Renderable>().connect<&AScenePrivate::renderableCreated>(this);
        m_registry.on_construct<ecs::RigidBody>().connect<&AScenePrivate::rigidBodyCreated>(this);

        // Setup change listeners
        m_registry.on_update<ecs::Transformable>().connect<&AScenePrivate::transformableChanged>(this);
        // entt::observer observer(m_registry, entt::collector.update<ecs::Transformable>());
    }

    void AScenePrivate::rigidBodyCreated(entt::registry &registry, entt::entity entity)
    {
        ecs::RigidBody &rigidBody = registry.get<ecs::RigidBody>(entity);
        ecs::Transformable &transform = registry.get<ecs::Transformable>(entity);

        ecs::RigidBody::Config config = rigidBody.config();
        config.bodyDef.position.x = transform.position().x;
        config.bodyDef.position.y = transform.position().y;
        rigidBody.setBody(m_physicsSystem.createBody(config.bodyDef));

        config.shape.SetAsBox(transform.scale().x / 2.f, transform.scale().y / 2.f);

        config.fixtureDef.shape = &config.shape;
        config.fixtureDef.density = 1.0f;
        config.fixtureDef.friction = 0.3f;
        rigidBody.body()->CreateFixture(&config.fixtureDef);
        rigidBody.setConfig(config);
    }

    void AScenePrivate::renderableCreated(entt::registry &registry, entt::entity entity)
    {
        ecs::Renderable &r = registry.get<ecs::Renderable>(entity);
        ecs::Transformable &t = registry.get<ecs::Transformable>(entity);

        t.setScale({r.shape()->getLocalBounds().width * 0.02f,
                    r.shape()->getLocalBounds().height * 0.02f});
    }

    void AScenePrivate::transformableChanged(entt::registry &registry, entt::entity entity)
    {
        // Using 50 pixels per meter
        // TODO: make an user config
        const float meterPerPixel = 50.f;
        const float pixelsPerMeter = 0.02f;

        ecs::Transformable &transform = registry.get<ecs::Transformable>(entity);
        // Update all dependant components...
        // TODO: refactor

        ecs::Renderable *renderable = registry.try_get<ecs::Renderable>(entity);
        if (renderable) {
            renderable->shape()->setOrigin(transform.scale().x * meterPerPixel / 2.f, transform.scale().y * meterPerPixel / 2.f);
            renderable->shape()->setPosition(transform.position().x * meterPerPixel, transform.position().y * meterPerPixel);
            renderable->shape()->setRotation(transform.angle() * 180 / b2_pi);
        }

        ecs::RigidBody *rigidBody = registry.try_get<ecs::RigidBody>(entity);
        if (rigidBody) {
            b2Vec2 b2Pos = rigidBody->body()->GetPosition();
            if (b2Pos.x != transform.position().x || b2Pos.y != transform.position().y || rigidBody->body()->GetAngle() != transform.angle()) {
                b2Pos = {transform.position().x, transform.position().y};
                rigidBody->body()->SetTransform(b2Pos, transform.angle());
            }
        }
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
        for (auto &gameObject : d->m_graph.gameObjects) {
            gameObject->onDestroyed();
            d->m_registry.destroy(gameObject->entity());
        }
    }

    void AScene::init()
    {
        PIMPL_D(AScene);
        Logger->info("Init");
    }

    void AScene::setRenderTarget(sf::RenderTarget *target)
    {
        PIMPL_D(AScene);
        d->m_renderSystem.setRenderTarget(target);
    }

    void AScene::stop()
    {
        Logger->info("Stop");
    }

    void AScene::onKeyboardEvent(sf::Keyboard::Key key, bool pressed)
    {
        // TODO: input system
        Logger->info("onKeyboardEvent");
    }

    void AScene::onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed)
    {
        // TODO: input system
        Logger->info("onMouseButtonEvent");
    }

    void AScene::update(float dt)
    {
        PIMPL_D(AScene);
        d->m_physicsSystem.update(d->m_registry, dt);
    }

    void AScene::draw()
    {
        PIMPL_D(AScene);
        d->m_renderSystem.update(d->m_registry, 0);
    }

    entt::registry &AScene::registry()
    {
        PIMPL_D(AScene);
        return d->m_registry;
    }

    const entt::registry &AScene::registry() const
    {
        const PIMPL_D(AScene);
        return d->m_registry;
    }

    std::unique_ptr<AGameObject> &AScene::addGameObject(std::unique_ptr<AGameObject> obj)
    {
        PIMPL_D(AScene);
        obj->setComponentRegistry(&d->m_registry);
        obj->setEntity(d->m_registry.create());
        d->m_graph.gameObjects.push_back(std::move(obj));
        return d->m_graph.gameObjects.back();
    }
}// namespace ecge