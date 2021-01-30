#include "ecge/components/component.hpp"

namespace ecge::ecs
{
    Component::Component(const Component &rhs)
    {
        *this = rhs;
    }

    Component::Component(Component &&rhs) noexcept
    {
        *this = std::move(rhs);
    }

    Component &Component::operator=(const Component &rhs)
    {
        if (this != &rhs) {
            m_registry = rhs.m_registry;
            m_entity = rhs.m_entity;
        }
        return *this;
    }

    Component &Component::operator=(Component &&rhs) noexcept
    {
        m_registry = rhs.m_registry;
        m_entity = rhs.m_entity;
        rhs.m_registry = nullptr;
        rhs.m_entity = entt::null;
        return *this;
    }

    void Component::setRegistry(entt::registry *registry)
    {
        m_registry = registry;
    }

    void Component::setEntity(entt::entity entity)
    {
        m_entity = entity;
    }

}// namespace ecge::ecs