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

    /*
     * 1. TransformableSystem:
     *  a. apply physics...
     *  b. update relatiev/absolute position from parent
     * 2. RenderableSystem
     *  a. draw using entity's absolute
     */
    struct Transformable
    {
        Transformable()
        {
            std::clog << "ctor transf" << std::endl;
        }
        // parent (id?entity?..)
        // relation between children -> parent => joints?
        sf::Vector2f position;
        // sf::Vector2f relativePosition; // 0 means same as parent pos
        sf::Vector2f scale;
        float angle = 0.f;
    };

    // Check if entt can calls a function when a specific component is added
    // => rigidbody created => generate b2Body* from the settings
    struct RigidBody
    {
        explicit RigidBody(AGameObject *gameObject);

        b2Body *body = nullptr;
        // b2BodyType type = b2_dynamicBody; // b2_staticBody, b2_kinematicBody
        b2BodyDef def;
        b2PolygonShape shape;
        b2FixtureDef fixtureDef;
        // AGameObject *gameObject = nullptr;
    };

    struct Scriptable
    {
        // std::vector<std::unique_ptr<IScript>> m_scripts;
    };
}