#pragma once

#include "agameobject.hpp"

#include <SFML/Graphics.hpp>

#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

#include <memory>
#include <iostream>

namespace ecge::ecs
{
    struct Renderable
    {
        explicit Renderable(sf::Shape *shape);
        std::unique_ptr<sf::Shape> shape;
    };

    struct Transformable
    {
//        meters = {0.02f * xPixels, 0.02f * yPixels};
//        pixels = {50.0f * xMeters, 50.0f * yMeters};
        sf::Vector2f position; // meters
        sf::Vector2f scale = {1,1}; // meters
        float angle = 0.f; // radians
    };

    struct RigidBody
    {
        struct Config
        {
            Config();
            b2BodyDef bodyDef;
            b2PolygonShape shape;
            b2FixtureDef fixtureDef;
        };

        RigidBody(AGameObject *gameObject, Config config = Config());
        b2Body *body = nullptr;
        Config config;
    };

    struct Scriptable
    {
        // std::vector<std::unique_ptr<IScript>> m_scripts;
    };
}