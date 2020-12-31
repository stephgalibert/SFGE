#include "ecge/ascene.hpp"
#include "scene/ascene_p.hpp"

#include "ecge/agameobject.hpp"
#include "ecge/components.hpp"

#include <iostream>

namespace ecge
{
	AScenePrivate::AScenePrivate(AScene* qq)
		: q_ptr(qq)
	{
        // Setup components dependencies
        m_registry.on_construct<ecs::Renderable>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();
        m_registry.on_construct<ecs::RigidBody>().connect<&entt::registry::get_or_emplace<ecs::Transformable>>();
        // m_registry.on_construct<ecs::RigidBody>().connect<entt::invoke<&ecs::RigidBody::test>>();
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