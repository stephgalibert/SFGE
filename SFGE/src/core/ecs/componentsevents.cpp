#include "componentsevents.hpp"

#include <utility>

#include "sfge/components/renderable.hpp"
#include "sfge/components/rigidbody.hpp"
#include "sfge/components/transformable.hpp"

#include "config/configurationmanager.hpp"
#include "config/physicsconfig.hpp"

#include <iostream>

namespace sfge::ecs
{
    TransformableEvents::TransformableEvents()
    {
        const auto physicsConfig = config::ConfigurationManager::getInstance().getPhysics();
        m_pixelsPerMeter = physicsConfig->getValue<float>(config::Physics::Key::PixelsPerMeter);
    }

    void TransformableEvents::changed(entt::registry &registry, entt::entity entity) const
    {
        // A Transformable component has been changed
        // We need to update the attached Renderable and the Rigidbody, if any.
        auto &transform = registry.get<Transformable>(entity);

        auto renderable = registry.try_get<Renderable>(entity);
        if (renderable) {
            // The origin must be the same as box2d: in the center of the object
            renderable->shape()->setOrigin(transform.getScale().x * m_pixelsPerMeter / 2.f, transform.getScale().y * m_pixelsPerMeter / 2.f);
            renderable->shape()->setPosition(transform.getPosition().x * m_pixelsPerMeter, transform.getPosition().y * m_pixelsPerMeter);
            renderable->shape()->setRotation(transform.getAngleRadians() * 180 / b2_pi);
        }

        RigidBody *rigidBody = registry.try_get<RigidBody>(entity);
        if (rigidBody) {
            b2Vec2 b2Pos = rigidBody->body()->GetPosition();
            if (b2Pos.x != transform.getPosition().x || b2Pos.y != transform.getPosition().y || rigidBody->body()->GetAngle() != transform.getAngleRadians()) {
                // Update the b2body ONLY IF it has a different transform (position and angle)
                b2Pos = {transform.getPosition().x, transform.getPosition().y};
                rigidBody->body()->SetTransform(b2Pos, transform.getAngleRadians());
            }
        }
    }

    RenderableEvents::RenderableEvents()
    {
        const auto physicsConfig = config::ConfigurationManager::getInstance().getPhysics();
        m_meterPerPixel = 1.f / physicsConfig->getValue<int>(config::Physics::Key::PixelsPerMeter);
    }

    void RenderableEvents::created(entt::registry &registry, entt::entity entity) const
    {
        const auto &renderable = registry.get<Renderable>(entity);
        auto &transformable = registry.get<Transformable>(entity);
        transformable.setScale({renderable.shape()->getLocalBounds().width * m_meterPerPixel,
                                renderable.shape()->getLocalBounds().height * m_meterPerPixel});
    }

    void RigidbodyEvents::setCreatorFn(std::function<b2Body *(const ecs::RigidBody::Config &)> fn)
    {
        m_creatorFn = std::move(fn);
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
        ecs::RigidBody &rigidBody = registry.get<ecs::RigidBody>(entity);
        ecs::Transformable &transform = registry.get<ecs::Transformable>(entity);

        ecs::RigidBody::Config config = rigidBody.config();
        b2Body *body = load(config, transform.getPosition(), transform.getScale(), transform.getAngleRadians());

        rigidBody.m_body = body;
        rigidBody.m_config = config;
    }

    b2Body *RigidbodyEvents::load(RigidBody::Config &config, const sf::Vector2f &pos,
                                  const sf::Vector2f &scale, float angle) const
    {
        config.bodyDef.position.x = pos.x;
        config.bodyDef.position.y = pos.y;
        config.bodyDef.angle = angle;

        config.shape.SetAsBox(scale.x / 2.f, scale.y / 2.f);

        config.fixtureDef.shape = &config.shape;
        config.fixtureDef.density = 1.0f;
        config.fixtureDef.friction = 0.3f;

        b2Body *body = m_creatorFn(config);
        body->CreateFixture(&config.fixtureDef);
        return body;
    }
}// namespace sfge::ecs