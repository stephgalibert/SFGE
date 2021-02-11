#pragma once

#include "component.hpp"

#include <SFML/Graphics.hpp>

namespace ecge::ecs
{
    class Transformable : public Component
    {
    public:
        void setPosition(const sf::Vector2f &pos);
        void setScale(const sf::Vector2f &scale);
        void setAngle(float angle);
        void setTransform(const sf::Vector2f &pos, float angle);

        [[nodiscard]] sf::Vector2f position() const;
        [[nodiscard]] sf::Vector2f scale() const;
        [[nodiscard]] float angle() const;

    private:
        sf::Vector2f m_position;      // meters
        sf::Vector2f m_scale = {1, 1};// meters
        float m_angle = 0.f;          // radians
    };
}// namespace ecge::ecs