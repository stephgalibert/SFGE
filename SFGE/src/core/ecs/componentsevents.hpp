#pragma once

#include "config/physicsconfig.hpp"
#include "sfge/components/rigidbody.hpp"
#include "sfge/components/transformable.hpp"

#include <entt/entt.hpp>

#include <SFML/Graphics.hpp>

#include <functional>

namespace sfge::ecs
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
        float m_pixelsPerMeter;
    };

    struct RigidbodyEventsCallbacks;

    class RigidbodyEvents
    {
    public:
        void setCallbacks(RigidbodyEventsCallbacks *callbacks);

        void created(entt::registry &registry, entt::entity entity) const;
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        void createConfig(entt::registry &registry, entt::entity entity) const;
        b2Body *load(RigidBody::Config &config, const Transformable &transform) const;

    private:
        RigidbodyEventsCallbacks *m_callbacks = nullptr;
    };
}// namespace sfge::ecs
