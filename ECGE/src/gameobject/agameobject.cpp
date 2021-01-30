#include "ecge/agameobject.hpp"
#include "agameobject_p.hpp"

#include <iostream>

#include "logger/Logger.h"

namespace ecge
{
    static auto Logger = Logger::CreateLogger(CLASSNAME(AGameObject));

    AGameObjectPrivate::AGameObjectPrivate(AGameObject *qq)
        : q_ptr(qq), m_entity(entt::null)
    {
    }

    AGameObject::AGameObject()
        : AGameObject(new AGameObjectPrivate(this))
    {
        Logger->debug("Ctor");
    }

    AGameObject::~AGameObject()
    {
        Logger->debug("Dtor");
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
    }

    entt::registry *AGameObject::componentRegistry()
    {
        PIMPL_D(AGameObject);
        return d->m_registry;
    }

    const entt::registry *AGameObject::componentRegistry() const
    {
        const PIMPL_D(AGameObject);
        return d->m_registry;
    }
}// namespace ecge