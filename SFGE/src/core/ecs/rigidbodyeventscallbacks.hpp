#pragma once

#include "sfge/components/rigidbody.hpp"

namespace sfge::ecs
{
    struct RigidbodyEventsCallbacks {
        virtual ~RigidbodyEventsCallbacks() = default;

        virtual b2Body *addBody(const ecs::RigidBody::Config &config) = 0;
        virtual void deleteBody(b2Body *body) = 0;
    };
}// namespace sfge::ecs