#pragma once

#include "config/physicsconfig.hpp"
#include "sfge/components/rigidbody.hpp"

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

    class RigidbodyEvents
    {
    public:
        void setCreatorFn(std::function<b2Body *(const ecs::RigidBody::Config &)> fn);

        void created(entt::registry &registry, entt::entity entity) const;
        void changed(entt::registry &registry, entt::entity entity) const;

    private:
        void createConfig(entt::registry &registry, entt::entity entity) const;
        b2Body *load(RigidBody::Config &config, const sf::Vector2f &pos,
                     const sf::Vector2f &scale, float angle) const;

    private:
        std::function<b2Body *(const ecs::RigidBody::Config &)> m_creatorFn;
    };
}// namespace sfge::ecs
