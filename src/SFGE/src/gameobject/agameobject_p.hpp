#pragma once

#include "sfge/agameobject.hpp"

#include <entt/entt.hpp>

namespace sfge
{
    class AGameObjectPrivate
    {
    public:
    private:
        explicit AGameObjectPrivate(AGameObject *qq);
        PIMPL_DECLARE_PUBLIC(AGameObject);

        entt::registry *m_registry = nullptr;
        entt::entity m_entity;
    };
}