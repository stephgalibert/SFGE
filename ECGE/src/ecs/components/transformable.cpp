#include "ecge/components/transformable.hpp"

#include <iostream>

namespace ecge::ecs
{
    Transformable::Transformable()
    {
        std::clog << "tf ctor" << std::endl;
    }

    Transformable::Transformable(const Transformable &rhs)
        : Component(rhs)
    {
        std::clog << "tf copy ctor" << std::endl;
        *this = rhs;
    }

    Transformable::Transformable(Transformable &&rhs) noexcept
        : Component(std::move(rhs))
    {
        std::clog << "tf move ctor" << std::endl;
        *this = std::move(rhs);
    }

    Transformable &Transformable::operator=(const Transformable &rhs)
    {
        std::clog << "tf assign op" << std::endl;
        if (this != &rhs) {
            Component::operator=(rhs);
            m_position = rhs.m_position;
            m_scale = rhs.m_scale;
            m_angle = rhs.m_angle;
        }
        return *this;
    }

    Transformable &Transformable::operator=(Transformable &&rhs) noexcept
    {
        m_position = rhs.m_position;
        m_scale = rhs.m_scale;
        m_angle = rhs.m_angle;
        return *this;
    }

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

    void Transformable::setAngle(float angle)
    {
        m_registry->patch<Transformable>(m_entity, [angle](Transformable &transform) {
            transform.m_angle = angle;
        });
    }

    void Transformable::setTransform(const sf::Vector2f &pos, float angle)
    {
        m_registry->patch<Transformable>(m_entity, [&pos, angle](Transformable &transform) {
            transform.m_position = pos;
            transform.m_angle = angle;
        });
    }

    sf::Vector2f Transformable::position() const
    {
        return m_position;
    }

    sf::Vector2f Transformable::scale() const
    {
        return m_scale;
    }

    float Transformable::angle() const
    {
        return m_angle;
    }
}// namespace ecge::ecs