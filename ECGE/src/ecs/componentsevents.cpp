#include "componentsevents.h"

#include <utility>

#include "ecge/components/renderable.hpp"
#include "ecge/components/rigidbody.hpp"
#include "ecge/components/transformable.hpp"

#include "config/configurationmanager.h"
#include "config/physicsconfig.h"

namespace ecge::ecs
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
            renderable->shape()->setOrigin(transform.scale().x * m_pixelsPerMeter / 2.f, transform.scale().y * m_pixelsPerMeter / 2.f);
            renderable->shape()->setPosition(transform.position().x * m_pixelsPerMeter, transform.position().y * m_pixelsPerMeter);
            renderable->shape()->setRotation(transform.angle() * 180 / b2_pi);
        }

        RigidBody *rigidBody = registry.try_get<RigidBody>(entity);
        if (rigidBody) {
            b2Vec2 b2Pos = rigidBody->body()->GetPosition();
            if (b2Pos.x != transform.position().x || b2Pos.y != transform.position().y || rigidBody->body()->GetAngle() != transform.angle()) {
                // Update the b2body ONLY IF it has a different transform (position and angle)
                b2Pos = {transform.position().x, transform.position().y};
                rigidBody->body()->SetTransform(b2Pos, transform.angle());
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
        ecs::RigidBody &rigidBody = registry.get<ecs::RigidBody>(entity);
        ecs::Transformable &transform = registry.get<ecs::Transformable>(entity);

        ecs::RigidBody::Config config = rigidBody.config();
        config.bodyDef.position.x = transform.position().x;
        config.bodyDef.position.y = transform.position().y;

        config.shape.SetAsBox(transform.scale().x / 2.f, transform.scale().y / 2.f);

        config.fixtureDef.shape = &config.shape;
        config.fixtureDef.density = 1.0f;
        config.fixtureDef.friction = 0.3f;

        b2Body *body = m_creatorFn(config);
        body->CreateFixture(&config.fixtureDef);
        rigidBody.setBody(body);
        rigidBody.setConfig(config);
    }

}// namespace ecge::ecs