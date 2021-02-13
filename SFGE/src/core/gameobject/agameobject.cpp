#include "sfge/gameobject/agameobject.hpp"
#include "agameobject_p.hpp"

#include "sfge/components/transformable.hpp"
#include <iostream>

namespace sfge
{
    AGameObjectPrivate::AGameObjectPrivate(AGameObject *qq)
        : q_ptr(qq), m_entity(entt::null)
    {
    }

    AGameObject::AGameObject()
        : AGameObject(new AGameObjectPrivate(this))
    {
    }

    AGameObject::~AGameObject()
    {
    }

    AGameObject::AGameObject(AGameObjectPrivate *dd)
        : d_ptr(dd)
    {
    }

    void AGameObject::onCreated()
    {
    }

    void AGameObject::onDestroyed()
    {
    }

    uint32_t AGameObject::getId() const
    {
        const PIMPL_D(AGameObject);
        return static_cast<uint32_t>(d->m_entity);
    }

    /*** Private methods ***/

    void AGameObject::setEntity(entt::entity entity)
    {
        PIMPL_D(AGameObject);
        d->m_entity = entity;
    }

    entt::entity AGameObject::entity() const
    {
        const PIMPL_D(AGameObject);
        return d->m_entity;
    }

    void AGameObject::setComponentRegistry(entt::registry *reg)
    {
        PIMPL_D(AGameObject);
        d->m_registry = reg;
        setEntity(d->m_registry->create());
    }

    entt::registry *AGameObject::componentRegistry() const
    {
        const PIMPL_D(AGameObject);
        return d->m_registry;
    }

    void AGameObject::setScene(AScene *scene)
    {
        PIMPL_D(AGameObject);
        d->m_scene = scene;
    }

    AScene *AGameObject::getScene() const
    {
        const PIMPL_D(AGameObject);
        return d->m_scene;
    }
}// namespace sfge