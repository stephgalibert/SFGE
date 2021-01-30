#include "ecge/agameobject.hpp"
#include "agameobject_p.hpp"

#include <iostream>

namespace ecge
{
    AGameObjectPrivate::AGameObjectPrivate(AGameObject *qq)
        : q_ptr(qq)
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
        std::clog << "agameobject oncreated" << std::endl;
    }

    void AGameObject::onDestroyed()
    {
        std::clog << "agameobject ondestroyed" << std::endl;
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