//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#include "componentsevents.hpp"

#include "rigidbodyeventscallbacks.hpp"
#include "sfge/components/renderable.hpp"

#include "config/physicsconfig.hpp"
#include "services/iconfigurationmanagerservice.h"
#include "sfge/services/servicelocator.hpp"

namespace sfge::ecs
{
    TransformableEvents::TransformableEvents()
    {
        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        m_pixelsPerMeter = config->getPhysics()->getPixelsPerMeter();
    }

    void TransformableEvents::changed(entt::registry &registry, entt::entity entity) const
    {
        // A Transformable component has been changed
        // We need to update the attached Renderable and the Rigidbody, if any.
        const auto &transformable = registry.get<Transformable>(entity);

        auto renderable = registry.try_get<Renderable>(entity);
        if (renderable) {
            renderable->setScale(transformable.getScale().x * m_pixelsPerMeter, transformable.getScale().y * m_pixelsPerMeter);
            // The origin must be the same as box2d: in the center of the object
            renderable->setOrigin(0.5, 0.5);
            renderable->setPosition(transformable.getPosition().x * m_pixelsPerMeter, transformable.getPosition().y * m_pixelsPerMeter);
            renderable->setRotation_DEGREES(transformable.getAngle_DEGREES());
        }

        auto rigidBody = registry.try_get<RigidBody>(entity);
        if (rigidBody) {
            b2Vec2 b2Pos = rigidBody->body()->GetPosition();
            if (b2Pos.x != transformable.getPosition().x || b2Pos.y != transformable.getPosition().y || rigidBody->body()->GetAngle() != transformable.getAngle_RADIANS()) {
                // Update the b2body ONLY IF it has a different transform (position and angle)
                b2Pos = {transformable.getPosition().x, transformable.getPosition().y};
                rigidBody->body()->SetTransform(b2Pos, transformable.getAngle_RADIANS());
            }
        }
    }

    RenderableEvents::RenderableEvents()
    {
        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto physicsConfig = config->getPhysics();
        m_pixelsPerMeter = config->getPhysics()->getPixelsPerMeter();
    }

    void RenderableEvents::changed(entt::registry &registry, entt::entity entity) const
    {
        const auto &transformable = registry.get<Transformable>(entity);
        auto &renderable = registry.get<Renderable>(entity);

        renderable.setScale(transformable.getScale().x * m_pixelsPerMeter,
                            transformable.getScale().y * m_pixelsPerMeter);
        renderable.setOrigin(0.5, 0.5);
        renderable.setPosition(transformable.getPosition().x * m_pixelsPerMeter,
                               transformable.getPosition().y * m_pixelsPerMeter);
        renderable.setRotation_DEGREES(transformable.getAngle_DEGREES());
    }

    void RigidbodyEvents::created(entt::registry &registry, entt::entity entity) const
    {
        createConfig(registry, entity);
    }

    void RigidbodyEvents::changed(entt::registry &registry, entt::entity entity) const
    {
        createConfig(registry, entity);
    }

    void RigidbodyEvents::createConfig(entt::registry &registry, entt::entity entity) const
    {
        const ecs::Transformable &transform = registry.get<ecs::Transformable>(entity);
        ecs::RigidBody &rigidBody = registry.get<ecs::RigidBody>(entity);

        ecs::RigidBody::Config config = rigidBody.config();
        b2Body *body = load(config, transform);

        if (rigidBody.m_body != nullptr) {
            m_callbacks->deleteBody(rigidBody.m_body);
        }
        rigidBody.m_body = body;
        rigidBody.m_config = config;
    }

    b2Body *RigidbodyEvents::load(RigidBody::Config &config, const Transformable &transform) const
    {
        const sf::Vector2f pos = transform.getPosition();
        config.bodyDef.position.x = pos.x;
        config.bodyDef.position.y = pos.y;
        config.bodyDef.angle = transform.getAngle_RADIANS();
        config.bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(transform.getGameObject());

        const sf::Vector2f scale = transform.getScale();
        config.shape.SetAsBox(scale.x / 2.f, scale.y / 2.f);
        // config.shape.Set(*points, count);

        config.fixtureDef.shape = &config.shape;
        config.fixtureDef.density = 1.0f;
        config.fixtureDef.friction = 0.3f;

        b2Body *body = m_callbacks->addBody(config);
        body->CreateFixture(&config.fixtureDef);
        return body;
    }

    void RigidbodyEvents::setCallbacks(RigidbodyEventsCallbacks *callbacks)
    {
        m_callbacks = callbacks;
    }
}// namespace sfge::ecs