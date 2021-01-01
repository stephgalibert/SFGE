#include "ecge/ascene.hpp"
#include "scene/ascene_p.hpp"

#include "ecge/agameobject.hpp"
#include "ecge/components.hpp"

#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

#include <iostream>

namespace ecge
{
	AScenePrivate::AScenePrivate(AScene* qq)
		: q_ptr(qq)
	{
        // Setup components dependencies
        // m_registry.on_construct<ecs::Renderable>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();
        // m_registry.on_construct<ecs::RigidBody>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();

        // Setup change listeners
        m_registry.on_construct<ecs::Renderable>().connect<&AScenePrivate::renderableCreated>(this);
        m_registry.on_construct<ecs::RigidBody>().connect<&AScenePrivate::rigidBodyCreated>(this);
    }

    void AScenePrivate::rigidBodyCreated(entt::registry &registry, entt::entity entity)
    {
        ecs::RigidBody &r = registry.get<ecs::RigidBody>(entity);
        ecs::Transformable &t = registry.get<ecs::Transformable>(entity);

        r.config.bodyDef.position.x = t.position.x;
        r.config.bodyDef.position.y = t.position.y;
        r.body = m_physicsSystem.createBody(r.config.bodyDef);

        r.config.shape.SetAsBox(t.scale.x / 2.f, t.scale.y / 2.f);

        r.config.fixtureDef.shape = &r.config.shape;
        r.config.fixtureDef.density = 1.0f;
        r.config.fixtureDef.friction = 0.3f;
        r.body->CreateFixture(&r.config.fixtureDef);
    }

    void AScenePrivate::renderableCreated(entt::registry &registry, entt::entity entity)
    {
        ecs::Renderable &r = registry.get<ecs::Renderable>(entity);
        ecs::Transformable &t = registry.get<ecs::Transformable>(entity);

        // Set the scale according to the shape size
        t.scale.x = r.shape->getLocalBounds().width * 0.02f;
        t.scale.y = r.shape->getLocalBounds().height * 0.02f;
    }

	AScene::AScene()
		: AScene(new AScenePrivate(this))
	{
	}

	AScene::AScene(AScenePrivate* dd)
		: d_ptr(dd)
	{
	}

	AScene::~AScene()
	{
        PIMPL_D(AScene);
        for (auto &gameObject : d->m_graph.gameObjects) {
            gameObject->onDestroyed();
            d->m_registry.destroy( gameObject->entity() );
        }
	}

    void AScene::init()
    {
        PIMPL_D(AScene);
        std::clog << "ascene init" << std::endl;
    }

    void AScene::setRenderTarget(sf::RenderTarget *target)
    {
        PIMPL_D(AScene);
        d->m_renderSystem.setRenderTarget(target);
    }

    void AScene::stop()
    {
        std::clog << "ascene::stop" << std::endl;
    }

    void AScene::onKeyboardEvent(sf::Keyboard::Key key, bool pressed)
    {
        // TODO: input system
        std::clog << "ascene::onkbdevent" << std::endl;
    }

    void AScene::onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed)
    {
        // TODO: input system
        std::clog << "ascene::onmousebuttonevent" << std::endl;
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
        obj->setEntity( d->m_registry.create() );
        d->m_graph.gameObjects.push_back(std::move(obj));
        return d->m_graph.gameObjects.back();
    }
}