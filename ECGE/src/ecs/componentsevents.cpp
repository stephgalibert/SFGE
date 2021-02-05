#include "componentsevents.h"

#include <utility>

#include "ecge/components/renderable.hpp"
#include "ecge/components/rigidbody.hpp"
#include "ecge/components/transformable.hpp"

namespace ecge::ecs
{
    void TransformableEvents::changed(entt::registry &registry, entt::entity entity)
    {
        // Using 50 pixels per meter
        // TODO: make an user config
        const float meterPerPixel = 50.f;
        const float pixelsPerMeter = 0.02f;

        Transformable &transform = registry.get<Transformable>(entity);

        Renderable *renderable = registry.try_get<Renderable>(entity);
        if (renderable) {
            renderable->shape()->setOrigin(transform.scale().x * meterPerPixel / 2.f, transform.scale().y * meterPerPixel / 2.f);
            renderable->shape()->setPosition(transform.position().x * meterPerPixel, transform.position().y * meterPerPixel);
            renderable->shape()->setRotation(transform.angle() * 180 / b2_pi);
        }

        RigidBody *rigidBody = registry.try_get<RigidBody>(entity);
        if (rigidBody) {
            b2Vec2 b2Pos = rigidBody->body()->GetPosition();
            if (b2Pos.x != transform.position().x || b2Pos.y != transform.position().y || rigidBody->body()->GetAngle() != transform.angle()) {
                b2Pos = {transform.position().x, transform.position().y};
                rigidBody->body()->SetTransform(b2Pos, transform.angle());
            }
        }
    }

    void RenderableEvents::created(entt::registry &registry, entt::entity entity)
    {
        Renderable &r = registry.get<Renderable>(entity);
        Transformable &t = registry.get<Transformable>(entity);

        t.setScale({r.shape()->getLocalBounds().width * 0.02f,
                    r.shape()->getLocalBounds().height * 0.02f});
    }

    void RigidbodyEvents::setCreatorFn(std::function<b2Body *(const ecs::RigidBody::Config &)> fn)
    {
        m_creatorFn = std::move(fn);
    }

    void RigidbodyEvents::created(entt::registry &registry, entt::entity entity)
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