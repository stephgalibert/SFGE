#include "sfge/components/transformable.hpp"

#include <iostream>

namespace sfge::ecs
{
    void Transformable::setPosition(const sf::Vector2f &pos)
    {
        m_registry->patch<Transformable>(m_entity, [&pos](Transformable &transform) {
            transform.m_position = pos;
        });
    }

    void Transformable::setScale(const sf::Vector2f &scale)
    {
        m_registry->patch<Transformable>(m_entity, [&scale](Transformable &transform) {
            transform.m_scale = scale;
        });
    }

    void Transformable::setAngle(float radians)
    {
        m_registry->patch<Transformable>(m_entity, [radians](Transformable &transform) {
            transform.m_radians = radians;
        });
    }

    void Transformable::setTransform(const sf::Vector2f &pos, float radians)
    {
        m_registry->patch<Transformable>(m_entity, [&pos, radians](Transformable &transform) {
            transform.m_position = pos;
            transform.m_radians = radians;
        });
    }

    sf::Vector2f Transformable::getPosition() const
    {
        return m_position;
    }

    sf::Vector2f Transformable::getScale() const
    {
        return m_scale;
    }

    float Transformable::getAngleRadians() const
    {
        return m_radians;
    }
}// namespace sfge::ecs