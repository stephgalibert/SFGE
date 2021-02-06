#pragma once

#include "ecge/agameobject.hpp"

#include <entt/entt.hpp>

namespace ecge
{
    class AGameObjectPrivate
    {
    public:
    private:
        explicit AGameObjectPrivate(AGameObject *qq);
        PIMPL_DECLARE_PUBLIC(AGameObject);

        entt::registry *m_registry = nullptr;
        AScene *m_scene = nullptr;
        entt::entity m_entity;
    };
}// namespace ecge