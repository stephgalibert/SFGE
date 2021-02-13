#pragma once

#include "sfge/gameobject/agameobject.hpp"

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
        AScene *m_scene = nullptr;
        entt::entity m_entity;
    };
}// namespace sfge