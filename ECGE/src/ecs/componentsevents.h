#pragma once

#include "config/physicsconfig.h"
#include "ecge/components/rigidbody.hpp"

#include <entt/entt.hpp>

#include <functional>

namespace ecge::ecs
{
    class TransformableEvents
    {
    public:
        TransformableEvents();
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        float m_pixelsPerMeter;
    };

    class RenderableEvents
    {
    public:
        RenderableEvents();
        void created(entt::registry &registry, entt::entity entity) const;

    private:
        float m_meterPerPixel;
    };

    class RigidbodyEvents
    {
    public:
        void setCreatorFn(std::function<b2Body *(const ecs::RigidBody::Config &)> fn);

        void created(entt::registry &registry, entt::entity entity) const;

    private:
        std::function<b2Body *(const ecs::RigidBody::Config &)> m_creatorFn;
    };
}// namespace ecge::ecs
