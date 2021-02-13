#pragma once

#include "component.hpp"

#include <SFML/Graphics.hpp>

namespace sfge::ecs
{
    class Transformable : public Component
    {
    public:
        void setPosition(const sf::Vector2f &pos);
        void setScale(const sf::Vector2f &scale);
        void setAngle(float radians);
        void setTransform(const sf::Vector2f &pos, float angleRadians);

        [[nodiscard]] sf::Vector2f getPosition() const;
        [[nodiscard]] sf::Vector2f getScale() const;
        [[nodiscard]] float getAngleRadians() const;

    private:
        sf::Vector2f m_position;      // meters
        sf::Vector2f m_scale = {1, 1};// meters
        float m_radians = 0.f;        // radians
    };
}// namespace sfge::ecs