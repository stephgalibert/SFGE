#pragma once

#include <entt/entt.hpp>

namespace ecge::ecs
{
    struct Component
    {
    public:
        Component() = default;
        Component(const Component &rhs);
        Component(Component &&rhs) noexcept;
        ~Component() = default;

        Component &operator=(const Component &o);
        Component &operator=(Component &&o) noexcept;

        void setRegistry(entt::registry *registry);
        void setEntity(entt::entity entity);

    protected:
        entt::registry *m_registry = nullptr;
        entt::entity m_entity = entt::null;
    };
}