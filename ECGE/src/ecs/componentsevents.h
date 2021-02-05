#pragma once

#include "ecge/components/rigidbody.hpp"
#include <entt/entt.hpp>

#include <functional>

namespace ecge::ecs
{
    class TransformableEvents
    {
    public:
        static void changed(entt::registry &registry, entt::entity entity);
    };

    class RenderableEvents
    {
    public:
        static void created(entt::registry &registry, entt::entity entity);
    };

    class RigidbodyEvents
    {
    public:
        void setCreatorFn(std::function<b2Body *(const ecs::RigidBody::Config &)> fn);

        void created(entt::registry &registry, entt::entity entity);

    private:
        std::function<b2Body *(const ecs::RigidBody::Config &)> m_creatorFn;
    };
}// namespace ecge::ecs
